#include <stdbool.h>

/*@ predicate sorted_increasing(int* arr, integer len) =
      \forall integer i; 0 <= i < len-1 ==> arr[i] < arr[i+1];
*/

/*@ predicate within_range(int* arr, integer len, integer low, integer high) =
      \forall integer i; 0 <= i < len ==> arr[i] >= low && arr[i] <= high;
*/

/*@ logic integer absolute_difference(integer a, integer b) =
      a > b ? a - b : b - a;
*/

/*@ lemma diff_equals_last_minus_first:
      \forall int* arr, integer len;
        len == 5 && sorted_increasing(arr, len) ==>
        absolute_difference(arr[0], arr[4]) == arr[4] - arr[0];
*/

/*@ requires \valid(v + (0..4));
    requires within_range(v, 5, 0, 123);
    requires sorted_increasing(v, 5);
    requires k >= 0 && k <= 123;
    ensures \result == (v[4] - v[0] <= k);
*/
bool func(int v[5], int k)
{
    int first;
    int last;
    int diff;
    
    first = v[0];
    last = v[4];
    
    //@ assert first < last;
    
    if (first > last) {
        diff = first - last;
    } else {
        diff = last - first;
    }
    
    //@ assert diff == v[4] - v[0];
    
    return diff <= k;
}
