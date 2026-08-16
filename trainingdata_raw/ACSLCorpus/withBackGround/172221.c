/*@
    predicate valid_range(integer a, integer b) =
        2 <= a && a <= 100 &&
        2 <= b && b <= 100;

    logic integer compute_result(integer a, integer b) =
        a * b - a - b + 1;

    lemma result_positive:
        \forall integer a, b;
        valid_range(a, b) ==> compute_result(a, b) > 0;

    lemma no_overflow:
        \forall integer a, b;
        valid_range(a, b) ==> compute_result(a, b) <= 2147483647;
*/

/*@
    requires valid_range(a, b);
    ensures \result == compute_result(a, b);
    ensures \result > 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top
    int ans;

    //@ assert 2 <= a && a <= 100;
    //@ assert 2 <= b && b <= 100;
    //@ assert a > 0;
    //@ assert b > 0;
    //@ assert a <= 100;
    //@ assert b <= 100;
    //@ assert a * b <= 10000;
    //@ assert a * b - a - b >= -196;
    //@ assert a * b - a - b + 1 <= 2147483647;
    //@ assert a * b - a - b + 1 >= 1;

    ans = a * b - a - b + 1;
    return ans;
}
