/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures ((\result) >= 0);
    ensures ((\result) == (a) - 2 * (b) || (\result) == 0);
*/
long func(long a, long b) {
    long result;
    
    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    
    //@ assert (a - 2 * b > 0) ==> (a - 2 * b >= 0);
    //@ assert !(a - 2 * b > 0) ==> (0 >= 0);
    
    if (a - 2 * b > 0) {
        result = a - 2 * b;
        //@ assert result == a - 2 * b;
        //@ assert result >= 0;
    } else {
        result = 0;
        //@ assert result == 0;
        //@ assert result >= 0;
    }
    
    //@ assert result >= 0;
    //@ assert result == a - 2 * b || result == 0;
    
    return result;
}
