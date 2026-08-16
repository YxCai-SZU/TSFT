#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (k) <= 100);
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> n % k == 0;
    ensures \result == 1 ==> n % k != 0;
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int k)
{
    unsigned int ans;
    //@ assert (1 <= (n) <= 100 && 1 <= (k) <= 100);
    
    if (n % k == 0)
    {
        ans = 0;
        //@ assert n % k == 0;
    }
    else
    {
        ans = 1;
        //@ assert n % k != 0;
    }
    
    return ans;
}
