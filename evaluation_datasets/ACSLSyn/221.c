#include <stdint.h>

/* predicate valid_range for first function */
/*@ predicate valid_range_uint(integer x) = 1 <= x <= 100; */

/* predicate valid_range for second function */
/*@ predicate valid_range_int(integer v) = 3 <= v <= 20; */

/* logic functions for second function */
/*@ logic integer case1(integer a) = a * 2 - 1; */
/*@ logic integer case2(integer b) = b * 2 - 1; */
/*@ logic integer case3(integer a, integer b) = a + b; */
/*@ logic integer case4(integer b) = b * 2; */

/* lemmas for second function */
/*@ lemma case1_bounds: \forall integer a; valid_range_int(a) ==> 0 <= case1(a) <= 39; */
/*@ lemma case2_bounds: \forall integer b; valid_range_int(b) ==> 0 <= case2(b) <= 39; */
/*@ lemma case3_bounds: \forall integer a, b; valid_range_int(a) && valid_range_int(b) ==> 0 <= case3(a,b) <= 40; */
/*@ lemma case4_bounds: \forall integer b; valid_range_int(b) ==> 0 <= case4(b) <= 40; */

/* First function: compute initial score from two valid inputs (1..100) */
int64_t func1(uint64_t a, uint64_t b)
{
    uint64_t a_local;
    uint64_t b_local;
    uint64_t p;
    uint64_t ans;
    uint64_t p_div;

    //@ assert valid_range_uint(a);
    //@ assert valid_range_uint(b);

    a_local = (a > 0) ? (a - 1) : 0;
    b_local = (b > 0) ? (b - 1) : 0;

    p = a_local + b_local;

    if (p > 0)
    {
        if (p < 3)
        {
            ans = 0;
        }
        else if (p == 3)
        {
            ans = 1;
        }
        else if (p == 4)
        {
            ans = 2;
        }
        else if (p == 5)
        {
            ans = 1;
        }
        else
        {
            p_div = p / 2;
            //@ assert p_div >= 0 || p_div == -1;
            if (p_div % 2 == 0)
            {
                ans = p_div;
            }
            else
            {
                ans = p_div + 1;
            }
        }
    }
    else
    {
        ans = 0;
    }

    //@ assert ans >= 0 || ans == -1;
    return (int64_t)ans;
}

/* Second function: refine score based on two valid inputs (3..20) */
int64_t func2(int64_t a, int64_t b)
{
    int64_t ans = 0;
    
    //@ assert valid_range_int(a);
    //@ assert valid_range_int(b);
    
    if (a > b + 1)
    {
        //@ assert 0 <= case1(a) <= 39;
        ans = a * 2 - 1;
    }
    else if (b > a + 1)
    {
        //@ assert 0 <= case2(b) <= 39;
        ans = b * 2 - 1;
    }
    else
    {
        //@ assert 0 <= case3(a,b) <= 40;
        ans = a + b;
    }
    
    if (b == a + 1)
    {
        //@ assert 0 <= case4(b) <= 40;
        ans = b * 2;
    }
    
    //@ assert ans >= 0;
    return ans;
}

/* Synthesized function: Game scoring system - compute final score from player attributes
   Scenario: A game calculates an initial score from two primary attributes (1..100),
   then refines it using two secondary attributes (3..20) to get the final score.
   The final score must be non-negative, representing a valid game score.
*/
int64_t compute_game_score(uint64_t attr1, uint64_t attr2, int64_t attr3, int64_t attr4)
{
    int64_t initial_score;
    int64_t refinement;
    int64_t final_score;

    initial_score = func1(attr1, attr2);
    
    refinement = func2(attr3, attr4);
    
    if (initial_score < 0)
    {
        final_score = refinement;
    }
    else
    {
        final_score = initial_score + refinement;
    }
    
    //@ assert final_score >= 0;
    
    return final_score;
}
