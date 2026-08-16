#include <stdbool.h>

/*@
    predicate has_odd(int* arr, integer len) =
        \exists integer i; 0 <= i < len && (arr[i] & 1) != 0;

    predicate all_even(int* arr, integer len) =
        \forall integer i; 0 <= i < len ==> (arr[i] & 1) == 0;

    lemma odd_implies_exists:
        \forall int* arr, integer len;
            has_odd(arr, len) ==> \exists integer i; 0 <= i < len && (arr[i] & 1) != 0;

    lemma even_implies_forall:
        \forall int* arr, integer len;
            all_even(arr, len) ==> \forall integer i; 0 <= i < len ==> (arr[i] & 1) == 0;
*/

/*@
    requires \valid(arr + (0..len-1));
    requires len > 0;
    ensures \result == true ==> has_odd(arr, len);
    ensures \result == false ==> all_even(arr, len);
*/
bool find_odd(int* arr, int len) {
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> (arr[j] & 1) == 0;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if ((arr[i] & 1) != 0) {
            //@ assert has_odd(arr, len);
            return true;
        }
        i++;
    }
    //@ assert all_even(arr, len);
    return false;
}
