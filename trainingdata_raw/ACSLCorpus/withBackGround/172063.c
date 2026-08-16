/*@
    predicate valid_range(integer a, integer b) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100;

    logic integer compute_ans(integer a, integer b) = a - 2 * b;

    lemma ans_nonnegative_or_correct:
        \forall integer a, b;
        valid_range(a, b) ==>
        (compute_ans(a, b) >= 0 || compute_ans(a, b) == a - 2 * b);
*/

/*@
    requires valid_range(a, b);
    ensures \result >= 0;
    ensures \result == a - 2 * b || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int ans;
    int res;

    ans = a - 2 * b;
    
    //@ assert ans >= 0 || ans == a - 2 * b;
    
    if (ans > 0) {
        res = ans;
    } else {
        res = 0;
    }
    
    return res;
}
