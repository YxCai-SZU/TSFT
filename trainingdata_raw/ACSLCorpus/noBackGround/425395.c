#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

/*@ requires \valid(arr + (0..len-1));
    requires 0 <= len <= INT_MAX;
    assigns \nothing;
    ensures \result == (len >= 10);
 */
bool is_at_least_ten_elements(int32_t* arr, int32_t len) {
    //@ assert 0 <= len <= INT_MAX;
    return len >= 10;
}

/*@ requires \valid(arr + (0..len-1));
    requires 0 <= len <= INT_MAX;
    assigns \nothing;
    ensures \result == (len >= 10);
 */
bool is_at_least_ten_elements_safe(int32_t* arr, int32_t len) {
    //@ assert 0 <= len <= INT_MAX;
    return len >= 10;
}

/*@ requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == a - 2 * b || \result == 0;
 */
int32_t func(int32_t a, int32_t b) {
    int32_t result;
    result = a - 2 * b;
    if (result > 0) {
        //@ assert result == a - 2 * b;
        return result;
    } else {
        //@ assert result <= 0;
        return 0;
    }
}
