#include <limits.h>

/*@
    requires (2 <= (a) <= 100) && (2 <= (b) <= 100);
    requires INT_MIN < (a - 1) * (b - 1) < INT_MAX;
    ensures ((\result) == ((a) - 1) * ((b) - 1));
*/
int func(int a, int b) {
    int result;
    
    //@ assert 1 <= a - 1;
    //@ assert 1 <= b - 1;
    
    result = (a - 1) * (b - 1);
    
    //@ assert result == (a - 1) * (b - 1);
    return result;
}
