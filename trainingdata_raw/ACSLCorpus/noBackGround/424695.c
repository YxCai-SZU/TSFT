#include <stddef.h>
#include <stdbool.h>

/*@
    requires ((N) >= 3 && (N) <= 100 &&
    \valid((a) + (0 .. (N)-1)) &&
    \forall integer j; 0 <= j < (N) ==> (a)[j] >= 1 && (a)[j] <= 100);
    ensures ((\result) >= 0 && (\result) <= (N));
    ensures ((N) >= 3 && (N) <= 100 &&
    \valid((a) + (0 .. (N)-1)) &&
    \forall integer j; 0 <= j < (N) ==> (a)[j] >= 1 && (a)[j] <= 100);
*/
size_t func(size_t N, int *a) {
    size_t count = 0;
    size_t i = 1;
    
    /*@
        loop invariant 1 <= i <= N-1;
        loop invariant count <= i-1;
        loop invariant ((N) >= 3 && (N) <= 100 &&
    \valid((a) + (0 .. (N)-1)) &&
    \forall integer j; 0 <= j < (N) ==> (a)[j] >= 1 && (a)[j] <= 100);
        loop assigns i, count;
        loop variant N - i;
    */
    while (i < N - 1) {
        //@ assert 0 <= i-1 < N && 0 <= i+1 < N;
        if (a[i - 1] != a[i + 1]) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
