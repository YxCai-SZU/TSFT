#include <stdbool.h>

/*@ requires 1 <= a <= 10;
    requires 1 <= b <= 10;
    requires 1 <= c <= 10;
    ensures \result == true <==> ((a == 5 && b == 5 && c == 7) || (a == 5 && b == 7 && c == 5) || (a == 7 && b == 5 && c == 5));
*/
bool func(int a, int b, int c) {
    bool result;
    //@ assert 1 <= a <= 10 && 1 <= b <= 10 && 1 <= c <= 10;
    
    if ((a == 5 && b == 5 && c == 7) || (a == 5 && b == 7 && c == 5) || (a == 7 && b == 5 && c == 5)) {
        //@ assert (((a) == 5 && (b) == 5 && (c) == 7) ||       ((a) == 5 && (b) == 7 && (c) == 5) ||       ((a) == 7 && (b) == 5 && (c) == 5));
        result = true;
    } else {
        //@ assert !(((a) == 5 && (b) == 5 && (c) == 7) ||       ((a) == 5 && (b) == 7 && (c) == 5) ||       ((a) == 7 && (b) == 5 && (c) == 5));
        result = false;
    }
    
    return result;
}
