#include <stdbool.h>

/*@
    requires (1 <= (x) <= 1000000);
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> x % 100 <= 5 * (x / 100);
    ensures \result == 1 ==> x % 100 > 5 * (x / 100);
*/
int func(int x) {
    int n;
    int q;
    int r;
    int result;
    
    n = x;
    q = 0;
    r = 0;
    result = 0;
    
    /*@
        loop invariant 1 <= x <= 1000000;
        loop invariant 0 <= q;
        loop invariant 0 <= n;
        loop invariant n == x - 100 * q;
        loop assigns n, q;
        loop variant n;
    */
    while (n >= 100) {
        //@ assert n >= 100;
        n = n - 100;
        q = q + 1;
    }
    
    r = n;
    
    //@ assert r == x % 100;
    //@ assert q == x / 100;
    
    if (r > 5 * q) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert result == 0 ==> r <= 5 * q;
    //@ assert result == 1 ==> r > 5 * q;
    
    return result;
}
