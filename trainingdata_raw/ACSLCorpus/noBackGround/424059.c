#include <stdbool.h>

/*@
    requires \valid_read(vec + (0 .. len-1));
    requires len >= 0;
    assigns \nothing;
    ensures \result == true ==> (\forall integer j; 0 <= j < (len) ==> (vec)[j] == 0);
    ensures \result == false ==> !(\forall integer j; 0 <= j < (len) ==> (vec)[j] == 0);
 */
bool is_none(int *vec, int len) {
    int i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\forall integer j; 0 <= j < (i) ==> (vec)[j] == 0);
        loop assigns i;
        loop variant len - i;
     */
    while (i < len) {
        if (vec[i] != 0) {
            //@ assert !(\forall integer j; 0 <= j < (len) ==> (vec)[j] == 0);
            return false;
        }
        i = i + 1;
    }
    //@ assert (\forall integer j; 0 <= j < (len) ==> (vec)[j] == 0);
    return true;
}
