#include <limits.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result >= 0;
    ensures \result == (1000 * ((x) / 500) + 5 * (((x) % 500) / 5));
    assigns \nothing;
*/
int func(int x) {
    int result;
    int temp_x;
    int five_hundreds;
    int fives;
    
    //@ assert (1 <= (x) <= 100000);
    
    result = 0;
    temp_x = x;
    five_hundreds = 0;
    
    /*@
        loop invariant 0 <= temp_x;
        loop invariant 0 <= five_hundreds;
        loop invariant x == temp_x + five_hundreds * 500;
        loop invariant (1 <= (x) <= 100000);
        loop assigns temp_x, five_hundreds;
        loop variant temp_x;
    */
    while (temp_x >= 500) {
        temp_x -= 500;
        five_hundreds += 1;
    }
    
    fives = 0;
    
    /*@
        loop invariant 0 <= temp_x;
        loop invariant 0 <= fives;
        loop invariant x == temp_x + five_hundreds * 500 + fives * 5;
        loop invariant (1 <= (x) <= 100000);
        loop assigns temp_x, fives;
        loop variant temp_x;
    */
    while (temp_x >= 5) {
        temp_x -= 5;
        fives += 1;
    }
    
    result = 1000 * five_hundreds + 5 * fives;
    
    //@ assert x == temp_x + five_hundreds * 500 + fives * 5;
    
    return result;
}

int main() {
    return 0;
}
