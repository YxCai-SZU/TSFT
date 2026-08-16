#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(a + (0 .. len-1));
  requires ((len) >= 1 &&
      \forall size_t i; 0 <= i < (len) ==> 1 <= (a)[i] <= 1000);
  assigns \nothing;
  ensures \result == 1 <==> (\forall size_t i; 0 <= i < (len) ==> 
        ((a)[i] % 2 == 0 ==> ((a)[i] % 3 == 0 || (a)[i] % 5 == 0)));
*/
bool func(int* a, size_t len) {
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= len;
      loop invariant ((len) >= 1 &&
      \forall size_t i; 0 <= i < (len) ==> 1 <= (a)[i] <= 1000);
      loop invariant \forall size_t k; 0 <= k < index ==> 
                     (a[k] % 2 == 0 ==> (a[k] % 3 == 0 || a[k] % 5 == 0));
      loop assigns index;
      loop variant len - index;
    */
    while (index < len) {
        int value = a[index];
        
        //@ assert value >= 1 && value <= 1000;
        
        if (value % 2 == 0 && (value % 3 != 0 && value % 5 != 0)) {
            //@ assert !(value % 2 == 0 ==> (value % 3 == 0 || value % 5 == 0));
            return false;
        }
        
        //@ assert value % 2 == 0 ==> (value % 3 == 0 || value % 5 == 0);
        index++;
    }
    
    //@ assert \forall size_t i; 0 <= i < len ==> (a[i] % 2 == 0 ==> (a[i] % 3 == 0 || a[i] % 5 == 0));
    return true;
}
