#include <stdbool.h>

/*@
    predicate condition(integer n) =
        n % 100 < 5 || (n % 100) % 5 == 0;
*/


bool func(int n)
{
    int mod100;
    bool result;
    
    mod100 = n % 100;
    
    if (mod100 < 5 || mod100 % 5 == 0) {
        //@ assert mod100 < 5 || mod100 % 5 == 0;
        result = true;
    } else {
        //@ assert mod100 >= 5 && mod100 % 5 != 0;
        result = false;
    }
    
    return result;
}
