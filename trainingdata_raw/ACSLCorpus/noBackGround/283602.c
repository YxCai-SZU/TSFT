#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result <= a;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> ((((b)) % ((a))) == 0);
    ensures \result == 1 ==> ((((b)) % ((a))) != 0);
*/
unsigned int func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int result;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    if (b % a == 0)
    {
        result = 0;
        //@ assert ((((b)) % ((a))) == 0);
    }
    else
    {
        //@ assert ((((b)) % ((a))) != 0);
        result = 1;
    }
    
    //@ assert result <= a;
    //@ assert result == 0 || result == 1;
    return result;
}
