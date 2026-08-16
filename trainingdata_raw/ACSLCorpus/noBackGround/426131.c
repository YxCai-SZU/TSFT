#include <stdbool.h>
#include <stddef.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result <= a;
    ensures \result == ((a) % (b) == 0 ? (a) / (b) : (a) / (b) + 1);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int result;
    
    result = a / b;
    
    //@ assert result == a / b;
    
    if (a % b != 0)
    {
        result = result + 1;
        //@ assert result == a / b + 1;
    }
    
    //@ assert result == ((a) % (b) == 0 ? (a) / (b) : (a) / (b) + 1);
    //@ assert result <= a;
    
    return result;
}
