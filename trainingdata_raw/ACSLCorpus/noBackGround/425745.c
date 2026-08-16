#include <stdbool.h>

/*@ requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    requires -100 <= d <= 100;
    ensures \result == 1 <==> ((a) <= (c) && (c) <= (b) && (d) <= (b) && (a) <= (d));
*/
bool func(int a, int b, int c, int d) {
    bool result;
    //@ assert ((a) <= (c) && (c) <= (b) && (d) <= (b) && (a) <= (d)) ==> ((a) <= (c) && (c) <= (b) && (d) <= (b) && (a) <= (d));
    result = a <= c && c <= b && d <= b && a <= d;
    return result;
}
