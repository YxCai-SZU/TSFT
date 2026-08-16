#include <stdbool.h>

/*@
    requires (1 <= (k) <= (n) <= 50);
    ensures \result == ((n) - (k) + 1);
    assigns \nothing;
*/
int func(int n, int k)
{
    // Variable declarations at top of scope
    int result;

    //@ assert k - 1 >= 0;
    //@ assert n - (k - 1) >= 0;
    //@ assert n - (k - 1) <= 50;

    result = n - (k - 1);
    return result;
}
