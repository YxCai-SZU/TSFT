#include <stdbool.h>

/*@ requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> a + b == c + d;
*/
bool func(int a, int b, int c, int d) {
    int x;
    int y;
    bool result;

    x = a + b;
    y = c + d;

    //@ assert x == y || x != y;

    result = (x == y);
    return result;
}
