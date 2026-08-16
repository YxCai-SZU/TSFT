/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    ensures \result <= b / a;
    ensures \result <= d / c;
    ensures \result == b / a || \result == d / c;
*/
unsigned long func(unsigned long a, unsigned long b,
                   unsigned long c, unsigned long d)
{
    unsigned long ans;
    //@ assert b / a <= b / a;
    //@ assert d / c <= d / c;
    
    if (b / a > d / c) {
        ans = d / c;
    } else {
        ans = b / a;
    }
    
    //@ assert ans <= b / a;
    //@ assert ans <= d / c;
    //@ assert ans == b / a || ans == d / c;
    
    return ans;
}
