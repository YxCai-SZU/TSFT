#include <stdbool.h>
#include <stddef.h>

/*@ requires 1 <= k <= 500;
    requires \valid(heights + (0..4));
    requires ((5) == 5 &&
      \forall integer i; 0 <= i < (5) ==> 0 <= (heights)[i] && (heights)[i] <= 500);
    assigns \nothing;
    ensures 0 <= \result <= 5;
*/
int func(int k, int *heights) {
    int count = 0;
    size_t index = 0;
    size_t len = 5;

    /*@ loop invariant (1 <= (k) <= 500 &&
      (((len)) == 5 &&
      \forall integer i; 0 <= i < ((len)) ==> 0 <= ((heights))[i] && ((heights))[i] <= 500) &&
      0 <= (index) <= (len) &&
      0 <= (count) <= (index) &&
      (count) <= 5);
        loop assigns count, index;
        loop variant len - index;
    */
    while (index < len) {
        int h = heights[index];
        if (h >= k) {
            count += 1;
        }
        index += 1;
        //@ assert (1 <= (k) <= 500 &&       (((len)) == 5 &&       \forall integer i; 0 <= i < ((len)) ==> 0 <= ((heights))[i] && ((heights))[i] <= 500) &&       0 <= (index) <= (len) &&       0 <= (count) <= (index) &&       (count) <= 5);
    }
    //@ assert count <= 5;
    return count;
}
