#include <stdbool.h>

/*@
    predicate non_negative(integer a, integer b, integer c) =
        a >= 0 && b >= 0 && c >= 0;
    
    predicate valid_k(integer a, integer b, integer c, integer k) =
        1 <= k && k <= a + b + c;
*/

/*@
    requires non_negative(a, b, c);
    requires valid_k(a, b, c, k);
    ensures \result <= k;
*/
int func(int a, int b, int c, int k)
{
    int cnt;
    int rst;
    
    cnt = 0;
    rst = k;
    
    //@ assert cnt <= k;
    
    if (a >= rst) {
        cnt += rst;
        rst -= rst;
    } else {
        cnt += a;
        rst -= a;
    }
    
    //@ assert cnt <= k;
    
    if (rst != 0) {
        if (b >= rst) {
            rst -= rst;
        } else {
            rst -= b;
        }
    }
    
    //@ assert cnt <= k;
    
    cnt -= rst;
    
    //@ assert cnt <= k;
    
    return cnt;
}
