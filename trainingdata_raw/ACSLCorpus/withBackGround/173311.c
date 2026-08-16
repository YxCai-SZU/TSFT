#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_range(integer n) = 1 <= n && n <= 100; */
/*@ predicate valid_x(integer x) = 1 <= x && x <= 10000; */
/*@ predicate valid_number(integer val) = 1 <= val && val <= 100; */
/*@ predicate valid_numbers(int *arr, integer n, integer len) = 
      len == n && 
      \forall integer i; 0 <= i < len ==> valid_number(arr[i]); */

/*@ logic integer sum_bounds(integer i) = i * 100; */

/*@ lemma sum_positive: 
      \forall integer i; 0 <= i ==> 0 <= sum_bounds(i); */

/*@
  requires valid_range(n);
  requires valid_x(x);
  requires \valid(numbers + (0 .. n-1));
  requires valid_numbers(numbers, n, n);
  ensures \result >= 0;
  ensures \result <= n + 1;
*/
int func(int n, int x, int *numbers) {
    int sum;
    int i;
    int index;
    int count;
    
    sum = 0;
    i = 0;
    index = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= index <= n;
      loop invariant index == i;
      loop invariant sum >= 0;
      loop invariant sum <= sum_bounds(i);
      loop invariant \forall integer j; 0 <= j < i ==> valid_number(numbers[j]);
      loop invariant valid_numbers(numbers, n, n);
      loop assigns sum, i, index;
    */
    while (i < n && index < n) {
        //@ assert 0 <= index < n;
        sum += numbers[index];
        i += 1;
        index += 1;
    }
    
    count = 0;
    if (sum <= x) {
        count = 1;
    }
    
    //@ assert count >= 0;
    //@ assert count <= n + 1;
    return count;
}
