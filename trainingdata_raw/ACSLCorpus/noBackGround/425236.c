#include <stddef.h>
#include <stdbool.h>

/*@
  requires n >= 1 && n <= 100;
  requires \valid(arr + (0 .. n-1));
  requires \forall integer i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= 100;
  assigns \nothing;
  ensures 0 <= \result <= n;
  ensures \forall integer i; 0 <= i < n ==> 
          (i + 1) % 2 == 0 && arr[i] % 2 == 0 ==> \result > 0;
*/
size_t func(size_t n, int *arr) {
    size_t ans = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant ans >= 0;
      loop invariant ans <= i;
      loop invariant \forall integer j; 0 <= j < i ==> 
                     (j + 1) % 2 == 0 && arr[j] % 2 == 0 ==> ans > 0;
      loop invariant n >= 1 && n <= 100;
      loop invariant \valid(arr + (0 .. n-1));
      loop invariant \forall integer j; 0 <= j < n ==> arr[j] >= 1 && arr[j] <= 100;
      loop assigns ans, i;
      loop variant n - i;
    */
    while (i < n) {
        int a = arr[i];
        
        //@ assert a >= 1 && a <= 100;
        
        if ((i + 1) % 2 == 0 && a % 2 == 0) {
            ans += 1;
        }
        
        i += 1;
    }
    
    return ans;
}
