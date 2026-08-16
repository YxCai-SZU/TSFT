#include <stdbool.h>
#include <stddef.h>

/*@
  requires n >= 2 && n <= 50;
  requires k >= 2 && k <= 100;
  requires \valid(arr + (0 .. n-1));
  requires \forall integer i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= 100;
  assigns \nothing;
  ensures \result == true ==> \forall integer i; 0 <= i < n ==> arr[i] >= k;
  ensures \result == false ==> \exists integer i; 0 <= i < n && arr[i] < k;
*/
bool func(size_t n, size_t k, const size_t *arr) {
    bool ans = true;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant ans == true ==> \forall integer j; 0 <= j < i ==> arr[j] >= k;
      loop invariant ans == false ==> \exists integer j; 0 <= j < i && arr[j] < k;
      loop assigns ans, i;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (arr[i] < k) {
            ans = false;
        }
        i++;
    }
    return ans;
}
