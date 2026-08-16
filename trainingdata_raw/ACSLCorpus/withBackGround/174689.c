#include <stdbool.h>

/*@
    predicate is_valid_range(integer r) = 1 <= r <= 100;
    
    logic integer pi_approx_const = 314;
    
    logic integer division_result(integer r) = 2 * r * pi_approx_const / 100;
    
    lemma division_property:
        \forall integer r, integer temp, integer count;
        is_valid_range(r) && temp >= 0 && temp == 2 * r * pi_approx_const - 100 * count && count >= 0 ==>
        count <= division_result(r);
*/

/*@
    requires is_valid_range(r);
    ensures \result == division_result(r);
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at top of scope
    int pi_approx;
    int result;
    int temp;
    int count;
    
    pi_approx = 314;
    result = 0;
    temp = 2 * r * pi_approx;
    count = 0;
    
    //@ assert temp == 2 * r * pi_approx_const;
    //@ assert temp >= 0;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 314;
        loop invariant temp >= 0;
        loop invariant temp == 2 * r * pi_approx_const - 100 * count;
        loop invariant count >= 0;
        loop invariant count <= division_result(r);
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 100)
    {
        //@ assert temp >= 100;
        temp = temp - 100;
        //@ assert temp >= 0;
        count = count + 1;
        //@ assert temp == 2 * r * pi_approx_const - 100 * count;
    }
    
    result = count;
    
    //@ assert result * 100 + temp == 2 * r * pi_approx_const;
    //@ assert result == division_result(r);
    
    return result;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
