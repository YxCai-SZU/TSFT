#include <stdint.h>

/*@
    predicate is_valid_range(integer r) = 1 <= r <= 100;
    
    logic integer calculate_expected(integer r) = 
        2 * 314159 * r / 100000;
    
    lemma loop_invariant_maintained:
        \forall integer r, pi, ans, temp, count;
        is_valid_range(r) && pi == 314159 && ans == 2 * pi * r &&
        temp >= 0 && temp == ans - count * 100000 && 
        count * 100000 <= ans ==>
        (temp >= 100000 ==> 
            temp - 100000 >= 0 &&
            temp - 100000 == ans - (count + 1) * 100000 &&
            (count + 1) * 100000 <= ans);
*/

/*@
    requires is_valid_range(r);
    ensures \result == calculate_expected(r);
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi;
    int64_t ans;
    int64_t count;
    int64_t temp;
    
    pi = 314159;
    ans = 2 * pi * r;
    count = 0;
    temp = ans;
    
    //@ assert is_valid_range(r) && pi == 314159 && ans == 2 * pi * r;
    //@ assert temp >= 0 && temp == ans - count * 100000 && count * 100000 <= ans;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314159;
        loop invariant ans == 2 * pi * r;
        loop invariant temp >= 0;
        loop invariant temp == ans - count * 100000;
        loop invariant count * 100000 <= ans;
        loop assigns temp, count;
    */
    while (temp >= 100000) {
        //@ assert temp >= 100000;
        temp -= 100000;
        count += 1;
        //@ assert temp >= 0;
        //@ assert temp == ans - count * 100000;
        //@ assert count * 100000 <= ans;
    }
    
    ans = count;
    //@ assert ans == calculate_expected(r);
    return ans;
}
