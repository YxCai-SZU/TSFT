#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 13) && (1 <= (b) && (b) <= 13) && (1 <= (c) && (c) <= 13);
    ensures \result == true <==> (a + b + c >= 22);
    ensures \result == false <==> (a + b + c < 22);
*/
bool func(unsigned long a, unsigned long b, unsigned long c)
{
    unsigned long total;
    bool result;

    total = a + b + c;
    
    if (total >= 22)
    {
        result = true;
        //@ assert total >= 22;
    }
    else
    {
        //@ assert total < 22;
        result = false;
    }
    
    return result;
}
