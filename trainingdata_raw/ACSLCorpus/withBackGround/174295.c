#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a && a <= b && b <= 100 && a <= 100 && b <= 100;

    logic integer diff(integer a, integer b) = b - a;
    logic integer price_val(integer a, integer b) = diff(a, b) * 5;

    lemma price_nonnegative: \forall integer a, b; valid_range(a, b) ==> price_val(a, b) >= 0;
*/

/*@
    requires valid_range(a, b);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> (\result * 8) / 100 == a && (\result * 10) / 100 == b;
*/
int64_t func(uint64_t a, uint64_t b)
{
    // Variable declarations
    uint64_t diff;
    uint64_t price;
    uint64_t a_approx;
    uint64_t temp_price;
    uint64_t b_approx;
    uint64_t temp_price2;
    int64_t result;

    // Initial computations
    diff = b - a;
    price = diff * 5;

    // First loop: division by 8
    a_approx = 0;
    temp_price = price;
    /*@
        loop invariant 1 <= a <= b <= 100;
        loop invariant a <= 100 && b <= 100;
        loop invariant temp_price >= 0;
        loop invariant price == diff * 5;
        loop invariant a_approx >= 0;
        loop invariant temp_price == price - a_approx * 8;
        loop invariant a_approx <= price / 8;
        loop assigns a_approx, temp_price;
        loop variant temp_price;
    */
    while (temp_price >= 8)
    {
        a_approx += 1;
        temp_price -= 8;
    }

    // Second loop: division by 10
    b_approx = 0;
    temp_price2 = price;
    /*@
        loop invariant 1 <= a <= b <= 100;
        loop invariant a <= 100 && b <= 100;
        loop invariant temp_price2 >= 0;
        loop invariant price == diff * 5;
        loop invariant b_approx >= 0;
        loop invariant temp_price2 == price - b_approx * 10;
        loop invariant b_approx <= price / 10;
        loop assigns b_approx, temp_price2;
        loop variant temp_price2;
    */
    while (temp_price2 >= 10)
    {
        b_approx += 1;
        temp_price2 -= 10;
    }

    // Final check and return
    if (a_approx == a && b_approx == b)
    {
        //@ assert price * 8 / 100 == a && price * 10 / 100 == b;
        result = (int64_t)price;
    }
    else
    {
        result = -1;
    }

    return result;
}

int main()
{
    return 0;
}
