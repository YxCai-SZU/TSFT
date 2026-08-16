#include <stdint.h>
#include <stdbool.h>

/*@
    requires (1 <= (N) <= 200000);
    requires \valid(a + (0 .. N-1));
    requires (\forall integer i; 0 <= i < (N) ==> 1 <= (a)[i] <= 1000000);
    assigns \nothing;
    ensures 0 <= \result <= N;
*/
int32_t func(uint64_t N, const int64_t *a) {
    int32_t count = 0;
    uint64_t index = 0;
    int64_t num = 0;

    /*@
        loop invariant 0 <= index <= N;
        loop invariant 0 <= count <= index;
        loop invariant 0 <= num <= index;
        loop invariant (1 <= (N) <= 200000);
        loop invariant (\forall integer i; 0 <= i < (N) ==> 1 <= (a)[i] <= 1000000);
        loop assigns count, index, num;
        loop variant N - index;
    */
    while (index < N) {
        //@ assert 0 <= index < N;
        if (num < (int64_t)N && (a[index] & 1) == 1) {
            num += 1;
            count += 1;
        }
        index += 1;
    }
    return count;
}
