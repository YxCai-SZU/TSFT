#include <stdbool.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result == true <==> (a < c && b < c) || (a > c && b > c);
*/
bool func(int a, int b, int c) {
    bool result;
    
    if ((a < c && b < c) || (a > c && b > c)) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == true <==> (a < c && b < c) || (a > c && b > c);
    
    return result;
}
