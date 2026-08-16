#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) > 0 && (n) <= 100 &&
      \valid((numbers) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] <= 1000);
  ensures 0 <= \result <= n;
  assigns \nothing;
*/
size_t func(size_t n, int *numbers) {
    size_t count = 0;
    size_t i = 0;
    
    //@ assert (0 <= (i) <= (n) &&       0 <= (count) <= (i) &&       (((n)) > 0 && ((n)) <= 100 &&       \valid(((numbers)) + (0 .. ((n))-1)) &&       \forall integer i; 0 <= i < ((n)) ==> 1 <= ((numbers))[i] <= 1000));
    
    /*@
      loop invariant (0 <= (i) <= (n) &&
      0 <= (count) <= (i) &&
      (((n)) > 0 && ((n)) <= 100 &&
      \valid(((numbers)) + (0 .. ((n))-1)) &&
      \forall integer i; 0 <= i < ((n)) ==> 1 <= ((numbers))[i] <= 1000));
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n) {
        bool is_divisible = true;
        int j = 2;
        
        //@ assert (2 <= (j) <= 10 &&       (((n)) > 0 && ((n)) <= 100 &&       \valid(((numbers)) + (0 .. ((n))-1)) &&       \forall integer i; 0 <= i < ((n)) ==> 1 <= ((numbers))[i] <= 1000) &&       (i) < (n));
        
        /*@
          loop invariant (2 <= (j) <= 10 &&
      (((n)) > 0 && ((n)) <= 100 &&
      \valid(((numbers)) + (0 .. ((n))-1)) &&
      \forall integer i; 0 <= i < ((n)) ==> 1 <= ((numbers))[i] <= 1000) &&
      (i) < (n));
          loop assigns j, is_divisible;
          loop variant 10 - j;
        */
        while (j < 10) {
            int number = numbers[i];
            int remainder = number;
            
            //@ assert ((remainder) >= 0 &&       (remainder) <= (number));
            
            /*@
              loop invariant ((remainder) >= 0 &&
      (remainder) <= (number));
              loop assigns remainder;
              loop variant remainder;
            */
            while (remainder >= j) {
                remainder -= j;
                //@ assert remainder >= 0;
            }
            
            if (remainder != 0) {
                is_divisible = false;
                break;
            }
            j++;
            //@ assert (2 <= (j) <= 10 &&       (((n)) > 0 && ((n)) <= 100 &&       \valid(((numbers)) + (0 .. ((n))-1)) &&       \forall integer i; 0 <= i < ((n)) ==> 1 <= ((numbers))[i] <= 1000) &&       (i) < (n));
        }
        
        if (is_divisible) {
            count++;
        }
        i++;
        //@ assert (0 <= (i) <= (n) &&       0 <= (count) <= (i) &&       (((n)) > 0 && ((n)) <= 100 &&       \valid(((numbers)) + (0 .. ((n))-1)) &&       \forall integer i; 0 <= i < ((n)) ==> 1 <= ((numbers))[i] <= 1000));
    }
    
    //@ assert 0 <= count <= n;
    return count;
}
