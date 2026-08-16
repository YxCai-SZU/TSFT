#include <stdbool.h>

/*@
    requires (3) == 3;
    requires ((a0) == 0 || (a1) == 0 || (a2) == 0);
    ensures \result >= 0;
    ensures \result <= 1;
*/
int func(int a0, int a1, int a2) {
    int is_exist;
    int index;
    int a[3];

    a[0] = a0;
    a[1] = a1;
    a[2] = a2;

    is_exist = 0;
    index = 0;

    /*@
        loop invariant 0 <= index <= 3;
        loop invariant is_exist == 0 || is_exist == 1;
        loop invariant (3) == 3;
        loop invariant ((a[0]) == 0 || (a[1]) == 0 || (a[2]) == 0);
        loop invariant \forall integer k; 0 <= k < index ==> a[k] != 0;
        loop assigns index, is_exist;
    */
    while (index < 3) {
        //@ assert 0 <= index < 3;
        if (a[index] == 0) {
            is_exist = 1;
            break;
        }
        index = index + 1;
    }
    return is_exist;
}
