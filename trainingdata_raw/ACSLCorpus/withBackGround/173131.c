/*@
    predicate is_small(integer a, integer b) =
        1 <= a <= 9 && 1 <= b <= 9;
    
    logic integer safe_product(integer a, integer b) =
        a * b;
    
    lemma product_bounds:
        \forall integer a, b;
            is_small(a, b) ==> 1 <= safe_product(a, b) <= 81;
*/

/*@
    requires 1 <= a <= 20;
    requires 1 <= b <= 20;
    ensures (a > 9 || b > 9) ==> \result == -1;
    ensures (a <= 9 && b <= 9) ==> \result == a * b;
*/
int func(int a, int b)
{
    int res;
    
    if (a > 9 || b > 9)
    {
        res = -1;
    }
    else
    {
        //@ assert a <= 9 && b <= 9;
        //@ assert a >= 1 && b >= 1;
        //@ assert is_small(a, b);
        //@ assert a * b <= 81;
        res = a * b;
    }
    
    return res;
}
