/*@
    predicate in_range(integer a) = 1 <= a && a <= 10;

    lemma product_bound:
        \forall integer a, b, c;
            in_range(a) && in_range(b) && in_range(c) ==>
            a * b * c <= 10 * 10 * 10;
*/

/*@
    requires 1 <= a <= 10;
    requires 1 <= b <= 10;
    requires 1 <= c <= 10;
    ensures \result <= 10 * 10 * 10;
*/
int func(int a, int b, int c)
{
    //@ assert 1 <= a && a <= 10;
    //@ assert 1 <= b && b <= 10;
    //@ assert 1 <= c && c <= 10;
    //@ assert a <= 10;
    //@ assert b <= 10;
    //@ assert c <= 10;
    //@ assert a * b <= 10 * 10;
    //@ assert a * b * c <= 10 * 10 * 10;
    //@ assert a * b * c <= 1000;
    
    return a * b * c;
}

int main()
{
    return 0;
}
