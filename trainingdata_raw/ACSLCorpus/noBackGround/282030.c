#include <stdbool.h>

/*@
    requires ((2) == 2 &&
        \valid_read((input) + (0..1)) &&
        1 <= (input)[0] <= 100 &&
        1 <= (input)[1] <= 100);
    ensures \result == (input[0] > input[1]);
    assigns \nothing;
*/
bool func(int *input) {
    //@ assert input[0] >= 1 && input[0] <= 100;
    //@ assert input[1] >= 1 && input[1] <= 100;
    
    if (input[0] > input[1]) {
        return true;
    } else {
        return false;
    }
}
