#include <stdbool.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int max_result;

    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    
    result = c - a + b;
    //@ assert result == ((c) - (a) + (b));
    
    if (result > 0) {
        max_result = result;
    } else {
        max_result = 0;
    }
    //@ assert max_result == ((((c)) - ((a)) + ((b))) > 0 ? (((c)) - ((a)) + ((b))) : 0);
    
    //@ assert max_result >= 0;
    //@ assert max_result <= c;
    
    return max_result;
}
