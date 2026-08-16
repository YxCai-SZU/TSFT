#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result == ((((n)) * ((n))) * 3);
    assigns \nothing;
*/
int func(int n)
{
    int n_squared;
    int result;
    
    //@ assert (1 <= (n) && (n) <= 10000);
    
    //@ assert 1 <= n && n <= 10000;
    
    //@ assert 1 <= n * n && n * n <= 100000000;
    
    n_squared = n * n;
    
    //@ assert 3 <= n_squared * 3 && n_squared * 3 <= 300000000;
    
    result = n_squared * 3;
    
    //@ assert result == ((((n)) * ((n))) * 3);
    
    return result;
}
