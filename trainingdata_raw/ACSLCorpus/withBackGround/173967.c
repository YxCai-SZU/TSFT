#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bound:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> product(a, b) <= 100000000;
*/

/*@
    requires valid_range(A) && valid_range(B) && valid_range(C) && valid_range(D);
    ensures \result == product(A, B) || \result == product(C, D);
    ensures \result >= product(A, B);
    ensures \result >= product(C, D);
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t B, int64_t C, int64_t D)
{
    // Variable declarations at scope top
    int64_t max_value;
    int64_t ab_product;
    int64_t cd_product;

    // Precondition verification
    //@ assert valid_range(A);
    //@ assert valid_range(B);
    //@ assert valid_range(C);
    //@ assert valid_range(D);

    // Calculate products
    ab_product = A * B;
    cd_product = C * D;

    // Apply product_bound lemma
    //@ assert product(A, B) <= 100000000;
    //@ assert product(C, D) <= 100000000;

    // Determine maximum
    if (ab_product > cd_product) {
        max_value = ab_product;
        //@ assert max_value == product(A, B);
        //@ assert max_value >= product(C, D);
    } else {
        max_value = cd_product;
        //@ assert max_value == product(C, D);
        //@ assert max_value >= product(A, B);
    }

    // Final verification
    //@ assert max_value == product(A, B) || max_value == product(C, D);
    //@ assert max_value >= product(A, B);
    //@ assert max_value >= product(C, D);

    return max_value;
}
