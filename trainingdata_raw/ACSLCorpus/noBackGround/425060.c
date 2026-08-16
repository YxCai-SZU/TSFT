#include <limits.h>

/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures (1 <= (n) && (n) <= 10 && 1 <= (m) && (m) <= 10) ==> \result == n * m;
    ensures !(1 <= (n) && (n) <= 10 && 1 <= (m) && (m) <= 10) ==> \result == -1;
    assigns \nothing;
*/
int func(int n, int m) {
    int result;
    int i;
    
    if (1 <= n && n <= 10 && 1 <= m && m <= 10) {
        i = 0;
        /*@
            loop invariant 0 <= i <= n;
            loop invariant 1 <= n <= 20;
            loop invariant 1 <= m <= 20;
            loop assigns i;
            loop variant n - i;
        */
        while (i < n) {
            i = i + 1;
        }
        //@ assert (1 <= (n) && (n) <= 10 && 1 <= (m) && (m) <= 10);
        //@ assert 1 <= n * m <= 100;
        result = n * m;
    } else {
        i = 0;
        /*@
            loop invariant 0 <= i <= m;
            loop invariant 1 <= n <= 20;
            loop invariant 1 <= m <= 20;
            loop assigns i;
            loop variant m - i;
        */
        while (i < m) {
            i = i + 1;
        }
        result = -1;
    }
    return result;
}
