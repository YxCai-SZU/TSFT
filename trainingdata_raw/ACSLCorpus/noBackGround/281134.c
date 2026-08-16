#include <stddef.h>
#include <stdint.h>

/*@
    requires ((N) >= 1 && (N) <= 100000 &&
        \valid((a) + (0 .. (N)-1)) &&
        \forall integer j; 0 <= j < (N) ==> (a)[j] >= 1 && (a)[j] <= 1000000000);
    ensures 0 <= \result <= N;
    assigns \nothing;
*/
size_t func(size_t N, const int64_t *a) {
    size_t n = 0;
    size_t i = 0;

    /*@
        loop invariant ((i) <= (N) &&
        (n) <= (i) &&
        (((N)) >= 1 && ((N)) <= 100000 &&
        \valid(((a)) + (0 .. ((N))-1)) &&
        \forall integer j; 0 <= j < ((N)) ==> ((a))[j] >= 1 && ((a))[j] <= 1000000000));
        loop invariant 0 <= i <= N;
        loop invariant 0 <= n <= i;
        loop assigns i, n;
        loop variant N - i;
    */
    while (i < N) {
        //@ assert i < N && i >= 0;
        if (i % 2 == 0 && a[i] % 2 == 1) {
            n += 1;
        }
        i += 1;
    }
    return n;
}
