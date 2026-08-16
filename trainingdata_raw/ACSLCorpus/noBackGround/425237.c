#include <stdbool.h>

/*@
    requires \valid(v + (0 .. 1));
    requires ((2) == 2);
    requires (\forall integer i; 0 <= i < (2) ==> 0 <= (v)[i] <= 16);
    ensures ((\result) == ((v)[0] <= 8 || (v)[1] <= 8));
*/
bool func(int *v) {
    int a;
    int b;
    
    a = v[0];
    b = v[1];
    
    if (a <= 8 || b <= 8) {
        //@ assert a <= 8 || b <= 8;
        return true;
    } else {
        //@ assert a > 8 && b > 8;
        return false;
    }
}
