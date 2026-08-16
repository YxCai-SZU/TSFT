#include <stdint.h>

/*@
  requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
  ensures \result == a * b;
  assigns \nothing;
*/
int32_t func(int32_t a, int32_t b) {
    // Declare all variables at scope top
    int32_t ans;
    
    //@ assert 1 <= a * b && a * b <= 100 * 100;
    
    ans = a * b;
    return ans;
}

/*@
  assigns \nothing;
  ensures \result == input;
*/
int32_t* procon_read(int32_t* input, int length) {
    // Declare all variables at scope top
    int32_t* result;
    
    result = input;
    return result;
}
