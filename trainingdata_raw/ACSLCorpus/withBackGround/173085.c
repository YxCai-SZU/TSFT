#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_array(int *a, integer n) =
        n >= 2 && n <= 100 &&
        \valid(a + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 100;

    logic integer min_value(integer p, integer i) =
        p < i ? p : i;
*/

/*@
    requires valid_array(a, n);
    ensures \result >= 0 && \result <= 1000;
    assigns \nothing;
*/
int func(size_t n, int *a) {
    int p = 1000;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant p >= 0 && p <= 1000;
        loop invariant \forall integer j; 0 <= j < index ==> p <= a[j];
        loop assigns p, index;
        loop variant n - index;
    */
    while (index < n) {
        int i = a[index];
        //@ assert i >= 1 && i <= 100;
        p = p < i ? p : i;
        index++;
    }
    int ans = p;
    //@ assert ans >= 0 && ans <= 1000;
    return ans;
}
