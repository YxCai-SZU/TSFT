#include <stdbool.h>

/*@
    requires (2 <= (n) <= 100 && 2 <= (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int func(int n, int m)
{
    //@ assert 1 <= (n - 1) && (n - 1) <= 99;
    //@ assert 1 <= (m - 1) && (m - 1) <= 99;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;
    
    return (n - 1) * (m - 1);
}
