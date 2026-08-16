/*@
    predicate valid_range(integer x) = 1 <= x <= 10;
    
    logic integer product(integer a, integer b, integer c) = a * b * c;
    
    lemma product_bound: 
        \forall integer a, b, c; 
        valid_range(a) && valid_range(b) && valid_range(c) ==> 
        product(a, b, c) <= 1000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == product(a, b, c);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Variable declarations at top
    int result;
    
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    
    //@ assert a * b <= 100;
    //@ assert a * b * c <= 1000;
    
    result = a * b * c;
    
    //@ assert result == product(a, b, c);
    return result;
}

/*@
    lemma func_postcondition:
        \forall integer a, b, c, result;
        valid_range(a) && valid_range(b) && valid_range(c) && 
        result == product(a, b, c) ==>
        result == product(a, b, c);
*/

int main()
{
    // Variable declarations at top
    int x;
    
    x = func(2, 3, 4);
    
    //@ assert x == 24;
    return 0;
}
