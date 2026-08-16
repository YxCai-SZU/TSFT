/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == (a + c) * (b + d);
    ensures (4 <= (\result) <= 40000);
*/
long func(long a, long b, long c, long d)
{
    // Variable declarations at scope top
    long result;
    long sum_ac;
    long sum_bd;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    
    sum_ac = a + c;
    //@ assert (2 <= (sum_ac) <= 200);
    
    sum_bd = b + d;
    //@ assert (2 <= (sum_bd) <= 200);
    
    //@ assert (4 <= (sum_ac * sum_bd) <= 40000);
    
    result = sum_ac * sum_bd;
    //@ assert result == (a + c) * (b + d);
    
    return result;
}
