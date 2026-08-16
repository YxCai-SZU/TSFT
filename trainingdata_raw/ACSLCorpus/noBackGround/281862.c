#include <limits.h>

/*@
    requires 0 <= x <= 1;
    ensures (x == 0 ==> \result == 1) && (x == 1 ==> \result == 0);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    //@ assert ((x) == 0 || (x) == 1);
    if (x == 0) {
        result = 1;
    } else {
        result = 0;
    }
    //@ assert (x == 0 && result == 1) || (x == 1 && result == 0);
    return result;
}

/*@
    requires a >= 0 && b >= 0 && c >= 0;
    requires 1 <= k <= a + b + c;
    ensures \result <= k;
    assigns \nothing;
*/
int func2(int a, int b, int c, int k)
{
    int cnt;
    int rst;
    int min_val;
    
    cnt = 0;
    rst = k;
    
    min_val = (a < rst) ? a : rst;
    cnt += min_val;
    rst -= min_val;
    
    min_val = (b < rst) ? b : rst;
    rst -= min_val;
    
    min_val = (c < rst) ? c : rst;
    rst -= min_val;
    
    cnt -= rst;
    
    //@ assert cnt <= k;
    return cnt;
}
