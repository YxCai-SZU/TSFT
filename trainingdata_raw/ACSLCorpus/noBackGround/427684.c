#include <stdbool.h>
#include <stddef.h>

/*@
  requires n > 0;
  requires \valid(v + (0 .. n-1));
  requires ((n) > 0 &&
      \forall integer i; 0 <= i < (n) ==> 0 <= (v)[i] && (v)[i] < (n));
  assigns \nothing;
  ensures \result == -1 ==> (\forall integer i; 0 <= i < (n) ==> (v)[i] != (n));
  ensures \result >= 0 ==> (0 <= (\result) && (\result) < (n) && (v)[(\result)] == (n));
*/
int func(unsigned int n, unsigned int *v) {
    unsigned int index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant \forall integer i; 0 <= i < index ==> v[i] != n;
      loop assigns index;
      loop variant n - index;
    */
    while (index < n) {
        //@ assert index < n;
        if (v[index] == n) {
            //@ assert (0 <= (index) && (index) < (n) && (v)[(index)] == (n));
            return (int)index;
        }
        //@ assert v[index] != n;
        index = index + 1;
    }
    //@ assert (\forall integer i; 0 <= i < (n) ==> (v)[i] != (n));
    return -1;
}

int main() {
    return 0;
}
