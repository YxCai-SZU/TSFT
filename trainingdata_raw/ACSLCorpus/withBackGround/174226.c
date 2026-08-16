#include <limits.h>

/*@
    predicate is_nonnegative(integer x) = x >= 0;
    predicate is_positive(integer x) = x >= 1;
    predicate valid_inputs(integer a, integer b, integer c, integer k) =
        is_nonnegative(a) &&
        is_nonnegative(b) &&
        is_nonnegative(c) &&
        is_positive(k) &&
        k <= a + b + c &&
        a + b + c <= 2000000000;
*/

/*@
    logic integer max3(integer a, integer b, integer c) =
        (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
*/

/*@
    lemma max3_nonnegative:
        \forall integer a, b, c;
        is_nonnegative(a) && is_nonnegative(b) && is_nonnegative(c) ==>
        is_nonnegative(max3(a, b, c));
*/

/*@
    requires valid_inputs(a, b, c, k);
    ensures \result <= k;
    ensures \result >= -k;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int cnt = 0;
    int rst = k;
    int max_val;
    
    // First max calculation
    if (a > b)
    {
        if (a > c)
        {
            max_val = a;
        }
        else
        {
            max_val = c;
        }
    }
    else
    {
        if (b > c)
        {
            max_val = b;
        }
        else
        {
            max_val = c;
        }
    }
    
    //@ assert max_val == max3(a, b, c);
    
    if (rst < max_val)
    {
        cnt += rst;
        rst = 0;
    }
    else
    {
        cnt += max_val;
        rst -= max_val;
    }
    
    // Second max calculation
    if (a > b)
    {
        if (a > c)
        {
            max_val = a;
        }
        else
        {
            max_val = c;
        }
    }
    else
    {
        if (b > c)
        {
            max_val = b;
        }
        else
        {
            max_val = c;
        }
    }
    
    //@ assert max_val == max3(a, b, c);
    
    if (rst < max_val)
    {
        rst = 0;
    }
    else
    {
        rst -= max_val;
    }
    
    //@ assert cnt - rst <= k;
    return cnt - rst;
}
