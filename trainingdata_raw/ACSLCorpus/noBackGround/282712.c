#include <stdbool.h>

/*@
    requires (1 <= (a) <= 13) && (1 <= (b) <= 13) && (1 <= (c) <= 13);
    ensures \result == true <==> (a + b + c) <= 21;
    ensures \result == false <==> (a + b + c) > 21;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result = false;
    unsigned int sum = 0;
    
    //@ assert (1 <= (a) <= 13);
    //@ assert (1 <= (b) <= 13);
    //@ assert (1 <= (c) <= 13);
    
    sum = a + b + c;
    
    //@ assert sum == a + b + c;
    
    if (sum <= 21)
    {
        result = true;
    }
    
    //@ assert result == (sum <= 21);
    
    return result;
}
