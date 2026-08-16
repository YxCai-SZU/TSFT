/*@
    requires 0 <= a && 0 <= b && 0 <= c;
    requires 1 <= k && k <= a + b + c;
    requires a + b + c <= 2000000000;
    ensures \result <= a + b + c;
*/
int func(int a, int b, int c, int k)
{
    int cnt;
    int rst;
    
    cnt = 0;
    rst = k;
    
    //@ assert ((a) >= 0 && (b) >= 0 && (c) >= 0);
    //@ assert (1 <= (k) && (k) <= (a) + (b) + (c));
    //@ assert ((a) + (b) + (c) <= 2000000000);
    
    if (a >= rst) {
        cnt += rst;
    } else {
        cnt += a;
        rst -= a;
    }
    
    //@ assert cnt <= ((a) + (b) + (c));
    
    rst -= (b < rst) ? b : rst;
    
    //@ assert cnt <= ((a) + (b) + (c));
    
    cnt -= (rst < 0) ? -rst : 0;
    
    //@ assert cnt <= ((a) + (b) + (c));
    //@ assert cnt <= a + b + c;
    
    return cnt;
}
