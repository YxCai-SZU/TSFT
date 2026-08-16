#include <stdint.h>
#include <stdbool.h>

/* First function: compute score based on parameters */
/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= n && m <= 5;

    logic integer expected_result(integer n, integer m) =
        100 * (n - m) + 1900 * m;

    lemma result_non_negative:
        \forall integer n, m; valid_params(n, m) ==> expected_result(n, m) >= 0;

    lemma result_upper_bound:
        \forall integer n, m; valid_params(n, m) ==> 
            expected_result(n, m) <= 100 * n + 1900 * m;

    lemma result_lower_bound:
        \forall integer n, m; valid_params(n, m) ==> 
            expected_result(n, m) >= 100 * n + 1900 * m - 100 * m;
*/

int32_t func1(uint32_t n, uint32_t m) {
    int32_t result;
    //@ assert valid_params(n, m);
    
    result = 100 * ((int32_t)n - (int32_t)m) + 1900 * (int32_t)m;
    
    //@ assert result == expected_result(n, m);
    //@ assert result >= 0;
    //@ assert result <= 100 * (int32_t)n + 1900 * (int32_t)m;
    //@ assert result >= 100 * (int32_t)n + 1900 * (int32_t)m - 100 * (int32_t)m;
    
    return result;
}

/* Second function: check conditions */
/*@
    predicate is_first_condition_met(integer x, integer a, integer b) =
        x <= a + b;
    
    predicate is_second_condition_met(integer x, integer a) =
        a <= x;
    
    lemma bounds_lemma:
        \forall integer a, b, x;
        0 <= a <= 100 && 0 <= b <= 100 && 0 <= x <= 100 ==>
        0 <= a + b <= 200 && a <= 100 && x <= 100;
*/

bool func2(unsigned long a, unsigned long b, unsigned long x)
{
    bool is_first_condition_met;
    bool is_second_condition_met;
    bool result;
    
    //@ assert 0 <= a + b <= 200;
    //@ assert a <= 100;
    //@ assert x <= 100;
    
    is_first_condition_met = x <= a + b;
    is_second_condition_met = a <= x;
    
    result = is_first_condition_met && is_second_condition_met;
    
    return result;
}

/* Third function: determine equality category */
/*@
    predicate valid_range(integer x) = 1 <= x <= 10;

    // Logical function to compute equality count
    logic integer equality_count(integer a, integer b, integer c) =
        (a == b ? 1 : 0) + (b == c ? 1 : 0) + (a == c ? 1 : 0);

    // Lemma for result interpretation
    lemma result_meaning:
        \forall integer a, b, c, cnt;
        valid_range(a) && valid_range(b) && valid_range(c) &&
        cnt == equality_count(a, b, c) ==>
        (cnt == 0 ==> a != b && b != c && a != c) &&
        (cnt == 1 ==> (a == b && a != c) || (a == c && a != b) || (b == c && a != b)) &&
        (cnt >= 2 ==> a == b && b == c);
*/

int32_t func3(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t num = 0;
    int32_t ans;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c);

    if (a == b)
    {
        num += 1;
    }
    //@ assert num == (a == b ? 1 : 0);

    if (b == c)
    {
        num += 1;
    }
    //@ assert num == (a == b ? 1 : 0) + (b == c ? 1 : 0);

    if (a == c)
    {
        num += 1;
    }
    //@ assert num == equality_count(a, b, c);

    if (num == 0)
    {
        ans = 3;
    }
    else if (num == 1)
    {
        ans = 2;
    }
    else
    {
        ans = 1;
    }

    //@ assert ans >= 1 && ans <= 3;

    if (ans == 1)
    {
        //@ assert a == b && b == c;
    }
    else if (ans == 2)
    {
        //@ assert (a == b && a != c) || (a == c && a != b) || (b == c && a != b);
    }
    else
    {
        //@ assert a != b && b != c && a != c;
    }

    return ans;
}

/* Synthesized function: Game score processor that validates inputs and computes final score */
int32_t process_game_score(uint32_t n, uint32_t m, uint32_t a, uint32_t b, uint32_t c,
                           unsigned long x, unsigned long y, unsigned long z)
{
    int32_t base_score;
    bool validation_passed;
    int32_t equality_category;
    int32_t final_score;
    
    base_score = func1(n, m);
    //@ assert base_score == expected_result(n, m);
    
    validation_passed = func2(x, y, z);
    //@ assert validation_passed == (z <= x + y && x <= z);
    
    equality_category = func3(a, b, c);
    //@ assert equality_category >= 1 && equality_category <= 3;
    
    if (validation_passed) {
        final_score = base_score * equality_category;
    } else {
        final_score = 0;
    }
    
    //@ assert final_score >= 0;
    //@ assert final_score == expected_result(n, m) * equality_category || final_score == 0;
    
    return final_score;
}
