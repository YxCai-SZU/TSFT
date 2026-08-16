/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == ((r) * (r));
    assigns \nothing;
*/
long func(long r) {
    // Variable declarations at scope top
    long ans;
    
    //@ assert (1 <= (r) && (r) <= 100);
    
    //@ assert 1 <= r * r && r * r <= 10000;
    
    ans = r * r;
    return ans;
}
