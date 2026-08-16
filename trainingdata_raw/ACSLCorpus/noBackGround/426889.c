#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(arr + (0 .. len-1));
    assigns \nothing;
    ensures \result == (len % 2 == 0);
*/
bool is_even_length(int *arr, size_t len) {
    //@ assert len % 2 == 0 || len % 2 != 0;
    //@ assert len % 2 == 0 || len % 2 != 0;
    return len % 2 == 0;
}
