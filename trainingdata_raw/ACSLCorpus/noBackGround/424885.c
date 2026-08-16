#include <stdbool.h>
#include <stddef.h>

/*@
  requires n >= 1 && n <= 100;
  requires \valid(arr + (0 .. n-1));
  requires ((n) >= 1 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> (arr)[i] >= 1 && (arr)[i] <= 1000);
  ensures \result == true <==> (\forall integer i; 0 <= i < (n) ==> 
        ((arr)[i] % 2 == 0 ==> ((arr)[i] % 3 == 0 || (arr)[i] % 5 == 0)));
  assigns \nothing;
*/
bool func(size_t n, int *arr) {
    bool result = true;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant ((n) >= 1 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> (arr)[i] >= 1 && (arr)[i] <= 1000);
      loop invariant result == true ==> 
        \forall integer j; 0 <= j < i ==> 
          (arr[j] % 2 == 0 ==> (arr[j] % 3 == 0 || arr[j] % 5 == 0));
      loop invariant result == false ==> 
        \exists integer j; 0 <= j < i && 
          arr[j] % 2 == 0 && !(arr[j] % 3 == 0 || arr[j] % 5 == 0);
      loop assigns i, result;
      loop variant n - i;
    */
    while (i < n) {
        int value = arr[i];
        if (value % 2 == 0) {
            if (value % 3 != 0 && value % 5 != 0) {
                result = false;
            }
        }
        i++;
    }
    return result;
}
