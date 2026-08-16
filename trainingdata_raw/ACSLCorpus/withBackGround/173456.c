#include <stdint.h>

/*@
    predicate valid_input(integer A, integer B) =
        1 <= A && A <= 100 &&
        1 <= B && B <= 100 &&
        A * B <= 1000000000;

    logic integer safe_product(integer A, integer B) = A * B;

    lemma product_bound: \forall integer A, B;
        valid_input(A, B) ==> safe_product(A, B) >= -1;
*/

/*@
    requires valid_input(A, B);
    ensures \result == safe_product(A, B) || \result == -1;
    ensures \result >= -1;
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t B)
{
    // Variable declarations at scope top
    int64_t C;

    //@ assert valid_input(A, B);
    //@ assert safe_product(A, B) >= -1;

    C = A * B;
    
    if (C > 1000000000) {
        return -1;
    } else {
        return C;
    }
}
