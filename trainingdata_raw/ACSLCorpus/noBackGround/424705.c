#include <stddef.h>
#include <stdbool.h>

/*@
    requires ((n) >= 2 && (n) <= 50 &&
        \valid((aa) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (aa)[i] >= 1 && (aa)[i] <= (n) &&
        \forall integer i; 0 <= i < (n)-1 ==> (aa)[i] != (aa)[i+1]);
    ensures \result >= 0 ==> \result < n;
    ensures \result >= 0 || \result == -1;
    assigns \nothing;
*/
int func(size_t n, const int *aa) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n-1;
        loop invariant count <= i;
        loop invariant count <= 2*i;
        loop invariant \valid(aa + (0 .. n-1));
        loop invariant \forall integer j; 0 <= j < n ==> aa[j] >= 1 && aa[j] <= n;
        loop invariant \forall integer j; 0 <= j < n-1 ==> aa[j] != aa[j+1];
        loop invariant n >= 2 && n <= 50;
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n - 1) {
        if (aa[i] != (int)(i + 1)) {
            count += 1;
        }
        i += 1;
    }
    
    if (aa[n - 1] != (int)n) {
        count += 1;
    }
    
    if (count <= 2) {
        //@ assert count <= 2;
        return 0;
    } else {
        return -1;
    }
}
