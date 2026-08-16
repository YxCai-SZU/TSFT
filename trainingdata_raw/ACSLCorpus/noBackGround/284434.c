#include <stdbool.h>
#include <stddef.h>

/*@
  requires n >= 1 && n <= 200000;
  requires \valid(numbers + (0 .. n-1));
  requires ((n) >= 1 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 1000000000);
  assigns \nothing;
  ensures \result >= 0 && \result <= n;
*/
int func(int n, int* numbers) {
    int count = 0;
    int index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant ((count) >= 0 && (count) <= (index) && (index) >= 0 && (index) <= (n));
      loop invariant ((n) >= 1 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 1000000000);
      loop assigns count, index;
      loop variant n - index;
    */
    while (index < n) {
        bool is_divisible = false;
        int inner_index = 1;
        
        /*@
          loop invariant 1 <= inner_index <= n;
          loop invariant ((n) >= 1 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 1000000000);
          loop assigns is_divisible, inner_index;
          loop variant n - inner_index;
        */
        while (inner_index < n) {
            if (index != inner_index) {
                int a = numbers[index];
                int b = numbers[inner_index];
                int remainder = a;
                
                /*@
                  loop invariant remainder >= 0;
                  loop assigns remainder;
                  loop variant remainder;
                */
                while (remainder >= b) {
                    remainder -= b;
                }
                
                /*@
                  loop invariant remainder < b;
                  loop assigns remainder;
                  loop variant b - remainder;
                */
                while (remainder < 0) {
                    remainder += b;
                }
                
                if (remainder == 0) {
                    is_divisible = true;
                }
            }
            inner_index++;
        }
        
        if (!is_divisible) {
            count++;
        }
        index++;
    }
    return count;
}
