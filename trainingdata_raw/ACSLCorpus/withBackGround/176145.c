/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    predicate scale_constants(integer pi, integer two, integer scale) =
        pi == 31415 && two == 2 && scale == 10000;
    predicate product_relation(integer pi, integer two, integer r, integer product) =
        product == pi * two * r;
    predicate loop_invariant(integer result, integer remainder, integer product, integer scale) =
        0 <= result &&
        result * scale + remainder == product &&
        0 <= remainder < product + scale;
*/

/*@
    logic integer target_result(integer r) = 2 * 31415 * r / 10000;
*/

/*@
    lemma product_equality:
        \forall integer pi, integer two, integer r, integer product;
        pi == 31415 && two == 2 && 1 <= r <= 100 && product == pi * two * r ==>
        product == 2 * pi * r;
    
    lemma remainder_equality:
        \forall integer result, integer remainder, integer product, integer scale;
        0 <= result && result * scale + remainder == product ==>
        remainder == product - result * scale;
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * 31415 * r / 10000;
    assigns \nothing;
*/
int func(int r)
{
    int pi;
    int two;
    int scale;
    int product;
    int result;
    int remainder;
    
    pi = 31415;
    two = 2;
    scale = 10000;
    
    product = pi * two * r;
    
    //@ assert product == 2 * pi * r;
    
    result = 0;
    remainder = product;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 31415 && two == 2 && scale == 10000;
        loop invariant product == pi * two * r;
        loop invariant 0 <= result;
        loop invariant result * scale + remainder == product;
        loop invariant 0 <= remainder < product + scale;
        loop assigns result, remainder;
        loop variant remainder;
    */
    while (remainder >= scale)
    {
        result += 1;
        remainder -= scale;
    }
    
    //@ assert remainder == product - result * scale;
    
    return result;
}

int main()
{
    return 0;
}
