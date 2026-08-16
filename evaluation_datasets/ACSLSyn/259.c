#include <stdint.h>
#include <stdbool.h>

/* First function: weighted sum calculation */
/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
*/

/*@
    logic integer weighted_sum(integer a, integer b, integer c) =
        a * 2 + b * 3 + c * 5;
*/

/*@
    lemma sum_non_negative:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            weighted_sum(a, b, c) >= 0;
*/

int32_t func_weighted_sum(int32_t a, int32_t b, int32_t c)
{
    int32_t sum = 0;
    
    //@ assert a > 0;
    sum += 2 * a;
    
    //@ assert b > 0;
    sum += 3 * b;
    
    //@ assert c > 0;
    sum += 5 * c;
    
    //@ assert sum >= 0;
    //@ assert sum <= weighted_sum(a, b, c);
    return sum;
}

/* Second function: climbing counter */

int func_climbing(int N, int H) {
    int ans = 0;
    int remaining_height = H;
    int i = 0;

    while (i < N) {
        bool can_climb = false;

        //@ assert remaining_height >= 0;
        if (remaining_height <= 1) {
            can_climb = true;
        } else if (remaining_height >= 2 * (N - i) + 1) {
            can_climb = true;
        }

        if (can_climb) {
            ans += 1;
            remaining_height = 0;
        } else {
            remaining_height -= 1;
        }
        i += 1;

        //@ assert ans <= i;
    }

    //@ assert ans <= N;
    return ans;
}

/* Third function: modulo four check */
/*@
    predicate in_range(integer v) = 1 <= v <= 9;

    logic integer combine(integer x, integer y) = x * 10 + y;

    logic integer mod_four(integer v) = v % 4;

    lemma mod_definition:
        \forall integer x, y;
            combine(x, y) % 4 == mod_four(combine(x, y));
*/

bool func_mod_check(int a, int b, int c)
{
    int b_c;
    int a_b;
    int c_a;
    unsigned int b_c_u;
    unsigned int a_b_u;
    unsigned int c_a_u;
    unsigned int b_c_mod;
    unsigned int a_b_mod;
    unsigned int c_a_mod;
    bool result;

    b_c = b * 10 + c;
    a_b = a * 10 + b;
    c_a = c * 10 + a;

    b_c_u = (unsigned int)b_c;
    a_b_u = (unsigned int)a_b;
    c_a_u = (unsigned int)c_a;

    b_c_mod = b_c_u % 4;
    a_b_mod = a_b_u % 4;
    c_a_mod = c_a_u % 4;

    //@ assert b_c_mod == b_c_u % 4;
    //@ assert a_b_mod == a_b_u % 4;
    //@ assert c_a_mod == c_a_u % 4;

    result = (b_c_mod < 1) || (a_b_mod < 1) || (c_a_mod < 1);
    return result;
}

/* Synthesized function: Data quality assessment for sensor readings
   Scenario: A sensor system collects three readings (a, b, c) within valid ranges.
   The system evaluates data quality based on:
   1. A weighted sum metric (func_weighted_sum)
   2. A climbing pattern analysis over N samples with initial height H (func_climbing)
   3. A modulo-four check on combined readings (func_mod_check)
   The final assertion ensures that if all individual checks pass, the overall quality score
   satisfies a high-level property: the score is non-negative and bounded by the weighted sum.
*/

int32_t assess_data_quality(int32_t a, int32_t b, int32_t c, int N, int H)
{
    int32_t quality_score = 0;
    
    int32_t weighted = func_weighted_sum(a, b, c);
    //@ assert weighted >= 0 && weighted <= weighted_sum(a, b, c);
    
    int climbs = func_climbing(N, H);
    //@ assert climbs >= 0 && climbs <= N;
    
    bool mod_ok = func_mod_check((int)a, (int)b, (int)c);
    
    if (mod_ok) {
        quality_score = weighted;
    } else {
        quality_score = 0;
    }
    
    //@ assert quality_score >= 0;
    //@ assert quality_score <= weighted_sum(a, b, c);
    
    return quality_score;
}
