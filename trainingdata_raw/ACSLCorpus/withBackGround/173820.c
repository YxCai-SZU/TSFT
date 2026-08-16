#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_range(size_t n) = 1 <= n <= 200000; */
/*@ predicate valid_value(long long v) = 1 <= v <= 1000000; */
/*@ predicate valid_array(long long *arr, size_t n) =
      \forall size_t i; 0 <= i < n ==> valid_value(arr[i]); */

/*@
  requires valid_range(n);
  requires \valid_read(numbers + (0 .. n-1));
  requires valid_array(numbers, n);
  ensures 1 <= \result <= n;
  assigns \nothing;
*/
int func(size_t n, const long long *numbers) {
    int count = 1;
    size_t i = 1;
    long long prev = numbers[0];
    
    /*@
      loop invariant 1 <= i <= n;
      loop invariant 1 <= count <= i;
      loop invariant valid_value(prev);
      loop assigns i, count, prev;
      loop variant n - i;
    */
    while (i < n) {
        long long num = numbers[i];
        //@ assert valid_value(num);
        
        if (prev <= num) {
            count += 1;
            prev = num;
        }
        i += 1;
    }
    
    //@ assert 1 <= count <= n;
    return count;
}
