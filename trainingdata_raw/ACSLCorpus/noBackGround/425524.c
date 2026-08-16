/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && 
             (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    ensures \result >= 0;
    ensures \result == a || \result == b || \result == c || \result == d;
    assigns \nothing;
*/
long func(long a, long b, long c, long d) {
    long min_ab;
    long min_cd;
    long ans;
    
    //@ assert (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000);
    //@ assert (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    
    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }
    
    if (c < d) {
        min_cd = c;
    } else {
        min_cd = d;
    }
    
    if (min_ab > min_cd) {
        ans = min_ab;
    } else {
        ans = min_cd;
    }
    
    //@ assert ans == a || ans == b || ans == c || ans == d;
    
    return ans;
}
