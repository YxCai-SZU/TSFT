#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (b - a == c - b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    int abs_diff_ab;
    int abs_diff_bc;
    bool result;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    
    //@ assert b - a >= -99 && b - a <= 99;
    //@ assert c - b >= -99 && c - b <= 99;

    if (b - a < 0) {
        abs_diff_ab = -(b - a);
    } else {
        abs_diff_ab = b - a;
    }
    //@ assert abs_diff_ab >= 0 && abs_diff_ab <= 99;

    if (c - b < 0) {
        abs_diff_bc = -(c - b);
    } else {
        abs_diff_bc = c - b;
    }
    //@ assert abs_diff_bc >= 0 && abs_diff_bc <= 99;

    result = (b - a == c - b);
    return result;
}
