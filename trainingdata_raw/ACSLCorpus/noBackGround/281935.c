#include <stdbool.h>

/*@
    requires (-1000 <= (A) <= 1000) && (-1000 <= (B) <= 1000);
    ensures \result == true <==> ((A) <= 0 && 0 <= (B));
    assigns \nothing;
*/
bool func(int A, int B)
{
    bool result;
    
    //@ assert (-1000 <= (A) <= 1000) && (-1000 <= (B) <= 1000);
    
    if (A <= 0 && 0 <= B) {
        //@ assert ((A) <= 0 && 0 <= (B));
        result = true;
    } else {
        //@ assert !((A) <= 0 && 0 <= (B));
        result = false;
    }
    
    //@ assert result == true <==> ((A) <= 0 && 0 <= (B));
    return result;
}
