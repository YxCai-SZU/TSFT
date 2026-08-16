#include <stdbool.h>

/*@
    predicate diff_in_range(integer diff) = -99 <= diff <= 99;
    predicate square_in_range(integer sq) = 0 <= sq <= 99 * 99;
    predicate sum_in_range(integer s) = 0 <= s <= 19801;
    logic integer square(integer x) = x * x;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> ((a - c)*(a - c) + (b - d)*(b - d)) <= 100;
*/
bool func(int a, int b, int c, int d)
{
    bool result;
    int diff1;
    int diff2;
    int square1;
    int square2;
    int sum;
    bool is_in_range;

    result = false;
    diff1 = a - c;
    diff2 = b - d;

    //@ assert diff_in_range(diff1);
    //@ assert diff_in_range(diff2);
    //@ assert square_in_range(square(diff1));
    //@ assert square_in_range(square(diff2));

    square1 = diff1 * diff1;
    square2 = diff2 * diff2;

    //@ assert square_in_range(square1);
    //@ assert square_in_range(square2);
    //@ assert sum_in_range(square1 + square2);

    sum = square1 + square2;
    is_in_range = false;

    if (sum <= 100)
    {
        is_in_range = true;
    }

    if (is_in_range)
    {
        result = true;
    }

    return result;
}
