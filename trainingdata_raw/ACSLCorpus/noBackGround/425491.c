#include <stdbool.h>
#include <stdint.h>

/*@
  requires (1 <= (n) <= 1000000);
  requires \valid(v + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((v)[i]) <= 1000000000));
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
int func(int n, int *v) {
    int count = 0;
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= count <= i;
      loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((v)[i]) <= 1000000000));
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n) {
        int v_i = v[i];
        
        if (v_i == 2 || v_i == 1) {
            count += 1;
        } else if (v_i >= 3) {
            int v_i_minus_1 = (v_i - 1 < 1) ? 0 : (v_i - 1);
            int v_i_minus_2 = (v_i - 2 < 1) ? 0 : (v_i - 2);
            
            //@ assert v_i_minus_1 >= 0 && v_i_minus_2 >= 0;
            
            if (v_i_minus_1 >= 1 && v_i_minus_2 >= 1) {
                count += 1;
            }
        }
        
        i += 1;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}
