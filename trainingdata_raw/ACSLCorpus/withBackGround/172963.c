#include <stdbool.h>

/*@
    predicate is_valid_params(integer k, integer x) =
        1 <= k <= 100 && 1 <= x <= 100000;

    logic integer calculate_sum(integer k) = 500 * k;

    predicate result_condition(integer sum, integer x, bool result) =
        result == (sum >= x);
*/

/*@
    requires is_valid_params(k, x);
    ensures result_condition(500 * k, x, \result);
    assigns \nothing;
*/
bool func(int k, int x)
{
    int sum;
    bool result;

    //@ assert is_valid_params(k, x);
    sum = 500 * k;
    //@ assert sum == calculate_sum(k);
    result = (sum >= x);
    //@ assert result_condition(sum, x, result);
    return result;
}

#ifdef TESTING
#include <assert.h>
int main()
{
    bool res1, res2;
    
    res1 = func(1, 500);
    //@ assert res1 == true;
    assert(res1 == true);
    
    res2 = func(1, 501);
    //@ assert res2 == false;
    assert(res2 == false);
    
    return 0;
}
#endif
