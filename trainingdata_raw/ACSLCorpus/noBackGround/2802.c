#include <stdbool.h>

/*@
    requires 1 <= a <= 16;
    requires 1 <= b <= 16;
    requires a + b <= 16;
    ensures \result == true <==> ((a) <= 8 && (b) <= 8);
    assigns \nothing;
*/
bool func(int a, int b)
{
    bool result;
    
    //@ assert 1 <= a <= 16 && 1 <= b <= 16;
    
    if (a > 8 || b > 8) {
        //@ assert a > 8 || b > 8;
        result = false;
    } else {
        //@ assert a <= 8 && b <= 8;
        result = true;
    }
    
    //@ assert result == true <==> ((a) <= 8 && (b) <= 8);
    return result;
}
