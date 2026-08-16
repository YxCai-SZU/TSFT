#include <limits.h>

/*@
    requires ((n) > INT_MIN);
    ensures \result < n;
    ensures \result == n - 1;
    assigns \nothing;
*/
int closest_num(int n)
{
    //@ assert n - 1 < n;
    return n - 1;
}
