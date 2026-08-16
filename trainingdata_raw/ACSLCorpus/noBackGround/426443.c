#include <stdbool.h>

/*@
    requires (0 <= (X) <= 100);
    ensures ((\result) >= 0 && ((\result) == 1000 || (\result) == 500 || (\result) == 0));
    assigns \nothing;
*/
int func(int X)
{
    int result;
    
    //@ assert (0 <= (X) <= 100);
    
    if (X >= 50) {
        if (X >= 80) {
            result = 1000;
        } else {
            result = 500;
        }
    } else {
        //@ assert X < 50;
        result = 0;
    }
    
    //@ assert ((result) >= 0 && ((result) == 1000 || (result) == 500 || (result) == 0));
    return result;
}
