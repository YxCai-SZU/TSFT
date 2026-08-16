#include <stdint.h>
#include <stdbool.h>

/*@
    requires \valid_read(m1+(0..size-1)) && \valid_read(m2+(0..size-1));
    requires (\forall integer i; 0 <= i < (size) ==> (m1)[i] == (m2)[i]);
    ensures (\forall integer i; 0 <= i < (size) ==> (m1)[i] == (m2)[i]);
    assigns \nothing;
*/
void check_equal_hash_map_element_wise(int *m1, int *m2, int size) {
    //@ assert (\forall integer i; 0 <= i < (size) ==> (m1)[i] == (m2)[i]);
}
