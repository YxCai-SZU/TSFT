#include <stdbool.h>

/*@ requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    requires ((y) % 2 == 0);
    ensures \result == x + (y / 2);
*/
int func(int x, int y) {
    int half_y;
    int temp_y;
    int result;
    
    if (y >= 0) {
        temp_y = y;
        half_y = 0;
        /*@ loop invariant 0 <= temp_y <= y;
            loop invariant half_y <= y / 2;
            loop invariant temp_y == y - 2 * half_y;
            loop assigns temp_y, half_y;
        */
        while (temp_y >= 2) {
            temp_y -= 2;
            half_y += 1;
        }
    } else {
        temp_y = y;
        half_y = 0;
        /*@ loop invariant y <= temp_y <= 0;
            loop invariant half_y >= y / 2;
            loop invariant temp_y == y - 2 * half_y;
            loop assigns temp_y, half_y;
        */
        while (temp_y <= -2) {
            temp_y += 2;
            half_y -= 1;
        }
    }
    
    result = x + half_y;
    //@ assert result == x + (y / 2);
    return result;
}
