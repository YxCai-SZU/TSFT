#include <stdbool.h>

/*@
  requires \valid(v+(0..5));
  requires (\forall integer i; 0 <= i < (6) ==> (((v)[i]) == 0 || ((v)[i]) == 1));
  ensures \result == true <==> (\exists integer i; 0 <= i < (6) && (v)[i] == 1);
*/
bool func(int *v) {
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= 6;
      loop invariant (\forall integer i; 0 <= i < (6) ==> (((v)[i]) == 0 || ((v)[i]) == 1));
      loop invariant (\forall integer j; 0 <= j < (i) ==> (v)[j] == 0);
      loop assigns i;
    */
    while (i < 6) {
        //@ assert 0 <= i < 6;
        if (v[i] == 1) {
            //@ assert (\exists integer i; 0 <= i < (6) && (v)[i] == 1);
            return true;
        }
        //@ assert v[i] == 0;
        i++;
    }
    //@ assert \forall integer j; 0 <= j < 6 ==> v[j] == 0;
    //@ assert !(\exists integer i; 0 <= i < (6) && (v)[i] == 1);
    return false;
}

int main() {
    return 0;
}
