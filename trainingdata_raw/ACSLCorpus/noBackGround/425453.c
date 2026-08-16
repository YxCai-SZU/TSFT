#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> ((((n)) % 100) * 21) < 10;
    ensures \result == 1 ==> ((((n)) % 100) * 21) >= 10;
*/
int func(int n)
{
    unsigned int n_unsigned;
    unsigned int remainder;
    unsigned int comparison;
    int result;

    //@ assert (1 <= (n) && (n) <= 10000);
    
    if (n < 0)
    {
        n_unsigned = (unsigned int)(-n);
    }
    else
    {
        n_unsigned = (unsigned int)n;
    }
    
    remainder = n_unsigned % 100;
    comparison = remainder * 21;
    
    if (comparison < 10)
    {
        //@ assert ((((n)) % 100) * 21) < 10;
        result = 0;
    }
    else
    {
        //@ assert ((((n)) % 100) * 21) >= 10;
        result = 1;
    }
    
    return result;
}
