#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* First function: bounds checking and sum verification */
/*@
    predicate bounds(integer v) = 1 <= v <= 100;

    lemma sum_bound:
        \forall integer x, y, z;
            bounds(x) && bounds(y) && bounds(z) ==> x + y + z <= 300;
*/

bool func1(unsigned long x, unsigned long y, unsigned long z)
{
    //@ assert bounds(x);
    //@ assert bounds(y);
    //@ assert bounds(z);
    //@ assert x + y + z <= 300;
    return x + y + z <= 1000;
}

/* Second function: array processing with accumulation */
/*@ predicate valid_n(integer n) = 2 <= n && n <= 20; */

/*@ predicate valid_aa(integer n, int64_t *aa, integer len) =
    len == n &&
    \forall integer i; 0 <= i < n ==> 1 <= aa[i] && aa[i] <= n; */

/*@ predicate valid_bb(integer n, int64_t *bb, integer len) =
    len == n &&
    \forall integer i; 0 <= i < n ==> 1 <= bb[i] && bb[i] <= 50; */

/*@ predicate valid_cc(integer n, int64_t *cc, integer len) =
    len == n - 1 &&
    \forall integer i; 0 <= i < n - 1 ==> 1 <= cc[i] && cc[i] <= 50; */

/*@ lemma ans_upper_bound:
    \forall integer i, integer n; 0 <= i <= n && valid_n(n) ==> i * 101 >= 0; */

int64_t func2(int64_t n, int64_t *aa, size_t aa_len, 
             int64_t *bb, size_t bb_len, 
             int64_t *cc, size_t cc_len)
{
    int64_t ans = 0;
    int64_t i = 0;
    
    while (i < n)
    {
        //@ assert i < aa_len;
        int64_t a = aa[i];
        //@ assert a - 1 >= 0;
        //@ assert a - 1 < n;
        ans += bb[a - 1];
        
        if (i > 0 && aa[i - 1] == a)
        {
            //@ assert i - 1 >= 0;
            //@ assert i - 1 < n - 1;
            ans += cc[i - 1];
        }
        
        i += 1;
    }
    
    return ans;
}

/* Synthesized function: Score validation system for a competition
 * 
 * Scenario: A competition scoring system where:
 * - Three judges (x, y, z) give scores (1-100 each)
 * - The total score must be <= 1000 (validated by func1)
 * - Additionally, we have contestant data with arrays aa, bb, cc representing
 *   a scoring pattern that must be processed (func2)
 * - The synthesized function validates that the judges' scores are reasonable
 *   and then computes the contestant's total score
 * 
 * Data flow:
 * 1. First validate the three judges' scores using func1
 * 2. Then process the contestant data using func2
 * 3. The final result is the contestant's total score, which should be >= 0
 */

int64_t competition_score_system(
    unsigned long x, unsigned long y, unsigned long z,
    int64_t n, int64_t *aa, size_t aa_len,
    int64_t *bb, size_t bb_len,
    int64_t *cc, size_t cc_len)
{
    bool scores_valid = func1(x, y, z);
    
    int64_t contestant_score = func2(n, aa, aa_len, bb, bb_len, cc, cc_len);
    
    //@ assert scores_valid <==> (x + y + z <= 1000);
    //@ assert contestant_score >= 0;
    //@ assert contestant_score <= n * 101;
    
    /* Core property: The contestant's total score is non-negative and 
     * bounded by the maximum possible score given the number of entries */
    //@ assert contestant_score >= 0 && contestant_score <= n * 101;
    
    return contestant_score;
}
