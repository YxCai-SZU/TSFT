#include <stdbool.h>

/*@
    requires 1 <= x && x <= 1000000000000000;
    ensures \result == (x >= 2000 && x % 2000 == 0);
    assigns \nothing;
*/
bool func(unsigned long long x) {
    bool result;
    unsigned long long temp_x;
    
    result = true;
    
    if (x < 2000) {
        result = false;
    } else {
        temp_x = x;
        
        /*@
            loop invariant 1 <= x && x <= 1000000000000000;
            loop invariant 0 <= temp_x && temp_x <= x;
            loop invariant temp_x % 2000 == x % 2000;
            loop assigns temp_x;
            loop variant temp_x;
        */
        while (temp_x >= 2000) {
            //@ assert temp_x % 2000 == x % 2000;
            temp_x -= 2000;
        }
        
        if (temp_x != 0) {
            result = false;
        }
    }
    
    return result;
}

int main() {
    return 0;
}
