#include <stdbool.h>

/*@
    requires (1 <= (n) <= 1000);
    ensures \result == ((n) / 3);
    assigns \nothing;
*/
int func(int n)
{
    int ans = 0;
    int m = n;
    int count = 0;
    
    /*@
        loop invariant 0 <= m <= n;
        loop invariant m == n - 3 * count;
        loop invariant 0 <= count <= ((n) / 3);
        loop assigns m, count;
        loop variant m;
    */
    while (m >= 3)
    {
        //@ assert m >= 3;
        m -= 3;
        count += 1;
        //@ assert m == n - 3 * count;
    }
    
    ans = count;
    //@ assert ans == ((n) / 3);
    return ans;
}
