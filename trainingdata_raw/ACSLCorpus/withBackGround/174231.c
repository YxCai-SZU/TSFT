#include <limits.h>

/*@
    predicate valid_input(integer a, integer b, integer h) =
        1 <= a <= 100 &&
        1 <= b <= 100 &&
        1 <= h <= 100 &&
        h % 2 == 0;

    logic integer trapezoid_area(integer a, integer b, integer h) =
        (h * (a + b)) / 2;

    lemma sum_bounds:
        \forall integer a, b;
        valid_input(a, b, 2) ==> 2 <= a + b <= 200;

    lemma product_bounds:
        \forall integer a, b, h, sum;
        valid_input(a, b, h) && sum == a + b ==> 2 <= h * sum <= 20000;
*/

/*@
    requires valid_input(a, b, h);
    ensures \result == trapezoid_area(a, b, h);
    assigns \nothing;
*/
long func(long a, long b, long h)
{
    // Declare all variables at the top
    long sum;
    long result = 0;
    long temp;

    //@ assert valid_input(a, b, h);

    sum = a + b;
    //@ assert 2 <= sum <= 200;

    //@ assert 2 <= h * sum <= 20000;
    temp = h * sum;

    /*@
        loop invariant 0 <= result <= trapezoid_area(a, b, h);
        loop invariant temp == h * sum - 2 * result;
        loop invariant valid_input(a, b, h);
        loop assigns result, temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        result += 1;
        temp -= 2;
    }

    //@ assert result == trapezoid_area(a, b, h);
    return result;
}
