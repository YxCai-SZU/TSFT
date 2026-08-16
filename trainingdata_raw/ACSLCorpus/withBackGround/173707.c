/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    
    logic integer product(integer a, integer b) = a * b;
    
    lemma product_bounds:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==> 
        1 <= product(a, b) <= 10000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == (a * b) / 2;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Variable declarations at top of scope
    int product;
    int res;
    int count;
    int temp;
    
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    
    //@ assert 1 <= a * b <= 10000;
    product = a * b;
    
    res = 0;
    count = 0;
    temp = product;
    
    /*@
        loop invariant 0 <= count <= product / 2;
        loop invariant temp == product - 2 * count;
        loop invariant 0 <= temp <= product;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 2)
    {
        int old_temp = temp;
        //@ assert temp >= 2;
        temp -= 2;
        count += 1;
        //@ assert temp == old_temp - 2;
    }
    
    //@ assert temp == product - 2 * count;
    //@ assert temp < 2;
    //@ assert count == product / 2;
    
    res = count;
    return res;
}
