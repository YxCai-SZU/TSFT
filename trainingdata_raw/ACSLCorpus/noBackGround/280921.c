#include <stdbool.h>

/*@
    requires n >= 1 && n <= 200;
    requires \valid(a + (0..n-1));
    requires (\forall integer j; 0 <= j < (n) ==> 1 <= (a)[j] <= 1000000);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n, int *a) {
    int w = 0;
    int i = 0;
    
    /*@
        loop invariant (0 <= (i) <= (n) &&
    (w) >= 0 &&
    (w) <= (i) &&
    (\forall integer j; 0 <= j < ((n)) ==> 1 <= ((a))[j] <= 1000000));
        loop assigns w, i;
        loop variant n - i;
    */
    while (i < n) {
        int v = a[i];
        //@ assert 1 <= v <= 1000000;
        
        if ((v & 1) == 1 || ((v >> 1) & 1) == 1) {
            w += 1;
        }
        //@ assert w <= i + 1;
        i += 1;
    }
    //@ assert w <= n;
    return w;
}
