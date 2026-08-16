#include <stdbool.h>
#include <stddef.h>

/*@
  requires n > 0;
  requires \valid(a + (0 .. n-1));
  requires \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 100;
  ensures 0 <= \result <= n;
  assigns \nothing;
*/
size_t func(size_t n, int* a) {
    size_t count = 0;
    size_t index = 0;
    
    /*@
      loop invariant ((((n)) > 0 &&
      \valid(((a)) + (0 .. ((n))-1)) &&
      \forall integer i; 0 <= i < ((n)) ==> 1 <= ((a))[i] <= 100) &&
      0 <= (index) <= (n) &&
      0 <= (count) <= (index) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 100);
      loop invariant n > 0;
      loop assigns index, count;
      loop variant n - index;
    */
    while (index < n) {
        int value = a[index];
        
        //@ assert 0 <= index < n;
        //@ assert 1 <= value <= 100;
        
        if (index % 2 == 0 && (value & 1) == 1) {
            //@ assert (index % 2 == 0) && ((value & 1) == 1);
            count++;
        }
        
        index++;
    }
    
    //@ assert index == n;
    //@ assert 0 <= count <= n;
    return count;
}
