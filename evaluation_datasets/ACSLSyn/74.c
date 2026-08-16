#include <stdint.h>
#include <stdbool.h>

/* ====== Function 1: Check equality count ====== */
/*@
    predicate all_equal(integer a, integer b, integer c) =
        a == b && b == c;

    predicate any_two_equal(integer a, integer b, integer c) =
        a == b || a == c || b == c;
*/

int32_t check_equality(uint32_t A, uint32_t B, uint32_t C)
{
    int32_t result = 0;
    
    //@ assert 1 <= A <= 100 && 1 <= B <= 100 && 1 <= C <= 100;
    
    if (A == B && B == C) {
        result += 3;
        //@ assert all_equal(A,B,C);
    } else if (A == B || A == C || B == C) {
        result += 2;
        //@ assert any_two_equal(A,B,C) && !all_equal(A,B,C);
    } else {
        //@ assert !any_two_equal(A,B,C);
    }
    
    //@ assert result >= 0 && result <= 3;
    return result;
}

/* ====== Function 2: Increment with bound check ====== */
/*@
predicate is_nonnegative(integer i) = 0 <= i;
predicate is_less_than_twenty(integer i) = i < 20;
predicate is_increment_le_twenty(integer i) = i + 1 <= 20;

lemma proof_lemma:
    \forall integer i; is_nonnegative(i) && is_less_than_twenty(i) ==> is_increment_le_twenty(i);
*/

int increment(int i)
{
    //@ assert is_nonnegative(i);
    //@ assert is_less_than_twenty(i);
    //@ assert is_increment_le_twenty(i);
    return i + 1;
}

/* ====== Function 3: Compute remaining hours ====== */
/*@
    predicate valid_hours(integer hs) = 1 <= hs <= 24;
    
    logic integer compute_result(integer hs) = 24 - hs;
*/

int32_t remaining_hours(uint32_t hs)
{
    int32_t x;
    
    //@ assert valid_hours(hs);
    x = (int32_t)(24 - hs);
    
    //@ assert x == compute_result(hs);
    return x;
}

/* ====== Function 4: Check range divisibility ====== */
/*@
    predicate valid_range(integer a, integer b, integer k) =
        1 <= a && a <= b && b <= 1000 &&
        1 <= k && k <= 1000;

    logic integer safe_div(integer b, integer k) = b / k;
    logic integer safe_mul(integer d, integer k) = d * k;

    lemma division_bound: \forall integer b, k;
        valid_range(1, b, k) ==> safe_div(b, k) <= 1000;
    lemma multiplication_bound: \forall integer b, k;
        valid_range(1, b, k) ==> safe_mul(safe_div(b, k), k) <= 1000000;
*/

void check_divisibility(unsigned k, unsigned a, unsigned b, bool *ans)
{
    unsigned div_result;
    unsigned mul_result;
    bool local_ans;

    //@ assert 1 <= k && k <= 1000;
    //@ assert 1 <= a && a <= b && b <= 1000;
    
    //@ assert b / k <= 1000;
    div_result = b / k;
    
    //@ assert div_result * k <= 1000000;
    mul_result = div_result * k;
    
    local_ans = (a <= mul_result);
    *ans = local_ans;
}

/* ====== Synthesized function: Game puzzle solver ====== */

/*@
    predicate valid_game_input(integer hour, integer a, integer b, integer c, integer k, integer a_range, integer b_range) =
        1 <= hour <= 24 && 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 &&
        1 <= a_range && a_range <= b_range && b_range <= 1000 && 1 <= k && k <= 1000;
*/

int32_t solve_game_puzzle(uint32_t hour, uint32_t a, uint32_t b, uint32_t c, 
                          unsigned k, unsigned a_range, unsigned b_range, bool *ans)
{
    int32_t equality_count = check_equality(a, b, c);
    //@ assert equality_count >= 0 && equality_count <= 3;
    
    int counter = 0;
    while (counter < equality_count)
    {
        //@ assert counter < equality_count;
        //@ assert 0 <= counter < 3;  // since equality_count <= 3
        counter = increment(counter);
    }
    //@ assert counter == equality_count;
    
    int32_t remaining = remaining_hours(hour);
    //@ assert 0 <= remaining <= 23;
    
    check_divisibility(k, a_range, b_range, ans);
    
    //@ assert remaining >= 0 && remaining <= 23;
    //@ assert *ans == (a_range <= (b_range / k) * k);
    //@ assert equality_count == counter;
    
    return remaining;
}
