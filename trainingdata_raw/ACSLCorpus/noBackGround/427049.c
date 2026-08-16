#include <stddef.h>
#include <stdbool.h>

/*@
  requires \valid_read(numbers + (0..len-1));
  assigns \nothing;
  ensures 0 <= \result <= len;
*/
size_t filter_even(const int* numbers, size_t len) {
    size_t odd_count = 0;
    size_t i = 0;

    /*@
      loop invariant 0 <= i <= len;
      loop invariant 0 <= odd_count <= i;
      loop assigns i, odd_count;
      loop variant len - i;
    */
    while (i < len) {
        int number = numbers[i];
        
        if ((number & 1) != 0) {
            //@ assert (((number) & 1) != 0);
            odd_count++;
        }
        i++;
    }
    
    return odd_count;
}
