#include <stdbool.h>
/*@
    requires 1 <= len <= 100;
    requires \valid_read(a + (0 .. len - 1));
    assigns \nothing;
    ensures \result == true <==> (\forall integer i; 0 <= i < (len) - 1 ==> (a)[i] < (a)[i + 1]);
*/
bool check_consecutive_increasing(int *a, int len) {
    int i = 0;
    /*@
        loop invariant 0 <= i <= len - 1;
        loop invariant \forall integer j; 0 <= j < i ==> a[j] < a[j + 1];
        loop assigns i;
        loop variant len - i;
    */
    while (i < len - 1) {
        //@ assert 0 <= i < len;
        if (a[i] >= a[i + 1]) {
            return false;
        }
        i++;
    }
    return true;
}
