#include <stdint.h>

/*@
    requires (1 <= (x) <= 1000000000);
    ensures \result >= 0;
    ensures \result <= (x / 11) * 2 + 2;
    ensures \result >= (x / 11) * 2;
    assigns \nothing;
*/
int64_t func(int64_t x) {
    int64_t res = 0;
    int64_t temp_x = x;
    int64_t count = 0;
    
    //@ assert (1 <= (x) <= 1000000000);
    //@ assert temp_x == x;
    
    /*@
        loop invariant 1 <= x <= 1000000000;
        loop invariant 0 <= temp_x <= x;
        loop invariant res == 0;
        loop invariant x == temp_x + 11 * count;
        loop invariant 0 <= count <= x / 11;
        loop assigns temp_x, count;
        loop variant temp_x;
    */
    while (temp_x >= 11) {
        temp_x -= 11;
        count += 1;
    }
    
    res += count * 2;
    
    if (temp_x > 6) {
        res += 2;
    } else {
        res += 1;
    }
    
    //@ assert res >= 0;
    //@ assert res <= (x / 11) * 2 + 2;
    //@ assert res >= (x / 11) * 2;
    
    return res;
}

int main() {
    return 0;
}
