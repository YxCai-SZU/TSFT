#include <stdbool.h>

/*@
    requires ((1 <= (x) <= 100) && (1 <= (y) <= 100));
    ensures \result == true <==> (((y) >= (x) * 2) && ((y) <= (x) * 4) && ((((y)) % 2 == 0)));
    assigns \nothing;
*/
bool func(int x, int y) {
    int temp_y;
    bool is_even = false;

    //@ assert ((1 <= (x) <= 100) && (1 <= (y) <= 100));
    
    if (y < x * 2 || y > x * 4) {
        return false;
    }

    temp_y = y;
    
    /*@
        loop invariant ((1 <= (x) <= 100) && (1 <= (y) <= 100));
        loop invariant 0 <= temp_y <= y;
        loop invariant temp_y % 2 == y % 2;
        loop assigns temp_y;
        loop variant temp_y;
    */
    while (temp_y >= 2) {
        temp_y -= 2;
    }

    if (temp_y == 0) {
        is_even = true;
    }

    if (is_even) {
        //@ assert (((y) >= (x) * 2) && ((y) <= (x) * 4) && ((((y)) % 2 == 0)));
        return true;
    } else {
        return false;
    }
}
