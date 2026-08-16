#include <stdint.h>

/*@
  requires (0 <= (x) <= 9) && (0 <= (a) <= 9);
  ensures (((x) < (a) ==> (\result) == 0) && ((x) >= (a) ==> (\result) == 10));
  assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t a) {
    uint32_t result;
    
    //@ assert (0 <= (x) <= 9);
    //@ assert (0 <= (a) <= 9);
    
    if (x < a) {
        result = 0;
    } else {
        result = 10;
    }
    
    //@ assert result == 0 || result == 10;
    //@ assert (x < a && result == 0) || (x >= a && result == 10);
    
    return result;
}

int main() {
    return 0;
}
