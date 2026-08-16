#include <stdbool.h>

/*@ requires 0 <= x <= 100 && 0 <= y <= 100;
    ensures \result == (y % 2 == 0 && y > 2 * x && y <= 4 * x);
    assigns \nothing;
 */
bool func(int x, int y) {
    bool is_even_val = false;
    int temp_y = y;
    
    /*@ loop invariant 0 <= temp_y <= y;
        loop invariant temp_y <= 100;
        loop invariant y <= 100;
        loop invariant temp_y % 2 == y % 2;
        loop invariant 0 <= x <= 100;
        loop assigns temp_y;
        loop variant temp_y;
     */
    while (temp_y >= 2) {
        //@ assert temp_y % 2 == y % 2;
        temp_y -= 2;
    }
    
    if (temp_y == 0) {
        is_even_val = true;
    }
    
    int min = 2 * x;
    int max = 4 * x;
    
    if (is_even_val && y > min && y <= max) {
        //@ assert 0 <= x <= 100;
        //@ assert 0 <= y <= 100;
        //@ assert y % 2 == 0;
        //@ assert y > 2 * x;
        //@ assert y <= 4 * x;
        return true;
    } else {
        return false;
    }
}
