#include <stddef.h>
#include <stdint.h>

/*@
  requires ((k) >= 1 && (k) <= 500);
  requires ((len) >= 1 && (len) <= 100000 &&
      \forall integer i; 0 <= i < (len) ==> (((heights)[i]) >= 1 && ((heights)[i]) <= 500));
  requires \valid_read(heights + (0 .. len-1));
  assigns \nothing;
  ensures 0 <= \result <= len;
*/
int func(int k, int *heights, size_t len) {
    int cnt = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= len;
      loop invariant 0 <= cnt <= (int)index;
      loop invariant index > 0 ==> 
        \forall integer i; 0 <= i < index ==> ((heights[i]) >= 1 && (heights[i]) <= 500);
      loop invariant ((k) >= 1 && (k) <= 500);
      loop invariant ((len) >= 1 && (len) <= 100000 &&
      \forall integer i; 0 <= i < (len) ==> (((heights)[i]) >= 1 && ((heights)[i]) <= 500));
      loop assigns cnt, index;
      loop variant len - index;
    */
    while (index < len) {
        //@ assert (0 <= (index) < (len));
        
        if (heights[index] >= k) {
            cnt = cnt + 1;
        }
        
        index = index + 1;
    }
    
    return cnt;
}
