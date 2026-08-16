#include <stdbool.h>

/*@
    requires (100 <= (n) && (n) <= 999);
    ensures \result == (((n) / 100) == ((n) % 10));
    assigns \nothing;
*/
bool func(int n)
{
    int a0;
    int a2;
    bool result;
    
    //@ assert (100 <= (n) && (n) <= 999);
    
    a0 = n / 100;
    a2 = n % 10;
    
    //@ assert a0 == ((n) / 100);
    //@ assert a2 == ((n) % 10);
    
    result = (a0 == a2);
    //@ assert result == (((n) / 100) == ((n) % 10));
    
    return result;
}
