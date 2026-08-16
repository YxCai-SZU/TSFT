#include <stdbool.h>
#include <stddef.h>

/*@
  requires (1 <= (n) && (n) <= 200000);
  requires \valid(numbers + (0 .. n-1));
  requires \forall integer i; 0 <= i < n ==> (1 <= (numbers[i]) && (numbers[i]) <= 1000000);
  assigns \nothing;
  ensures \result >= 0;
*/
int func(int n, int* numbers) {
    int count = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= (size_t)n;
      loop invariant 0 <= count <= (int)index;
      loop invariant \forall integer i; 0 <= i < n ==> (1 <= (numbers[i]) && (numbers[i]) <= 1000000);
      loop invariant (1 <= (n) && (n) <= 200000);
      loop assigns count, index;
      loop variant n - index;
    */
    while (index < (size_t)n) {
        int value = numbers[index];
        //@ assert (1 <= (value) && (value) <= 1000000);
        if (value & 1) {
            count += 1;
        }
        index += 1;
    }
    //@ assert count >= 0;
    return count;
}
