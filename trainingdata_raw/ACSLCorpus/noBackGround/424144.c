#include <limits.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (r) <= 4111);
    ensures (((n) >= 10 ==> (\result) == (r)) &&
        ((n) < 10 ==> (\result) == (r) + 100 * (10 - (n))));
    assigns \nothing;
*/
int func(int n, int r)
{
    int pay;
    int ans;

    //@ assert 1 <= n <= 100 && 0 <= r <= 4111;
    
    if (n >= 10) {
        pay = 0;
    } else {
        pay = 100 * (10 - n);
    }

    //@ assert pay == (n >= 10 ? 0 : 100 * (10 - n));
    //@ assert 0 <= pay <= 900;
    //@ assert r + pay <= 4111 + 900;
    
    ans = r + pay;
    
    //@ assert (n >= 10 ==> ans == r) && (n < 10 ==> ans == r + 100 * (10 - n));
    
    return ans;
}
