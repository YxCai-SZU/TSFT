#include <stdint.h>

/*@
    predicate valid_range(integer a) = 1 <= a <= 10;

    logic integer compute_result(integer a) = a + a * a + a * a * a;

    lemma result_bounds: 
        \forall integer a; valid_range(a) ==> 1 <= compute_result(a) <= 1331;
*/

/*@
    requires valid_range(a);
    ensures \result == compute_result(a);
    assigns \nothing;
*/
int64_t func(int64_t a) {
    // Variable declarations at top
    int64_t result;
    
    //@ assert valid_range(a);
    //@ assert 1 <= compute_result(a) && compute_result(a) <= 1331;
    
    result = a + a * a + a * a * a;
    
    //@ assert result == compute_result(a);
    return result;
}

int main() {
    return 0;
}
