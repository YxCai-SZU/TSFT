#include <stdbool.h>

/*@
    requires 1 <= n && n <= 20;
    requires 1 <= m && m <= 20;
    ensures \result == ((1 <= (n) && (n) <= 10 && 1 <= (m) && (m) <= 10) ? (n) * (m) : -1);
*/
int func(int n, int m)
{
    int result;
    
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= m && m <= 20;
    
    if (1 <= n && n <= 10 && 1 <= m && m <= 10) {
        //@ assert (1 <= (n) && (n) <= 10 && 1 <= (m) && (m) <= 10);
        result = n * m;
    } else {
        result = -1;
    }
    
    //@ assert result == ((1 <= (n) && (n) <= 10 && 1 <= (m) && (m) <= 10) ? (n) * (m) : -1);
    return result;
}
