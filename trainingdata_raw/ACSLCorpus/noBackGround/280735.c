#include <limits.h>

/*@
    requires (-100 <= (a) <= 100);
    requires (-100 <= (b) <= 100);
    ensures \result == ((a) + (b)) || \result == ((a) - (b)) || \result == ((a) * (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) - (b));
    ensures \result >= ((a) * (b));
*/
int func(int a, int b) {
    int add;
    int sub;
    int mul;
    int result;

    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    
    add = a + b;
    sub = a - b;
    
    //@ assert -10000 <= a * b <= 10000;
    mul = a * b;
    
    result = add;
    
    if (sub > result) {
        result = sub;
    }
    
    if (mul > result) {
        result = mul;
    }
    
    //@ assert result == ((a) + (b)) || result == ((a) - (b)) || result == ((a) * (b));
    //@ assert result >= ((a) + (b));
    //@ assert result >= ((a) - (b));
    //@ assert result >= ((a) * (b));
    
    return result;
}
