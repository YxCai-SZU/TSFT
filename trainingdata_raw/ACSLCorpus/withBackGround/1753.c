/*@
    predicate is_small(integer x) = 1 <= x <= 9;
    predicate both_small(integer a, integer b) = is_small(a) && is_small(b);
    predicate one_large(integer a, integer b) = a > 9 || b > 9;
    
    logic integer product(integer a, integer b) = a * b;
    
    lemma product_bounds:
        \forall integer a, b;
            is_small(a) && is_small(b) ==> 1 <= product(a, b) <= 81;
*/

/*@
    requires 1 <= a <= 20;
    requires 1 <= b <= 20;
    ensures (a > 9 || b > 9) ==> \result == -1;
    ensures (a <= 9 && b <= 9) ==> \result == a * b;
*/
int func(int a, int b)
{
    int result;
    
    if (a > 9 || b > 9)
    {
        //@ assert a > 9 || b > 9;
        result = -1;
    }
    else
    {
        //@ assert a <= 9 && b <= 9;
        //@ assert 1 <= a * b <= 81;
        result = a * b;
    }
    
    return result;
}
