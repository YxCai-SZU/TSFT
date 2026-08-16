#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int *arr, size_t n) =
      n >= 2 && n <= 50 &&
      \forall size_t i; 0 <= i < n ==> 0 <= arr[i] && arr[i] <= 100;
*/

/*@ predicate monotonic_triplet(int a, int b, int c) =
      (a < b && b < c) || (a > b && b > c);
*/

/*@ lemma c_nonnegative:
      \forall integer c, i; c >= 0 && c <= i ==> c >= 0;
*/

/*@ requires 2 <= n <= 50;
    requires \valid(arr + (0 .. n-1));
    requires valid_array(arr, n);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(size_t n, int arr[]) {
    int c = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n-2;
        loop invariant c >= 0;
        loop invariant c <= (int)i;
        loop invariant valid_array(arr, n);
        loop assigns c, i;
        loop variant n - i;
    */
    while (i < n - 2) {
        //@ assert 0 <= i < n-2;
        if (arr[i] < arr[i + 1] && arr[i + 1] < arr[i + 2]) {
            c = c + 1;
        }
        //@ assert c >= 0;
        if (arr[i] > arr[i + 1] && arr[i + 1] > arr[i + 2]) {
            c = c + 1;
        }
        //@ assert c >= 0;
        i += 1;
    }
    return c;
}
