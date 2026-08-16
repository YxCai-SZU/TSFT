#include <stdint.h>
#include <stddef.h>

/*@ requires N >= 1 && N <= 200000;
    requires \valid_read(numbers + (0 .. N-1));
    requires ((N) >= 1 && (N) <= 200000 &&
      \forall size_t i; 0 <= i < (N) ==> 1 <= ((uint64_t*)numbers)[i] && ((uint64_t*)numbers)[i] <= 1000000);
    assigns \nothing;
    ensures 0 <= \result <= N;
*/
uint64_t func(size_t N, const uint64_t* numbers) {
    uint64_t ok_cnt = 0;
    uint64_t ng_cnt = 0;
    size_t i = 0;

    /*@ loop invariant 0 <= i <= N;
        loop invariant ok_cnt >= 0;
        loop invariant ng_cnt >= 0;
        loop invariant ok_cnt + ng_cnt == i;
        loop invariant ((N) >= 1 && (N) <= 200000 &&
      \forall size_t i; 0 <= i < (N) ==> 1 <= ((uint64_t*)numbers)[i] && ((uint64_t*)numbers)[i] <= 1000000);
        loop assigns i, ok_cnt, ng_cnt;
        loop variant N - i;
    */
    while (i < N) {
        uint64_t a = numbers[i];
        if (a % 2 == 0) {
            ng_cnt += 1;
        } else {
            ok_cnt += 1;
        }
        i += 1;
    }

    uint64_t ans = (ok_cnt * 2 > ng_cnt) ? ng_cnt : ok_cnt;
    //@ assert ans >= 0;
    //@ assert ans <= N;
    return ans;
}
