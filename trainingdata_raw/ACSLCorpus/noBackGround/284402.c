#include <stdbool.h>
/*@
    requires \valid(a + (0..1));
    requires 1 <= a[0] <= 100;
    requires 0 <= a[1] <= 4111;
    assigns \nothing;
    ensures \result == (((a[0]) < 10 && (a[1]) < 10) ? ((a[1]) + (a[0]) * 100) : -1);
*/
int func(int a[2]) {
    int result = -1;
    //@ assert (1 <= (a[0]) <= 100 && 0 <= (a[1]) <= 4111);
    
    if (a[0] < 10 && a[1] < 10) {
        result = a[1] + a[0] * 100;
        //@ assert a[0] < 10 && a[1] < 10 ==> result == a[1] + a[0] * 100;
    }
    //@ assert !(a[0] < 10 && a[1] < 10) ==> result == -1;
    
    //@ assert result == (((a[0]) < 10 && (a[1]) < 10) ? ((a[1]) + (a[0]) * 100) : -1);
    return result;
}
