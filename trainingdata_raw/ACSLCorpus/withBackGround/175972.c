/*@
    predicate bounds(integer x, integer y) =
        1 <= x && x <= 10000 &&
        1 <= y && y <= 10000;

    lemma no_over_underflow:
        \forall integer x, y; bounds(x, y) ==> x * y <= 10000 * 10000;

    lemma no_overflow_add:
        \forall integer x, y; bounds(x, y) ==> x + y <= 20000;
*/

/*@
    requires 1 <= x && x <= 10000;
    requires 1 <= y && y <= 10000;
    ensures \result <= 10000 * 10000;
    assigns \nothing;
*/
int safe_multiply(int x, int y)
{
    //@ assert bounds(x, y);
    //@ assert x * y <= 10000 * 10000;
    return x * y;
}

/*@
    requires 1 <= x && x <= 10000;
    requires 1 <= y && y <= 10000;
    ensures \result <= 20000;
    assigns \nothing;
*/
int safe_add(int x, int y)
{
    //@ assert bounds(x, y);
    //@ assert x + y <= 20000;
    return x + y;
}

int main()
{
    int a;
    int b;
    int result1;
    int result2;
    
    a = 5000;
    b = 6000;
    
    result1 = safe_multiply(a, b);
    result2 = safe_add(a, b);
    
    return 0;
}
