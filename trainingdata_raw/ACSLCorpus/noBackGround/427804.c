#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) > 0 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= (n));
    ensures -1 <= \result && \result < n + 1;
*/
int func(int n, int *a)
{
  int result = -1;
  int count = 0;
  size_t i = 0;

  /*@ loop invariant (0 <= (i) <= (n) &&
      -1 <= (result) && (result) < (n) + 1 &&
      0 <= (count) && (count) <= (i) &&
      (((n)) > 0 && ((n)) <= 200000 &&
      \forall integer i; 0 <= i < ((n)) ==> 1 <= ((a))[i] && ((a))[i] <= ((n))));
      loop assigns i, count, result;
      loop variant n - i;
  */
  while (i < (size_t)n) {
    int value = a[i];
    if (value == count + 1) {
      count = count + 1;
    } else {
      result = count;
    }
    i = i + 1;
  }
  return result;
}
