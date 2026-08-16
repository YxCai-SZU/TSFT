#include <stdbool.h>

/*@
    requires (1 <= (input) && (input) <= 9);
    ensures \result == (input == 3 || input == 5 || input == 7);
    assigns \nothing;
*/
bool func(unsigned int input) {
    // Variable declarations at the top
    bool result;

    //@ assert (1 <= (input) && (input) <= 9);
    
    if (input == 3 || input == 5 || input == 7) {
        //@ assert (1 <= (input) && (input) <= 9);
        result = true;
    } else {
        //@ assert (1 <= (input) && (input) <= 9);
        result = false;
    }
    
    return result;
}
