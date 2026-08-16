#include <stddef.h>

/*@
    requires 1 <= input && input <= 1000000;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> ((input) % 1000 == 0);
    ensures \result == 0 ==> !((input) % 1000 == 0);
*/
int func(size_t input)
{
    int result;
    //@ assert 1 <= input && input <= 1000000;
    
    if (input % 1000 == 0)
    {
        //@ assert ((input) % 1000 == 0);
        result = 1;
    }
    else
    {
        //@ assert !((input) % 1000 == 0);
        result = 0;
    }
    
    //@ assert result == 1 || result == 0;
    return result;
}
