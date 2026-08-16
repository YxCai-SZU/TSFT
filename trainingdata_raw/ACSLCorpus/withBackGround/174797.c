#include <stdint.h>

/*@
    predicate is_less_than_0x10000000(integer x) = x < 0x10000000;
    predicate is_less_than_0x20000000(integer x) = x < 0x20000000;
    
    logic integer double_val(integer x) = x * 2;
    
    lemma double_bound: \forall integer x; is_less_than_0x10000000(x) ==> 
        double_val(x) < 0x20000000;
*/

/*@
    requires is_less_than_0x10000000(x);
    ensures \result == double_val(x);
    ensures is_less_than_0x20000000(\result);
*/
uint32_t func(uint32_t x) {
    uint32_t result;
    
    //@ assert x < 0x10000000;
    //@ assert double_val(x) < 0x20000000;
    
    result = x * 2;
    
    //@ assert result == double_val(x);
    //@ assert result < 0x20000000;
    
    return result;
}

int main() {
    return 0;
}
