#include <stdbool.h>

/*@
    predicate all_ones_or_threes(int *arr, integer len) =
        \forall integer i; 0 <= i < len ==> (arr[i] == 1 || arr[i] == 3);
    
    predicate all_one_two_three(int *arr, integer len) =
        \forall integer i; 0 <= i < len ==> (arr[i] == 1 || arr[i] == 2 || arr[i] == 3);
    
    lemma loop_maintains:
        \forall int *arr, integer len, integer index;
        all_one_two_three(arr, len) ==>
        (0 <= index <= len && all_ones_or_threes(arr, index)) ==>
        (index < len && arr[index] != 2 ==> all_ones_or_threes(arr, index+1));
*/

/*@
    requires len >= 1;
    requires all_one_two_three(v, len);
    ensures \result == true <==> all_ones_or_threes(v, len);
*/
bool func(int *v, int len) {
    int index = 0;
    //@ ghost int old_len = len;
    
    /*@
        loop invariant 0 <= index <= len;
        loop invariant all_ones_or_threes(v, index);
        loop invariant all_one_two_three(v, old_len);
        loop assigns index;
    */
    while (index < len) {
        //@ assert 0 <= index < len;
        
        if (v[index] == 2) {
            return false;
        }
        //@ assert v[index] == 1 || v[index] == 3;
        index++;
    }
    return true;
}
