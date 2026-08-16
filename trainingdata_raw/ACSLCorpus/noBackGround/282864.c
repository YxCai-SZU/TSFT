#include <stdbool.h>

/*@
  requires n > 0 && n <= 100;
  requires \valid(arr + (0 .. n-1));
  requires ((n) > 0 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> ((arr)[i] > 0 && (arr)[i] <= 1000));
  ensures \result == true <==> (\forall integer i; 0 <= i < (n) ==>
        ((arr)[i] % 2 == 0 ==> ((arr)[i] % 3 == 0 || (arr)[i] % 5 == 0)));
  assigns \nothing;
*/
bool func(int n, int *arr) {
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant ((n) > 0 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> ((arr)[i] > 0 && (arr)[i] <= 1000));
      loop invariant \forall integer k; 0 <= k < i && arr[k] % 2 == 0 ==> 
                     arr[k] % 3 == 0 || arr[k] % 5 == 0;
      loop assigns i;
      loop variant n - i;
    */
    while (i < n) {
        int x = arr[i];
        
        //@ assert x > 0 && x <= 1000;
        
        if (x % 2 == 0) {
            //@ assert x % 2 == 0;
            if (x % 3 != 0 && x % 5 != 0) {
                //@ assert !(x % 3 == 0 || x % 5 == 0);
                return false;
            }
        }
        i++;
    }
    return true;
}
