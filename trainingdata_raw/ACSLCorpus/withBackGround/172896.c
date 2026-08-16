/*@
    predicate valid_radius(integer r) = 1 <= r && r <= 100;
    predicate nonnegative_circumference(integer c) = c >= 0;
    predicate circumference_bound(integer c, integer r) = 
        c * 100000 <= 2 * 314159 * r + 100000;
    
    logic integer initial_product(integer r) = 2 * 314159 * r;
    
    lemma product_nonnegative: 
        \forall integer r; valid_radius(r) ==> initial_product(r) >= 0;
*/

/*@
    requires valid_radius(r);
    ensures nonnegative_circumference(\result);
    ensures circumference_bound(\result, r);
    assigns \nothing;
*/
long func(long r)
{
    long pi_approx;
    long circumference;
    long temp;
    long divisor;
    
    pi_approx = 314159;
    circumference = 0;
    temp = 2 * pi_approx * r;
    divisor = 100000;
    
    /*@
        loop invariant valid_radius(r);
        loop invariant pi_approx == 314159;
        loop invariant divisor == 100000;
        loop invariant temp >= 0;
        loop invariant circumference * 100000 + temp == initial_product(r);
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        //@ assert temp >= divisor;
        temp -= divisor;
        circumference += 1;
    }
    
    //@ assert circumference * 100000 <= initial_product(r) + 100000;
    return circumference;
}
