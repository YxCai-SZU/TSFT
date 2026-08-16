#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100);
    requires (1 <= (m) <= 100);
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(int n, int m)
{
    //@ assert (1 <= (n) <= 100);
    //@ assert (1 <= (m) <= 100);
    return n == m;
}
