#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (c - b == b - a);
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    //@ assert c - b == b - a ==> (c - b) == (b - a);
    return (c - b) == (b - a);
}
