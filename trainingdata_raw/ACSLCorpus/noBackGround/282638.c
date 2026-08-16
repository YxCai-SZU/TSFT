#include <stddef.h>
#include <stdbool.h>

/*@
    requires (1 <= (N) &&
        1 <= (K) <= 500 &&
        \valid((h)+(0..(N)-1)) &&
        \forall integer j; 0 <= j < (N) ==> 1 <= (h)[j] && (h)[j] <= 500);
    ensures \result <= N;
    assigns \nothing;
*/
size_t func(size_t N, size_t K, int *h) {
    size_t count = 0;
    size_t i = 0;

    /*@
        loop invariant (0 <= (i) <= (N) &&
        (count) <= (i) &&
        (1 <= ((N)) &&
        1 <= ((K)) <= 500 &&
        \valid(((h))+(0..((N))-1)) &&
        \forall integer j; 0 <= j < ((N)) ==> 1 <= ((h))[j] && ((h))[j] <= 500));
        loop assigns i, count;
        loop variant N - i;
    */
    while (i < N) {
        //@ assert 0 <= i < N;
        if (h[i] >= (int)K) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
