#include <stdbool.h>
#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
*/

bool func1(int d, int t, int s)
{
    int product;
    
    //@ assert 1 <= t <= 10000;
    //@ assert 1 <= s <= 10000;
    //@ assert t * s <= 10000 * 10000;
    
    product = t * s;
    
    //@ assert product == t * s;
    return d <= product;
}

/*@
    predicate is_even_and_large(uint32_t n) =
        n % 2 == 0 && n > 2;

    predicate is_odd_or_small(uint32_t n) =
        n % 2 != 0 || n <= 2;
*/

int32_t func2(uint32_t n)
{
    int32_t result;

    //@ assert 1 <= n <= 100;

    if (n % 2 == 0 && n > 2)
    {
        //@ assert n % 2 == 0 && n > 2;
        result = 1;
    }
    else
    {
        //@ assert n % 2 != 0 || n <= 2;
        result = 0;
    }

    //@ assert result == 0 || result == 1;
    //@ assert result == 1 ==> n % 2 == 0 && n > 2;
    //@ assert result == 0 ==> n % 2 != 0 || n <= 2;

    return result;
}

int synthesize_feasibility_check(int d, int t, int s, uint32_t p)
{
    bool feasible;
    int32_t priority_class;
    int result;
    
    feasible = func1(d, t, s);
    
    priority_class = func2(p);
    
    if (feasible && priority_class == 1)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    
    //@ assert result == 1 <==> (d <= t * s) && (p % 2 == 0 && p > 2);
    
    return result;
}
