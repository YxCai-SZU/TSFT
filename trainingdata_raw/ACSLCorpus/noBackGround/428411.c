#include <stdbool.h>
/*@
    requires \valid(list+(0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result <= list[0];
    ensures (\forall integer j; 0 <= j < (len) ==> (\result) <= (list)[j]);
*/
int find_min(int *list, int len) {
    int min;
    int i;
    
    min = list[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\forall integer j; 0 <= j < (i) ==> (min) <= (list)[j]);
        loop assigns min, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (list[i] < min) {
            min = list[i];
        }
        i = i + 1;
    }
    return min;
}
