#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == (n % 4 == 0);
    assigns \nothing;
*/
bool func(int n)
{
    //@ assert n % 4 == n % 4;
    return (n % 4) == 0;
}
