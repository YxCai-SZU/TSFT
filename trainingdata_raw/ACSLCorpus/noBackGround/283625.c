#include <stdbool.h>

/*@
    requires (-40 <= (x) && (x) <= 40);
    ensures (x >= 30 ==> \result == true) && (x < 30 ==> \result == false);
    assigns \nothing;
*/
bool func(int x)
{
    bool result;
    //@ assert (-40 <= (x) && (x) <= 40);
    
    result = (x >= 30);
    
    //@ assert (x >= 30 ==> result == true) && (x < 30 ==> result == false);
    return result;
}

/*@
    requires (-40 <= (x) && (x) <= 40);
    ensures (x >= 30 ==> \result == true) && (x < 30 ==> \result == false);
    assigns \nothing;
*/
bool func2(int x)
{
    bool is_hot;
    bool result;
    
    is_hot = true;
    //@ assert is_hot == true;
    
    result = (x >= 30);
    
    //@ assert (x >= 30 ==> result == true) && (x < 30 ==> result == false);
    return result;
}
