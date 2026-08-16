#include <stddef.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100000;

    logic integer compute_change(integer n) =
        (1000 - n % 1000) % 1000;

    lemma change_properties:
        \forall integer n;
            is_valid_n(n) ==>
            compute_change(n) >= 0 &&
            compute_change(n) < 1000;
*/

/*@
    requires is_valid_n(n);
    ensures \result >= 0;
    ensures \result < 1000;
    ensures \result == compute_change(n);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t r;
    size_t change;

    //@ assert is_valid_n(n);
    r = n % 1000;

    if (r == 0) {
        change = 0;
    } else {
        change = 1000 - r;
    }

    //@ assert change == compute_change(n);
    return change;
}
