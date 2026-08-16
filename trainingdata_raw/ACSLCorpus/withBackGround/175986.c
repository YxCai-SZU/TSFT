#include <stdbool.h>

/*@
    predicate is_nonnegative(integer x) = x >= 0;
    predicate is_within_range(integer x) = 1 <= x <= 100000;
    predicate temp_k_invariant(integer temp_k, integer k, integer a) =
        temp_k >= 0 && temp_k <= k && a >= 0 && a <= (k - temp_k) / 2;
*/

/*@
    logic integer sequence_value(integer a, integer b) =
        a == b ? a + b + 1 : a + b;
*/

/*@
    lemma temp_k_decreases:
        \forall integer temp_k, k, a;
        temp_k_invariant(temp_k, k, a) && temp_k >= 2 ==>
            temp_k_invariant(temp_k - 2, k, a + 1);
*/

/*@
    requires is_within_range(k);
    ensures is_nonnegative(\result);
    assigns \nothing;
*/
int func(int k)
{
    int a = 0;
    int b = 0;
    int temp_k = k;

    /*@
        loop invariant temp_k_invariant(temp_k, k, a);
        loop invariant is_within_range(k);
        loop assigns temp_k, a;
        loop variant temp_k;
    */
    while (temp_k >= 2)
    {
        //@ assert temp_k >= 2 && temp_k <= k;
        temp_k -= 2;
        a += 1;
        //@ assert temp_k_invariant(temp_k, k, a);
    }

    b = (temp_k == 1) ? 1 : 0;

    int result = (a == b) ? (a + b + 1) : (a + b);

    //@ assert is_nonnegative(result);
    return result;
}
