#include <stdbool.h>

/*@
    requires 1 <= n <= 9;
    ensures \result == (n == 7 || n == 5 || n == 3);
    assigns \nothing;
 */
bool func(int n)
{
    //@ assert 1 <= n <= 9;
    return n == 7 || n == 5 || n == 3;
}
