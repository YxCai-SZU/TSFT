#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == true <==> ((((x)) / 100) * 100 <= (x) && (x) <= (((x)) / 100) * 105);
    assigns \nothing;
*/
bool func(unsigned long x)
{
    unsigned long n;
    bool ans;
    
    //@ assert (1 <= (x) <= 100000);
    
    n = x / 100;
    ans = false;
    
    if (n * 100 <= x && x <= n * 105) {
        ans = true;
    }
    
    //@ assert ans == true <==> (x / 100 * 100 <= x && x <= x / 100 * 105);
    
    return ans;
}
