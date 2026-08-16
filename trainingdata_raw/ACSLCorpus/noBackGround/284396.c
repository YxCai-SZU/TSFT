#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) >= 1 && (n) <= 100 &&
      (x) >= 1 && (x) <= 10000);
  requires n >= 1 && n <= 100;
  requires x >= 1 && x <= 10000;
  requires \valid(numbers + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
  ensures \result >= 0 || \result == -1;
  ensures \result >= 0 ==> \result <= n + 1;
*/
int func(int n, int x, int *numbers) {
    int count = 0;
    int sum = 0;
    int index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= count <= index;
      loop invariant sum <= index * 100;
      loop invariant index > 0 ==> (\forall integer i; 0 <= i < (index) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
      loop invariant n >= 1 && n <= 100;
      loop invariant x >= 1 && x <= 10000;
      loop invariant (\forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
      loop assigns count, sum, index;
    */
    while (index < n && sum < x) {
        //@ assert 0 <= index < n;
        sum += numbers[index];
        count += 1;
        index += 1;
    }
    
    int result;
    if (sum >= x) {
        //@ assert count >= 0;
        result = count + 1;
    } else {
        result = -1;
    }
    
    return result;
}
