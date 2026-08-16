#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    requires ((y) % 2 == 0);
    ensures \result == ((x) + (((y) / 2)));
    ensures 1 <= \result <= 150;
*/
long func(long x, long y) {
    long half_y;
    long count;
    long temp_y;
    
    if (y >= 0) {
        count = 0;
        temp_y = y;
        /*@
            loop invariant 0 <= temp_y <= y;
            loop invariant ((temp_y) % 2 == 0);
            loop invariant count == ((y - temp_y) / 2);
            loop assigns temp_y, count;
            loop variant temp_y;
        */
        while (temp_y >= 2) {
            temp_y -= 2;
            count += 1;
        }
        half_y = count;
    } else {
        count = 0;
        temp_y = y;
        /*@
            loop invariant -2 <= temp_y <= y;
            loop invariant ((temp_y) % 2 == 0);
            loop invariant count == ((y - temp_y) / 2);
            loop assigns temp_y, count;
            loop variant -temp_y;
        */
        while (temp_y <= -2) {
            temp_y += 2;
            count -= 1;
        }
        half_y = count;
    }
    
    //@ assert half_y == ((y) / 2);
    
    long result = x + half_y;
    
    //@ assert result == ((x) + (((y) / 2)));
    
    return result;
}

int main() {
    return 0;
}
