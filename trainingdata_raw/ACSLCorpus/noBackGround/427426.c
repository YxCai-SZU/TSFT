#include <stdbool.h>

/*@
    requires (1 <= (k) && (k) <= 100 &&
        1 <= (x) && (x) <= 100000);
    ensures \result == (x <= k * 500);
    assigns \nothing;
*/
bool func(int k, int x)
{
    int yen_per_coin;
    bool ans;

    yen_per_coin = 500;
    //@ assert yen_per_coin == 500;
    
    ans = x <= k * yen_per_coin;
    //@ assert ans == (x <= k * 500);
    
    return ans;
}
