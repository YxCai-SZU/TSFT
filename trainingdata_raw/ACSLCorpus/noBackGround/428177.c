#include <stdint.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures \result == (x / 500) * 1000 + ((x % 500) / 5) * 5;
*/
int64_t func(int64_t x) {
    int64_t result = 0;
    int64_t temp_x = x;
    int64_t div_500 = 0;
    int64_t modulo_500 = 0;
    int64_t div_5 = 0;
    
    //@ assert temp_x == x;
    
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant div_500 * 500 + temp_x == x;
        loop invariant (0 <= (x) <= 1000000000);
        loop assigns temp_x, div_500;
        loop variant temp_x;
    */
    while (temp_x >= 500) {
        temp_x -= 500;
        div_500 += 1;
    }
    
    modulo_500 = temp_x;
    
    /*@
        loop invariant 0 <= modulo_500 <= ((x) % 500);
        loop invariant div_5 * 5 + modulo_500 == ((x) % 500);
        loop assigns modulo_500, div_5;
        loop variant modulo_500;
    */
    while (modulo_500 >= 5) {
        modulo_500 -= 5;
        div_5 += 1;
    }
    
    result = div_500 * 1000 + div_5 * 5;
    return result;
}

int main() {
    return 0;
}
