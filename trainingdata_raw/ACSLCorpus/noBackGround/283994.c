#include <stdbool.h>

/*@
    requires 0 <= x <= 100 && 0 <= y <= 100 && 0 <= z <= 100;
    ensures \result <==> (((x) * (y)) * (z) <= 1000000);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y, unsigned int z)
{
    // Variable declarations at scope top
    bool result;
    unsigned int intermediate;
    unsigned int final_product;

    //@ assert 0 <= x <= 100 && 0 <= y <= 100;
    //@ assert x * y <= 10000;
    
    intermediate = x * y;
    
    //@ assert intermediate <= 10000;
    //@ assert 0 <= z <= 100;
    //@ assert intermediate * z <= 1000000;
    
    final_product = intermediate * z;
    result = final_product <= 1000000;
    
    //@ assert result <==> (((x) * (y)) * (z) <= 1000000);
    return result;
}
