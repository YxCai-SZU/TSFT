#include <stdint.h>

/*@
    requires (-100 <= (x) && (x) <= 100) && (-100 <= (y) && (y) <= 100) && (-100 <= (z) && (z) <= 100);
    requires x * y <= 10000 && x * z <= 10000 && y * z <= 10000;
    ensures \result == ((x) * (y) + (x) * (z));
    assigns \nothing;
*/
int64_t func(int64_t x, int64_t y, int64_t z)
{
    //@ assert (-10000 <= (x * y) && (x * y) <= 10000);
    //@ assert (-10000 <= (x * z) && (x * z) <= 10000);
    //@ assert (-10000 <= (y * z) && (y * z) <= 10000);
    
    int64_t product_y;
    int64_t product_z;
    int64_t result;
    
    product_y = x * y;
    product_z = x * z;
    result = product_y + product_z;
    
    //@ assert result == ((x) * (y) + (x) * (z));
    return result;
}
