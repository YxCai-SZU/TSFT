#include <stdbool.h>

/*@
    requires (1 <= (input) && (input) <= 9);
    ensures \result == true <==> ((input) == 7 || (input) == 5 || (input) == 3);
    assigns \nothing;
*/
bool func(unsigned long input)
{
    bool result;
    
    //@ assert 1 <= input && input <= 9;
    
    if (input == 7 || input == 5 || input == 3) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
