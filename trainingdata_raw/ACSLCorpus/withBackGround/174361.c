/*@
    predicate is_equal(integer a, integer b) = a == b;
    predicate is_greater(integer a, integer b) = a > b;
    
    lemma calc_transitive:
        \forall integer a, b, x, y;
            is_equal(a, 3) && is_equal(b, 2) && is_equal(x, 3) && is_equal(y, 2) ==>
            is_greater(a + 1, b);
*/

/*@
    requires a == 3;
    requires b == 2;
    ensures \result == 1;
*/
int calc_example_3(int a, int b)
{
    int x;
    int y;
    
    x = 3;
    y = 2;
    
    //@ assert x == 3;
    //@ assert y == 2;
    //@ assert x + 1 > y;
    
    return 1;
}

int main()
{
    return 0;
}
