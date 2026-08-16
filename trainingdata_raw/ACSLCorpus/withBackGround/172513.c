#include <stdint.h>

/*@
    predicate product_invariant(integer r, integer pi_approx, integer product, integer result, integer temp) =
        1 <= r <= 100 &&
        pi_approx == 314 &&
        product == 2 * r * pi_approx &&
        result * 100 + temp == product &&
        temp >= 0;

    logic integer loop_decreases(integer temp) = temp;
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * r * 314 / 100;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi_approx;
    int64_t product;
    int64_t result;
    int64_t temp;

    pi_approx = 314;
    product = 2 * r * pi_approx;
    result = 0;
    temp = product;

    /*@
        loop invariant product_invariant(r, pi_approx, product, result, temp);
        loop invariant loop_decreases(temp) >= 0;
        loop assigns result, temp;
        loop variant temp;
    */
    while (temp >= 100)
    {
        //@ assert temp >= 100;
        result += 1;
        temp -= 100;
        //@ assert result * 100 + temp == product;
    }

    //@ assert result * 100 + temp == product && temp < 100;
    return result;
}
