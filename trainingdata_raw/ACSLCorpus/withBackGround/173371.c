#include <stdbool.h>

/*@
    predicate valid_params(integer k, integer x) =
        1 <= k && k <= 100 &&
        1 <= x && x <= 100000;

    logic integer coins_value(integer k) = 500 * k;

    predicate coins_sufficient(integer k, integer x) =
        coins_value(k) >= x;
*/

/*@
    requires valid_params(k, x);
    ensures \result == (coins_value(k) >= x);
    assigns \nothing;
*/
bool func(int k, int x)
{
    int coins;
    bool result;

    //@ assert valid_params(k, x);
    
    coins = 500 * k;
    
    //@ assert coins == coins_value(k);
    
    result = coins >= x;
    
    //@ assert result == (coins_value(k) >= x);
    
    return result;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    bool test_result1;
    bool test_result2;
    
    test_result1 = func(4, 1500);
    assert(test_result1 == false);
    
    test_result2 = func(10, 500);
    assert(test_result2 == true);
    
    return 0;
}
#endif
