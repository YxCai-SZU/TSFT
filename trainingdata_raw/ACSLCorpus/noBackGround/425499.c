#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result == ((a <= c) && (c <= (b + (a - 1))));
*/
bool func(int a, int b, int c) {
    bool result;
    int a_plus;
    
    result = false;
    
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    
    if (b + (a - 1) < 100) {
        a_plus = b + (a - 1);
    } else {
        a_plus = 100;
    }
    
    //@ assert a_plus == (((b) + ((a) - 1) < 100) ? ((b) + ((a) - 1)) : 100);
    
    if (a <= c && c <= a_plus) {
        result = true;
    }
    
    //@ assert result == ((a <= c) && (c <= (((b) + ((a) - 1) < 100) ? ((b) + ((a) - 1)) : 100)));
    
    return result;
}
