#include <stdbool.h>

/*@
    requires -40 <= k <= 40;
    ensures \result <==> ((k) >= 30);
    assigns \nothing;
 */
bool func(int k)
{
    //@ assert -40 <= k <= 40;
    return k >= 30;
}
