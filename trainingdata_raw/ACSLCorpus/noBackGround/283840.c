#include <stdbool.h>

/*@
    requires (-40 <= (X) && (X) <= 40);
    ensures \result == (((X) >= 30 ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(int X)
{
    bool result;
    
    //@ assert -40 <= X && X <= 40;
    
    result = (X >= 30);
    
    //@ assert (X >= 30 ==> result == true);
    
    return result;
}

int main()
{
    return 0;
}
