#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result == (a + b == c || b + c == a || c + a == b);
    assigns \nothing;
*/
bool func(int a, int b, int c) {
    bool a_bool = false;
    bool b_bool = false;
    bool c_bool = false;
    
    //@ assert a + b <= 200;
    //@ assert b + c <= 200;
    //@ assert c + a <= 200;
    
    if (a + b == c) {
        a_bool = true;
    }
    if (b + c == a) {
        b_bool = true;
    }
    if (c + a == b) {
        c_bool = true;
    }
    
    if (a_bool || b_bool || c_bool) {
        return true;
    } else {
        return false;
    }
}
