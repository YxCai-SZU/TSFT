#include <stdbool.h>

/*@ requires 0 <= len1 && 0 <= len2;
    requires \valid(list1 + (0 .. len1-1));
    requires \valid(list2 + (0 .. len2-1));
    ensures \result ==> (\exists integer i, j; 0 <= i < (len1) && 0 <= j < (len2) && (list1)[i] == (list2)[j]);
    ensures !\result ==> (\forall integer i, j; 0 <= i < (len1) && 0 <= j < (len2) ==> (list1)[i] != (list2)[j]);
    assigns \nothing;
*/
bool has_common_element_c(int *list1, int len1, int *list2, int len2)
{
    int i = 0;
    int j = 0;
    
    /*@ loop invariant 0 <= i <= len1;
        loop invariant \forall integer k, m; 0 <= k < i && 0 <= m < len2 ==> list1[k] != list2[m];
        loop assigns i, j;
        loop variant len1 - i;
    */
    while (i < len1) {
        j = 0;
        
        /*@ loop invariant 0 <= i < len1;
            loop invariant 0 <= j <= len2;
            loop invariant \forall integer k, m; (0 <= k < i && 0 <= m < len2) || (k == i && 0 <= m < j) ==> list1[k] != list2[m];
            loop assigns j;
            loop variant len2 - j;
        */
        while (j < len2) {
            //@ assert 0 <= i < len1 && 0 <= j < len2;
            if (list1[i] == list2[j]) {
                //@ assert (\exists integer i, j; 0 <= i < (len1) && 0 <= j < (len2) && (list1)[i] == (list2)[j]);
                return true;
            }
            j++;
        }
        i++;
    }
    
    //@ assert (\forall integer i, j; 0 <= i < (len1) && 0 <= j < (len2) ==> (list1)[i] != (list2)[j]);
    return false;
}
