#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> (a + b == c || a + c == b || b + c == a);
    assigns \nothing;
*/
bool func(int a, int b, int c) {
    int max;

    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;
    
    if (a > b) {
        if (a > c) {
            max = a;
        } else {
            max = c;
        }
    } else {
        if (b > c) {
            max = b;
        } else {
            max = c;
        }
    }

    //@ assert max == ((a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c)));
    
    if (a + b == max || a + c == max || b + c == max) {
        //@ assert a + b == max || a + c == max || b + c == max;
        return true;
    } else {
        //@ assert a + b != max && a + c != max && b + c != max;
        //@ assert !((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
        return false;
    }
}
