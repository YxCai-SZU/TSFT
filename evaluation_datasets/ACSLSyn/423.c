#include <stdbool.h>
#include <stdint.h>

/* ==================== Original Functions (Unchanged) ==================== */

/* --- Function 1: Compute index mapping --- */
/*@
    predicate valid_params(integer N, integer i) =
        1 <= N <= 100 && 1 <= i <= N;

    logic integer compute_j(integer N, integer i) =
        N - (i - 1);

    lemma j_bounds: \forall integer N, i; valid_params(N, i) ==> 1 <= compute_j(N, i) <= N;
*/

int func1(int N, int i)
{
    //@ assert valid_params(N, i);
    int j = N - (i - 1);
    //@ assert j == compute_j(N, i);
    //@ assert 1 <= j <= N;
    return j;
}

/* --- Function 2: Count how many of {2*min, 2*min+1, 2*min+2} are <= sum --- */
/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    lemma result_bound:
        \forall integer a, b, c, min, result;
        valid_range(a) && valid_range(b) && valid_range(c) &&
        min == (a < b ? (a < c ? a : c) : (b < c ? b : c)) &&
        result == (2*min <= a+b+c ? 1 : 0) + (2*min+1 <= a+b+c ? 1 : 0) + (2*min+2 <= a+b+c ? 1 : 0)
        ==> 0 <= result <= 100;
*/

unsigned int func2(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int min;
    unsigned int result;
    unsigned int temp;

    min = a;
    //@ assert min == a;
    if (b < min) {
        min = b;
    }
    //@ assert min == (a < b ? a : b);
    if (c < min) {
        min = c;
    }
    //@ assert min == (a < b ? (a < c ? a : c) : (b < c ? b : c));

    result = 0;
    temp = 2 * min;
    //@ assert temp == 2 * min;
    if (temp <= a + b + c) {
        result += 1;
    }
    //@ assert result == (2*min <= a+b+c ? 1 : 0);

    temp = 2 * min + 1;
    //@ assert temp == 2 * min + 1;
    if (temp <= a + b + c) {
        result += 1;
    }
    //@ assert result == (2*min <= a+b+c ? 1 : 0) + (2*min+1 <= a+b+c ? 1 : 0);

    temp = 2 * min + 2;
    //@ assert temp == 2 * min + 2;
    if (temp <= a + b + c) {
        result += 1;
    }
    //@ assert result == (2*min <= a+b+c ? 1 : 0) + (2*min+1 <= a+b+c ? 1 : 0) + (2*min+2 <= a+b+c ? 1 : 0);

    //@ assert 0 <= result <= 100;
    return result;
}

/* --- Function 3: Count tens digit sum from three digits --- */
/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 9 &&
        1 <= b && b <= 9 &&
        1 <= c && c <= 9;

    logic integer total_sum(integer a, integer b, integer c) = a + b + c;

    lemma sum_bounds: \forall integer a, b, c;
        valid_input(a, b, c) ==> 3 <= total_sum(a, b, c) && total_sum(a, b, c) <= 27;
*/

int func3(long long a, long long b, long long c)
{
    long long sum;
    long long result;
    long long temp_sum;

    //@ assert valid_input(a, b, c);
    //@ assert 3 <= a + b + c && a + b + c <= 27;

    sum = a + b + c;
    result = 0;
    temp_sum = sum;

    while (temp_sum >= 10)
    {
        //@ assert temp_sum >= 10;
        temp_sum -= 10;
        result += 1;
        //@ assert temp_sum == sum - result * 10;
    }

    if (temp_sum > 0)
    {
        result += 1;
    }

    //@ assert result >= 1 && result <= 10;
    return result;
}

/* --- Function 4: Even/odd transformation --- */
/*@
    predicate is_even(integer x) = x % 2 == 0;
    predicate is_odd(integer x) = x % 2 != 0;
*/

uint64_t func4(uint64_t n)
{
    uint64_t ans;
    //@ assert 1 <= n <= 1000000000;
    
    if (n % 2 == 0) {
        ans = n;
        //@ assert ans == n;
    } else {
        ans = 2 * n;
        //@ assert ans == 2 * n;
    }
    
    return ans;
}

bool even_check(uint64_t x)
{
    bool res;
    //@ assert 1 <= x <= 1000000000;
    
    res = (x % 2 == 0);
    //@ assert res ==> is_even(x);
    //@ assert !res ==> is_odd(x);
    
    return res;
}

/* ==================== Synthesized Complex Function ==================== */

/* Scenario: 
   A multi-round game score computation system.
   Input: N (total rounds), i (current round index), three digits a,b,c (score components), n (player seed)
   Data flow:
     1. Compute reversed round index j = func1(N, i)
     2. Apply even/odd transformation to seed: t = func4(n)
     3. Use t and j to derive three adjusted score values, then compute func2 on them
     4. Compute func3 on the original digits as a baseline
     5. Combine results to produce final score
*/

unsigned int synthesized_func(int N, int i, long long a, long long b, long long c, uint64_t n)
{
    int j;
    uint64_t t;
    unsigned int score_adjust;
    int baseline;
    unsigned int final_score;
    
    j = func1(N, i);
    //@ assert 1 <= j <= N;
    
    t = func4(n);
    //@ assert (is_even(n) ==> t == n) && (is_odd(n) ==> t == 2*n);
    
    unsigned int v1 = (unsigned int)((j % 100) + 1);
    unsigned int v2 = (unsigned int)((t % 100) + 1);
    
    uint64_t t_mod = t % 100;
    int combined = (j % 100) + (int)t_mod;
    unsigned int v3 = (unsigned int)((combined % 100) + 1);
    
    //@ assert valid_range(v1) && valid_range(v2) && valid_range(v3);
    score_adjust = func2(v1, v2, v3);
    //@ assert 0 <= score_adjust <= 100;
    
    baseline = func3(a, b, c);
    //@ assert 1 <= baseline <= 10;
    
    unsigned int raw = (unsigned int)(baseline * (score_adjust + 1));
    if (raw > 100) {
        final_score = 100;
    } else {
        final_score = raw;
    }
    
    //@ assert final_score >= 0 && final_score <= 100;
    
    return final_score;
}
