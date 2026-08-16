#include <stdint.h>

/*@
    predicate is_valid_x(integer x) = 101 <= x && x <= 100000000000000000;
    
    logic integer x_minus_100(integer x) = x - 100;
    
    lemma x_minus_100_bounds: 
        \forall integer x; is_valid_x(x) ==> 1 <= x_minus_100(x) <= 99999999999999900;
    
    lemma subtraction_safe:
        \forall integer x; is_valid_x(x) ==> x >= 100 && x_minus_100(x) <= 100000000000000000;
*/

/*@
    requires is_valid_x(x);
    ensures \result <= x - 100;
    ensures \result >= 0;
    assigns \nothing;
*/
uint64_t func(uint64_t x) {
    // Variable declarations at top of scope
    uint64_t x_minus_100;
    uint64_t quotient = 0;
    uint64_t remainder;
    uint64_t result;
    
    // Precondition verification
    //@ assert 101 <= x && x <= 100000000000000000;
    
    // Ensure no underflow/overflow
    //@ assert x >= 100;
    //@ assert x - 100 <= 100000000000000000;
    
    x_minus_100 = x - 100;
    remainder = x_minus_100;
    
    /*@
        loop invariant 101 <= x && x <= 100000000000000000;
        loop invariant 0 <= quotient <= x_minus_100 / 100;
        loop invariant remainder == x_minus_100 - quotient * 100;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 100) {
        quotient += 1;
        remainder -= 100;
    }
    
    result = quotient * 100;
    
    // Add remainder if >= 100
    if (remainder >= 100) {
        result += remainder;
    }
    
    // Adjust result if remainder < 100 but adding would exceed x
    if (remainder < 100 && result + remainder > x) {
        result += remainder;
    }
    
    // Postcondition verification
    //@ assert result <= x - 100;
    //@ assert result >= 0;
    
    return result;
}

int main() {
    return 0;
}
