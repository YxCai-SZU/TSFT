#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_array(int* arr, integer n) =
      n > 0 && n <= 2000 &&
      \forall integer i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= 2000;
*/

/*@ lemma index_in_bounds:
      \forall integer i, integer n; 0 <= i < n ==> i >= 0 && i < n;
*/

/*@ lemma count_non_negative:
      \forall integer c, integer i; c >= 0 && c <= i ==> c >= 0;
*/

/*@
  requires n > 0 && n <= 2000;
  requires \valid(numbers + (0 .. n-1));
  requires is_valid_array(numbers, n);
  assigns \nothing;
  ensures \result >= 0 && \result <= n;
*/
int func(size_t n, int numbers[]) {
    int c = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant c >= 0;
      loop invariant c <= (int)i;
      loop invariant is_valid_array(numbers, n);
      loop assigns c, i;
      loop variant n - i;
    */
    while (i < n) {
        int a = numbers[i];
        
        //@ assert 0 <= i < n;
        //@ assert a >= 1 && a <= 2000;
        
        if (i % 2 == 0 && (a & 1) == 1) {
            //@ assert c >= 0 && c <= (int)i;
            c += 1;
            //@ assert c >= 1 && c <= (int)i + 1;
        }
        
        i += 1;
    }
    
    //@ assert c >= 0 && c <= (int)n;
    return c;
}
