#include <stdbool.h>
#include <stdint.h>

/*@
    requires 0 <= len && len < 0x80000000;
    ensures \result == (len % 2 == 0);
    assigns \nothing;
*/
bool is_even_length_c(uint32_t len) {
    bool result;
    //@ assert 0 <= len && len < 0x80000000;
    result = (len % 2 == 0);
    return result;
}
