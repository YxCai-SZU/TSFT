#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == ((a * 100) / 100 == a || (b * 100) / 100 == b);
*/
bool func(unsigned int a, unsigned int b) {
    unsigned int a_unscaled;
    unsigned int b_unscaled;
    unsigned int a_scaled;
    unsigned int b_scaled;
    bool result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    
    //@ assert ((a) * 100) <= 10000;
    a_unscaled = a * 100;
    
    //@ assert ((b) * 100) <= 10000;
    b_unscaled = b * 100;
    
    a_scaled = (a_unscaled + 99) / 100;
    b_scaled = (b_unscaled + 99) / 100;
    
    //@ assert (((((a)) * 100) + 99) / 100) == ((a) * 100) / 100 || (((((a)) * 100) + 99) / 100) == (((a) * 100) + 99) / 100;
    //@ assert (((((b)) * 100) + 99) / 100) == ((b) * 100) / 100 || (((((b)) * 100) + 99) / 100) == (((b) * 100) + 99) / 100;
    
    result = (a_scaled == a) || (b_scaled == b);
    
    //@ assert result == ((a * 100) / 100 == a || (b * 100) / 100 == b);
    return result;
}
