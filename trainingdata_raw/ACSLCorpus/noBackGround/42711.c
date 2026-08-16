#include <stdint.h>
#include <stdbool.h>

/*@
    requires N >= 1 && N <= 1000000;
    requires \valid(input_vec + (0 .. N-1));
    requires ((N) >= 1 && (N) <= 1000000 &&
        \forall integer i; 0 <= i < (N) ==> (input_vec)[i] >= 1 && (input_vec)[i] <= 1000000000);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= ((N) * 1000000000);
*/
int64_t func(int64_t N, int64_t *input_vec) {
    int64_t ans = 0;
    int64_t i = 0;
    int64_t pos = 0;

    /*@
        loop invariant 0 <= i <= N;
        loop invariant 0 <= pos <= i;
        loop invariant ans >= 0;
        loop invariant ans <= ((i) * 1000000000);
        loop invariant \forall integer j; 0 <= j < i ==> input_vec[j] >= 1 && input_vec[j] <= 1000000000;
        loop invariant ((N) >= 1 && (N) <= 1000000 &&
        \forall integer i; 0 <= i < (N) ==> (input_vec)[i] >= 1 && (input_vec)[i] <= 1000000000);
        loop assigns i, pos, ans;
        loop variant N - i;
    */
    while (i < N) {
        int64_t value = input_vec[i];
        if (value >= 0) {
            pos += 1;
        } else {
            ans += pos;
        }
        i += 1;
    }
    return ans;
}
