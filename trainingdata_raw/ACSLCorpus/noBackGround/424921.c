/*@
    requires (3 <= (n) && (n) <= 100);
    ensures \result == (180 * (n) - 360);
    assigns \nothing;
*/
int func(int n) {
    int result;
    int idx;
    
    //@ assert (3 <= (n) && (n) <= 100);
    
    result = 0;
    idx = 0;
    
    /*@
        loop invariant 0 <= idx <= n;
        loop invariant result == 180 * idx;
        loop assigns idx, result;
        loop variant n - idx;
    */
    while (idx < n) {
        //@ assert idx < n;
        idx = idx + 1;
        result = result + 180;
        //@ assert result == 180 * idx;
    }
    
    //@ assert result == 180 * n;
    result = result - 360;
    
    //@ assert result == 180 * n - 360;
    return result;
}
