#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((a * 100) / 50 >= b);
    assigns \nothing;
*/
bool func(int a, int b) {
    int result;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    result = (a * 100) / 50;
    //@ assert result == (a * 100) / 50;
    
    return result >= b;
}
