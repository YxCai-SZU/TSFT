#include <stdbool.h>

/*@
    predicate is_in_range(int *a, integer len) =
        \forall integer i; 0 <= i < len ==> 1 <= a[i] && a[i] <= 100;

    predicate is_increasing(int *a, integer len) =
        \forall integer i; 0 <= i < len - 1 ==> a[i] < a[i + 1];
*/

/*@
    requires 1 <= len && len <= 100;
    requires \valid_read(a + (0 .. len - 1));
    requires is_in_range(a, len);
    assigns \nothing;
    ensures \result == true <==> is_increasing(a, len);
*/
bool is_increasing_sequence(int *a, int len) {
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= len - 1;
        loop invariant \forall integer j; 0 <= j < i ==> a[j] < a[j + 1];
        loop assigns i;
        loop variant len - i;
    */
    while (i < len - 1) {
        //@ assert 0 <= i && i < len - 1;
        if (a[i] >= a[i + 1]) {
            return false;
        }
        i++;
    }
    return true;
}
