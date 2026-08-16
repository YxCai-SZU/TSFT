#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
  requires \valid_read(v + (0 .. len-1));
  assigns \nothing;
  behavior found:
    assumes (\exists integer i; 0 <= i < (len) && (v)[i] == 0xffffffff);
    ensures \result != 0;
    ensures *\result == 0xffffffff;
  behavior not_found:
    assumes !(\exists integer i; 0 <= i < (len) && (v)[i] == 0xffffffff);
    ensures \result == 0;
  complete behaviors;
  disjoint behaviors;
*/
uint32_t* find_x(uint32_t* v, size_t len) {
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= len;
      loop invariant (\forall integer x; 0 <= x < (index) ==> (v)[x] != 0xffffffff);
      loop assigns index;
      loop variant len - index;
    */
    while (index < len) {
        //@ assert (\forall integer x; 0 <= x < (index) ==> (v)[x] != 0xffffffff);
        
        if (v[index] == 0xffffffff) {
            //@ assert (\exists integer i; 0 <= i < (len) && (v)[i] == 0xffffffff);
            return &v[index];
        }
        
        //@ assert v[index] != 0xffffffff;
        index = index + 1;
    }
    
    //@ assert !(\exists integer i; 0 <= i < (len) && (v)[i] == 0xffffffff);
    return 0;
}
