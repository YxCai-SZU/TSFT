#include <stdbool.h>
#include <stddef.h>

/*@
    requires k > 0;
    requires \valid(heights + (0 .. len-1));
    requires ((len) >= 1 && (len) <= 100000 &&
        \forall size_t i; 0 <= i < (len) ==> 1 <= (heights)[i] && (heights)[i] <= 500);
    assigns \nothing;
    ensures \result >= 0 && \result <= len;
*/
unsigned int func(unsigned int k, unsigned int *heights, size_t len) {
    unsigned int ans = 0;
    size_t index = 0;

    /*@
        loop invariant (0 <= (index) && (index) <= (len) &&
        0 <= (ans) && (ans) <= (index) &&
        (k) > 0 &&
        (((len)) >= 1 && ((len)) <= 100000 &&
        \forall size_t i; 0 <= i < ((len)) ==> 1 <= ((heights))[i] && ((heights))[i] <= 500) &&
        (ans) <= (len) &&
        (index) <= (len));
        loop assigns ans, index;
        loop variant len - index;
    */
    while (index < len) {
        unsigned int h = heights[index];
        if (h >= k) {
            ans += 1;
        }
        index += 1;
    }

    //@ assert ans <= len;
    return ans;
}
