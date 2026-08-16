#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result == (((a) * (a)) < 1000 || ((b) * (b)) < 1000 || ((a) * (b)) < 1000);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    //@ assert 1 <= ((a) * (a)) <= 10000;
    
    //@ assert 1 <= ((b) * (b)) <= 10000;
    
    //@ assert 1 <= ((a) * (b)) <= 10000;
    
    if (a * a < 1000) {
        return true;
    } else if (b * b < 1000) {
        return true;
    } else if (a * b < 1000) {
        return true;
    } else {
        return false;
    }
}
