#include <stdbool.h>
/*@
    requires \valid(arr + (0..len-1));
    requires len > 0;
    ensures \result ==> (\exists integer i; 0 <= i < (len) && (arr)[i] == 0);
    ensures !\result ==> (\forall integer i; 0 <= i < (len) ==> (arr)[i] != 0);
    assigns \nothing;
*/
bool contains_zero(int *arr, int len) {
    int i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] != 0;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] == 0) {
            //@ assert (\exists integer i; 0 <= i < (len) && (arr)[i] == 0);
            return true;
        }
        //@ assert arr[i] != 0;
        i++;
    }
    //@ assert (\forall integer i; 0 <= i < (len) ==> (arr)[i] != 0);
    return false;
}
