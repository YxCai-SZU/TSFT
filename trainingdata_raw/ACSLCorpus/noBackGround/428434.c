#include <stdbool.h>

/*@
    requires \valid_read(a + (0..1));
    requires a[0] >= -100 && a[0] <= 100;
    requires a[1] >= -100 && a[1] <= 100;
    assigns \nothing;
    ensures (a[0] == a[1] && \result == 0) ||
            (a[0] != a[1] && \result == 1);
*/
int func(int *a) {
    int result;
    
    //@ assert a[0] >= -100 && a[0] <= 100;
    
    if (a[0] == a[1]) {
        //@ assert ((a)[(0)] == (a)[(1)]);
        result = 0;
    } else {
        //@ assert !((a)[(0)] == (a)[(1)]);
        result = 1;
    }
    
    //@ assert (a[0] == a[1] && result == 0) || (a[0] != a[1] && result == 1);
    return result;
}
