#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer compute_aa_mod(integer a) = (a * 1000) % 500;
    logic integer compute_bb_mod(integer b) = (b * 10) % 500;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    ensures \result == (compute_aa_mod(a) <= compute_bb_mod(b));
*/
bool func(unsigned int a, unsigned int b) {
    unsigned int aa;
    unsigned int bb;
    unsigned int aa_mod;
    unsigned int bb_mod;
    bool result;

    aa = a * 1000;
    bb = b * 10;
    aa_mod = aa % 500;
    bb_mod = bb % 500;

    //@ assert aa_mod == compute_aa_mod(a);
    //@ assert bb_mod == compute_bb_mod(b);

    if (aa_mod <= bb_mod) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == (compute_aa_mod(a) <= compute_bb_mod(b));
    return result;
}
