#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

/*@
    requires \valid(v + (0 .. 4));
    requires (\forall integer i; 0 <= i < (5) ==> (v)[i] <= 40);
    requires 5 < UINT_MAX;
    ensures \result == true;
    assigns \nothing;
*/
bool func(unsigned int *v) {
    bool result;
    
    //@ assert \forall integer i; 0 <= i < 5 ==> v[i] <= 40;
    
    result = true;
    //@ assert result == true;
    
    return result;
}
