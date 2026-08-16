#include <stdbool.h>
#include <stddef.h>

/*@
  requires (2 <= (k) <= 1000000 &&
      2 <= (n) <= 200000 &&
      (\forall integer i; 0 <= i < ((n)) ==> 0 <= ((numbers))[i] && ((numbers))[i] < ((k))) &&
      (\forall integer i; 0 <= i < ((n)) - 1 ==> ((numbers))[i] < ((numbers))[i + 1]));
  requires \valid_read(numbers + (0 .. n-1));
  ensures 0 <= \result <= k;
*/
int func(int k, size_t n, int numbers[]) {
    int a = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n - 1;
      loop invariant 0 <= a <= k;
      loop invariant (2 <= (k) <= 1000000 &&
      2 <= (n) <= 200000 &&
      (\forall integer i; 0 <= i < ((n)) ==> 0 <= ((numbers))[i] && ((numbers))[i] < ((k))) &&
      (\forall integer i; 0 <= i < ((n)) - 1 ==> ((numbers))[i] < ((numbers))[i + 1]));
      loop assigns a, index;
      loop variant n - index;
    */
    while (index < n - 1) {
        size_t next_index = index + 1;
        
        //@ assert 0 <= index < n - 1;
        //@ assert 0 <= next_index < n;
        //@ assert numbers[index] < numbers[next_index];
        
        int diff = numbers[next_index] - numbers[index];
        
        //@ assert 0 < diff < k;
        
        if (a < k - diff) {
            a = a;
        } else {
            a = k - diff;
        }
        
        //@ assert 0 <= a <= k;
        
        index += 1;
    }
    
    //@ assert 0 <= a <= k;
    return a;
}
