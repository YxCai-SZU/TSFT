#include <stddef.h>
#include <stdint.h>

/*@
    requires len < 0x80000000;
    ensures \result == len + 1;
    assigns \nothing;
*/
size_t lemma_len_push(size_t len) {
    //@ assert len < 0x80000000;
    return len + 1;
}

/*@
    requires 0 <= i && i < len && len < 0x80000000;
    ensures \result == len;
    assigns \nothing;
*/
size_t lemma_len_update(size_t len, size_t i) {
    //@ assert 0 <= i && i < len;
    //@ assert len < 0x80000000;
    return len;
}

int main() {
    return 0;
}
