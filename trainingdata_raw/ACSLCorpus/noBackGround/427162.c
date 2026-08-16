#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((len) >= 2 &&
        \valid((v) + (0 .. (len)-1)));
    ensures \result == true <==> v[0] < v[1];
*/
bool func(int *v, size_t len) {
    int first;
    int second;
    bool result;

    //@ assert ((len) >= 2 &&         \valid((v) + (0 .. (len)-1)));
    //@ assert ((len)) >= 2;
    
    first = v[0];
    second = v[1];
    
    //@ assert 0 <= 0 < ((len));
    //@ assert 0 <= 1 < ((len));
    
    result = first < second;
    //@ assert result == true <==> ((v)[(0)]) < ((v)[(1)]);
    
    return result;
}
