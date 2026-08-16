#include <stdbool.h>

/* 
 * Scenario: Network Packet Processing - Priority Classification and Rate Limiting
 * 
 * This function simulates a network traffic shaper that:
 * 1. Classifies packets based on their priority (using func) 
 * 2. Calculates the allowed bandwidth for the classified flow (using the bandwidth calculator)
 * 
 * The classification uses three packet header fields (flags) to determine priority:
 * - result == 1: High priority (all flags equal)
 * - result == 2: Medium priority (two flags equal)
 * - result == 3: Low priority (all flags different)
 * 
 * The bandwidth calculator determines the minimum bandwidth based on four flow parameters.
 * The final output is the bandwidth limit for the given packet priority class.
 */

/*@
    predicate in_range(integer x) = -100 <= x <= 100;

    logic integer result_value(integer a, integer b, integer c) =
        (a == b && b == c) ? 1 :
        ((a == b || b == c || a == c) && !(a == b && b == c)) ? 2 : 3;

    lemma second_branch_lemma:
        \forall integer a, b, c;
            in_range(a) && in_range(b) && in_range(c) &&
            (a == b || b == c || a == c) &&
            !(a == b && b == c) ==>
            ((a == b || b == c || a == c) && !(a == b && b == c));

    lemma third_branch_lemma:
        \forall integer a, b, c;
            in_range(a) && in_range(b) && in_range(c) &&
            a != b && b != c && a != c ==>
            (a != b && b != c && a != c);
*/

int func(long long a, long long b, long long c)
{
    long long result;

    if (a == b && b == c)
    {
        result = 1;
        //@ assert result == 1;
        return result;
    }
    else if (a == b || b == c || a == c)
    {
        //@ assert (a == b || b == c || a == c) && !(a == b && b == c);
        result = 2;
        //@ assert result == 2;
        return result;
    }
    else
    {
        //@ assert a != b && b != c && a != c;
        result = 3;
        //@ assert result == 3;
        return result;
    }
}

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer min(integer x, integer y) = x < y ? x : y;
    
    lemma sum_bounds:
        \forall integer a, b, c, d;
        valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==>
        a + b + c + d <= 40000;
*/

long func2(long a, long b, long c, long d)
{
    long min_ab;
    long min_cd;
    long ans;
    
    //@ assert a >= 1;
    //@ assert b >= 1;
    //@ assert c >= 1;
    //@ assert d >= 1;
    
    //@ assert a <= 10000;
    //@ assert b <= 10000;
    //@ assert c <= 10000;
    //@ assert d <= 10000;
    
    //@ assert a + b + c + d <= 40000;
    
    if (a + b < c) {
        min_ab = a + b;
    } else {
        min_ab = c;
    }
    
    if (c + d < b) {
        min_cd = c + d;
    } else {
        min_cd = b;
    }
    
    if (min_ab < min_cd) {
        ans = min_ab;
    } else {
        ans = min_cd;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= b + c + d;
    
    return ans;
}

/* 
 * Synthesized function: Network traffic shaper
 * 
 * Determines the bandwidth limit for a packet flow based on:
 * - Packet header flags (flag1, flag2, flag3): Used for priority classification
 * - Flow parameters (param1, param2, param3, param4): Used for bandwidth calculation
 * 
 * The function ensures that the returned bandwidth limit is always non-negative
 * and bounded by the total flow capacity.
 */

long traffic_shaper(long long flag1, long long flag2, long long flag3,
                    long param1, long param2, long param3, long param4)
{
    int priority;
    long bandwidth_limit;
    
    priority = func(flag1, flag2, flag3);
    
    bandwidth_limit = func2(param1, param2, param3, param4);
    
    
    //@ assert bandwidth_limit >= 0;
    //@ assert bandwidth_limit <= param2 + param3 + param4;
    
    return bandwidth_limit;
}
