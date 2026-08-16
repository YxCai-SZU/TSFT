#include <stdbool.h>

/*@
    requires 1 <= a <= 16;
    requires 1 <= b <= 16;
    requires a + b <= 16;
    ensures \result == (a <= 8 || b <= 8);
*/
bool func(long a, long b) {
    long a_adjusted;
    long b_adjusted;
    bool result;
    
    //@ assert (1 <= (a) <= 16);
    //@ assert (1 <= (b) <= 16);
    //@ assert ((a) + (b) <= 16);
    
    if (a > 8) {
        a_adjusted = a - 8;
    } else {
        a_adjusted = 0;
    }
    
    if (b > 8) {
        b_adjusted = b - 8;
    } else {
        b_adjusted = 0;
    }
    
    //@ assert a_adjusted == ((a) > 8 ? (a) - 8 : 0);
    //@ assert b_adjusted == ((b) > 8 ? (b) - 8 : 0);
    
    result = (a_adjusted <= 0 || b_adjusted <= 0);
    
    //@ assert result == (a <= 8 || b <= 8);
    return result;
}
