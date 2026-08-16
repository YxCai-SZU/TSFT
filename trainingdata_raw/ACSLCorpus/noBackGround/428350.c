#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100 && 2 <= (b) <= 1000 && (b) % 2 == 0);
    ensures \result == ((a) == 0 ? (b) : ((a) + (a) <= (b) ? (b) - (a) : (b) - (a) - (a)));
    ensures \result == b || \result == b - a || \result == b - a - a;
*/
int func(int a, int b)
{
    int result = 0;
    
    //@ assert (0 <= (a) <= 100 && 2 <= (b) <= 1000 && (b) % 2 == 0);
    
    if (a == 0) {
        result = b;
    } else if (a + a <= b) {
        result = b - a;
    } else {
        result = b - a - a;
    }
    
    //@ assert result == ((a) == 0 ? (b) : ((a) + (a) <= (b) ? (b) - (a) : (b) - (a) - (a)));
    return result;
}
