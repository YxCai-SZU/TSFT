/*@
    requires (1 <= (d) <= 10000) && (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    ensures \result == (d <= t * s);
*/
_Bool func(int d, int t, int s) {
    int result;
    
    //@ assert (1 <= (t) <= 10000);
    //@ assert (1 <= (s) <= 10000);
    //@ assert 1 <= t * s <= 10000 * 10000;
    
    if (d <= t * s) {
        //@ assert d <= t * s;
        result = 1;
    } else {
        //@ assert !(d <= t * s);
        result = 0;
    }
    
    return result;
}
