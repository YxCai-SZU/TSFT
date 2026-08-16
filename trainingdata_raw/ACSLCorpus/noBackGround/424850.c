#include <stdbool.h>

/*@
    requires ((n) >= 0) && ((m) >= 0);
    requires (0 <= (n) && (n) <= 100) && (0 <= (m) && (m) <= 100);
    ensures \result == n * m;
    assigns \nothing;
*/
int func(int n, int m)
{
    //@ assert (0 <= (n) * (m) && (n) * (m) <= 10000);
    //@ assert (0 <= (n) * (m) && (n) * (m) <= 10000);
    return n * m;
}
