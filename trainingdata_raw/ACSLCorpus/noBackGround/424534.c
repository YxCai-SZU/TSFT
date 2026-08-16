#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((len) >= 2 &&
        \valid((v) + (0 .. (len)-1)) &&
        (v)[0] >= 1 && (v)[0] <= 100 &&
        (v)[1] >= 1 && (v)[1] <= 100);
    ensures \result == true <==> v[0] <= v[1];
    assigns \nothing;
*/
bool func(int *v, size_t len) {
    int a;
    int b;
    
    //@ assert len >= 2;
    //@ assert \valid(v + (0 .. len-1));
    //@ assert v[0] >= 1 && v[0] <= 100;
    //@ assert v[1] >= 1 && v[1] <= 100;
    
    a = v[0];
    b = v[1];
    
    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    
    return a <= b;
}
