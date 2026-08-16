/*@
    predicate bounds(integer a, integer b, integer c) =
        a >= 0 && a <= 10 &&
        b >= 0 && b <= 10 &&
        c >= 0 && c <= 10;
        
    lemma product_bounds:
        \forall integer a, b, c;
        bounds(a, b, c) ==> a * b * c >= 0 && a * b * c <= 1000;
*/

/*@
    requires bounds(a, b, c);
    ensures \result == a * b * c;
    ensures \result >= 0 && \result <= 1000;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    //@ assert bounds(a, b, c);
    
    //@ assert a * b <= 100;
    //@ assert a * b * c <= 1000;
    
    return a * b * c;
}

int main()
{
    return 0;
}
