#include <stddef.h>
#include <stdbool.h>

/*@ predicate heights_valid(size_t *heights, integer len) =
    len == 5 &&
    \forall integer i; 0 <= i < len ==> 1 <= heights[i] && heights[i] <= 500;
*/

/*@
    requires 1 <= k <= 500;
    requires \valid(heights + (0 .. 4));
    requires heights_valid(heights, 5);
    assigns \nothing;
    ensures \result <= 5;
*/
size_t func(size_t k, size_t *heights) {
    size_t ans = 0;
    size_t index = 0;
    size_t len = 5;
    
    /*@
        loop invariant 0 <= index <= len;
        loop invariant ans <= index;
        loop assigns ans, index;
        loop variant len - index;
    */
    while (index < len) {
        size_t h = heights[index];
        if (h >= k) {
            ans = ans + 1;
        }
        index = index + 1;
    }
    
    //@ assert ans <= len;
    return ans;
}
