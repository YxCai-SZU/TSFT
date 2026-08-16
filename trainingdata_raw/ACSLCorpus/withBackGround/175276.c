#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_even(integer n) = n % 2 == 0; */
/*@ predicate is_odd(integer n) = n % 2 != 0; */

/*@ lemma len_bounds: \forall size_t len; len < 0x80000000 ==> len >= 0; */

/*@
    requires len < 0x80000000;
    ensures \result == (len % 2 == 0);
    assigns \nothing;
*/
bool is_even_length(size_t len) {
    //@ assert len < 0x80000000;
    return len % 2 == 0;
}

/*@
    requires len < 0x80000000;
    ensures \result == (len % 2 != 0);
    assigns \nothing;
*/
bool is_odd_length(size_t len) {
    //@ assert len < 0x80000000;
    return len % 2 != 0;
}
