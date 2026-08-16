#include <stdbool.h>

/*@
    requires 1 <= n <= 10000;
    requires 0 <= a <= 1000;
    ensures \result == (n % 500 - a <= 0);
*/
bool func(int n, int a)
{
    unsigned int n_unsigned;
    unsigned int remainder;
    int remainder_signed;
    
    // Convert to unsigned for modulo operation
    if (n < 0) {
        n_unsigned = (unsigned int)(-n);
    } else {
        n_unsigned = (unsigned int)n;
    }
    
    // Perform modulo operation
    remainder = n_unsigned % 500;
    
    // Adjust the remainder to be within the range [0, 500)
    if (remainder > 500) {
        remainder -= 500;
    }
    
    // Convert back to signed integer for the comparison
    remainder_signed = (int)remainder;
    
    //@ assert remainder_signed == n % 500;
    
    return remainder_signed - a <= 0;
}
