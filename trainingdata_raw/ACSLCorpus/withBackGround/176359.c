#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer max_of_two(integer x, integer y) = x > y ? x : y;
    logic integer min_of_two(integer x, integer y) = x < y ? x : y;

    lemma max_min_mid_property:
        \forall integer a, b, c, max2, min2, mid;
            valid_range(a) && valid_range(b) && valid_range(c) &&
            max2 == max_of_two(max_of_two(a, b), c) &&
            min2 == min_of_two(min_of_two(a, b), c) &&
            mid == a + b + c - max2 - min2 ==>
            (10 * max2 + mid + min2) >= 10 &&
            (10 * max2 + mid + min2) <= 999;
*/

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result >= 10;
    ensures \result <= 999;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int max1;
    int max2;
    int min1;
    int min2;
    int mid;
    int result;

    // Calculate max1
    if (a > b) {
        max1 = a;
    } else {
        max1 = b;
    }

    // Calculate max2
    if (max1 > c) {
        max2 = max1;
    } else {
        max2 = c;
    }

    // Calculate min1
    if (a < b) {
        min1 = a;
    } else {
        min1 = b;
    }

    // Calculate min2
    if (min1 < c) {
        min2 = min1;
    } else {
        min2 = c;
    }

    // Calculate mid
    mid = a + b + c - max2 - min2;

    // Calculate result
    result = 10 * max2 + mid + min2;

    //@ assert result >= 10;
    //@ assert result <= 999;

    return result;
}
