#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (3 * (n) * (n));
    assigns \nothing;
*/
int func(int n)
{
    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert 3 * n * n <= 30000;
    return 3 * n * n;
}
