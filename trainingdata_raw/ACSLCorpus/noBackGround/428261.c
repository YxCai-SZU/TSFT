#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100 &&
        1 <= (d) && (d) <= 100);
    ensures \result == ((a - c) * (b - d) <= 0);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    int left;
    int right;
    int product;
    bool is_less_or_equal;

    left = a - c;
    right = b - d;

    //@ assert -99 <= left <= 99;
    //@ assert -99 <= right <= 99;
    //@ assert -9801 <= left * right <= 9801;

    product = left * right;

    is_less_or_equal = false;
    if (product <= 0)
    {
        is_less_or_equal = true;
    }

    return is_less_or_equal;
}
