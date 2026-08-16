#include <stdbool.h>

/*@ requires 1 <= X <= 9;
    ensures \result == (X == 3 || X == 5 || X == 7);
    assigns \nothing;
 */
bool func(int X)
{
    //@ assert 1 <= X <= 9;
    
    bool res;
    
    if (X == 3 || X == 5 || X == 7) {
        res = true;
    } else {
        res = false;
    }
    
    return res;
}
