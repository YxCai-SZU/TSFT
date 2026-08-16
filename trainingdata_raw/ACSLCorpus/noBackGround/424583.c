#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(int n)
{
    int result;
    
    //@ assert (1 <= (n) <= 100);
    
    if ((n % 2 == 0) && (n >= 13)) {
        result = 1;
    } else if ((n % 2 != 0) && (n >= 13)) {
        result = 0;
    } else if ((n % 2 == 0) && (n <= 12)) {
        result = 0;
    } else if ((n % 2 != 0) && (n <= 12)) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert result == 0 || result == 1;
    
    return result;
}
