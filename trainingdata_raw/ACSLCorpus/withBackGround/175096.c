#include <stdint.h>
#include <stddef.h>

/*@ predicate valid_array(int64_t* arr, size_t n) =
      n >= 2 && n <= 200000 &&
      \valid(arr + (0 .. n-1)) &&
      \forall size_t i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= 1000000000;
*/

/*@ predicate loop_invariant(int64_t* a, size_t n, size_t i, size_t prev, size_t count) =
      0 <= i <= n &&
      0 <= prev < n &&
      0 <= count <= i &&
      valid_array(a, n);
*/

/*@ lemma count_non_negative:
      \forall int64_t* a, size_t n, size_t i, size_t prev, size_t count;
      loop_invariant(a, n, i, prev, count) ==> count >= 0;
*/

/*@
  requires valid_array(a, n);
  ensures \result >= 0;
*/
int64_t func(size_t n, int64_t* a)
{
  size_t prev = 0;
  size_t count = 0;
  size_t i = 0;
  
  /*@
    loop invariant loop_invariant(a, n, i, prev, count);
    loop assigns i, prev, count;
    loop variant n - i;
  */
  while (i < n) {
    int64_t value = a[i];
    //@ assert value >= 1 && value <= 1000000000;
    
    if (a[prev] <= value) {
      count++;
    } else {
      prev = i;
    }
    i++;
  }
  
  //@ assert count >= 0;
  return (int64_t)count;
}
