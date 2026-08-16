#include <stdbool.h>
#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (n % 100) * 21 <= n;
    ensures \result == 0 ==> (n % 100) * 21 > n;
*/
int func(int n)
{
    int n_mod_100;
    int twentyone_times_n_mod_100;
    int result;

    n_mod_100 = n % 100;
    //@ assert n_mod_100 == n % 100;
    
    if (n_mod_100 < 0)
    {
        n_mod_100 = n_mod_100 + 100;
    }
    
    twentyone_times_n_mod_100 = 21 * n_mod_100;
    
    if (twentyone_times_n_mod_100 <= n)
    {
        //@ assert n_mod_100 * 21 <= n;
        result = 1;
    }
    else
    {
        //@ assert n_mod_100 * 21 > n;
        result = 0;
    }
    
    return result;
}
