/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;
    
    logic integer product_val(integer a, integer b) = a * b + 1;
    
    lemma product_bounds: \forall integer a, b; valid_range(a, b) ==> 1 <= a * b <= 10000;
*/

/*@
    requires valid_range(a, b);
    ensures \result == (a * b + 1) / 2;
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int product;
    int result = 0;
    int temp;
    
    //@ assert 1 <= a <= 100 && 1 <= b <= 100;
    
    //@ assert 1 <= a * b <= 10000;
    product = a * b + 1;
    
    temp = product;
    
    /*@
        loop invariant 0 <= result;
        loop invariant 0 <= temp;
        loop invariant temp == product - 2 * result;
        loop invariant product == a * b + 1;
        loop assigns result, temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        result += 1;
        temp -= 2;
    }
    
    //@ assert result == (a * b + 1) / 2;
    return result;
}

int main()
{
    return 0;
}
