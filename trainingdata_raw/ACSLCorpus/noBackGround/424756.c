#include <stdbool.h>
#include <stddef.h>

/*@
  requires n >= 3 && n <= 200000;
  requires \valid(p + (0..n-1));
  requires (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= (n));
  ensures \result >= 0;
  ensures \result <= n-2;
  assigns \nothing;
*/
int func(int n, const long long *p) {
    int count = 0;
    int index = 1;
    
    /*@
      loop invariant 1 <= index <= n-1;
      loop invariant count >= 0;
      loop invariant count <= index-1;
      loop assigns count, index;
      loop variant n - index;
    */
    while (index < n - 1) {
        int p_index = index;
        long long p_im1 = p[p_index - 1];
        long long p_i = p[p_index];
        long long p_ip1 = p[p_index + 1];
        
        //@ assert p_im1 != p_i && p_i != p_ip1;
        
        if ((p_im1 < p_i && p_i < p_ip1) || (p_im1 > p_i && p_i > p_ip1)) {
            //@ assert count + 1 >= 0;
            count += 1;
        }
        
        //@ assert index + 1 >= 1;
        index += 1;
    }
    
    //@ assert count <= n-2;
    return count;
}
