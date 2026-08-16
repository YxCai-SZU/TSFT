#include <stdbool.h>

/*@
  requires (3 <= (n) <= 10);
  requires \valid(numbers + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] <= 100);
  ensures \result == true <==> (\forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] <= 100);
*/
bool func(int n, int *numbers) {
    int i = 0;
    int j;
    int sum;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant \forall integer k; 0 <= k < i ==> 1 <= numbers[k] <= 100;
      loop assigns i, j, sum;
      loop variant n - i;
    */
    while (i < n) {
        sum = 0;
        j = 0;
        
        /*@
          loop invariant 0 <= j <= n;
          loop invariant 0 <= sum <= j * 100;
          loop invariant \forall integer k; 0 <= k < j ==> 1 <= numbers[k] <= 100;
          loop assigns j, sum;
          loop variant n - j;
        */
        while (j < n) {
            if (i != j) {
                sum += numbers[j];
            }
            j++;
        }
        
        //@ assert sum >= 0;
        
        i++;
    }
    
    //@ assert (\forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] <= 100);
    return true;
}
