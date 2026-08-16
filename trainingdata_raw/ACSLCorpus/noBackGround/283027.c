#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures 1 <= \result <= 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result = 0;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    if (a == b) {
        result += 1;
    }
    if (a == c) {
        result += 1;
    }
    if (b == c) {
        result += 1;
    }
    
    //@ assert 0 <= result <= 3;
    
    if (result == 3) {
        result = 1;
    } else {
        result = result + 1;
    }
    
    //@ assert 1 <= result <= 3;
    return result;
}
