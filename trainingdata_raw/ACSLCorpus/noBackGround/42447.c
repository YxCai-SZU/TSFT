#include <stddef.h>

/*@
    requires \valid_read(hs + (0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result >= 1;
    ensures \result <= len;
*/
size_t func(const size_t *hs, size_t len) {
    size_t max = 0;
    size_t count = 1;
    size_t index = 0;

    /*@
        loop invariant ((index) < (len));
        loop invariant ((count) >= 1 && (count) <= (index) + 1);
        loop invariant ((max) <= (index) + 1);
        loop assigns index, count, max;
        loop variant len - index;
    */
    while (index < len - 1) {
        size_t current = hs[index];
        size_t next = hs[index + 1];

        if (current <= next) {
            count += 1;
        } else {
            max = (max > count) ? max : count;
            count = 1;
        }
        index += 1;
    }

    max = (max > count) ? max : count;
    return max;
}
