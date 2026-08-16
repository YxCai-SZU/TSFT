#include <stddef.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (p) <= 100);
    ensures \result <= (a * 3 + p) / 2;
    assigns \nothing;
*/
size_t func(size_t a, size_t p) {
    size_t total_pieces;
    size_t pies;

    total_pieces = a * 3 + p;

    //@ assert total_pieces == a * 3 + p;
    //@ assert total_pieces / 2 <= (a * 3 + p) / 2;

    pies = total_pieces / 2;
    return pies;
}
