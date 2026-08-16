#include <limits.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == n * n;
    ensures (1 <= (n) <= 100 && (n) * (n) <= 10000);
*/
int func(int n)
{
    //@ assert n > 0;
    //@ assert n <= 100;
    //@ assert n * n <= 10000;
    
    return n * n;
}
