#include <stdbool.h>

/*@
    requires (400 <= (x) && (x) < 2000);
    ensures ((\result) == 8 || (\result) == 4 || (\result) == 0);
    assigns \nothing;
*/
int func(int x)
{
    int result = 0;
    
    //@ assert (400 <= (x) && (x) < 2000);
    
    if (400 <= x && x <= 599) {
        result = 8;
        //@ assert ((result) == 8 || (result) == 4 || (result) == 0);
    } else if (600 <= x && x <= 799) {
        result = 4;
        //@ assert ((result) == 8 || (result) == 4 || (result) == 0);
    } else if (800 <= x && x <= 1999) {
        result = 0;
        //@ assert ((result) == 8 || (result) == 4 || (result) == 0);
    }
    
    //@ assert ((result) == 8 || (result) == 4 || (result) == 0);
    
    return result;
}
