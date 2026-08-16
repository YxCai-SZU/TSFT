/*@
    predicate valid_range(integer x) = 1 <= x <= 50;

    logic integer multiply(integer a, integer b) = a * b;

    lemma product_bound: \forall integer a, b; valid_range(a) && valid_range(b) ==> multiply(a, b) <= 2500;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == multiply(a, b);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int ans;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert multiply(a, b) <= 2500;

    ans = a * b;
    return ans;
}
