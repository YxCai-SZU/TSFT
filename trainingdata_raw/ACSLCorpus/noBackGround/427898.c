#include <stdbool.h>
#include <stddef.h>

/*@
  requires n > 0;
  requires \valid(arr + (0..n-1));
  requires (\forall integer i; 0 <= i < (n) ==> (arr)[i] > 0);
  ensures \result == true <==> (\forall integer i; 0 <= i < (n) && (arr)[i] % 2 == 0 ==> 
         (arr)[i] % 3 == 0 || (arr)[i] % 5 == 0);
*/
bool func(size_t n, int arr[]) {
    bool ans = true;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant \forall integer k; 0 <= k < i && arr[k] % 2 == 0 ==> 
                     arr[k] % 3 == 0 || arr[k] % 5 == 0;
      loop invariant ans == true <==> 
                     (\forall integer k; 0 <= k < i && arr[k] % 2 == 0 ==> 
                      arr[k] % 3 == 0 || arr[k] % 5 == 0);
      loop assigns i, ans;
      loop variant n - i;
    */
    while (i < n) {
        int ai = arr[i];
        
        if (ai % 2 != 0) {
            i++;
            continue;
        }
        
        //@ assert ai % 2 == 0;
        
        if (!(ai % 3 == 0 || ai % 5 == 0)) {
            ans = false;
            break;
        }
        
        //@ assert ai % 3 == 0 || ai % 5 == 0;
        i++;
    }
    
    return ans;
}
