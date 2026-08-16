#include <stdbool.h>

/* First function: choose_ans */
/*@
    predicate is_in_range(integer x) = -100 <= x <= 100;

    logic integer choose_ans(integer a, integer b, integer c) =
        a == b ? c : (b == c ? a : (c == a ? b : a));

    lemma ans_property:
        \forall integer a, b, c;
            is_in_range(a) && is_in_range(b) && is_in_range(c) ==>
            (choose_ans(a, b, c) == a || choose_ans(a, b, c) == b || choose_ans(a, b, c) == c);

    lemma equal_case_property:
        \forall integer a, b, c;
            is_in_range(a) && is_in_range(b) && is_in_range(c) ==>
            (a == b || b == c || a == c) ==>
            (choose_ans(a, b, c) == a || choose_ans(a, b, c) == b || choose_ans(a, b, c) == c);
*/

long func_choose(long A, long B, long C)
{
    long ans;

    ans = A;

    //@ assert ans == A || ans == B || ans == C;

    if (A == B)
    {
        ans = C;
        //@ assert ans == A || ans == B || ans == C;
    }

    if (B == C)
    {
        ans = A;
        //@ assert ans == A || ans == B || ans == C;
    }

    if (C == A)
    {
        ans = B;
        //@ assert ans == A || ans == B || ans == C;
    }

    //@ assert ans == A || ans == B || ans == C;

    if (A == B || B == C || A == C)
    {
        //@ assert ans == A || ans == B || ans == C;
    }

    return ans;
}

/* Second function: check_sum */
/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer double_sum(integer a, integer b) = a * 2 + b * 2;

    lemma sum_range: \forall integer a, b; valid_range(a, b) ==> 4 <= double_sum(a, b) <= 400;
*/

bool func_check_sum(int A, int B) {
    int sum;
    bool is_even;
    int temp_sum;
    bool is_greater_or_equal;
    int temp_sum_copy;
    int count;

    sum = A * 2 + B * 2;

    //@ assert valid_range(A, B);
    //@ assert sum == double_sum(A, B);

    is_even = false;
    temp_sum = sum;

    while (temp_sum >= 2) {
        temp_sum -= 2;
    }

    if (temp_sum == 0) {
        is_even = true;
    }

    is_greater_or_equal = false;
    temp_sum_copy = sum;
    count = 0;

    while (temp_sum_copy >= 2) {
        temp_sum_copy -= 2;
        count += 1;
    }

    if (count >= 5) {
        is_greater_or_equal = true;
    }

    //@ assert is_greater_or_equal == (sum >= 10);
    return is_even && is_greater_or_equal;
}

/* Third function: check_exactly_one_pair */
/*@ predicate is_max(integer a, integer b, integer res) =
      (a >= b ==> res == a) && (a < b ==> res == b);
*/

int max(int a, int b)
{
    int res;
    if (a > b) {
        res = a;
    } else {
        res = b;
    }
    //@ assert is_max(a, b, res);
    return res;
}

/*@ predicate exactly_one_pair_equal(integer a, integer b, integer c) =
      (a == b && a != c) ||
      (a == c && a != b) ||
      (b == c && a != b);
*/

bool func_check_exactly_one_pair(int a, int b, int c)
{
    int ans;
    bool result;
    ans = 0;
    if (a == b) {
        ans += 1;
    }
    //@ assert (a == b ==> ans == 1) && (a != b ==> ans == 0);
    if (a == c) {
        ans += 1;
    }
    //@ assert (ans == 1) ==> exactly_one_pair_equal(a, b, c);
    if (b == c) {
        ans += 1;
    }
    //@ assert ans == 1 <==> exactly_one_pair_equal(a, b, c);
    result = (ans == 1);
    return result;
}

/* Synthesized function: score_calculator
   Real-world scenario: A simple scoring system for a game where three players (A, B, C)
   have scores. The system selects a base score from the three (using choose_ans logic),
   then checks if the sum of two selected scores meets a threshold, and finally validates
   that exactly one pair of scores is equal to ensure fairness in the selection process.
   The final assertion ensures that the output state is consistent: if the selection
   process is valid (exactly one pair equal), then the base score is one of the input scores. */
int score_calculator(int A, int B, int C)
{
    long base_score;
    bool threshold_met;
    bool valid_selection;
    int result;

    base_score = func_choose((long)A, (long)B, (long)C);

    threshold_met = func_check_sum(A, B);

    valid_selection = func_check_exactly_one_pair(A, B, C);

    if (threshold_met && valid_selection) {
        result = (int)base_score;
    } else {
        result = 0;
    }

    //@ assert (valid_selection == 1) ==> (base_score == A || base_score == B || base_score == C);

    return result;
}
