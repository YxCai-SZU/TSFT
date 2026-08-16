#include <stdbool.h>
#include <stddef.h>

/*@
  requires N > 0 && N <= 100;
  requires \valid(a + (0..N-1));
  requires (\forall integer i; 0 <= i < (N) ==> 1 <= (a)[i] <= 1000);
  ensures \result == \true <==> 
           (\forall integer i; 0 <= i < N && a[i] % 2 == 0 ==> 
             a[i] % 3 == 0 || a[i] % 5 == 0);
*/
bool func(size_t N, int *a) {
    size_t i = 0;
    bool flag = true;
    
    /*@
      loop invariant 0 <= i <= N;
      loop invariant (\forall integer i; 0 <= i < (N) ==> 1 <= (a)[i] <= 1000);
      loop invariant flag == \true <==> 
        (\forall integer j; 0 <= j < i && a[j] % 2 == 0 ==> 
          a[j] % 3 == 0 || a[j] % 5 == 0);
      loop assigns i, flag;
      loop variant N - i;
    */
    while (i < N) {
        int value = a[i];
        
        //@ assert value >= 1 && value <= 1000;
        
        if (value % 2 == 0) {
            //@ assert value % 2 == 0;
            if (value % 3 != 0 && value % 5 != 0) {
                //@ assert !(value % 3 == 0 || value % 5 == 0);
                flag = false;
            }
        }
        i += 1;
    }
    return flag;
}
