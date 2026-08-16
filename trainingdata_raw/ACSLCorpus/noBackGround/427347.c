#include <stdbool.h>
/*@
    requires \valid(list+(0..len-1));
    requires len > 0;
    ensures \result == true ==> \exists integer i; 0 <= i < len && list[i] == target;
    ensures \result == false ==> \forall integer i; 0 <= i < len ==> list[i] != target;
*/
bool contains_target(int target, int *list, int len) {
    int i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\forall integer j; 0 <= j < (i) ==> (list)[j] != (target));
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert (\forall integer j; 0 <= j < (i) ==> (list)[j] != (target));
        if (list[i] == target) {
            //@ assert (\exists integer j; 0 <= j < (i+1) && (list)[j] == (target));
            return true;
        }
        i++;
        //@ assert (\forall integer j; 0 <= j < (i) ==> (list)[j] != (target));
    }
    //@ assert (\forall integer j; 0 <= j < (len) ==> (list)[j] != (target));
    return false;
}
