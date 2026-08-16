#include <stdint.h>

/*@ requires ((1 <= ((a)) <= 20) && (1 <= ((b)) <= 20) && (((a)) <= ((b))));
    ensures \result == ((((a)) + ((b))) > (((b)) - ((a))) ? (((a)) + ((b))) : (((b)) - ((a))));
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b) {
    int64_t result;
    int64_t i;
    int64_t max_value;
    
    result = 0;
    i = 0;
    
    /*@ loop invariant 0 <= i <= 2;
        loop invariant ((1 <= ((a)) <= 20) && (1 <= ((b)) <= 20) && (((a)) <= ((b))));
        loop invariant i == 0 ==> result == 0;
        loop invariant i == 1 ==> result == ((a) + (b));
        loop invariant i == 2 ==> result == ((b) - (a));
        loop assigns i, result;
        loop variant 2 - i;
    */
    while (i < 2) {
        if (i == 0) {
            result = a + b;
        } else {
            result = b - a;
        }
        i += 1;
    }
    
    //@ assert result == ((b) - (a));
    
    if (a + b > b - a) {
        max_value = a + b;
    } else {
        max_value = b - a;
    }
    
    //@ assert max_value == ((((a)) + ((b))) > (((b)) - ((a))) ? (((a)) + ((b))) : (((b)) - ((a))));
    
    return max_value;
}
