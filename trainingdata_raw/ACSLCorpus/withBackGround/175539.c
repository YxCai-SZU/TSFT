#include <stdint.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= 100 && n * m <= 9223372036854775807;

    logic integer product(integer n, integer m) = n * m;

    lemma product_positive: \forall integer n, m; valid_params(n, m) ==> product(n, m) >= 1;
*/

/*@
    requires valid_params(n, m);
    ensures \result == product(n, m);
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m) {
    // Variable declarations
    int64_t result;
    
    // Precondition assertions
    //@ assert 1 <= n <= 100;
    //@ assert 1 <= m <= 100;
    //@ assert n * m <= 9223372036854775807;
    //@ assert n * m >= 1;
    
    result = n * m;
    
    /*@
        loop invariant valid_params(n, m);
        loop invariant result == product(n, m);
        loop invariant result >= 1;
        loop assigns \nothing;
    */
    while (result < 0) {
        // Loop body is unreachable due to invariants
    }
    
    // Postcondition verification
    //@ assert result == product(n, m);
    
    return result;
}

int main() {
    return 0;
}
