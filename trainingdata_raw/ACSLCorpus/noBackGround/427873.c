#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == true <==> ((a > c) || (a == c && b > d));
    assigns \nothing;
*/
bool func(int a, int b, int c, int d) {
    bool result;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    
    if (a == c) {
        if (b > d) {
            //@ assert a == c && b > d;
        }
    } else if (a > c) {
        //@ assert a > c;
    }
    
    result = (a > c) || (a == c && b > d);
    return result;
}
