#include <stdint.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures \result >= 0;
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
*/
int64_t func(int64_t x) {
    int64_t q1 = 0;
    int64_t temp_x = x;
    int64_t q2 = 0;
    int64_t ans = 0;
    
    //@ assert (0 <= (x) <= 1000000000);
    
    /*@
        loop invariant 0 <= q1 <= ((x) / 500);
        loop invariant temp_x >= 0;
        loop invariant temp_x == x - q1 * 500;
        loop invariant (0 <= (x) <= 1000000000);
        loop assigns q1, temp_x;
    */
    while (temp_x >= 500) {
        //@ assert temp_x >= 500;
        q1 += 1;
        temp_x -= 500;
        //@ assert temp_x == x - q1 * 500;
    }
    
    //@ assert temp_x == ((x) % 500);
    
    /*@
        loop invariant 0 <= q2 <= ((((x) % 500)) / 5);
        loop invariant temp_x >= 0;
        loop invariant temp_x == ((x) % 500) - q2 * 5;
        loop invariant (0 <= (x) <= 1000000000);
        loop assigns q2, temp_x;
    */
    while (temp_x >= 5) {
        //@ assert temp_x >= 5;
        q2 += 1;
        temp_x -= 5;
        //@ assert temp_x == ((x) % 500) - q2 * 5;
    }
    
    ans = q1 * 1000 + q2 * 5;
    
    //@ assert ans == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    return ans;
}

int main() {
    return 0;
}
