#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(v + (0 .. len-1));
    requires ((len) > 0 &&
        \forall integer i; 0 <= i < (len) ==> (v)[i] > 0);
    ensures \result == true <==> len == 4;
    assigns \nothing;
*/
bool func(unsigned int *v, size_t len) {
    // Variable declarations at top of scope
    bool result;
    
    //@ assert len > 0;
    
    //@ assert \forall integer i; 0 <= i < len ==> v[i] > 0;
    
    //@ assert ((integer)(len)) == (integer)len;
    
    if (len != 4) {
        result = false;
        //@ assert result == false;
        return result;
    }
    
    result = true;
    //@ assert result == true;
    return result;
}
