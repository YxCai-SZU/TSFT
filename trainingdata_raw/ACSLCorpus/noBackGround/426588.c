#include <stdbool.h>

/*@
    requires 10 <= n <= 99;
    ensures \result == true <==> ((n) % 10 == 9 || ((n) / 10) % 10 == 9);
*/
bool func(int n)
{
    unsigned long long n_unsigned;
    bool result;

    //@ assert n >= 10 && n <= 99;
    
    if (n < 0)
    {
        n_unsigned = (unsigned long long)(-n);
    }
    else
    {
        n_unsigned = (unsigned long long)n;
    }
    
    //@ assert n_unsigned == (n < 0 ? (unsigned long long)(-n) : (unsigned long long)n);
    
    result = (n_unsigned % 10 == 9) || ((n_unsigned / 10) % 10 == 9);
    
    //@ assert result == true <==> ((n) % 10 == 9 || ((n) / 10) % 10 == 9);
    
    return result;
}
