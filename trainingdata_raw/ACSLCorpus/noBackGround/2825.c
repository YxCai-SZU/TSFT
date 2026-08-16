#include <stdbool.h>
#include <stddef.h>

/*@
    requires len < 0x80000000;
    ensures \result == (len % 2 == 0);
    assigns \nothing;
*/
bool is_even_length_c(size_t len) {
    //@ assert len < 0x80000000;
    return len % 2 == 0;
}
