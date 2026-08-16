#include <stdbool.h>

/*@
    requires 10 <= n && n <= 99;
    ensures \result == (n % 10 == 9 || n >= 90);
*/
bool func(unsigned long n)
{
    bool condition1;
    bool condition2;
    bool result;

    //@ assert (10 <= (n) && (n) <= 99);
    
    condition1 = (n % 10 == 9);
    condition2 = (n >= 90);
    
    //@ assert condition1 == (n % 10 == 9);
    //@ assert condition2 == (n >= 90);
    
    result = condition1 || condition2;
    
    //@ assert result ==> (n % 10 == 9 || n >= 90);
    
    return result;
}
