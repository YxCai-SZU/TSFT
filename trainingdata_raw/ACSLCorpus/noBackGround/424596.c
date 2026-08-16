#include <stdbool.h>

/*@
    requires (1 <= (a) <= 3) && (1 <= (b) <= 3) && ((a) != (b));
    ensures \result == 1 || \result == 2 || \result == 3;
    ensures \result != a && \result != b;
*/
unsigned int func(unsigned int a, unsigned int b) {
    unsigned int result;
    
    result = 1;
    
    if ((a == 1 && b == 2) || (a == 2 && b == 1)) {
        result = 3;
    } else if ((a == 1 && b == 3) || (a == 3 && b == 1)) {
        result = 2;
    }
    
    //@ assert result == 1 || result == 2 || result == 3;
    //@ assert result != a;
    //@ assert result != b;
    
    return result;
}
