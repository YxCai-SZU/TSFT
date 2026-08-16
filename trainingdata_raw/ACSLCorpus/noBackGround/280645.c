#include <stdbool.h>
#include <stddef.h>

/*@ requires (0 < (n) <= 200000);
    requires (\valid_read((input_numbers) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (input_numbers)[i] <= 1000000000);
    ensures 0 <= \result <= n;
    assigns \nothing;
 */
int func(size_t n, int *input_numbers) {
    int count = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant (\valid_read((input_numbers) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (input_numbers)[i] <= 1000000000);
        loop assigns count, index;
        loop variant n - index;
     */
    while (index < n) {
        int a = input_numbers[index];
        //@ assert 1 <= a <= 1000000000;
        
        if (a & 1) {
            count = count + 1;
        }
        index += 1;
    }
    return count;
}
