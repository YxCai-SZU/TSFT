#include <stdbool.h>

/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures (((n) == 10 && (m) == 10) ==> \result == 0);
    ensures ((!((n) == 10 && (m) == 10)) ==> \result == 1);
*/
int func(int n, int m)
{
    int result;
    //@ assert 1 <= n <= 20;
    //@ assert 1 <= m <= 20;
    
    if (n == 10 && m == 10) {
        //@ assert ((n) == 10 && (m) == 10);
        result = 0;
    } else {
        //@ assert (!((n) == 10 && (m) == 10));
        result = 1;
    }
    
    return result;
}
