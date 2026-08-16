/*@
    predicate is_small(integer a, integer b) =
        1 <= a <= 9 && 1 <= b <= 9;
    
    predicate is_large(integer a, integer b) =
        (1 <= a <= 20 && 1 <= b <= 20) && (a > 9 || b > 9);
    
    logic integer product(integer a, integer b) = a * b;
    
    lemma product_bound:
        \forall integer a, b;
            is_small(a, b) ==> product(a, b) <= 81;
*/

/*@
    requires 1 <= a <= 20;
    requires 1 <= b <= 20;
    ensures (a <= 9 && b <= 9) ==> \result == product(a, b);
    ensures (a > 9 || b > 9) ==> \result == -1;
*/
int func(unsigned int a, unsigned int b)
{
    int result;
    
    if (a > 9 || b > 9)
    {
        //@ assert is_large(a, b);
        result = -1;
    }
    else
    {
        //@ assert is_small(a, b);
        //@ assert product(a, b) <= 81;
        result = (int)(a * b);
    }
    
    return result;
}
