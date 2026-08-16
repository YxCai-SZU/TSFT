#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (b) && (b) <= 100 &&
        0 <= (c) && (c) <= 100 &&
        0 <= (d) && (d) <= 100);
    ensures \result == (a * c <= b * d);
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int left_product;
    unsigned int right_product;
    bool result;

    //@ assert (0 <= (a) && (a) <= 100 &&         0 <= (b) && (b) <= 100 &&         0 <= (c) && (c) <= 100 &&         0 <= (d) && (d) <= 100);
    
    //@ assert a * c <= 10000;
    //@ assert b * d <= 10000;
    
    left_product = a * c;
    right_product = b * d;
    
    //@ assert left_product == a * c;
    //@ assert right_product == b * d;
    
    result = left_product <= right_product;
    
    //@ assert result == (a * c <= b * d);
    return result;
}
