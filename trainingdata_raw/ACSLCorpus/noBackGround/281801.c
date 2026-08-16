#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(arr + (0..len-1));
    requires len >= 0;
    assigns \nothing;
    ensures \result == (len % 2 != 0);
*/
bool has_odd_num_elements(int *arr, size_t len) {
    //@ assert len >= 0;
    return len % 2 != 0;
}
