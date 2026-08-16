#include <stdbool.h>

/*@ predicate diff_in_range(integer a, integer b) = 1 <= b <= a <= 20; */
/*@ predicate c_in_range(integer c) = 1 <= c <= 20; */
/*@ logic integer compute_diff(integer a, integer b) = a - b; */
/*@ logic integer compute_result(integer diff, integer c) = diff > c ? 0 : c - diff; */

/*@ lemma diff_nonnegative: 
      \forall integer a, b; diff_in_range(a, b) ==> compute_diff(a, b) >= 0; */
/*@ lemma diff_upper_bound: 
      \forall integer a, b; diff_in_range(a, b) ==> compute_diff(a, b) <= 20; */
/*@ lemma result_lower_bound: 
      \forall integer diff, c; c_in_range(c) && diff >= 0 ==> compute_result(diff, c) >= 0; */
/*@ lemma result_upper_bound: 
      \forall integer diff, c; c_in_range(c) && diff >= 0 ==> compute_result(diff, c) <= c; */
/*@ lemma result_zero_case: 
      \forall integer diff, c; diff >= c ==> compute_result(diff, c) == 0; */
/*@ lemma result_nonzero_case: 
      \forall integer diff, c; diff < c ==> compute_result(diff, c) == c - diff; */

/*@ requires 1 <= b <= a <= 20;
    requires 1 <= c <= 20;
    ensures \result >= 0;
    ensures \result <= c;
    ensures a - b >= c ==> \result == 0;
    ensures a - b < c ==> \result == c - (a - b);
    assigns \nothing;
 */
int func(int a, int b, int c)
{
    int diff;
    int result;

    diff = a - b;
    //@ assert diff >= 0;
    //@ assert diff <= 20;

    if (diff > c)
    {
        result = 0;
    }
    else
    {
        result = c - diff;
    }

    //@ assert result >= 0;
    //@ assert result <= c;
    //@ assert diff >= c ==> result == 0;
    //@ assert diff < c ==> result == c - diff;

    return result;
}
