#include <stdbool.h>
#include <stddef.h>

/* ===== Function 1: Score calculation based on sequence constraints ===== */
/*@ predicate a_in_range(int *a, integer n) =
      \forall integer i; 0 <= i < n ==> 1 <= a[i] <= n;
*/
/*@ predicate b_in_range(int *b, integer n) =
      \forall integer i; 0 <= i < n ==> 1 <= b[i] <= 50;
*/
/*@ predicate c_in_range(int *c, integer n) =
      \forall integer i; 0 <= i < n-1 ==> 1 <= c[i] <= 50;
*/
/*@ predicate a_distinct(int *a, integer n) =
      \forall integer i, j; 0 <= i < j < n ==> a[i] != a[j];
*/
/*@ predicate a_prefix_distinct(int *a, integer i) =
      \forall integer j, k; 0 <= j < k < i ==> a[j] != a[k];
*/

int func_score(int n, int *a, int *b, int *c)
{
    int ret = 0;
    int i = 0;
    
    while (i < n)
    {
        int num = a[i];
        //@ assert 1 <= num <= n;
        ret = ret + b[num - 1];
        
        if (i + 1 < n && a[i + 1] == num + 1)
        {
            //@ assert 1 <= num <= n-1;
            ret = ret + c[num - 1];
        }
        
        i += 1;
    }
    
    return ret;
}

/* ===== Function 2: Maximum value with safety check ===== */
/*@
    logic integer max_value(integer x, integer y) = (x > y) ? x : y;

    lemma max_value_lemma:
        \forall integer x, y; x <= y ==> max_value(x, y) == y;

    lemma max_value_symmetric_lemma:
        \forall integer x, y; y <= x ==> max_value(x, y) == x;
*/

int max_value_checked(int x, int y) {
    int result;
    //@ assert x >= 0 && y >= 0;
    if (x > y) {
        result = x;
    } else {
        result = y;
    }
    //@ assert result == max_value(x, y);
    return result;
}

/* ===== Function 3: Time difference calculation ===== */
/*@
    predicate valid_time(integer h, integer m) =
        0 <= h < 24 && 0 <= m < 60;

    logic integer time_diff(integer h1, integer m1, integer h2, integer m2, integer k) =
        (m2 - m1) + (60 * (h2 - h1 - 1)) - k;

    lemma ans_nonnegative:
        \forall integer h1, m1, h2, m2, k, ans;
        valid_time(h1, m1) && valid_time(h2, m2) && 0 <= k < 1440 &&
        ans == (time_diff(h1, m1, h2, m2, k) < 0 ? 0 : time_diff(h1, m1, h2, m2, k)) ==>
        ans >= 0;

    lemma ans_upper_bound:
        \forall integer h1, m1, h2, m2, k, ans;
        valid_time(h1, m1) && valid_time(h2, m2) && 0 <= k < 1440 &&
        ans == (time_diff(h1, m1, h2, m2, k) < 0 ? 0 : time_diff(h1, m1, h2, m2, k)) ==>
        ans <= 1440;
*/

int func_time(int h1, int m1, int h2, int m2, int k) {
    int ans;

    //@ assert valid_time(h1, m1);
    //@ assert valid_time(h2, m2);
    //@ assert 0 <= k < 1440;

    ans = (m2 - m1) + (60 * (h2 - h1 - 1)) - k;

    //@ assert ans == time_diff(h1, m1, h2, m2, k);

    if (ans < 0) {
        ans = 0;
        //@ assert ans == 0;
    } else {
        //@ assert ans >= 0;
    }

    //@ assert ans >= 0;
    //@ assert ans <= 1440;

    return ans;
}

/* ===== Function 4: Count matching elements between two arrays ===== */
/*@ predicate an_valid_range(int *an, integer n) =
      \forall integer i; 0 <= i < n ==> 1 <= an[i] <= 123;
*/

/*@ predicate bn_valid_range(int *bn, integer m) =
      \forall integer i; 0 <= i < m ==> 1 <= bn[i] <= 123;
*/

/*@ lemma array_lengths_preserved:
      \forall int *an, int *bn, integer n, integer m;
      an_valid_range(an, n) && bn_valid_range(bn, m) ==>
      an_valid_range(an, n) && bn_valid_range(bn, m);
*/

int func_match(int n, int m, int x, int *an, int *bn) {
    int ans = 0;
    size_t index = 0;
    
    while (index < (size_t)m) {
        int b = bn[index];
        int i = 0;
        bool found = false;
        
        while (i < n) {
            //@ assert an_valid_range(an, n);
            if (an[i] == b) {
                found = true;
                break;
            }
            i++;
        }
        
        if (found) {
            ans++;
        }
        index++;
    }
    
    //@ assert 0 <= ans <= m;
    return ans;
}

/* ===== Synthesized Function: Student Contest Score Aggregator =====
   Real-world scenario: A programming contest platform computes a student's total score
   based on multiple criteria:
   1. Score from sequence-based problem (func_score) - measures pattern recognition
   2. Time bonus from solving problems quickly (func_time) - measures speed
   3. Matching score from knowledge base (func_match) - measures knowledge coverage
   4. Maximum of two partial scores (max_value_checked) - takes best performance
   
   The final score is the sum of the sequence score and the maximum of time bonus and matching score,
   ensuring the student is rewarded for both consistent performance and peak performance.
*/

int student_total_score(
    int n, int *a, int *b, int *c,
    int h1, int m1, int h2, int m2, int k,
    int n2, int m2_2, int x, int *an, int *bn
) {
    int seq_score = func_score(n, a, b, c);
    //@ assert seq_score >= 0;
    
    int time_bonus = func_time(h1, m1, h2, m2, k);
    //@ assert time_bonus >= 0 && time_bonus <= 1440;
    
    int match_score = func_match(n2, m2_2, x, an, bn);
    //@ assert match_score >= 0 && match_score <= m2_2;
    
    int scaled_match = match_score * 10;
    int performance_score = max_value_checked(time_bonus, scaled_match);
    //@ assert performance_score == max_value(time_bonus, scaled_match);
    
    int total = seq_score + performance_score;
    
    //@ assert total >= 0;
    
    return total;
}
