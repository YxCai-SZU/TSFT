#include <stdbool.h>

/*@ requires (1 <= (x) <= 9);
    ensures \result == true <==> ((x) == 3 || (x) == 5 || (x) == 7);
    assigns \nothing;
 */
bool func(int x) {
    int a;
    int b;
    int c;
    bool result;
    
    a = 3;
    b = 5;
    c = 7;
    
    //@ assert (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    
    if (x == a || x == b || x == c) {
        //@ assert ((x) == 3 || (x) == 5 || (x) == 7);
        result = true;
    } else {
        //@ assert !((x) == 3 || (x) == 5 || (x) == 7);
        result = false;
    }
    
    return result;
}
