/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result == ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d));
*/
long func(long a, long b, long c, long d)
{
    long min_ab;
    long min_cd;
    long result;
    
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    min_ab = a < b ? a : b;
    //@ assert min_ab == ((a) < (b) ? (a) : (b));
    
    min_cd = c < d ? c : d;
    //@ assert min_cd == ((c) < (d) ? (c) : (d));
    
    result = min_ab + min_cd;
    //@ assert result == ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d));
    
    return result;
}
