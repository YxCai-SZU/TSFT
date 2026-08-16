#include <stdint.h>
#include <stdbool.h>

/* ======== Original function 1: compute_ans ======== */
/*@
    predicate min_val_bounds(integer n, integer m, integer min_val) =
        1 <= n <= 1000000000000000000 &&
        1 <= m <= 1000000000000000000 &&
        min_val == (n < m ? n : m) &&
        1 <= min_val <= 1000000000000000000 &&
        min_val <= n && min_val <= m;

    logic integer compute_ans(integer n, integer m, integer min_val) =
        2 * min_val >= m ?
        n + (m / 2) - min_val :
        min_val + (m - 2 * min_val) / 4;

    lemma ans_bounds:
        \forall integer n, m, min_val, ans;
        min_val_bounds(n, m, min_val) && ans == compute_ans(n, m, min_val) ==>
        ans >= 0 && ans <= n + m;
*/

uint64_t func1(uint64_t n, uint64_t m)
{
    uint64_t min_val;
    uint64_t ans;

    //@ assert 1 <= n <= 1000000000000000000;
    //@ assert 1 <= m <= 1000000000000000000;

    min_val = n < m ? n : m;

    //@ assert min_val_bounds(n, m, min_val);

    if (2 * min_val >= m)
    {
        ans = n + (m / 2) - min_val;
        //@ assert ans == n + (m / 2) - min_val;
    }
    else
    {
        ans = min_val + (m - 2 * min_val) / 4;
        //@ assert ans == min_val + (m - 2 * min_val) / 4;
    }

    //@ assert ans == compute_ans(n, m, min_val);
    //@ assert ans >= 0;
    //@ assert ans <= n + m;

    return ans;
}

/* ======== Original function 2: check_sum ======== */
/*@
    predicate valid_range(integer x) = 0 < x <= 5000;
    
    logic integer sum(integer a, integer b) = a + b;
    
    lemma sum_bounds:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> 0 < sum(a, b) <= 10000;
*/

bool func2(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int i;
    
    if (a + b >= c) {
        //@ assert a + b >= c;
        return true;
    } else {
        i = 0;
        while (i < 10000) {
            //@ assert 0 <= i * i <= 10000 * 10000;
            i++;
        }
        //@ assert a + b < c;
        return false;
    }
}

/* ======== Original function 3: compute_result ======== */
/*@
    predicate in_range(integer x) = 1 <= x && x <= 9;

    logic integer compute_l(integer a, integer b, integer c) = 10 * b + a + c;

    lemma result_bounds:
        \forall integer a, b, c, result;
        in_range(a) && in_range(b) && in_range(c) &&
        result == compute_l(a, b, c) || result == compute_l(a, b, c) + 1 ==>
        result >= compute_l(a, b, c) && result <= compute_l(a, b, c) + 1;
*/

unsigned int func3(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int max;
    unsigned int l;
    unsigned int result;

    //@ assert in_range(a) && in_range(b) && in_range(c);

    if (a >= b && a >= c)
    {
        max = a;
    }
    else if (b >= a && b >= c)
    {
        max = b;
    }
    else
    {
        max = c;
    }

    l = 10 * b + a + c;
    result = l;

    if (l % 4 < 3)
    {
        result += 1;
    }

    //@ assert result >= compute_l(a, b, c);
    //@ assert result <= compute_l(a, b, c) + 1;

    return result;
}

/* ======== Original function 4: check_equal ======== */
/*@
    predicate are_equal(integer n, integer m) = n == m;
*/

bool func4(unsigned int n, unsigned int m)
{
    unsigned int max_val;
    unsigned int min_val;
    bool are_equal;
    int diff;

    if (n > m) {
        max_val = n;
    } else {
        max_val = m;
    }

    if (n < m) {
        min_val = n;
    } else {
        min_val = m;
    }

    diff = (int)n - (int)m;
    are_equal = (diff == 0);

    //@ assert are_equal ==> (n == m);
    //@ assert !are_equal ==> (n != m);

    return are_equal;
}

/* ======== Synthesized function: process_payment_data ======== */
/* Real-world scenario: Payment processing system that validates transaction limits,
   checks merchant availability, computes a transaction code, and verifies data integrity.
   Data flow:
   1. func1 computes the maximum allowed transaction amount based on balance (n) and limit (m)
   2. func2 checks if merchant availability score (a+b) meets threshold (c)
   3. func3 generates a transaction verification code from three digits
   4. func4 verifies that the transaction ID (n) matches the processed amount (m) for audit
*/

/*@
    predicate payment_valid(integer balance, integer limit, integer score_a, integer score_b, 
                           integer threshold, integer digit_a, integer digit_b, integer digit_c,
                           integer trans_id, integer proc_amount) =
        balance >= 1 && balance <= 1000000000000000000 &&
        limit >= 1 && limit <= 1000000000000000000 &&
        score_a >= 1 && score_a <= 5000 &&
        score_b >= 1 && score_b <= 5000 &&
        threshold >= 1 && threshold <= 5000 &&
        digit_a >= 1 && digit_a <= 9 &&
        digit_b >= 1 && digit_b <= 9 &&
        digit_c >= 1 && digit_c <= 9 &&
        trans_id >= 1 && trans_id <= 100 &&
        proc_amount >= 0 && proc_amount <= trans_id;
*/

uint64_t process_payment_data(
    uint64_t balance, uint64_t limit,
    unsigned int score_a, unsigned int score_b, unsigned int threshold,
    unsigned int digit_a, unsigned int digit_b, unsigned int digit_c,
    unsigned int trans_id, unsigned int proc_amount)
{
    uint64_t max_amount;
    bool merchant_available;
    unsigned int verification_code;
    bool data_integrity;
    uint64_t final_result;

    max_amount = func1(balance, limit);
    //@ assert max_amount >= 0 && max_amount <= balance + limit;

    merchant_available = func2(score_a, score_b, threshold);
    //@ assert merchant_available == (score_a + score_b >= threshold);

    verification_code = func3(digit_a, digit_b, digit_c);
    //@ assert verification_code >= compute_l(digit_a, digit_b, digit_c);
    //@ assert verification_code <= compute_l(digit_a, digit_b, digit_c) + 1;

    data_integrity = func4(trans_id, proc_amount);
    //@ assert data_integrity == (trans_id == proc_amount);

    if (merchant_available && data_integrity) {
        final_result = max_amount;
    } else {
        final_result = 0;
    }

    //@ assert final_result >= 0;
    //@ assert final_result <= balance + limit;

    return final_result;
}
