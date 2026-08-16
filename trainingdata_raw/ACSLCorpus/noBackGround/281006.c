#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(arr + (0 .. n-1));
  requires ((n) >= 2 && (n) <= 100000 &&
      \forall size_t i; 0 <= i < (n) ==> (arr)[i] >= 1 && (arr)[i] <= 1000000000);
  requires 1 <= k && k <= 1000000000;
  assigns \nothing;
  ensures \result == true <==> (\exists size_t i; 0 <= i < (n) && (arr)[i] % (k) == 0);
*/
bool func(size_t n, size_t k, unsigned int *arr) {
    bool ans = false;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant ans == false || ans == true;
      loop invariant \forall size_t j; 0 <= j < i ==> arr[j] >= 1 && arr[j] <= 1000000000;
      loop invariant ans == true <==> \exists size_t j; 0 <= j < i && arr[j] % k == 0;
      loop invariant ((n) >= 2 && (n) <= 100000 &&
      \forall size_t i; 0 <= i < (n) ==> (arr)[i] >= 1 && (arr)[i] <= 1000000000);
      loop invariant 1 <= k && k <= 1000000000;
      loop assigns ans, i;
      loop variant n - i;
    */
    while (i < n) {
        unsigned int a = arr[i];
        if (a % k == 0) {
            ans = true;
        }
        i++;
    }
    return ans;
}
