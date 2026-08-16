/*@
    predicate bounds(integer a, integer b, integer c) =
        0 <= a && a < 10 &&
        0 <= b && b < 10 &&
        0 <= c && c < 10;

    lemma sum_bound:
        \forall integer a, b, c;
        bounds(a, b, c) ==> a + b + c <= 27;
*/

/*@
    requires bounds(a, b, c);
    ensures \result <= 27;
*/
int func(int a, int b, int c)
{
    //@ assert a < 10;
    //@ assert b < 10;
    //@ assert c < 10;
    
    int sum = a + b + c;
    
    //@ assert sum <= 27;
    return sum;
}
