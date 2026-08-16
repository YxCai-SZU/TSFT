#include <limits.h>

/*@
    requires x >= -1000 && x <= 1000;
    ensures \result == ((x) >= 0 ? (x) : -(x));
    ensures \result >= 0;
    ensures (x == 0 || x == -0) ==> \result == 0;
*/
int test_func(int x) {
    int result;
    
    //@ assert ((x) >= -1000 && (x) <= 1000 ==>         ((((x)) >= 0 ? ((x)) : -((x))) == (x) || (((x)) >= 0 ? ((x)) : -((x))) == -(x)) &&         (((x)) >= 0 ? ((x)) : -((x))) >= 0 &&         ((x) == 0 || (x) == -0 ==> (((x)) >= 0 ? ((x)) : -((x))) == 0));
    
    if (x >= 0) {
        result = x;
    } else {
        result = -x;
    }
    
    //@ assert result == x || result == -x;
    //@ assert result >= 0;
    //@ assert (x == 0 || x == -0) ==> result == 0;
    
    return result;
}

int main() {
    int x = 10;
    int y;
    
    y = test_func(x);
    
    //@ assert y == 10;
    
    return 0;
}
