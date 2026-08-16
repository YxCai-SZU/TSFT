/*@
    predicate bounds(integer x, integer y) = 0 <= x && x <= 10 && 0 <= y && y <= 10;
    predicate product_bounded(integer x, integer y) = x * y <= 100;
    
    lemma product_bound_lemma: \forall integer x, y; bounds(x, y) ==> product_bounded(x, y);
*/

/*@
    requires bounds(x, y);
    ensures \result <= 100;
    assigns \nothing;
*/
unsigned int nonlinear_arith_example(unsigned int x, unsigned int y)
{
    unsigned int result;
    
    //@ assert bounds(x, y);
    //@ assert product_bounded(x, y);
    
    result = x * y;
    
    //@ assert result <= 100;
    return result;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
