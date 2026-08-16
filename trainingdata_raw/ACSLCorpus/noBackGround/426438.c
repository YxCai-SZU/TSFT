#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 10);
    ensures \result == ((n) + (((n)) * ((n))) + (((n)) * ((n)) * ((n))));
    assigns \nothing;
*/
int func(int n)
{
    int res;
    
    //@ assert (1 <= (n) && (n) <= 10);
    res = n;
    
    //@ assert 1 <= n * n && n * n <= 100;
    res = res + n * n;
    
    //@ assert 1 <= n * n * n && n * n * n <= 1000;
    res = res + n * n * n;
    
    //@ assert res == ((n) + (((n)) * ((n))) + (((n)) * ((n)) * ((n))));
    return res;
}
