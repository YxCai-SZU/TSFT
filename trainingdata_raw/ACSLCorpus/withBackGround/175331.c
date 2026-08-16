/*@
    predicate bounds(integer a, integer b) =
        0 <= a && a <= 100 &&
        0 <= b && b <= 100;
        
    logic integer product(integer a, integer b) = a * b;
    
    lemma product_in_bounds:
        \forall integer a, b;
        bounds(a, b) ==> product(a, b) <= 10000;
*/

/*@
    requires bounds(a, b);
    ensures \result == product(a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int result;
    
    //@ assert bounds(a, b);
    
    //@ assert product(a, b) <= 10000;
    
    result = a * b;
    
    //@ assert result == product(a, b);
    
    return result;
}

int main()
{
    return 0;
}
