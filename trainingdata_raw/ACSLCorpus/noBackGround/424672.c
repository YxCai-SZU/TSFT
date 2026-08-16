#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100);
    ensures \result == (x >= 30);
    assigns \nothing;
*/
bool func(int x) {
    int a[5] = {1, 2, 3, 4, 5};
    int index = 0;
    
    //@ ghost int original_x = x;
    
    /*@
        loop invariant 0 <= index <= 5;
        loop invariant (1 <= (original_x) <= 100);
        loop assigns index;
        loop variant 5 - index;
    */
    while (index < 5) {
        //@ assert index < 5;
        index = index + 1;
    }
    
    //@ assert (1 <= (original_x) <= 100);
    return x >= 30;
}
