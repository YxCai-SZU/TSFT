#include <stdbool.h>
/*@
    requires len > 0;
    requires \valid(list + (0 .. len-1));
    ensures ((\result) == true ?
            \exists integer i; 0 <= i < (len) && (list)[i] == (target)
        :
            \forall integer i; 0 <= i < (len) ==> (list)[i] != (target));
    assigns \nothing;
*/
bool contains_target(int target, int *list, int len) {
    int i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> list[j] != target;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (list[i] == target) {
            //@ assert \exists integer j; 0 <= j < len && list[j] == target;
            return true;
        }
        //@ assert list[i] != target;
        i++;
    }
    //@ assert \forall integer j; 0 <= j < len ==> list[j] != target;
    return false;
}
