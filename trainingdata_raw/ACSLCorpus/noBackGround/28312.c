/*@
    requires (1 <= (r) <= 100);
    ensures \result >= 0;
    ensures \result <= 2 * r * 3;
    assigns \nothing;
*/
long func(long r) {
    long pi;
    long circumference;
    
    pi = 3;
    
    //@ assert 2 * pi * 1 <= 2 * pi * r;
    //@ assert 2 * pi * r <= 2 * pi * 100;
    
    circumference = 2 * pi * r;
    
    //@ assert circumference >= 0;
    //@ assert circumference <= 2 * r * 3;
    
    return circumference;
}
