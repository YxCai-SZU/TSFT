#include <stdbool.h>
#include <limits.h>

/* ====== Original functions (adapted for the scenario) ====== */

/* Function 1: compute base score from n, m */
/*@
    predicate valid_params(integer n, integer m) =
        1 <= n && n <= 100 &&
        1 <= m && m <= n &&
        m <= 5;

    logic integer base_value(integer n, integer m) =
        100 * (n - m) + 1900 * m;

    logic integer max_value(integer n, integer m, integer shift) =
        base_value(n, m) + 100 * shift;

    lemma shift_bounds:
        \forall integer n, m, shift;
        valid_params(n, m) && 0 <= shift && shift <= m ==>
        base_value(n, m) <= max_value(n, m, shift);
*/

long compute_base_score(long n, long m)
{
    long ans;
    long shift;
    long temp;

    //@ assert valid_params(n, m);
    ans = 100 * (n - m) + 1900 * m;
    shift = 0;
    temp = n - m;

    while (temp >= 1 && shift < m)
    {
        //@ assert temp >= 1 && shift < m;
        temp = temp - 1;
        shift = shift + 1;
        ans = ans + 100;
        //@ assert ans <= max_value(n, m, shift);
    }

    //@ assert ans >= base_value(n, m);
    //@ assert ans <= max_value(n, m, m);
    return ans;
}

/* Function 2: check if range E-A fits within K */
/*@
    predicate is_valid_range(integer A, integer B, integer C, integer D, integer E, integer K) =
        0 <= A && A < B && B <= 123 &&
        0 <= B && B < C && C <= 123 &&
        0 <= C && C < D && D <= 123 &&
        0 <= D && D < E && E <= 123 &&
        K <= 123;

    logic integer difference(integer E, integer A) = E - A;

    lemma difference_nonnegative: \forall integer A, E; A <= E ==> difference(E, A) >= 0;
    lemma difference_bounded: \forall integer A, E; 0 <= A && E <= 123 ==> difference(E, A) <= 123;
*/

bool check_range_fits(unsigned long long A, unsigned long long B, unsigned long long C,
                      unsigned long long D, unsigned long long E, unsigned long long K)
{
    //@ assert E >= A;
    //@ assert E - A <= 123;
    return E - A <= K;
}

/* Function 3: check if (x, y) satisfies condition */
/*@
    predicate is_even(integer n) = n % 2 == 0;
    predicate in_range(integer x, integer y) = 
        y >= x * 2 && y <= x * 4;
    predicate condition_holds(integer x, integer y) = 
        is_even(y) && in_range(x, y) && is_even(y);
*/

int check_condition(int x, int y) {
    int result;
    //@ assert 1 <= x <= 100;
    //@ assert 1 <= y <= 100;
    
    if ((y % 2 == 0) && (y >= x * 2) && (y <= x * 4) && (y % 2 == 0)) {
        //@ assert condition_holds(x, y);
        result = 1;
    } else {
        //@ assert !condition_holds(x, y);
        result = 0;
    }
    
    return result;
}

/* Function 4: check strict ordering a < b < c */
/*@ predicate is_less_than(integer a, integer b, integer c) = 
      a < b && b < c; */

/*@ lemma bounds_lemma: 
      \forall integer a, b, c; 
      a > INT_MIN && b > INT_MIN && c > INT_MIN &&
      a < INT_MAX && b < INT_MAX && c < INT_MAX ==> 
      (a < b && b < c) == (a < b && b < c); */

bool check_ordering(int a, int b, int c)
{
    bool result;
    
    //@ assert a > INT_MIN;
    //@ assert b > INT_MIN;
    //@ assert c > INT_MIN;
    //@ assert a < INT_MAX;
    //@ assert b < INT_MAX;
    //@ assert c < INT_MAX;
    
    result = a < b && b < c;
    
    //@ assert result == (a < b && b < c);
    return result;
}

/* ====== Synthesized high-level function ====== */

/* Scenario: Student contest scoring system.
   Given:
   - n: total number of problems, m: number of hard problems (for base score)
   - x, y: problem difficulty parameters (x: easy count, y: hard count)
   - a, b, c: three judge scores (must be strictly increasing)
   - A, B, C, D, E, K: submission timestamp ranges (must be within K)
   
   The function verifies that:
   1. Score is computed correctly.
   2. Problem parameters satisfy condition_holds(x, y).
   3. Judge scores are strictly increasing.
   4. Submission timestamps fit within the allowed range K.
   
   Final invariant: all four checks pass (return 1) or at least one fails (return 0).
*/

int process_contest(long n, long m, int x, int y, int a, int b, int c,
                    unsigned long long A, unsigned long long B, unsigned long long C,
                    unsigned long long D, unsigned long long E, unsigned long long K)
{
    long score;
    bool range_ok;
    int cond_ok;
    bool order_ok;
    int result;
    
    score = compute_base_score(n, m);
    //@ assert score >= base_value(n, m);
    //@ assert score <= max_value(n, m, m);
    
    range_ok = check_range_fits(A, B, C, D, E, K);
    //@ assert range_ok == (E - A <= K);
    
    cond_ok = check_condition(x, y);
    //@ assert cond_ok == 1 <==> condition_holds(x, y);
    
    order_ok = check_ordering(a, b, c);
    //@ assert order_ok == (a < b && b < c);
    
    if (score >= 0 && range_ok && cond_ok == 1 && order_ok) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert (result == 1) <==> (score >= base_value(n, m) && E - A <= K && condition_holds(x, y) && a < b && b < c);
    
    return result;
}
