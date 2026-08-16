/*@
    predicate leq(integer a, integer b) = a <= b;
    predicate eq(integer a, integer b) = a == b;
    
    lemma calc_example_3:
        \forall integer a, b; a <= b ==> a <= b + 1;
    
    lemma calc_example_4:
        \forall integer x, y; x <= y && y <= x + 1 ==> x <= y;
    
    lemma calc_example_5:
        \forall integer x; x > 0 ==> 2 * x == x + x;
*/

/*@
    requires a <= b;
    ensures \result == 0;
*/
int calc_example_3_impl(int a, int b)
{
    int result;
    
    //@ assert a <= b;
    //@ assert a <= b + 1;
    
    result = 0;
    return result;
}

/*@
    requires x <= y;
    requires y <= x + 1;
    ensures \result == 0;
*/
int calc_example_4_impl(int x, int y)
{
    int result;
    
    //@ assert x <= y;
    
    result = 0;
    return result;
}

/*@
    requires x > 0;
    ensures \result == 0;
*/
int calc_example_5_impl(int x)
{
    int result;
    
    //@ assert 2 * x == x + x;
    
    result = 0;
    return result;
}

int main()
{
    return 0;
}
