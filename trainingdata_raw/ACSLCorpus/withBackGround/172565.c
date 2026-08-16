#include <stdbool.h>
#include <stddef.h>

/*@ predicate zero_exists(int* arr, integer len) =
      \exists integer j; 0 <= j < len && arr[j] == 0;
*/

/*@ predicate no_zeros(int* arr, integer len) =
      \forall integer j; 0 <= j < len ==> arr[j] != 0;
*/

/*@ lemma index_bound: \forall integer i, integer len;
      0 <= i < len ==> i <= len;
*/

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires \forall integer i; 0 <= i < len ==> 
           arr[i] >= -2147483648 && arr[i] <= 2147483647;
  ensures \result == true ==> zero_exists(arr, len);
  ensures \result == false ==> no_zeros(arr, len);
*/
bool exists_number(int* arr, size_t len) {
    size_t index = 0;
    /*@
      loop invariant 0 <= index <= len;
      loop invariant \forall integer i; 0 <= i < index ==> arr[i] != 0;
      loop assigns index;
      loop variant len - index;
    */
    while (index < len) {
        int x = arr[index];
        if (x == 0) {
            //@ assert zero_exists(arr, len);
            return true;
        }
        //@ assert arr[index] != 0;
        index++;
    }
    //@ assert no_zeros(arr, len);
    return false;
}
