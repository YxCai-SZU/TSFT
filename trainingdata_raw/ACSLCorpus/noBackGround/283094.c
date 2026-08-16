/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (2 * 3 * (r));
    assigns \nothing;
*/
long func(long r)
{
    long pi_approx;
    long circumference;
    
    pi_approx = 3;
    circumference = 2 * pi_approx * r;
    
    //@ assert 2 * pi_approx * r == 2 * 3 * r;
    //@ assert circumference == 2 * 3 * r;
    
    return circumference;
}
