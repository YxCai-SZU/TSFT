/*@
    predicate a_in_range(integer a) = 0 <= a && a <= 24;
    predicate b_in_range(integer b) = 0 <= b && b <= 24;
    predicate product_in_range(integer a, integer b) = 0 <= a * b && a * b <= 24 * 24;
    
    lemma product_bound: \forall integer a, b; a_in_range(a) && b_in_range(b) ==> product_in_range(a, b);
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures \result == (a * b <= 25);
    assigns \nothing;
*/
int func(int a, int b) {
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert product_in_range(a, b);
    
    int result;
    result = (a * b <= 25);
    return result;
}
