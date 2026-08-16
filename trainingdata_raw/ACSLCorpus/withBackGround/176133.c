#include <stdbool.h>

/*@
    predicate diff_in_range(integer diff) = -99 <= diff <= 99;
    predicate square_in_range(integer sq) = 0 <= sq <= 9801;
    logic integer square(integer diff) = diff * diff;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> (a - b) * (a - b) >= (c - d) * (c - d);
*/
bool func(int a, int b, int c, int d)
{
    int diff1;
    int diff2;
    int square1;
    int square2;
    bool result;

    diff1 = a - b;
    diff2 = c - d;

    //@ assert diff_in_range(diff1);
    //@ assert square_in_range(diff1 * diff1);
    square1 = diff1 * diff1;

    //@ assert diff_in_range(diff2);
    //@ assert square_in_range(diff2 * diff2);
    square2 = diff2 * diff2;

    result = square1 >= square2;
    return result;
}
