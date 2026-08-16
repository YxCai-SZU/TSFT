#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 9 && 1 <= (b) && (b) <= 9 && 1 <= (c) && (c) <= 9);
    ensures \result == 1 <==> (((a) == (b) + (c) || (a) == (c) + (b) || (b) == (a) + (c) || (b) == (c) + (a) || (c) == (a) + (b) || (c) == (b) + (a)) &&
        !((a) == (b) && (b) == (c)));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int sorted0;
    unsigned int sorted1;
    unsigned int sorted2;
    
    // Manual sorting logic
    if (a <= b && a <= c) {
        sorted0 = a;
        if (b <= c) {
            sorted1 = b;
            sorted2 = c;
        } else {
            sorted1 = c;
            sorted2 = b;
        }
    } else if (b <= a && b <= c) {
        sorted0 = b;
        if (a <= c) {
            sorted1 = a;
            sorted2 = c;
        } else {
            sorted1 = c;
            sorted2 = a;
        }
    } else {
        sorted0 = c;
        if (a <= b) {
            sorted1 = a;
            sorted2 = b;
        } else {
            sorted1 = b;
            sorted2 = a;
        }
    }
    
    //@ assert sorted0 <= sorted1 && sorted1 <= sorted2;
    //@ assert sorted0 + sorted1 + sorted2 == a + b + c;
    
    bool result = (sorted2 == sorted1 + sorted0) && !(sorted0 == sorted1 && sorted1 == sorted2);
    
    //@ assert result == 1 <==> (((a) == (b) + (c) || (a) == (c) + (b) || (b) == (a) + (c) || (b) == (c) + (a) || (c) == (a) + (b) || (c) == (b) + (a)) &&         !((a) == (b) && (b) == (c)));
    return result;
}
