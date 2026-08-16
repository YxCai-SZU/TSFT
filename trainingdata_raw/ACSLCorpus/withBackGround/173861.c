#include <stdbool.h>

/*@ predicate is_range_sorted(integer a, integer b, integer c) =
      a < b && b < c;
*/

/*@
  requires -100 <= a <= 100;
  requires -100 <= b <= 100;
  requires -100 <= c <= 100;
  ensures \result == true <==> is_range_sorted(a, b, c);
*/
bool is_range_sorted(int a, int b, int c) {
    bool result;
    result = a < b && b < c;
    //@ assert result == true <==> is_range_sorted(a, b, c);
    return result;
}

/*@
  requires \valid(arr + (0..len-1));
  requires len > 0;
  requires \forall integer i; 0 <= i < len ==> -100 <= arr[i] <= 100;
  ensures \exists integer i; 0 <= i < len && \result == arr[i];
  ensures \forall integer i; 0 <= i < len ==> \result >= arr[i];
*/
int find_max(int *arr, int len) {
    int max;
    int i;
    max = arr[0];
    i = 1;
    /*@
      loop invariant 1 <= i <= len;
      loop invariant \exists integer j; 0 <= j < i && max == arr[j];
      loop invariant \forall integer j; 0 <= j < i ==> max >= arr[j];
      loop assigns i, max;
    */
    while (i < len) {
        if (arr[i] > max) {
            max = arr[i];
        }
        i++;
    }
    //@ assert \forall integer j; 0 <= j < len ==> max >= arr[j];
    return max;
}

/*@
  requires \valid(arr + (0..len-1));
  requires len > 0;
  requires \forall integer i; 0 <= i < len ==> -100 <= arr[i] <= 100;
  ensures \exists integer i; 0 <= i < len && \result == arr[i];
  ensures \forall integer i; 0 <= i < len ==> \result <= arr[i];
*/
int find_min(int *arr, int len) {
    int min;
    int i;
    min = arr[0];
    i = 1;
    /*@
      loop invariant 1 <= i <= len;
      loop invariant \exists integer j; 0 <= j < i && min == arr[j];
      loop invariant \forall integer j; 0 <= j < i ==> min <= arr[j];
      loop assigns i, min;
    */
    while (i < len) {
        if (arr[i] < min) {
            min = arr[i];
        }
        i++;
    }
    //@ assert \forall integer j; 0 <= j < len ==> min <= arr[j];
    return min;
}
