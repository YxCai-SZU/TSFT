#include <limits.h>

/*@
    requires ((3 <= ((a)) <= 20) && (3 <= ((b)) <= 20));
    ensures \result == a + b || \result == a * 2 - 1 || \result == b * 2 - 1;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b) {
    int max_value;
    int result;
    
    //@ assert (3 <= (a) <= 20);
    //@ assert (3 <= (b) <= 20);
    
    max_value = a > b ? a : b;
    
    //@ assert ((a) > (b) ? (a) : (b)) == max_value;
    //@ assert 3 <= max_value <= 20;
    
    if (a == max_value) {
        //@ assert a + b >= 0;
        result = a + b;
    } else if (b == max_value) {
        //@ assert a * 2 - 1 >= 0;
        result = a * 2 - 1;
    } else {
        //@ assert b * 2 - 1 >= 0;
        result = b * 2 - 1;
    }
    
    //@ assert result == a + b || result == a * 2 - 1 || result == b * 2 - 1;
    //@ assert result >= 0;
    
    return result;
}
