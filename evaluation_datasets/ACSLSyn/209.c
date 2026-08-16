#include <stdbool.h>

/* First function: checks if (x % 100) * 21 <= x for valid range numbers */
/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100000;
    
    logic integer division_result(integer x) = x / 100;
    logic integer modulus_result(integer x) = x % 100;
    
    lemma division_modulus_relation:
        \forall integer x; is_valid_range(x) ==> 
        x == 100 * division_result(x) + modulus_result(x);
*/

bool func1(unsigned int x) {
    unsigned int n;
    unsigned int m;
    unsigned int temp_x;
    unsigned int temp_n;
    unsigned int temp_m;
    
    n = x / 100;
    m = x % 100;
    
    temp_x = x;
    temp_n = 0;
    temp_m = 0;
    
    while (temp_x >= 100) {
        temp_x -= 100;
        temp_n += 1;
    }
    temp_m = temp_x;
    
    //@ assert temp_n == n && temp_m == m;
    
    if (temp_m * 21 <= x) {
        return true;
    } else {
        return false;
    }
}

/* Second function: checks if range of sorted 5-tuple <= k */
/*@
    predicate sorted(integer a, integer b, integer c, integer d, integer e) =
        a <= b && b <= c && c <= d && d <= e;
    
    logic integer diff(integer e, integer a) = e - a;
*/

bool func2(unsigned long long a, unsigned long long b, unsigned long long c,
           unsigned long long d, unsigned long long e, unsigned long long k)
{
    unsigned long long l;
    
    //@ assert sorted(a, b, c, d, e);
    //@ assert diff(e, a) <= 123;
    //@ assert k <= 123;
    
    l = e - a;
    
    if (l > k)
    {
        //@ assert l > k;
        //@ assert diff(e, a) > k;
        return false;
    }
    else
    {
        //@ assert l <= k;
        //@ assert diff(e, a) <= k;
        return true;
    }
}

/* Synthesized function: Score eligibility checker for a competition
 *
 * Real-world scenario: In a programming competition, each participant has
 * an ID (x) that encodes their category (first 2 digits) and score (last 2 digits).
 * The eligibility rule requires:
 * 1. The participant's category score (score * 21) must not exceed their ID (basic rule)
 * 2. Among the top 5 participants in sorted order by score, the range between
 *    highest and lowest must not exceed a threshold k (consistency rule)
 *
 * Data flow: 
 * - Input x is a participant ID (1-100000)
 * - Inputs a,b,c,d,e are sorted scores of top 5 participants
 * - Input k is the maximum allowed range
 * - Returns true if both conditions are met, false otherwise
 */
bool check_eligibility(unsigned int x, 
                       unsigned long long a, unsigned long long b, 
                       unsigned long long c, unsigned long long d, 
                       unsigned long long e, unsigned long long k)
{
    bool basic_rule_ok;
    bool consistency_ok;
    
    basic_rule_ok = func1(x);
    
    consistency_ok = func2(a, b, c, d, e, k);
    
    /* High-level property: The eligibility check ensures that
     * both the individual score constraint and the group consistency
     * constraint are simultaneously satisfied.
     * This represents a two-stage verification process common in
     * real-world eligibility systems.
     */
    //@ assert basic_rule_ok == ((x % 100) * 21 <= x);
    //@ assert consistency_ok == (diff(e, a) <= k);
    
    return basic_rule_ok && consistency_ok;
}
