#include <stdbool.h>

/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures (m > n ==> \result == 0);
    ensures (m <= n ==> \result == n - m + 1);
    assigns \nothing;
*/
int func(int n, int m)
{
    int ans;

    //@ assert 1 <= n <= 20;
    //@ assert 1 <= m <= 20;
    
    if (m > n) {
        ans = 0;
        //@ assert ans == 0;
    } else {
        ans = n - m + 1;
        //@ assert ans == n - m + 1;
    }

    //@ assert (m > n ==> ans == 0) && (m <= n ==> ans == n - m + 1);
    return ans;
}
