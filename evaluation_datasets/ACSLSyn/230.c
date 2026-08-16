#include <stdint.h>

/* ================================================================
   Original function 1: computes n + m (with a specific loop-based algorithm)
   ================================================================ */

/*@
    predicate bounds(integer n, integer m) =
        1 <= n && n <= 20 &&
        1 <= m && m <= 20;

    logic integer partial_sum(integer base, integer total, integer remaining) =
        base + (total - remaining);
*/

int func1(int n, int m)
{
    int result = 0;

    //@ assert bounds(n, m);
    
    if (n > m)
    {
        result += n;
        int temp_m = m;
        
        while (temp_m > 0)
        {
            //@ assert temp_m > 0;
            result += 1;
            temp_m -= 1;
        }
    }
    else
    {
        result += m;
        int temp_n = n;
        
        while (temp_n > 0)
        {
            //@ assert temp_n > 0;
            result += 1;
            temp_n -= 1;
        }
    }
    
    //@ assert result == n + m;
    return result;
}

/* ================================================================
   Original function 2: computes max + zero_count, clamped to [1,4]
   ================================================================ */

/*@
    predicate valid_input(integer a, integer b, integer c, integer d) =
        a <= 100 && b <= 100 && c <= 100 && d <= 100 &&
        1 <= a + b + c + d <= 400;
*/

/*@
    logic integer max_of_four(integer a, integer b, integer c, integer d) =
        (a >= b && a >= c && a >= d) ? a :
        (b >= c && b >= d) ? b :
        (c >= d) ? c : d;
*/

/*@
    lemma ans_range:
        \forall integer a, b, c, d;
        valid_input(a, b, c, d) ==>
        \let max_val = max_of_four(a, b, c, d);
        \let zero_count = (a == 0 ? 1 : 0) + (b == 0 ? 1 : 0) + 
                         (c == 0 ? 1 : 0) + (d == 0 ? 1 : 0);
        \let raw_ans = max_val + zero_count;
        \let final_ans = (raw_ans < 4) ? raw_ans : 4;
        1 <= final_ans <= 4;
*/

uint64_t func2(uint64_t x[4])
{
    uint64_t ans;
    uint64_t tmp;
    
    ans = 0;
    tmp = 0;
    
    //@ assert tmp == 0;
    
    if (x[0] > tmp) {
        tmp = x[0];
    }
    //@ assert tmp == max_of_four(x[0], 0, 0, 0);
    
    if (x[1] > tmp) {
        tmp = x[1];
    }
    //@ assert tmp == max_of_four(x[0], x[1], 0, 0);
    
    if (x[2] > tmp) {
        tmp = x[2];
    }
    //@ assert tmp == max_of_four(x[0], x[1], x[2], 0);
    
    if (x[3] > tmp) {
        tmp = x[3];
    }
    //@ assert tmp == max_of_four(x[0], x[1], x[2], x[3]);
    
    ans = tmp;
    
    if (x[0] == 0) {
        ans += 1;
    }
    //@ assert ans == max_of_four(x[0], x[1], x[2], x[3]) + (x[0] == 0 ? 1 : 0);
    
    if (x[1] == 0) {
        ans += 1;
    }
    //@ assert ans == max_of_four(x[0], x[1], x[2], x[3]) + (x[0] == 0 ? 1 : 0) + (x[1] == 0 ? 1 : 0);
    
    if (x[2] == 0) {
        ans += 1;
    }
    //@ assert ans == max_of_four(x[0], x[1], x[2], x[3]) + (x[0] == 0 ? 1 : 0) + (x[1] == 0 ? 1 : 0) + (x[2] == 0 ? 1 : 0);
    
    if (x[3] == 0) {
        ans += 1;
    }
    //@ assert ans == max_of_four(x[0], x[1], x[2], x[3]) + (x[0] == 0 ? 1 : 0) + (x[1] == 0 ? 1 : 0) + (x[2] == 0 ? 1 : 0) + (x[3] == 0 ? 1 : 0);
    
    if (ans < 4) {
        //@ assert ans >= 1;
    } else {
        ans = 4;
    }
    
    //@ assert ans >= 1;
    //@ assert ans <= 4;
    
    return ans;
}

/* ================================================================
   Synthesized function: compute a "score" for a small team based on
   four performance metrics, then scale it by the sum of two "effort"
   values.  Real-world scenario: scoring a project team (4 members)
   where each member has a performance value (0-100) and two effort
   indicators (1-20 each).  The final score is team_score * effort_sum,
   clamped to a reasonable range.
   ================================================================ */

/*@
    predicate valid_team(
        integer p0, integer p1, integer p2, integer p3,
        integer e1, integer e2
    ) =
        0 <= p0 <= 100 && 0 <= p1 <= 100 && 0 <= p2 <= 100 && 0 <= p3 <= 100 &&
        1 <= p0 + p1 + p2 + p3 <= 400 &&
        1 <= e1 <= 20 && 1 <= e2 <= 20;
*/

/*@
    logic integer team_score(integer p0, integer p1, integer p2, integer p3) =
        (max_of_four(p0, p1, p2, p3) +
         (p0 == 0 ? 1 : 0) + (p1 == 0 ? 1 : 0) +
         (p2 == 0 ? 1 : 0) + (p3 == 0 ? 1 : 0)) < 4 ?
        (max_of_four(p0, p1, p2, p3) +
         (p0 == 0 ? 1 : 0) + (p1 == 0 ? 1 : 0) +
         (p2 == 0 ? 1 : 0) + (p3 == 0 ? 1 : 0)) : 4;

    logic integer effort_sum(integer e1, integer e2) =
        e1 + e2;
*/

uint64_t team_evaluation(uint64_t perf[4], int eff1, int eff2)
{
    uint64_t score = func2(perf);
    //@ assert score >= 1 && score <= 4;

    int effort = func1(eff1, eff2);
    //@ assert effort >= 2 && effort <= 40;

    uint64_t result = score * (uint64_t)effort;

    //@ assert score >= 1 && score <= 4;
    //@ assert effort >= 2 && effort <= 40;
    //@ assert result >= 2 && result <= 4 * (eff1 + eff2);

    return result;
}
