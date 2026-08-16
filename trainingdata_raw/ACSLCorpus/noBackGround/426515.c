#include <stdbool.h>

/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures \result == ((a) * 2) || \result == ((b) * 2) || 
            \result == ((((a)) * 2) - 1) || \result == ((((b)) * 2) - 1);
*/
int func(int a, int b)
{
    int max;
    int x;

    if (a > b) {
        max = a;
    } else {
        max = b;
    }

    x = max * 2 - 1;

    //@ assert x == ((((a)) * 2) - 1) || x == ((((b)) * 2) - 1);

    return x;
}
