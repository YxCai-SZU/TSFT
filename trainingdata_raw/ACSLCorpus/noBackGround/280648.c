#include <stdbool.h>
#include <stdint.h>

/*@ requires 
      (2 <= (n) && (n) <= 100000) &&
      \valid(a + (0 .. n-1)) &&
      (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 10000);
    ensures 
      0 <= \result && \result <= n; */
int func(int n, int *a) 
{
  int count = 0;
  int index = 0;
  int i = 0;
  
  /*@ loop invariant (0 <= (i) && (i) <= (n) &&
      0 <= (index) && (index) < (n) &&
      0 <= (count) && (count) <= (i) &&
      (2 <= ((n)) && ((n)) <= 100000) &&
      (\forall integer i; 0 <= i < ((n)) ==> 1 <= ((a))[i] && ((a))[i] <= 10000));
      loop assigns i, index, count;
      loop variant n - i; */
  while (i < n) {
    int value = a[index];
    if (value & 1) {
      count++;
    }
    index = (index + 1) % n;
    i++;
    
    //@ assert index < n;
  }
  return count;
}
