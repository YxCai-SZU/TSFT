#include <stdbool.h>
#include <stddef.h>

/*@
  requires 1 <= n <= 100;
  ensures \result == true ==> n % 2 == 1;
  ensures \result == false ==> n % 2 == 0;
*/
bool is_odd_func(unsigned int n) {
    bool ret;
    ret = (n % 2 != 0);
    //@ assert ret == true ==> n % 2 == 1;
    return ret;
}

/*@
  requires \valid_read(v + (0 .. len-1));
  requires \forall integer i; 0 <= i < len ==> 1 <= v[i] <= 100;
  ensures \result == true ==> \forall integer i; 0 <= i < len ==> v[i] % 2 == 1;
  ensures \result == false ==> \exists integer i; 0 <= i < len && v[i] % 2 == 0;
*/
bool all_odd(unsigned int *v, size_t len) {
    size_t index;
    index = 0;
    
    /*@
      loop invariant 0 <= index <= len;
      loop invariant \forall integer i; 0 <= i < index ==> v[i] % 2 == 1;
      loop invariant \forall integer i; 0 <= i < len ==> 1 <= v[i] <= 100;
      loop assigns index;
      loop variant len - index;
    */
    while (index < len) {
        //@ assert 0 <= index < len;
        if (v[index] % 2 == 0) {
            //@ assert \exists integer i; 0 <= i < len && v[i] % 2 == 0;
            return false;
        }
        //@ assert v[index] % 2 == 1;
        index = index + 1;
    }
    //@ assert \forall integer i; 0 <= i < len ==> v[i] % 2 == 1;
    return true;
}

int main() {
    return 0;
}
