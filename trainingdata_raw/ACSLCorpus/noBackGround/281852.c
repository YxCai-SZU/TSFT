#include <stddef.h>
#include <stdint.h>

/*@
  requires n > 0;
  requires k > 0;
  requires \valid(arr + (0 .. n-1));
  requires ((n) > 0 &&
      \forall integer i; 0 <= i < (n) ==> (arr)[i] > 0 && (arr)[i] <= 1000000000);
  assigns \nothing;
  ensures 0 <= \result <= n;
  ensures \forall integer i; 0 <= i < n ==> 
          (arr[i] % k == 0 ==> \result > 0);
  ensures \forall integer i; 0 <= i < n ==> 
          (arr[i] % k != 0 ==> \result >= 0);
*/
size_t func(size_t n, size_t k, size_t *arr) {
    size_t ans = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= ans <= index;
      loop invariant k > 0;
      loop invariant ((n) > 0 &&
      \forall integer i; 0 <= i < (n) ==> (arr)[i] > 0 && (arr)[i] <= 1000000000);
      loop invariant index > 0 ==> 
        \forall integer i; 0 <= i < index ==> 
        (arr[i] % k == 0 ==> ans > 0);
      loop invariant index > 0 ==> 
        \forall integer i; 0 <= i < index ==> 
        (arr[i] % k != 0 ==> ans >= 0);
      loop assigns ans, index;
      loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        
        if (arr[index] % k == 0) {
            ans += 1;
        }
        
        index += 1;
    }
    
    return ans;
}
