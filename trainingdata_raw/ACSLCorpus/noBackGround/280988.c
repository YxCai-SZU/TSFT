#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures ((n) % 2 == 0) ==> \result == 1;
    ensures !((n) % 2 == 0) ==> \result == 0;
    assigns \nothing;
*/
int func(int n)
{
    int ans;
    //@ assert 1 <= n <= 100;
    
    if (n % 2 == 0) {
        ans = 1;
    } else {
        ans = 0;
    }
    
    return ans;
}
