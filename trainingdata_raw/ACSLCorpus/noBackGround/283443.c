#include <stdbool.h>
#include <stdint.h>

/*@
    requires x == 0xFF;
    ensures \result == true;
*/
bool test_all_bits_set_impl(uint8_t x) {
    //@ assert x == 0xFF;
    
    bool result;
    result = true;
    
    return result;
}

int main() {
    uint8_t x;
    x = 0xFF;
    
    bool check;
    check = test_all_bits_set_impl(x);
    
    return 0;
}
