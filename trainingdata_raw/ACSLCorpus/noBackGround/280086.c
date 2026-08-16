#include <stdbool.h>

/*@
    requires (1 <= (x) && (x) <= 205 &&
        1 <= (y) && (y) <= 205);
    ensures \result >= 0;
    ensures (x == 1 && y == 1) ==> \result == 1000000;
    ensures (x != 1 || y != 1) ==> \result <= 600000;
    assigns \nothing;
*/
int func(int x, int y)
{
    int x_result;
    int y_result;
    int max_result;
    int result;

    //@ assert (1 <= (x) && (x) <= 205 &&         1 <= (y) && (y) <= 205);
    
    if (x == 1) {
        x_result = 300000;
    } else {
        x_result = 0;
    }
    
    if (y == 1) {
        y_result = 300000;
    } else {
        y_result = 0;
    }
    
    if (x_result > y_result) {
        max_result = x_result;
    } else {
        max_result = y_result;
    }
    
    if (x == 1 && y == 1) {
        //@ assert x == 1 && y == 1;
        result = 1000000;
    } else if (x == 1 || y == 1) {
        //@ assert x == 1 || y == 1;
        result = max_result + 1;
    } else {
        //@ assert x != 1 && y != 1;
        result = 0;
    }
    
    //@ assert result >= 0;
    return result;
}
