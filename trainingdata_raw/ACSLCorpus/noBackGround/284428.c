#include <stdbool.h>

/*@
    requires ((1 <= ((n)) <= 100) && (1 <= ((m)) <= 100));
    ensures \result >= 0;
    ensures \result <= n;
    ensures \result <= m;
    ensures n < m ==> \result == n;
    ensures n >= m ==> \result == m;
*/
int func(int n, int m) {
    int result;
    
    //@ assert ((1 <= ((n)) <= 100) && (1 <= ((m)) <= 100));
    
    if (n < m) {
        //@ assert n < m;
        result = n;
    } else {
        //@ assert n >= m;
        result = m;
    }
    
    //@ assert result >= 0;
    //@ assert result <= n;
    //@ assert result <= m;
    //@ assert (n < m ==> result == n) && (n >= m ==> result == m);
    
    return result;
}

