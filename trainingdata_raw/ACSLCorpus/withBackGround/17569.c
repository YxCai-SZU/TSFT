#include <stdbool.h>

/*@
    predicate all_unique(int *listval, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> listval[i] != listval[j];

    lemma outer_loop_invariant_maintains:
        \forall int *listval, integer len, integer i;
            0 <= i <= len && len > 0 &&
            (\forall integer ii, jj; 0 <= ii < i && ii < jj < len ==> listval[ii] != listval[jj]) &&
            i < len ==>
            (\forall integer jj; 0 <= jj < i+1 && jj != i ==> listval[i] != listval[jj]);

    lemma inner_loop_invariant_maintains:
        \forall int *listval, integer len, integer i, integer j;
            0 <= i < len && i < j <= len && len > 0 &&
            (\forall integer ii, jj; 0 <= ii < i && ii < jj < len ==> listval[ii] != listval[jj]) &&
            (\forall integer jj; 0 <= jj < j && jj != i ==> listval[i] != listval[jj]) &&
            j < len && listval[i] != listval[j] ==>
            (\forall integer jj; 0 <= jj < j+1 && jj != i ==> listval[i] != listval[jj]);
*/

/*@
    requires \valid(listval + (0 .. len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result <==> all_unique(listval, len);
*/
bool all_unique(int *listval, int len) {
    int i = 0;
    int j = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant len > 0;
        loop invariant \forall integer ii, jj; 0 <= ii < i && ii < jj < len ==> listval[ii] != listval[jj];
        loop assigns i, j;
        loop variant len - i;
    */
    while (i < len) {
        j = i + 1;
        
        /*@
            loop invariant 0 <= i < len;
            loop invariant i < j <= len;
            loop invariant len > 0;
            loop invariant \forall integer ii, jj; 0 <= ii < i && ii < jj < len ==> listval[ii] != listval[jj];
            loop invariant \forall integer jj; 0 <= jj < j && jj != i ==> listval[i] != listval[jj];
            loop assigns j;
            loop variant len - j;
        */
        while (j < len) {
            //@ assert 0 <= i < len && 0 <= j < len;
            if (listval[i] == listval[j]) {
                //@ assert !all_unique(listval, len);
                return false;
            }
            j++;
        }
        i++;
    }
    //@ assert all_unique(listval, len);
    return true;
}
