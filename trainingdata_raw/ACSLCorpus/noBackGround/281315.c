#include <stdint.h>

/*@ requires (2 <= (a) && (a) <= 100) && (2 <= (b) && (b) <= 100);
    assigns \nothing;
    ensures \result == (((a) - 1) * ((b) - 1));
    ensures 1 <= \result <= 9801;
 */
int32_t func(int32_t a, int32_t b) {
    int32_t result;
    
    //@ assert 1 <= a - 1 && a - 1 <= 99;
    //@ assert 1 <= b - 1 && b - 1 <= 99;
    
    result = (a - 1) * (b - 1);
    
    //@ assert result == (((a) - 1) * ((b) - 1));
    
    return result;
}

/*@ requires \valid(input + (0..len-1));
    assigns \nothing;
    ensures \result == input;
    ensures \forall integer i; 0 <= i < len ==> \result[i] == input[i];
 */
int32_t* procon_read(int32_t* input, int32_t len) {
    return input;
}

/*@ assigns \nothing;
 */
int main() {
    return 0;
}
