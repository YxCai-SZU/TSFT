/*@
    predicate x_in_range(integer x) = 1 <= x && x <= 10;
    predicate y_in_range(integer y) = 1 <= y && y <= 10;
    predicate product_in_range(integer p) = 1 <= p && p <= 100;
    
    lemma product_range: 
        \forall integer x, y; 
        x_in_range(x) && y_in_range(y) ==> product_in_range(x * y);
*/

/*@
    requires x_in_range(x);
    requires y_in_range(y);
    ensures \result == x * y;
    ensures product_in_range(\result);
*/
int func(int x, int y)
{
    //@ assert x_in_range(x);
    //@ assert y_in_range(y);
    //@ assert product_in_range(x * y);
    
    int result;
    result = x * y;
    
    //@ assert result == x * y;
    //@ assert product_in_range(result);
    
    return result;
}

int main()
{
    return 0;
}
