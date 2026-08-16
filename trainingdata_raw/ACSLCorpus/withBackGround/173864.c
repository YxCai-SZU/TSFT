#include <stdbool.h>

/*@
    predicate is_valid_params(integer k, integer x) =
        1 <= k && k <= 100 &&
        1 <= x && x <= 100000;

    logic integer total_cost(integer k) = k * 500;
*/

/*@
    requires is_valid_params(k, x);
    ensures \result == true <==> k * 500 >= x;
    assigns \nothing;
*/
bool func(int k, int x)
{
    bool ans;
    int yen_per_coin = 500;

    //@ assert is_valid_params(k, x);
    
    if (x <= k * yen_per_coin)
    {
        ans = true;
    }
    else
    {
        ans = false;
    }

    //@ assert ans == true <==> k * 500 >= x;
    return ans;
}
