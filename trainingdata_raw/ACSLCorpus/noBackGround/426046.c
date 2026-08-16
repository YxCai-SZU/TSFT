#include <stdbool.h>
#include <stddef.h>

/*@
  requires (1 <= (n) && (n) <= 100 &&
      1 <= (x) && (x) <= 10000 &&
      \valid((l_vec) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (l_vec)[i] && (l_vec)[i] <= 100);
  ensures 0 <= \result && \result <= n;
  assigns \nothing;
*/
int func(int n, int x, int *l_vec) {
    int count = 0;
    int total = 0;
    int index = 0;
    
    /*@
      loop invariant (0 <= (index) && (index) <= (n) &&
      0 <= (total) && (total) <= (x) + 100 &&
      0 <= (count) && (count) <= (index) &&
      ((index) > 0 ==> \forall integer i; 0 <= i < (index) ==> (total) >= (l_vec)[i]) &&
      (1 <= ((n)) && ((n)) <= 100 &&
      1 <= ((x)) && ((x)) <= 10000 &&
      \valid(((l_vec)) + (0 .. ((n))-1)) &&
      \forall integer i; 0 <= i < ((n)) ==> 1 <= ((l_vec))[i] && ((l_vec))[i] <= 100));
      loop assigns total, count, index;
      loop variant n - index;
    */
    while (total <= x && index < n) {
        //@ assert 0 <= index && index < n;
        total += l_vec[index];
        //@ assert total >= l_vec[index];
        count += 1;
        index += 1;
    }
    
    //@ assert 0 <= count && count <= n;
    return count;
}
