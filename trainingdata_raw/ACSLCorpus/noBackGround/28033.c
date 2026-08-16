/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result >= 0;
    ensures \result <= b + c + d;
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long min_ab;
    long min_cd;
    long ans;
    
    //@ assert a >= 1;
    //@ assert b >= 1;
    //@ assert c >= 1;
    //@ assert d >= 1;
    
    //@ assert a <= 10000;
    //@ assert b <= 10000;
    //@ assert c <= 10000;
    //@ assert d <= 10000;
    
    //@ assert a + b + c + d <= 40000;
    
    if (a + b < c) {
        min_ab = a + b;
    } else {
        min_ab = c;
    }
    
    if (c + d < b) {
        min_cd = c + d;
    } else {
        min_cd = b;
    }
    
    if (min_ab < min_cd) {
        ans = min_ab;
    } else {
        ans = min_cd;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= b + c + d;
    
    return ans;
}
