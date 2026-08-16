#include <stddef.h>

/*@
    requires \valid(l + (0 .. n-1));
    requires ((n) >= 1 && (n) <= 100 &&
    (x) >= 1 && (x) <= 10000 &&
    \valid((l) + (0 .. (n)-1)) &&
    \forall integer k; 0 <= k < (n) ==> (l)[k] >= 1 && (l)[k] <= 100);
    ensures \result >= 0 && \result <= n;
*/
size_t func(size_t n, int x, int *l) {
    int d = 0;
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant ((i) >= 0 && (i) <= (n) &&
    (d) >= 0 && (d) <= (x) + 100 &&
    (count) >= 0 && (count) <= (i) &&
    ((i) > 0 ==> \forall integer j; 0 <= j < (i) ==> (d) >= (l)[j]) &&
    (((n)) >= 1 && ((n)) <= 100 &&
    ((x)) >= 1 && ((x)) <= 10000 &&
    \valid(((l)) + (0 .. ((n))-1)) &&
    \forall integer k; 0 <= k < ((n)) ==> ((l))[k] >= 1 && ((l))[k] <= 100));
        loop assigns i, d, count;
        loop variant n - i;
    */
    while (i < n && d <= x) {
        //@ assert i < n && d <= x;
        count += 1;
        d += l[i];
        i += 1;
    }
    
    //@ assert count >= 0 && count <= n;
    return count;
}
