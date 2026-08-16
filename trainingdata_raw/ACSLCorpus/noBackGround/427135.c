#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 500);
    requires (1 <= (b) && (b) <= 500);
    requires (1 <= (c) && (c) <= 1000);
    ensures \result == true <==> (a + b >= c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    int state = 0;
    
    //@ assert (1 <= (a) && (a) <= 500);
    if (a >= 1 && a <= 500) {
        state += 1;
    }
    
    //@ assert (1 <= (b) && (b) <= 500);
    if (b >= 1 && b <= 500) {
        state += 1;
    }
    
    //@ assert (1 <= (c) && (c) <= 1000);
    if (c >= 1 && c <= 1000) {
        state += 1;
    }
    
    if (state == 3) {
        //@ assert ((1 <= ((a)) && ((a)) <= 500) && (1 <= ((b)) && ((b)) <= 500) && (1 <= ((c)) && ((c)) <= 1000));
        return (a + b) >= c;
    } else {
        //@ assert !((1 <= ((a)) && ((a)) <= 500) && (1 <= ((b)) && ((b)) <= 500) && (1 <= ((c)) && ((c)) <= 1000));
        return false;
    }
}
