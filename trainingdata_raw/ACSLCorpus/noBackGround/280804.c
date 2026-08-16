#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(arr + (0..len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result == (len % 2 == 0);
*/
bool is_even(const int *arr, size_t len) {
    //@ assert len < 0x80000000;
    return (len % 2) == 0;
}
