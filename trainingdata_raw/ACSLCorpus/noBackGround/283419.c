#include <stdbool.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == ((c) > (a) - (b) ? (c) - ((a) - (b)) : 0);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    
    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    
    if (c > (a - b)) {
        result = c - (a - b);
    } else {
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result <= c;
    //@ assert result == ((c) > (a) - (b) ? (c) - ((a) - (b)) : 0);
    
    return result;
}
