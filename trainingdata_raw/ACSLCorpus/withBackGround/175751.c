#include <stdint.h>
#include <limits.h>

/*@
    predicate in_range(integer v) = 0 <= v <= 50;
    predicate sum_in_range(integer s) = 0 <= s <= 100;
*/

/*@
    logic integer min3(integer x, integer y, integer z) =
        (x <= y && x <= z) ? x : ((y <= z) ? y : z);
*/

/*@
    lemma sum_range_lemma:
        \forall integer a, b;
            in_range(a) && in_range(b) ==> sum_in_range(a + b);
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == 0 || \result == 1;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t m;
    int64_t diff1;
    int64_t diff2;
    int64_t diff3;
    int64_t min_diff;
    int64_t result;
    
    //@ assert in_range(a) && in_range(b) && in_range(c);
    
    //@ assert sum_in_range(a + b);
    //@ assert sum_in_range(a + c);
    
    m = INT64_MAX;
    
    //@ assert m == INT64_MAX;
    
    //@ assert a + b + c >= 0;
    m = (m < a + b + c) ? m : (a + b + c);
    diff1 = (a + b + c) - m;
    
    //@ assert m <= a + b + c;
    //@ assert diff1 >= 0;
    
    m = (m < a + b) ? m : (a + b);
    diff2 = (a + b) - m;
    
    //@ assert m <= a + b;
    //@ assert diff2 >= 0;
    
    m = (m < a + c) ? m : (a + c);
    diff3 = (a + c) - m;
    
    //@ assert m <= a + c;
    //@ assert diff3 >= 0;
    
    min_diff = diff1;
    
    //@ assert min_diff == diff1;
    //@ assert min_diff >= 0;
    
    if (diff2 < min_diff)
    {
        min_diff = diff2;
    }
    
    //@ assert min_diff >= 0;
    
    if (diff3 < min_diff)
    {
        min_diff = diff3;
    }
    
    //@ assert min_diff >= 0;
    
    if (min_diff == 0)
    {
        result = 0;
    }
    else
    {
        result = 1;
    }
    
    //@ assert result == 0 || result == 1;
    return result;
}
