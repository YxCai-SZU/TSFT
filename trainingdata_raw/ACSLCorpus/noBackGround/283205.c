#include <stdbool.h>

/*@
    requires 1 <= x <= 10;
    requires 1 <= y <= 10;
    ensures \result == true <==> (x * y) % 2 == 0;
    ensures \result == false <==> (x * y) % 2 != 0;
*/
bool func(unsigned int x, unsigned int y)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int product_val;
    
    // Precondition assertions
    //@ assert 1 <= x <= 10;
    //@ assert 1 <= y <= 10;
    
    // Bounds verification
    //@ assert x * y <= 100;
    
    product_val = x * y;
    
    if (product_val % 2 == 0) {
        result = true;
        //@ assert ((((x) * (y))) % 2 == 0);
    } else {
        result = false;
        //@ assert !((((x) * (y))) % 2 == 0);
    }
    
    return result;
}
