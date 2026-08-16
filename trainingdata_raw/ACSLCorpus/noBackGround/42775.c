#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100);
    requires (1 <= (k) <= 1000);
    ensures \result == (n % 500 <= k);
    assigns \nothing;
*/
bool func(int k, int n)
{
    int ans;
    bool result;

    ans = n % 500;
    //@ assert ans == n % 500;
    
    result = ans <= k;
    return result;
}
