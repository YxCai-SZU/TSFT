#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    predicate pi_constant(integer pi) = pi == 3142;
    predicate temp_formula(integer temp, integer r, integer count) = 
        temp == 2 * 3142 * r - 1000 * count;
    predicate count_bound(integer count, integer r) = 
        count <= 2 * 3142 * r / 1000;
*/

/*@
    logic integer calculate_result(integer r) = 2 * 3142 * r / 1000;
*/

/*@
    lemma loop_invariant_maintained:
        \forall integer r, temp, count;
        valid_range(r) && pi_constant(3142) && 0 <= count && 
        temp >= 0 && temp_formula(temp, r, count) && 
        count_bound(count, r) && temp >= 1000 ==>
        temp_formula(temp - 1000, r, count + 1) && 
        count_bound(count + 1, r);
*/

/*@
    lemma loop_terminates:
        \forall integer temp;
        temp >= 0 ==> temp - 1000 < temp;
*/

/*@
    requires valid_range(r);
    ensures \result == calculate_result(r);
*/
int64_t func(int64_t r)
{
    // Variable declarations
    int64_t pi = 3142;
    int64_t ans = 0;
    int64_t temp = 2 * pi * r;
    int64_t count = 0;
    
    //@ assert pi_constant(pi);
    //@ assert temp_formula(temp, r, count);
    
    /*@
        loop invariant valid_range(r);
        loop invariant pi_constant(pi);
        loop invariant 0 <= count;
        loop invariant temp >= 0;
        loop invariant temp_formula(temp, r, count);
        loop invariant count_bound(count, r);
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 1000)
    {
        //@ assert temp >= 1000;
        temp -= 1000;
        count += 1;
        //@ assert temp_formula(temp, r, count);
    }
    
    ans = count;
    //@ assert ans == calculate_result(r);
    
    return ans;
}
