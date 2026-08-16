#include <stdint.h>

/*@
    predicate product_invariant(integer r, integer pi_approx, integer two_r,
                                integer product, integer divisor, integer temp,
                                integer count) =
        1 <= r <= 100 &&
        pi_approx == 314 &&
        two_r == 2 * r &&
        product == two_r * pi_approx &&
        divisor == 100 &&
        temp >= 0 &&
        count * divisor + temp == product &&
        count * 100 + temp == 2 * r * 314;

    lemma division_lemma:
        \forall integer r, product, divisor, count, temp;
        product_invariant(r, 314, 2*r, product, divisor, temp, count) &&
        temp < divisor ==>
        count == product / divisor;
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * r * 314 / 100;
*/
int64_t func(int64_t r)
{
    int64_t pi_approx;
    int64_t two_r;
    int64_t product;
    int64_t ans;
    int64_t temp;
    int64_t divisor;
    int64_t count;

    pi_approx = 314;
    two_r = 2 * r;
    product = two_r * pi_approx;
    ans = 0;
    temp = product;
    divisor = 100;
    count = 0;

    /*@
        loop invariant product_invariant(r, pi_approx, two_r, product, divisor, temp, count);
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        count += 1;
    }
    ans = count;

    //@ assert ans * 100 + temp == 2 * r * 314;
    //@ assert temp < 100;
    //@ assert ans * 100 + temp == 2 * r * 314;
    //@ assert 2 * r * 314 == 2 * r * 314;
    //@ assert ans * 100 + temp == 2 * r * 314;

    return ans;
}

int main()
{
    return 0;
}
