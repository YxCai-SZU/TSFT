#include <stdbool.h>
#include <stddef.h>

/*@
  requires n > 0;
  requires \valid(v + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> ((v[i]) < 0x80000000);
  ensures \result != 0 ==> \forall integer i; 0 <= i < n ==> (((1) != 0) ==> ((v[i]) < 0x80000000));
  ensures \result == 0 ==> \exists integer i; 0 <= i < n && (((0) != 0) ==> ((v[i]) < 0x80000000));
*/
bool func(unsigned int n, const unsigned int* v) {
    unsigned int index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant index > 0 ==> \forall integer i; 0 <= i < index ==> (((1) != 0) ==> ((v[i]) < 0x80000000));
      loop invariant \forall integer i; 0 <= i < n ==> ((v[i]) < 0x80000000);
      loop assigns index;
      loop variant n - index;
    */
    while (index < n) {
        //@ assert ((v[index]) < 0x80000000);
        
        //@ assert (((1) != 0) ==> ((v[index]) < 0x80000000)) || (((0) != 0) ==> ((v[index]) < 0x80000000));
        
        //@ assert (((1) != 0) ==> ((v[index]) < 0x80000000));
        
        index = index + 1;
    }
    return true;
}

int main() {
    return 0;
}
