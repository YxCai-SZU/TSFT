/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bounds:
        \forall integer a, b;
        valid_range(a, b) ==> 1 <= product(a, b) <= 10000;
*/

/*@
    requires valid_range(a, b);
    ensures \result == product(a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert valid_range(a, b);
    //@ assert product(a, b) <= 10000;
    
    int result;
    
    result = a * b;
    
    //@ assert result == product(a, b);
    return result;
}
