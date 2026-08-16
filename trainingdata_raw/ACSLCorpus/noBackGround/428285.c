#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == (a == b && b == c);
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    bool is_all_equal = true;

    //@ assert is_all_equal == true;
    if (a != b) {
        is_all_equal = false;
    }
    //@ assert is_all_equal == (a == b);
    if (b != c) {
        is_all_equal = false;
    }
    //@ assert is_all_equal == (a == b && b == c);
    if (c != a) {
        is_all_equal = false;
    }
    //@ assert is_all_equal == (a == b && b == c);
    return is_all_equal;
}
