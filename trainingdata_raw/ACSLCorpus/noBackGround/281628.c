#include <stdbool.h>

/*@
    requires \valid_read(listval + (0..len-1));
    requires len > 0;
    ensures \result ==> listval[0] > 0;
    ensures \result ==> listval[len-1] > 0;
    assigns \nothing;
*/
bool all_positive(int *listval, int len) {
    bool all_pos = true;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant all_pos ==> (\forall integer j; 0 <= j < (i) ==> (listval)[j] > 0);
        loop invariant len > 0;
        loop assigns i, all_pos;
        loop variant len - i;
    */
    while (i < len) {
        if (listval[i] <= 0) {
            all_pos = false;
        }
        i++;
    }
    
    //@ assert all_pos ==> listval[0] > 0;
    //@ assert all_pos ==> listval[len-1] > 0;
    return all_pos;
}
