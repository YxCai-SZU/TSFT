#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) >= 1 && (n) <= 100000 &&
      \valid((arr) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (arr)[i] >= 1 && (arr)[i] <= 1000000000);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
int func(int n, int *arr) {
    int i;
    int count;
    int cur;
    
    i = 0;
    count = 0;
    cur = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= count <= i;
      loop invariant i > 0 ==> \forall integer j; 0 <= j < i ==> arr[j] >= 1 && arr[j] <= 1000000000;
      loop invariant ((n) >= 1 && (n) <= 100000 &&
      \valid((arr) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (arr)[i] >= 1 && (arr)[i] <= 1000000000);
      loop assigns i, count, cur;
      loop variant n - i;
    */
    while (i < n) {
        int val;
        
        val = arr[i];
        
        if (cur < val) {
            cur = val;
        } else if (cur > val) {
            //@ assert count >= 0;
            count = count + 1;
            cur = val;
        }
        
        i = i + 1;
    }
    
    return count;
}
