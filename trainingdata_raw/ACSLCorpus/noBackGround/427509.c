#include <stdbool.h>

/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures ((\result) == (a) + (a) - 1 || (\result) == (a) + (b) || (\result) == (b) + (b) - 1);
    ensures \result >= 0;
*/
int func(int a, int b) {
    int max;
    int result;
    
    //@ assert a >= 3 && a <= 20;
    //@ assert b >= 3 && b <= 20;
    
    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    
    if (max == a) {
        result = a + a - 1;
        //@ assert result == a + a - 1;
    } else {
        //@ assert a + b >= 0;
        result = a + b;
        //@ assert result == a + b;
    }
    
    //@ assert result >= 0;
    return result;
}
