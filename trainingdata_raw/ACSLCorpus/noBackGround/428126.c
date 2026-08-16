#include <stdbool.h>

/*@
    requires \valid(a + (0..2));
    requires ((3) == 3 &&
    \forall integer i; 0 <= i < (3) ==> 1 <= (a)[i] <= 100);
    ensures \result == (a[1] < a[0] && a[1] < a[2]);
    assigns \nothing;
*/
bool func(int *a) {
    bool result;
    
    //@ assert ((3) == 3 &&     \forall integer i; 0 <= i < (3) ==> 1 <= (a)[i] <= 100);
    
    if (a[1] < a[0] && a[1] < a[2]) {
        //@ assert a[1] < a[0] && a[1] < a[2];
        result = true;
    } else {
        //@ assert !(a[1] < a[0] && a[1] < a[2]);
        result = false;
    }
    
    return result;
}
