#include <stdbool.h>

/*@
    requires (0 <= (v0) <= 100) && (0 <= (v1) <= 100) && (0 <= (v2) <= 100);
    requires ((v0) != (v1) && (v1) != (v2) && (v0) != (v2));
    ensures \result == true <==> ((v0) < (v1) && (v1) < (v2));
*/
bool func(int v0, int v1, int v2)
{
    bool result;

    //@ assert (0 <= (v0) <= 100);
    //@ assert (0 <= (v1) <= 100);
    //@ assert (0 <= (v2) <= 100);
    
    if (v0 < v1 && v1 < v2) {
        //@ assert ((v0) < (v1) && (v1) < (v2));
        result = true;
    } else {
        //@ assert !((v0) < (v1) && (v1) < (v2));
        result = false;
    }
    
    return result;
}
