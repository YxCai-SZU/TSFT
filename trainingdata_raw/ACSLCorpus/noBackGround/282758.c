#include <stdbool.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
    ensures \result == true <==> ((a) <= (c) && (c) <= (b));
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool ret = true;

    //@ assert (-100 <= (a) <= 100);
    
    if (a > c || c > b) {
        ret = false;
    }
    
    //@ assert ret == true <==> ((a) <= (c) && (c) <= (b));
    
    return ret;
}
