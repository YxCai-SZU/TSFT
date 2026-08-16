#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    requires a != b;
    requires b != c;
    requires a != c;
    ensures \result == true <==> ((a <= c && c <= b) || (b <= c && c <= a));
*/
bool func(int a, int b, int c)
{
    bool is_within_range = false;

    //@ assert a != b && b != c && a != c;

    if (a <= c && c <= b) {
        is_within_range = true;
    }

    if (b <= c && c <= a) {
        is_within_range = true;
    }

    //@ assert is_within_range == true <==> ((a <= c && c <= b) || (b <= c && c <= a));

    return is_within_range;
}
