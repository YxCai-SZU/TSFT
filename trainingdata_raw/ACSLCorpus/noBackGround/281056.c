#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == ((a < c) && (b > c)) || ((a > c) && (b < c));
*/
bool func(int a, int b, int c) {
    int x;
    int y;
    
    if (a < b) {
        x = a;
        y = b;
    } else {
        x = b;
        y = a;
    }
    
    //@ assert ((x) <= (y));
    
    return (c > x) && (c < y);
}
