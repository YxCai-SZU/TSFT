#include <stdbool.h>

/*@
    requires (100 <= (n) && (n) <= 999);
    assigns \nothing;
    ensures \result == true <==> ((n) / 100 == 7 ||
        ((n) / 10) % 10 == 7 ||
        (n) % 10 == 7);
*/
bool func(unsigned int n)
{
    bool ret;
    
    //@ assert (100 <= (n) && (n) <= 999);
    
    ret = (n / 100 == 7) || ((n / 10) % 10 == 7) || (n % 10 == 7);
    
    //@ assert ret == true <==> ((n) / 100 == 7 ||         ((n) / 10) % 10 == 7 ||         (n) % 10 == 7);
    
    return ret;
}
