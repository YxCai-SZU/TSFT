#include <stdint.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result == (l * l * l) / 27;
*/
int32_t func(int32_t l) {
    // Variable declarations at scope top
    int32_t l_cubed;
    int32_t result;
    int32_t remainder;
    int32_t divisor;
    int32_t final_result;
    int32_t final_remainder;
    
    // Precondition verification
    //@ assert (1 <= (l) <= 1000);
    
    // Calculate l^3 with bounds checking
    //@ assert 0 < l * l * l <= 1000000000;
    l_cubed = l * l * l;
    
    // Division by 27 using repeated subtraction
    result = 0;
    remainder = l_cubed;
    divisor = 27;
    
    /*@
        loop invariant 1 <= l <= 1000;
        loop invariant l_cubed == l * l * l;
        loop invariant result * 27 + remainder == l_cubed;
        loop invariant 0 <= remainder;
        loop invariant l * l * l <= 1000000000;
        loop assigns remainder, result;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        remainder -= divisor;
        result += 1;
    }
    
    // Final division check
    if (remainder == 0) {
        //@ assert result * 27 == l_cubed;
        return result;
    } else {
        final_result = result;
        final_remainder = remainder;
        
        /*@
            loop invariant 1 <= l <= 1000;
            loop invariant l_cubed == l * l * l;
            loop invariant final_result * 27 + final_remainder == l_cubed;
            loop invariant 0 <= final_remainder;
            loop invariant l * l * l <= 1000000000;
            loop assigns final_remainder, final_result;
            loop variant final_remainder;
        */
        while (final_remainder >= divisor) {
            final_remainder -= divisor;
            final_result += 1;
        }
        
        //@ assert final_result * 27 + final_remainder == l_cubed;
        //@ assert final_remainder < divisor;
        return final_result;
    }
}

int main() {
    return 0;
}
