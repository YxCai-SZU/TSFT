#include <stdbool.h>
#include <stdint.h>

/*@ predicate distinct_elements(int32_t* arr, integer len) =
      \forall integer i, j; 0 <= i < j < len ==> arr[i] != arr[j];
*/

/*@ predicate valid_range(int32_t* arr, integer len, integer n) =
      \forall integer i; 0 <= i < len ==> 1 <= arr[i] && arr[i] <= n;
*/

/*@ lemma bound_lemma:
      \forall integer n; 2 <= n <= 50 ==> n >= 2 && n <= 50;
*/

/*@ lemma count_bound:
      \forall integer cnt, i, n;
        0 <= cnt <= i && i <= n && 2 <= n <= 50 ==> cnt >= 0 && cnt <= n;
*/

/*@
  requires 2 <= n <= 50;
  requires \valid(numbers + (0 .. n-1));
  requires distinct_elements(numbers, n);
  requires valid_range(numbers, n, n);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
int32_t func(int32_t n, int32_t* numbers) {
    // Variable declarations
    int32_t count;
    int32_t i;
    int32_t num;
    
    count = 0;
    i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer k; 0 <= k < i ==> 
            (numbers[k] == k+1 ==> count > 0) && 
            (numbers[k] != k+1 ==> count >= 0);
        loop assigns i, count, num;
        loop variant n - i;
    */
    while (i < n) {
        num = numbers[i];
        
        //@ assert 0 <= i && i < n;
        //@ assert 1 <= num && num <= n;
        
        if (num == i + 1) {
            count = count + 1;
        }
        
        i = i + 1;
    }
    
    //@ assert count >= 0;
    //@ assert count <= n;
    
    return count;
}
