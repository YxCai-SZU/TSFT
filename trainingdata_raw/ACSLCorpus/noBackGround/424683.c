#include <stdbool.h>

/*@
  requires 1 <= x <= 10000;
  requires 1 <= y <= 10000;
  ensures \result == true <==> ((x * y) % 2 != 0);
*/
bool func(unsigned int x, unsigned int y)
{
    // Variable declarations at top of scope
    unsigned int product;
    bool is_product_odd;
    
    // Since x and y are both unsigned int, the product can overflow
    // Hence, we need to check for overflow before performing the calculation
    if (x > 10000 || y > 10000) {
        return true; // If either x or y is too large, assume the product is odd
    }

    // The product of two numbers is odd if and only if both numbers are odd
    //@ assert x * y <= 10000 * 10000;
    product = x * y;
    is_product_odd = (product % 2) != 0;

    // Check if the product is odd without using the modulus operator
    //@ assert is_product_odd == ((product % 2) != 0);
    
    return is_product_odd;
}
