#include <stdbool.h>

/*@
    requires 1 <= n && n <= 100;
    ensures \result == (n % 15 == 0);
*/
bool func(unsigned int n)
{
    bool result = false;
    
    //@ assert n % 15 == 0 ==> ((((n)) % 3 == 0) && (((n)) % 5 == 0));
    if (n % 15 == 0) {
        result = true;
    }
    
    //@ assert result == (n % 15 == 0);
    return result;
}
