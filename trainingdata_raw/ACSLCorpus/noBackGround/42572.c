#include <stdbool.h>

/*@
  requires 1 <= n <= 100;
  requires 1 <= m <= 100;
  requires \valid(scores + (0 .. m-1));
  requires \valid(time + (0 .. m-1));
  requires (\forall integer i; 0 <= i < (m) ==> 1 <= (scores)[i] && (scores)[i] <= 1000);
  requires (\forall integer i; 0 <= i < (m) ==> 1 <= (time)[i] && (time)[i] <= 1000);
  ensures 0 <= \result <= m;
  assigns \nothing;
*/
int func(int n, int m, int *scores, int *time) {
    int count = 0;
    int index = 0;
    
    /*@
      loop invariant 0 <= index <= m;
      loop invariant 0 <= count <= index;
      loop assigns count, index;
      loop variant m - index;
    */
    while (index < m) {
        int s = scores[index];
        int t = time[index];
        int sum = s + t;
        
        //@ assert 1 <= s <= 1000;
        
        if (sum >= n) {
            count += 1;
        }
        index += 1;
    }
    return count;
}
