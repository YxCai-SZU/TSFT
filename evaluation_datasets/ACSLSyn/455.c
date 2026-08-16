#include <stdbool.h>

/* ============================================================
   Scenario:  4x4 Sudoku Grid Validation & Score Calculation
   Data Flow: 
     1. Given four 4x4 Sudoku grid parameters (a,b,c,d) representing
        row sums, compute a "balance score" using func1.
     2. Given three digits (a,b,c) from a row, validate the digit
        parity and column constraints using func2.
     3. Given three digits (a,b,c) compute the "max digit sum" using func3.
     4. Given an array of daily scores (days) of length n, count how
        many exceed a threshold (2*m-1) using func4.
   The synthesized function "process_sudoku_grid" combines these to
   verify that the final computed score is consistent with the input
   constraints.
   ============================================================ */

/* ---------- Original func1 (unchanged) ---------- */
/*@
    predicate valid_input(integer a, integer b, integer c, integer d) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= c && c <= 100 &&
        1 <= d && d <= 100;

    logic integer total_sum(integer a, integer b, integer c, integer d) =
        a + b + c + d;

    lemma ans_bound_lemma:
        \forall integer a, b, c, d, min_val, s, ans;
        valid_input(a, b, c, d) &&
        min_val == \min(\min(\min(a, b), c), d) &&
        s == total_sum(a, b, c, d) - min_val * 4 &&
        ans == min_val + s / 2
        ==>
        ans >= 0 && ans <= total_sum(a, b, c, d);
*/

unsigned int func1(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int min_val;
    unsigned int ans;
    unsigned int s;

    min_val = a;
    ans = 0;

    //@ assert min_val == a;
    if (b < min_val)
    {
        min_val = b;
    }
    //@ assert min_val == \min(a, b);
    if (c < min_val)
    {
        min_val = c;
    }
    //@ assert min_val == \min(\min(a, b), c);
    if (d < min_val)
    {
        min_val = d;
    }
    //@ assert min_val == \min(\min(\min(a, b), c), d);

    ans += min_val;

    s = a + b + c + d - min_val * 4;
    //@ assert s == total_sum(a, b, c, d) - min_val * 4;

    ans += s / 2;
    //@ assert ans == min_val + s / 2;

    //@ assert ans >= 0;
    //@ assert ans <= a + b + c + d;

    return ans;
}

/* ---------- Original func2 (unchanged) ---------- */
/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer to_unsigned(integer x) = x < 0 ? x + 10 : x;

    logic integer bc_value(integer b, integer c) = 
        to_unsigned(b) * 10 + to_unsigned(c);

    logic integer bc_mod_4(integer b, integer c) = 
        bc_value(b, c) % 4;

    logic integer a_mod_2(integer a) = 
        to_unsigned(a) % 2;

    lemma unsigned_conversion: 
        \forall integer a, b, c; 
        valid_range(a) && valid_range(b) && valid_range(c) ==> 
        to_unsigned(a) == (unsigned)a && 
        to_unsigned(b) == (unsigned)b && 
        to_unsigned(c) == (unsigned)c;
*/

bool func2(int a, int b, int c) {
    unsigned int b_unsigned;
    unsigned int c_unsigned;
    unsigned int a_unsigned;
    unsigned int bc;
    unsigned int bc_mod_4;
    unsigned int a_mod_2;
    bool result;

    b_unsigned = (unsigned int)(b < 0 ? b + 10 : b);
    c_unsigned = (unsigned int)(c < 0 ? c + 10 : c);
    a_unsigned = (unsigned int)(a < 0 ? a + 10 : a);

    bc = b_unsigned * 10 + c_unsigned;
    bc_mod_4 = bc % 4;
    
    //@ assert bc_mod_4 == (b_unsigned * 10 + c_unsigned) % 4;

    a_mod_2 = a_unsigned % 2;
    
    //@ assert a_mod_2 == a_unsigned % 2;

    if (bc_mod_4 < 1 || a_mod_2 == 0) {
        result = true;
    } else {
        result = false;
    }

    return result;
}

/* ---------- Original func3 (unchanged) ---------- */
/*@
    predicate is_in_range(integer x) = 1 <= x && x <= 9;

    logic integer max_of_two(integer x, integer y) = (x > y) ? x : y;

    lemma max_in_range:
        \forall integer x, y;
            is_in_range(x) && is_in_range(y) ==> is_in_range(max_of_two(x, y));
*/

int func3(int a, int b, int c)
{
    int max_ab;
    int max_bc;
    int max_ac;
    int max;
    int max_final;
    int result;

    //@ assert is_in_range(a) && is_in_range(b) && is_in_range(c);

    max_ab = (a > b) ? a : b;
    //@ assert is_in_range(max_ab);

    max_bc = (b > c) ? b : c;
    //@ assert is_in_range(max_bc);

    max_ac = (a > c) ? a : c;
    //@ assert is_in_range(max_ac);

    max = (max_ab > max_bc) ? max_ab : max_bc;
    //@ assert is_in_range(max);

    max_final = (max > max_ac) ? max : max_ac;
    //@ assert is_in_range(max_final);

    result = max_final * 10 + max_final;

    if (max_ab == max && max_ac == max)
    {
        result += max_bc;
    }
    else if (max_ab == max && max_bc == max)
    {
        result += max_ac;
    }
    else
    {
        result += max_ab;
    }

    //@ assert result >= 10 && result <= 999;
    return result;
}

/* ---------- Original func4 (unchanged) ---------- */

int func4(int n, int m, int *days)
{
    int count = 0;
    int index = 0;
    while (index < n)
    {
        int day = days[index];
        if (day >= 2 * m - 1)
        {
            count += 1;
        }
        index += 1;
    }
    return count;
}

/* ============================================================
   Synthesized function: process_sudoku_grid
   Combines func1, func2, func3, func4 into a realistic scenario:
   - Input: 4 row-sum parameters (a,b,c,d), 3 digit parameters (x,y,z)
            for validation, array of daily scores (days) of length n,
            threshold parameter m.
   - Process:
       1. Compute balance score from row sums (func1)
       2. Validate digit constraints (func2)
       3. Compute max digit sum (func3)
       4. Count scores above threshold (func4)
   - High-level property (assert Q):
        The final result (total) is non-negative and does not exceed
        the sum of all input parameters plus the count of high scores.
   ============================================================ */

int process_sudoku_grid(unsigned int a, unsigned int b, unsigned int c, unsigned int d,
                        int x, int y, int z,
                        int n, int m, int *days)
{
    unsigned int balance_score;
    bool validation_flag;
    int max_digit_sum;
    int high_score_count;
    int total;

    balance_score = func1(a, b, c, d);
    //@ assert balance_score >= 0 && balance_score <= a + b + c + d;

    validation_flag = func2(x, y, z);
    //@ assert validation_flag == (bc_mod_4(y, z) < 1 || a_mod_2(x) == 0);

    if (validation_flag) {
        max_digit_sum = func3(x, y, z);
        //@ assert max_digit_sum >= 10 && max_digit_sum <= 999;
    } else {
        max_digit_sum = 0;
    }

    high_score_count = func4(n, m, days);
    //@ assert 0 <= high_score_count && high_score_count <= n;

    total = (int)balance_score + max_digit_sum + high_score_count;

    //@ assert total >= 0 && total <= (a + b + c + d) + 999 + n;

    return total;
}
