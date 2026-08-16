/*@
    predicate valid_range(integer a, integer b) =
        2 <= a <= 100 && 2 <= b <= 100;

    logic integer compute_result(integer a, integer b) =
        a * b - (a + b - 1);

    lemma no_overflow_sum: \forall integer a, b; valid_range(a, b) ==> a + b - 1 <= 199;
    lemma no_overflow_product: \forall integer a, b; valid_range(a, b) ==> a * b <= 10000;
    lemma no_underflow: \forall integer a, b; valid_range(a, b) ==> a * b >= a + b - 1;
*/

/*@
    requires valid_range(a, b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b)
{
    // Variable declarations at top
    int result;

    //@ assert a + b - 1 <= 199;
    //@ assert a * b <= 10000;
    //@ assert a * b >= a + b - 1;

    result = (int)(a * b - (a + b - 1));
    return result;
}
