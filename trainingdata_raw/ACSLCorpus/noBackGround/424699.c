/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (2 * (r) * (3));
    assigns \nothing;
*/
long func(long r)
{
    long pi = 3;
    long circumference;
    
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert pi == 3;
    
    circumference = 2 * r * pi;
    
    //@ assert circumference == (2 * (r) * (pi));
    //@ assert circumference >= 6;
    //@ assert circumference <= 600;
    
    return circumference;
}
