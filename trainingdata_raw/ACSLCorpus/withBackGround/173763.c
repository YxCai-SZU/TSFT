#include <stdbool.h>

/*@ predicate is_in_range(integer x) = 0 <= x <= 10; */

/*@
    requires is_in_range(a);
    requires is_in_range(b);
    requires is_in_range(c);
    ensures \result <==> (a <= b && b <= c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert is_in_range(a);
    //@ assert is_in_range(b);
    //@ assert is_in_range(c);
    return (a <= b) && (b <= c);
}
