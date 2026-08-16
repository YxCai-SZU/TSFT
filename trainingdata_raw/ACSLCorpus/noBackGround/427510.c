#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n));
    ensures \result == (n == m);
*/
bool func(long n, long m) {
    long i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant (1 <= (n) <= 100 && 0 <= (m) <= (n));
        loop assigns i;
    */
    while (i < n) {
        i = i + 1;
    }
    
    //@ assert i == n;
    return i == m;
}
