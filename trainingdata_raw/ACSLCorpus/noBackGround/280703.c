#include <stdbool.h>
#include <stddef.h>

/*@
  requires n >= 1 && n <= 1000000;
  requires \valid(numbers + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> numbers[i] >= 1 && numbers[i] <= 1000000;
  assigns \nothing;
  ensures 0 <= \result <= n;
  ensures \forall integer i; 0 <= i < n ==> (((numbers[i]) & 1) == 0) ==> \exists integer j; 0 <= j < n && (((numbers[j]) & 1) == 0);
*/
size_t func(int n, int numbers[]) {
    size_t count = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= count <= index;
      loop assigns index, count;
      loop variant n - index;
    */
    while (index < (size_t)n) {
        int x = numbers[index];
        bool is_even = (x & 1) == 0;
        
        //@ assert is_even == ((x & 1) == 0);
        
        if (is_even) {
            count += 1;
        }
        index += 1;
    }
    
    //@ assert count <= n;
    return count;
}
