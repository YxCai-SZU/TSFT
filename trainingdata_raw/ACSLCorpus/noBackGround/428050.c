#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(list1 + (0..len-1));
    requires len >= 0;
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len ==> 
            (list1[i] == val ==> \result >= 1);
*/
int count_val(int *list1, int len, int val) {
    int count = 0;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant ((count) >= 0 && (count) <= (i));
        loop invariant (\forall integer j; 0 <= j < (i) ==> 
            ((list1)[j] == (val) ==> (count) >= 1));
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert i >= 0 && i < len;
        if (list1[i] == val) {
            count = count + 1;
        }
        i = i + 1;
    }
    return count;
}
