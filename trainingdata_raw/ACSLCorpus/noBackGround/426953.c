#include <stdbool.h>

/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures \result >= 0;
    ensures (m >= n && \result == 0) || (m < n && \result == n - m);
*/
int func(int n, int m)
{
    int result;
    //@ assert 1 <= n <= 20 && 1 <= m <= 20;
    
    if (m >= n) {
        result = 0;
        //@ assert m >= n && result == 0;
    } else {
        result = n - m;
        //@ assert m < n && result == n - m;
    }
    
    //@ assert result >= 0;
    //@ assert (m >= n && result == 0) || (m < n && result == n - m);
    return result;
}
