#include <stdbool.h>

/*@
    requires (-40 <= (x) <= 40);
    ensures \result ==> x >= 30;
    ensures !\result ==> x < 30;
    assigns \nothing;
*/
bool func(int x)
{
    bool result;
    //@ assert (-40 <= (x) <= 40);
    
    //@ ghost
    //@ assert x >= 30 || x < 30;
    
    result = (x >= 30);
    
    //@ assert ((result) ==> (x) >= 30);
    //@ assert (!(result) ==> (x) < 30);
    
    return result;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    bool result;
    
    result = func(30);
    //@ assert result == true;
    assert(result == true);
    
    result = func(25);
    //@ assert result == false;
    assert(result == false);
    
    result = func(-40);
    //@ assert result == false;
    assert(result == false);
    
    return 0;
}
#endif
