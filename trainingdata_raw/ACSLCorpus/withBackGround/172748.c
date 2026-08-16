#include <stddef.h>

/*@
    predicate valid_n(integer n) = 1 <= n <= 100;

    logic integer total_deduction(integer n, integer temp_n) = 
        ((n - temp_n) / 15) * 200;

    logic integer final_result(integer n, integer temp_n) = 
        n * 800 - total_deduction(n, temp_n);

    lemma deduction_bound: 
        \forall integer n, temp_n; 
        valid_n(n) && 0 <= temp_n <= n ==> 
        total_deduction(n, temp_n) <= n * 800;

    lemma temp_n_property: 
        \forall integer n, temp_n; 
        valid_n(n) && 0 <= temp_n <= n ==> 
        (n - temp_n) % 15 == 0 ==> temp_n + 15 * ((n - temp_n) / 15) == n;
*/

/*@
    requires valid_n(n);
    ensures \result == n * 800 - (n / 15 * 200);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t ret;
    size_t temp_n;

    //@ assert valid_n(n);
    ret = n * 800;
    temp_n = n;

    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant ret == final_result(n, temp_n);
        loop invariant (n - temp_n) % 15 == 0;
        loop assigns ret, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        ret = ret - 200;
        temp_n = temp_n - 15;
        //@ assert ret == final_result(n, temp_n);
    }

    //@ assert temp_n < 15;
    //@ assert ret == n * 800 - (n / 15 * 200);
    return ret;
}
