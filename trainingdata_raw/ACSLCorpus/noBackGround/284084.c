#include <stddef.h>
#include <stdbool.h>

/*@
    requires 1 <= k <= 500;
    requires ((len) >= 1 && (len) <= 100000 &&
        \forall size_t i; 0 <= i < (len) ==> (heights)[i] >= 1 && (heights)[i] <= 500);
    assigns \nothing;
    ensures ((\result) <= (len));
    ensures (\forall size_t i; 0 <= i < (len) && (heights)[i] >= (k) ==> (\result) >= 1);
*/
size_t func(size_t k, int *heights, size_t len) {
    size_t ans = 0;
    size_t index = 0;

    /*@
        loop invariant index <= len;
        loop invariant ans <= index;
        loop invariant \forall size_t i; 0 <= i < index && heights[i] >= k ==> ans >= 1;
        loop assigns ans, index;
        loop variant len - index;
    */
    while (index < len) {
        //@ assert index < len;
        if (heights[index] >= k) {
            ans += 1;
        }
        index += 1;
    }
    return ans;
}
