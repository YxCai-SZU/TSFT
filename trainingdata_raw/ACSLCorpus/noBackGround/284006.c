#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == true <==> (a + b == c || b + c == a || c + a == b);
    assigns \nothing;
*/
bool func(int a, int b, int c) {
    // Variable declarations at top of scope
    int m = 0;
    int n = 0;
    int p = 0;
    bool result = false;

    //@ assert a + b <= 200;
    //@ assert b + c <= 200;
    //@ assert c + a <= 200;

    if (a + b == c || b + c == a || c + a == b) {
        result = true;
    } else {
        m = 0;
        n = 0;
        p = 0;
        
        if (a + b == c) {
            m = 1;
        } else {
            n = 1;
        }
        
        if (b + c == a) {
            m = 1;
        } else {
            n = 1;
        }
        
        if (c + a == b) {
            m = 1;
        } else {
            n = 1;
        }
        
        if (m == 1) {
            result = true;
        } else {
            result = false;
        }
    }
    
    return result;
}
