#include <stdbool.h>

/*@ predicate sorted(int *arr, integer len) =
      \forall integer i, j; 0 <= i < j < len ==> arr[i] <= arr[j];
*/

/*@ predicate exists_at(int *arr, integer len, int x) =
      \exists integer i; 0 <= i < len && arr[i] == x;
*/

/*@ lemma sorted_preserved:
      \forall int *arr, integer len, integer i;
      sorted(arr, len) && 0 <= i < len ==> sorted(arr, len);
*/

/*@ requires 0 <= n;
    requires sorted(arr, n);
    ensures \result == true <==> exists_at(arr, n, x);
    assigns \nothing;
*/
bool search(int *arr, int n, int x) {
    int i = 0;
    /*@ loop invariant 0 <= i <= n;
        loop invariant sorted(arr, n);
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] != x;
        loop assigns i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (arr[i] == x) {
            //@ assert exists_at(arr, n, x);
            return true;
        }
        i = i + 1;
    }
    //@ assert \forall integer k; 0 <= k < n ==> arr[k] != x;
    return false;
}
