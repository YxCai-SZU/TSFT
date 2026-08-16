#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == ((a * b) - 1 >= c * d);
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    // Declare all variables at the top
    unsigned int ab_product;
    unsigned int cd_product;
    bool result;
    
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    // Calculate a * b
    ab_product = a * b;
    //@ assert ab_product == ((a) * (b));
    
    // Calculate c * d
    cd_product = c * d;
    //@ assert cd_product == ((c) * (d));
    
    // Verify product bounds
    //@ assert 1 <= ab_product <= 10000 * 10000;
    //@ assert 1 <= cd_product <= 10000 * 10000;
    
    // Verify subtraction safety
    //@ assert ab_product - 1 <= 10000 * 10000 - 1;
    //@ assert ab_product - 1 >= 0;
    
    // Compute final comparison
    result = (ab_product - 1) >= cd_product;
    
    // Final verification
    //@ assert result == ((a * b) - 1 >= c * d);
    
    return result;
}
