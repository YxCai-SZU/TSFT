#include <stdbool.h>

/*@
    requires (1 <= (a) <= 3 && 1 <= (b) <= 3 && (a) != (b));
    ensures \result == (6 - (a) - (b));
    ensures 1 <= \result <= 3;
    ensures \result != a && \result != b;
*/
long func(long a, long b) {
    long result;
    
    //@ assert 1 <= a <= 3;
    //@ assert 1 <= b <= 3;
    //@ assert a != b;
    
    result = 6 - a - b;
    
    //@ assert result >= 1;
    //@ assert result <= 3;
    //@ assert result != a && result != b;
    
    return result;
}
