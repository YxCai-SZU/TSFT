#include <stdbool.h>

/*@ predicate is_in_range(integer x) = 1 <= x <= 9; */

/*@
    requires is_in_range(a) && is_in_range(b) && is_in_range(c);
    ensures \result == ((a == b && c != a) || (a == c && c != b) || (b == c && c != a));
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert is_in_range(a);
    //@ assert is_in_range(b);
    //@ assert is_in_range(c);
    return (a == b && c != a) || (a == c && c != b) || (b == c && c != a);
}
