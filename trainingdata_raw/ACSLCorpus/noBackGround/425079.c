#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(b1+(0..len-1)) && \valid(b2+(0..len-1));
  requires ((\forall integer i; 0 <= i < ((len)) ==> \at(((b1))[i],Here) == \at(((b2))[i],Here)) && (c1) == (c2));
  ensures \forall integer i; 0 <= i < len ==> b1[i] == b2[i];
  ensures c1 == c2;
*/
void test(int *b1, int *b2, int len, int c1, int c2) {
    //@ assert ((\forall integer i; 0 <= i < ((len)) ==> \at(((b1))[i],Here) == \at(((b2))[i],Here)) && (c1) == (c2));
    //@ assert c1 == c2;
    //@ assert (\forall integer i; 0 <= i < (len) ==> \at((b1)[i],Here) == \at((b2)[i],Here));
}

int main() {
    return 0;
}
