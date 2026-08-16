#include <stdbool.h>

/*@
    requires (3 <= (a) <= 20) && (3 <= (b) <= 20);
    ensures \result == a + b || \result == b * 2 - 1 || \result == a * 2 - 1;
    ensures \result >= 0;
*/
int func(int a, int b)
{
    int max_val;
    int min_val;
    int result;

    //@ assert (3 <= (a) <= 20) && (3 <= (b) <= 20);

    // Implementing min manually
    if (a < b) {
        min_val = a;
        max_val = b;
    } else {
        min_val = b;
        max_val = a;
    }

    a = max_val;
    b = min_val;

    //@ assert a == ((a) > (b) ? (a) : (b)) && b == ((a) < (b) ? (a) : (b));
    //@ assert (3 <= (a) <= 20) && (3 <= (b) <= 20);

    if (a == b) {
        result = a + b;
        //@ assert result == a + b;
    } else if (a == b + 1) {
        result = b * 2 - 1;
        //@ assert result == b * 2 - 1;
    } else {
        result = a * 2 - 1;
        //@ assert result == a * 2 - 1;
    }

    //@ assert result == a + b || result == b * 2 - 1 || result == a * 2 - 1;
    //@ assert result >= 0;

    return result;
}
