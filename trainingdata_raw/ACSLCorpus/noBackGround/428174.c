#include <limits.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures \result == ((x) / 500) * 1000 + (((x) % 500) / 5) * 5;
    assigns \nothing;
*/
long long func(long long x) {
    long long x_500 = 0;
    long long temp_x = x;
    long long x_5 = 0;
    long long temp_x2 = 0;
    long long result = 0;
    
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant x_500 <= ((x) / 500);
        loop invariant temp_x == x - x_500 * 500;
        loop assigns x_500, temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 500) {
        //@ assert temp_x >= 500;
        x_500 += 1;
        temp_x -= 500;
    }
    
    /*@
        loop invariant temp_x < 500;
        loop invariant 0 <= x_500 <= ((x) / 500);
        loop invariant temp_x == x - x_500 * 500;
        loop assigns x_500, temp_x;
        loop variant -temp_x;
    */
    while (temp_x < 0) {
        //@ assert temp_x < 0;
        x_500 -= 1;
        temp_x += 500;
    }
    
    temp_x2 = temp_x;
    
    /*@
        loop invariant 0 <= temp_x2 <= temp_x;
        loop invariant x_5 <= (((x) % 500) / 5);
        loop invariant temp_x2 == temp_x - x_5 * 5;
        loop assigns x_5, temp_x2;
        loop variant temp_x2;
    */
    while (temp_x2 >= 5) {
        //@ assert temp_x2 >= 5;
        x_5 += 1;
        temp_x2 -= 5;
    }
    
    /*@
        loop invariant temp_x2 < 5;
        loop invariant 0 <= x_5 <= (((x) % 500) / 5);
        loop invariant temp_x2 == temp_x - x_5 * 5;
        loop assigns x_5, temp_x2;
        loop variant -temp_x2;
    */
    while (temp_x2 < 0) {
        //@ assert temp_x2 < 0;
        x_5 -= 1;
        temp_x2 += 5;
    }
    
    result = x_500 * 1000 + x_5 * 5;
    
    //@ assert result == ((x) / 500) * 1000 + (((x) % 500) / 5) * 5;
    return result;
}

int main() {
    return 0;
}
