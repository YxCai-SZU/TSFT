#include <stdbool.h>

/*@
  requires \valid(v + (0..4));
  requires \forall integer i; 0 <= i <= 4 ==> ((v[i]) == (i) + 1 || (v[i]) == 0);
  requires ((v[0]) == 0 || (v[1]) == 0 || (v[2]) == 0 || (v[3]) == 0 || (v[4]) == 0);
  ensures 1 <= \result <= 5;
  ensures v[\result - 1] == 0;
*/
long func(long v[5]) {
    int i;
    i = 0;
    
    /*@
      loop invariant 0 <= i <= 5;
      loop invariant \forall integer j; 0 <= j <= 4 ==> ((v[j]) == (j) + 1 || (v[j]) == 0);
      loop invariant ((v[0]) == 0 || (v[1]) == 0 || (v[2]) == 0 || (v[3]) == 0 || (v[4]) == 0);
      loop invariant \forall integer k; 0 <= k < i ==> v[k] != 0;
      loop assigns i;
    */
    while (i < 5) {
        //@ assert 0 <= i <= 4;
        if (v[i] == 0) {
            //@ assert v[i] == 0;
            return (long)(i + 1);
        }
        //@ assert v[i] != 0;
        i = i + 1;
    }
    return -1;
}
