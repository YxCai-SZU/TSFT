#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
*/
bool func(int a, int b) {
    bool is_possible = false;
    int temp_a = a;
    int temp_b = b;
    int temp_ab = a + b;
    
    // Check if a is a multiple of 3
    /*@
        loop invariant 0 <= temp_a <= a;
        loop invariant a == temp_a + 3 * ((a - temp_a) / 3);
        loop assigns temp_a;
    */
    while (temp_a >= 3) {
        temp_a -= 3;
    }
    //@ assert temp_a == a % 3;
    if (temp_a == 0) {
        is_possible = true;
    }
    
    // Check if b is a multiple of 3
    /*@
        loop invariant 0 <= temp_b <= b;
        loop invariant b == temp_b + 3 * ((b - temp_b) / 3);
        loop assigns temp_b;
    */
    while (temp_b >= 3) {
        temp_b -= 3;
    }
    //@ assert temp_b == b % 3;
    if (temp_b == 0) {
        is_possible = true;
    }
    
    // Check if (a + b) is a multiple of 3
    /*@
        loop invariant 0 <= temp_ab <= a + b;
        loop invariant a + b == temp_ab + 3 * ((a + b - temp_ab) / 3);
        loop assigns temp_ab;
    */
    while (temp_ab >= 3) {
        temp_ab -= 3;
    }
    //@ assert temp_ab == (a + b) % 3;
    if (temp_ab == 0) {
        is_possible = true;
    }
    
    return is_possible;
}

int main() {
    return 0;
}
