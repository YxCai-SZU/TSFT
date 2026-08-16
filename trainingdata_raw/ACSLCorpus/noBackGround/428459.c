#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
  requires \valid(c + (0 .. len-1));
  requires len > 0;
  requires \forall integer i; 0 <= i < len ==> (true);
  assigns \nothing;
  ensures \forall integer i; 0 <= i < len ==> c[i] <= \result;
*/
uint32_t collection_reduction(const uint32_t* c, size_t len) {
    uint32_t result;
    size_t i;
    
    result = c[0];
    i = 1;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall integer k; 0 <= k < i ==> c[k] <= result;
      loop assigns result, i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert (true);
        result = result >= c[i] ? result : c[i];
        //@ assert ((result) >= (result) && (result) >= (c[i]));
        i = i + 1;
    }
    
    return result;
}

/*@
  requires true;
  assigns \nothing;
  ensures \result <= a;
  ensures \result <= b;
*/
uint32_t min_numbers(uint32_t a, uint32_t b) {
    uint32_t ret;
    
    if (a < b) {
        ret = a;
    } else {
        ret = b;
    }
    
    //@ assert ret <= a;
    //@ assert ret <= b;
    
    return ret;
}

int main() {
    return 0;
}
