/*@
    predicate valid_range(integer a, integer b) =
        2 <= a && a <= 100 && 2 <= b && b <= 100;

    lemma subtraction_safe: \forall integer a, b; valid_range(a, b) ==> a - 1 >= 1 && b - 1 >= 1;

    lemma product_bound: \forall integer a, b; valid_range(a, b) ==> (a - 1) * (b - 1) <= 99 * 99;
*/

/*@
    requires valid_range(a, b);
    ensures \result == (a - 1) * (b - 1);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int result;
    
    //@ assert a - 1 >= 1;
    result = (a - 1) * (b - 1);
    return result;
}
