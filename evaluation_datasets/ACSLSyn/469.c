#include <stdbool.h>
#include <stdint.h>

/*@
    predicate min_val_is_a_or_b(integer a, integer b, integer min_val) =
        min_val == a || min_val == b;
*/

/*@
    predicate in_range(integer x) = 0 <= x <= 123;
    
    predicate ordered(integer a, integer b, integer c, integer d, integer e) = 
        a < b && b < c && c < d && d < e;
*/

bool func1(long long a, long long b, long long c)
{
    long long min_val;
    bool result;

    if (a < b)
    {
        min_val = a;
    }
    else
    {
        min_val = b;
    }

    //@ assert min_val_is_a_or_b(a, b, min_val);

    result = (a + b + 1 < c) || (a + 1 < c && c - (a + 1) < b);
    return result;
}

uint32_t func2(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    uint32_t result = 0;
    
    //@ assert b > a;
    //@ assert d > c;
    //@ assert b - a - 1 <= 122;
    //@ assert (b - a - 1) + (d - c - 1) <= 244;
    
    result += b - a - 1;
    result += d - c - 1;
    
    return result;
}

/*@
    predicate valid_candidate_range(integer a, integer b, integer c, integer d, integer e, integer min_val) =
        min_val == a || min_val == b;
    
    predicate combined_property(integer a, integer b, integer c, integer d, integer e, integer result1, integer result2) =
        (result1 == 1 ==> (a + b + 1 < c || (a + 1 < c && c - (a + 1) < b))) &&
        (result2 == (b - a - 1) + (d - c - 1));
*/

void process_candidate_range(long long a, long long b, long long c, uint32_t d, uint32_t e, bool *result1, uint32_t *result2)
{
    *result1 = func1(a, b, c);
    
    *result2 = func2(a, b, c, d, e);
    
    //@ assert combined_property(a, b, c, d, e, (bool)*result1, (integer)*result2);
}
