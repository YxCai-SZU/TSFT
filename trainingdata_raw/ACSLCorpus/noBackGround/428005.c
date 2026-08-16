#include <stdint.h>
#include <stdbool.h>

/*@
    requires ((n) > 0 && (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000000000);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int32_t func(uint64_t n, int64_t *a) {
    int32_t count = 0;
    int32_t count1 = 0;
    uint64_t index = 0;

    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= (int32_t)index;
        loop invariant 0 <= count1 <= (int32_t)index;
        loop invariant \forall integer i; 0 <= i < index ==> a[i] > 0 && a[i] <= 1000000000;
        loop invariant n > 0 && n <= 200000;
        loop assigns index, count, count1;
        loop variant n - index;
    */
    while (index < n) {
        int64_t value = a[index];
        if (value & 1) {
            count++;
        } else {
            count1++;
        }
        index++;
    }

    if (count1 & 1) {
        count1++;
    }

    int32_t min_count = count < count1 ? count : count1;

    //@ assert min_count >= 0;
    //@ assert min_count <= (int32_t)n;

    return min_count;
}
