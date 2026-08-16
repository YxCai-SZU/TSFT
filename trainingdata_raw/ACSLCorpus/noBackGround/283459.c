#include <stdbool.h>

/*@
    requires (-40 <= (X) <= 40);
    ensures (((X) > 30 ==> (\result) == 2) && ((X) <= 30 ==> (\result) == 0));
    assigns \nothing;
*/
int func(int X)
{
    int result;
    
    //@ assert (-40 <= (X) <= 40);
    
    if (X > 30) {
        //@ assert X > 30;
        result = 2;
    } else {
        //@ assert X <= 30;
        result = 0;
    }
    
    //@ assert (((X) > 30 ==> (result) == 2) && ((X) <= 30 ==> (result) == 0));
    return result;
}
