#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100;

    logic integer func_result(integer a, integer b) =
        (a + b) % 2 == 0 ?
        a + b / 2 :
        a + b / 2 + 1;

    lemma result_bound: \forall integer a, b;
        valid_input(a, b) ==> 
        func_result(a, b) <= a + b + 1 && 
        func_result(a, b) >= 0;
*/

/*@
    requires valid_input(a, b);
    ensures \result == func_result(a, b);
    ensures \result <= a + b + 1;
    ensures \result >= 0;
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t result;
    
    //@ assert valid_input(a, b);
    
    if ((a + b) % 2 == 0) {
        result = a + b / 2;
    } else {
        //@ assert a + b / 2 + 1 <= a + b + 1;
        result = a + b / 2 + 1;
    }
    
    //@ assert result == func_result(a, b);
    //@ assert result <= a + b + 1;
    //@ assert result >= 0;
    
    return result;
}
