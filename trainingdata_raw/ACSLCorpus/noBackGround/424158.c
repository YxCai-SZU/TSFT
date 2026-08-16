#include <stdbool.h>

/*@
    requires ((m) >= 0 && (m) <= 0xffffffff);
    ensures \result == ((m & 0xAAAAAAAA) == 0xAAAAAAAA || (m & 0xAAAAAAAA) != 0xAAAAAAAA);
*/
bool test_duplicate_consecutive_bits(unsigned int m) {
    // Variable declarations at top of scope
    unsigned int consecutive_bits;
    bool result;
    
    //@ assert ((m) >= 0 && (m) <= 0xffffffff);
    
    consecutive_bits = m & 0xAAAAAAAA;
    result = consecutive_bits == 0xAAAAAAAA || consecutive_bits != 0xAAAAAAAA;
    
    //@ assert result == ((m & 0xAAAAAAAA) == 0xAAAAAAAA || (m & 0xAAAAAAAA) != 0xAAAAAAAA);
    return result;
}

int main() {
    return 0;
}
