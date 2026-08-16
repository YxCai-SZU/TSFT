/*@
    predicate is_within_range(integer len) = 0 <= len && len < 0x80000000;
    
    logic integer seq_len(integer s_len, integer i) = s_len + 1;
    
    lemma push_len_lemma: \forall integer s_len, integer i; 
        is_within_range(s_len) ==> seq_len(s_len, i) == s_len + 1;
*/

#include <stdint.h>

/*@
    requires is_within_range(s_len);
    ensures \result == s_len + 1;
    assigns \nothing;
*/
uint32_t example_push_len(uint32_t s_len, uint8_t i) {
    uint32_t result;
    
    //@ assert is_within_range(s_len);
    
    result = s_len + 1;
    
    //@ assert result == s_len + 1;
    
    return result;
}

int main() {
    return 0;
}
