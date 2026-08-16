#include <stddef.h>

/*@
    predicate is_valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer compute_result(integer a, integer b) =
        a > b * 2 ? a - b * 2 : 0;

    lemma result_non_negative:
        \forall integer a, b;
            is_valid_range(a, b) ==> compute_result(a, b) >= 0;
*/

/*@
    requires is_valid_range(a, b);
    ensures \result == compute_result(a, b);
    ensures \result >= 0;
    assigns \nothing;
*/
size_t func(size_t a, size_t b) {
    size_t min_val;
    size_t result;

    min_val = a < b * 2 ? a : b * 2;
    
    if (a > b * 2) {
        //@ assert a > b * 2;
        //@ assert a - b * 2 >= 0;
        result = a - b * 2;
    } else {
        //@ assert 0 >= 0;
        result = 0;
    }
    
    return result;
}

int main() {
    return 0;
}
