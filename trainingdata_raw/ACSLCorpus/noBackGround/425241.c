#include <stdbool.h>
#include <stddef.h>

/*@
  requires (1 <= (n) <= 200000);
  requires (\valid((numbers) + (0 .. (n)-1)) && 
      \forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 1000000000));
  ensures \result >= 0;
  ensures \result <= n;
*/
int func(int n, int *numbers) {
    int count = 0;
    size_t index = 0;
    size_t num_index = 0;
    
    /*@
      loop invariant 0 <= index <= (size_t)n;
      loop invariant 0 <= num_index <= (size_t)n;
      loop invariant 0 <= count <= index;
      loop invariant index > 0 ==> 
        \forall integer i; 0 <= i < index ==> (1 <= (numbers[i]) <= 1000000000);
      loop invariant (1 <= (n) <= 200000);
      loop assigns count, index, num_index;
      loop variant (size_t)n - index;
    */
    while (index < (size_t)n && num_index < (size_t)n) {
        int num = numbers[num_index];
        bool divisible = false;
        size_t temp_index = index;
        
        /*@
          loop invariant 0 <= temp_index <= (size_t)n;
          loop invariant 0 <= count <= index;
          loop invariant index > 0 ==> 
            \forall integer i; 0 <= i < index ==> (1 <= (numbers[i]) <= 1000000000);
          loop invariant (1 <= (n) <= 200000);
          loop assigns temp_index, divisible;
          loop variant (size_t)n - temp_index;
        */
        while (temp_index < (size_t)n) {
            int temp_num = numbers[temp_index];
            int remainder = num;
            
            /*@
              loop invariant remainder >= 0;
              loop invariant (1 <= (n) <= 200000);
              loop invariant 0 <= count <= index;
              loop assigns remainder;
              loop variant remainder;
            */
            while (remainder >= temp_num) {
                remainder -= temp_num;
            }
            
            if (remainder == 0) {
                divisible = true;
            }
            temp_index++;
        }
        
        if (!divisible) {
            count++;
        }
        index++;
        num_index++;
    }
    
    //@ assert count >= 0;
    //@ assert count <= n;
    return count;
}
