#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer h) =
        1 <= a <= 100 &&
        1 <= b <= 100 &&
        1 <= h <= 100 &&
        h % 2 == 0;

    logic integer trapezoid_area(integer a, integer b, integer h) =
        (a + b) * h / 2;

    lemma product_bounds:
        \forall integer a, b, h;
        valid_params(a, b, h) ==> 1 <= (a + b) * h <= 20000;
*/

/*@
    requires valid_params(a, b, h);
    ensures \result == trapezoid_area(a, b, h);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t h)
{
    // Variable declarations at scope top
    int64_t sum;
    int64_t prod;
    int64_t ans;
    int64_t temp;
    int64_t count;

    // Precondition verification
    //@ assert valid_params(a, b, h);

    sum = a + b;
    //@ assert sum == a + b;

    prod = sum * h;
    //@ assert prod == sum * h;

    // Product bounds verification
    //@ assert 1 <= prod <= 20000;

    ans = 0;
    temp = prod;
    count = 0;

    /*@
        loop invariant 0 <= count <= prod / 2;
        loop invariant temp == prod - 2 * count;
        loop invariant temp >= 0;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
        count += 1;
    }

    ans = count;
    //@ assert ans == count;

    // Postcondition verification
    //@ assert ans == trapezoid_area(a, b, h);
    return ans;
}
