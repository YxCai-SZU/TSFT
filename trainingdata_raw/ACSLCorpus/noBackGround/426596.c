#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(v + (0 .. len-1));
  assigns \nothing;
  ensures \result == 1 <==> (\exists integer i; 0 <= i < (len) && (v)[i] > (threshold));
*/
bool threshold_exceeded(unsigned int *v, size_t len, unsigned int threshold) {
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= len;
      loop invariant \forall integer x; 0 <= x < index ==> v[x] <= threshold;
      loop assigns index;
      loop variant len - index;
    */
    while (index < len) {
        //@ assert 0 <= index < len;
        if (v[index] > threshold) {
            //@ assert (\exists integer i; 0 <= i < (len) && (v)[i] > (threshold));
            return true;
        }
        index = index + 1;
    }
    //@ assert \forall integer i; 0 <= i < len ==> v[i] <= threshold;
    //@ assert !(\exists integer i; 0 <= i < (len) && (v)[i] > (threshold));
    return false;
}

int main() {
    return 0;
}
