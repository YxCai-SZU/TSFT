/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
long func(long r) {
    long pi_approx;
    long area;
    
    pi_approx = 3;
    
    //@ assert 3 * r * r <= 30000;
    
    area = pi_approx * r * r;
    
    //@ assert area == 3 * r * r;
    
    return area;
}
