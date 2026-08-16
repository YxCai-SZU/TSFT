#include <stdint.h>
#include <limits.h>

/*@ requires len1 < 0x80000000;
    requires len2 < 0x80000000;
    assigns \nothing;
    ensures \result <= len1;
    ensures \result <= len2;
    ensures \result == len1 || \result == len2;
*/
uint32_t min_length(uint32_t *list1, uint32_t len1,
                    uint32_t *list2, uint32_t len2) {
    // Variable declarations at scope top
    uint32_t min_val;
    uint32_t temp_len1;
    uint32_t temp_len2;

    // Main logic
    temp_len1 = len1;
    temp_len2 = len2;
    if (temp_len1 < temp_len2) {
        min_val = temp_len1;
    } else {
        min_val = temp_len2;
    }

    return min_val;
}
