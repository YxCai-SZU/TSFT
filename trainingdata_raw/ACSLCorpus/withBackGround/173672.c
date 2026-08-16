/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= c && c <= 100;

    predicate product_in_range(integer a, integer b) =
        1 <= a * b && a * b <= 10000;

    logic integer expected_result(integer a, integer b) = (a * b) / 2;

    lemma overflow_safe: \forall integer a, b; valid_input(a, b, 1) ==> product_in_range(a, b);
*/

/*@
    requires valid_input(a, b, c);
    ensures \result == expected_result(a, b);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Variable declarations at top of scope
    int product;
    int result = 0;
    int count = 0;
    
    //@ assert product_in_range(a, b);
    
    product = a * b;
    
    /*@
        loop invariant 0 <= product;
        loop invariant 0 <= result;
        loop invariant product + 2 * result == a * b;
        loop assigns product, result;
    */
    while (product >= 2)
    {
        product -= 2;
        result += 1;
    }
    
    //@ assert result == expected_result(a, b);
    return result;
}
