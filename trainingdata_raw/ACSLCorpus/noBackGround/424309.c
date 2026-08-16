#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 1000000);
    ensures \result == true <==> ((n) >= 2000 && ((n) % 2000 <= 1000));
    assigns \nothing;
*/
bool func(unsigned long n)
{
    bool result;
    
    //@ assert (1 <= (n) && (n) <= 1000000);
    
    if (n >= 2000) {
        unsigned long r = n % 2000;
        //@ assert n >= 2000;
        result = (r <= 1000);
    } else {
        //@ assert n < 2000;
        result = false;
    }
    
    //@ assert result == true <==> ((n) >= 2000 && ((n) % 2000 <= 1000));
    return result;
}
