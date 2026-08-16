#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;

    logic integer total_calc(integer i) = i * 800;

    logic integer final_calc(integer n) = n * 800 - (n / 15) * 200;

    lemma total_lemma: \forall integer n; is_valid_n(n) ==> total_calc(n) == n * 800;
    lemma final_lemma: \forall integer n; is_valid_n(n) ==> final_calc(n) == n * 800 - (n / 15) * 200;
*/

/*@
    requires is_valid_n(n);
    ensures \result == final_calc(n);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t x = 800;
    int32_t y = 200;
    int32_t total = 0;
    uint32_t i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant total == total_calc(i);
        loop invariant is_valid_n(n);
        loop invariant i > 0 ==> total == i * x;
        loop assigns total, i;
        loop variant n - i;
    */
    while (i < n)
    {
        total += x;
        i += 1;
    }

    int32_t final_result = total - ((n / 15) * y);

    //@ assert total == total_calc(n);
    //@ assert final_result == final_calc(n);

    return final_result;
}
