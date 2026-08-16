#include <stdint.h>
#include <stddef.h>

/*@
    requires ((N) > 0 && (N) <= 200000 &&
        \valid((A) + (0 .. (N)-1)) &&
        \forall integer i; 0 <= i < (N) ==> 1 <= (A)[i] <= 1000000000);
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(size_t N, uint64_t *A) {
    int64_t ans = 0;
    uint64_t prev_height = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= N;
        loop invariant 0 <= ans <= ((i) * 1000000000);
        loop invariant prev_height <= 1000000000;
        loop invariant \forall integer j; 0 <= j < i ==> 1 <= A[j] <= 1000000000;
        loop invariant ((N) > 0 && (N) <= 200000 &&
        \valid((A) + (0 .. (N)-1)) &&
        \forall integer i; 0 <= i < (N) ==> 1 <= (A)[i] <= 1000000000);
        loop invariant i > 0 ==> ans >= 0;
        loop assigns ans, prev_height, i;
        loop variant N - i;
    */
    while (i < N) {
        uint64_t height = A[i];
        if (height < prev_height) {
            //@ assert prev_height - height <= 1000000000;
            ans += (int64_t)(prev_height - height);
        } else {
            prev_height = height;
        }
        i++;
    }
    return ans;
}
