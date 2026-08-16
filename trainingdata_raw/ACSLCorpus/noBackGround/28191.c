#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == true <==> (((((x)) / 100) * 100) + 100) < x;
    assigns \nothing;
*/
bool func(unsigned int x)
{
    // Variable declarations at scope top
    unsigned int div_result;
    unsigned int scaled;
    unsigned int thresh;
    bool condition;
    bool result;

    //@ assert (1 <= (x) <= 100000);
    
    // Arithmetic computations
    div_result = x / 100;
    //@ assert div_result <= 1000;
    
    scaled = div_result * 100;
    //@ assert scaled <= 100000;
    
    thresh = scaled + 100;
    //@ assert thresh <= 101000;
    
    condition = thresh < x;
    
    if (condition) {
        //@ assert thresh < x;
        result = true;
    } else {
        //@ assert !(thresh < x);
        result = false;
    }
    
    //@ assert result == true <==> thresh < x;
    return result;
}
