#include <stddef.h>
#include <stdint.h>

/*@ requires ((N) >= 1 && (N) <= 200000 &&
      \valid((vec) + (0 .. (N)-1)) &&
      \forall integer i; 0 <= i < (N) ==> 1 <= (vec)[i] && (vec)[i] <= (N));
    assigns \nothing;
    ensures \result >= -1 && \result <= (int64_t)N;
*/
int64_t func(size_t N, int64_t *vec) {
    size_t tmp = 0;
    size_t index = 0;

    /*@ loop invariant ((index) <= (N) && (tmp) <= (index));
        loop invariant index <= N && tmp <= index;
        loop assigns tmp, index;
        loop variant N - index;
    */
    while (index < N) {
        int64_t i = vec[index];
        //@ assert 1 <= i && i <= N;
        if (i == (int64_t)(tmp + 1)) {
            tmp += 1;
        }
        index += 1;
    }

    if (tmp == 0) {
        return -1;
    } else {
        return (int64_t)(N - tmp);
    }
}
