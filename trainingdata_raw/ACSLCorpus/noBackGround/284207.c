#include <stdbool.h>

/*@ requires 1 <= x <= 100 && 1 <= y <= 100;
    ensures \result == true <==> (y % 2 == 0 && (y / 2) >= x);
    assigns \nothing;
*/
bool func(int x, int y) {
    bool even = false;
    int temp_y = y;
    int div = 0;
    int count = 0;
    
    /*@ loop invariant 0 <= temp_y <= y;
        loop invariant temp_y % 2 == y % 2;
        loop invariant even == false;
        loop assigns temp_y;
        loop variant temp_y;
    */
    while (temp_y >= 2) {
        temp_y -= 2;
    }
    
    if (temp_y == 0) {
        even = true;
    }
    
    temp_y = y;
    count = 0;
    
    /*@ loop invariant 0 <= temp_y <= y;
        loop invariant 0 <= count;
        loop invariant count * 2 + temp_y == y;
        loop assigns temp_y, count;
        loop variant temp_y;
    */
    while (temp_y >= 2) {
        temp_y -= 2;
        count += 1;
    }
    div = count;
    
    //@ assert even == (y % 2 == 0);
    //@ assert div == y / 2;
    
    return even && div >= x;
}
