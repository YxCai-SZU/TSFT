/*@
    predicate valid_inputs(integer a, integer b) =
        a >= 1 && a <= 100 &&
        b >= 0 && b <= a * a;

    logic integer compute_result(integer a, integer b) =
        a * a - b;

    lemma no_underflow: \forall integer a, b; valid_inputs(a, b) ==> a * a >= 0;
    lemma no_overflow: \forall integer a, b; valid_inputs(a, b) ==> a * a <= 10000;
*/

/*@
    requires valid_inputs(a, b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 0 && b <= a * a;
    //@ assert a * a >= 0;
    //@ assert a * a <= 10000;
    
    int ans = a * a - b;
    return ans;
}
