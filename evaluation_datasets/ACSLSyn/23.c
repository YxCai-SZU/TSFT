#include <stdint.h>

/*@
    predicate is_valid_range(integer x, integer y) =
        1 <= x <= 100 && 1 <= y <= 100;
    
    predicate post_condition(integer x, integer y, integer ans) =
        ans != 0 ==> (y % 2 == 0 && 1 <= x < y);
*/

int func1(int x, int y)
{
    int ans = 0;
    
    //@ assert is_valid_range(x, y);
    
    if (1 <= x && x <= 100 && 1 <= y && y <= 100)
    {
        if (y % 2 == 0 && 1 <= x && x < y)
        {
            ans = 1;
        }
    }
    
    //@ assert post_condition(x, y, ans);
    
    return ans;
}

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 1000000000000000000;

    logic integer func_spec(integer n) =
        n % 2 == 0 ? n / 2 - 1 : n / 2;

    lemma func_bounds:
        \forall integer n;
        is_valid_n(n) ==> 0 <= func_spec(n) && func_spec(n) <= n / 2 + 1;
*/

uint64_t func2(uint64_t n)
{
    uint64_t result;
    //@ assert is_valid_n(n);
    
    if (n % 2 == 0)
    {
        result = n / 2 - 1;
        //@ assert result == func_spec(n);
    }
    else
    {
        uint64_t x = n / 2;
        //@ assert x >= 0 && x <= n / 2 + 1;
        result = x;
        //@ assert result == func_spec(n);
    }
    
    //@ assert result >= 0;
    //@ assert result <= n / 2 + 1;
    return result;
}

/*@
    predicate valid_game_parameters(integer x, integer y, integer n) =
        is_valid_range(x, y) && is_valid_n(n) && (x + y) <= n;

    predicate high_level_property(integer x, integer y, integer n, int flag, uint64_t count) =
        (flag != 0 ==> (y % 2 == 0 && 1 <= x < y)) &&
        (count == func_spec(n));
*/

int analyze_game_level(int x, int y, uint64_t n, uint64_t *count)
{
    //@ assert valid_game_parameters(x, y, n);
    
    int flag = func1(x, y);
    //@ assert post_condition(x, y, flag);
    
    *count = func2(n);
    //@ assert *count == func_spec(n);
    
    //@ assert high_level_property(x, y, n, flag, *count);
    
    return flag;
}
