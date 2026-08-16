/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && 
             (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b));
    ensures \result >= ((c) * (d));
*/
long func(long a, long b, long c, long d)
{
    long ab;
    long cd;
    long result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert (1 <= (d) <= 100);
    
    //@ assert 1 <= ((a) * (b)) <= 10000;
    //@ assert 1 <= ((c) * (d)) <= 10000;
    
    ab = a * b;
    cd = c * d;
    
    if (ab > cd) {
        result = ab;
    } else {
        result = cd;
    }
    
    //@ assert result == ((a) * (b)) || result == ((c) * (d));
    //@ assert result >= ((a) * (b));
    //@ assert result >= ((c) * (d));
    
    return result;
}
