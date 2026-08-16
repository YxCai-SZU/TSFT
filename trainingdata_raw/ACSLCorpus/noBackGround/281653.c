#include <stdbool.h>
#include <stdint.h>

/*@ requires n >= 1 && n <= 100;
    requires \valid(a_vec + (0 .. n-1));
    requires ((n) >= 1 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a_vec)[i] && (a_vec)[i] <= 100);
    assigns \nothing;
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result <= n;
*/
int32_t func(uint32_t n, uint32_t *a_vec) {
    uint32_t break_count = 0;
    uint32_t count = 0;
    uint32_t i = 0;

    /*@ loop invariant (0 <= (i) <= (n) &&
      0 <= (break_count) <= (i) &&
      0 <= (count) <= (i) &&
      \valid((a_vec) + (0 .. (n)-1)) &&
      \forall integer j; 0 <= j < (n) ==> 1 <= (a_vec)[j] && (a_vec)[j] <= 100);
        loop invariant i <= n;
        loop assigns i, break_count, count;
        loop variant n - i;
    */
    while (i < n) {
        uint32_t a = a_vec[i];

        if (a < count + 1) {
            break_count += 1;
        } else {
            count += 1;
        }

        i += 1;

        //@ assert i <= n;
    }

    if (count == 0) {
        return -1;
    } else {
        return (int32_t)count;
    }
}
