/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == ((r) * (r));
    assigns \nothing;
*/
int func(int r) {
    int result;
    
    // Simple case: r = 1
    if (r == 1) {
        //@ assert ((r) * (r)) == 1;
        return 1;
    }
    
    // Simple case: r = 0
    if (r == 0) {
        //@ assert ((r) * (r)) == 0;
        return 0;
    }
    
    // Simple case: r = -1
    if (r == -1) {
        //@ assert ((r) * (r)) == 1;
        return 1;
    }
    
    //@ assert -100 <= r && r <= 100;
    //@ assert -10000 <= r * r && r * r <= 10000;
    
    result = r * r;
    
    //@ assert result == ((r) * (r));
    return result;
}
