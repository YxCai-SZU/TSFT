#include <stdbool.h>

/*@
    requires \valid(v + (0 .. 2));
    requires ((len) >= 3 && (len) <= 100 &&
        \forall integer i; 0 <= i < (len) ==> 1 <= (v)[i] <= 1000);
    ensures \result == (v[0] < v[1] && v[1] < v[2]);
*/
bool func(int *v, int len)
{
    bool result;
    
    //@ assert len >= 3;
    
    if (v[0] < v[1] && v[1] < v[2]) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == (v[0] < v[1] && v[1] < v[2]);
    return result;
}
