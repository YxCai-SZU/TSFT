#include <stdbool.h>
#include <stdint.h>

/*@ requires ((n) >= 1 && (n) <= 100000 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100000000000000000);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int32_t func(uint32_t n, const uint64_t *a) {
    int32_t count = 0;
    uint32_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop assigns index, count;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert index < n;
        if (index % 2 == 0 && a[index] % 2 == 1) {
            count = count + 1;
        }
        index = index + 1;
    }
    return count;
}
