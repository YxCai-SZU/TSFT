#include <stdbool.h>
#include <stddef.h>

/*@
  requires (2 <= (n) && (n) <= 100000 &&
      1 <= (x) && (x) <= 1000000000 &&
      \valid((a)+(0..(n)-2)) &&
      \forall integer i; 0 <= i < (n)-1 ==> 1 <= (a)[i] && (a)[i] <= 1000000000 &&
      \forall integer i; 0 <= i < (n)-1 ==> (a)[i] != (x));
  assigns \nothing;
  ensures 0 <= \result && \result <= n-1;
*/
long func(long n, long x, const long *a) {
    long cnt = 0;
    long current_x = x;
    long i = 0;
    
    //@ assert (2 <= (n) && (n) <= 100000 &&       1 <= (x) && (x) <= 1000000000 &&       \valid((a)+(0..(n)-2)) &&       \forall integer i; 0 <= i < (n)-1 ==> 1 <= (a)[i] && (a)[i] <= 1000000000 &&       \forall integer i; 0 <= i < (n)-1 ==> (a)[i] != (x));
    
    /*@ loop invariant (0 <= (i) && (i) <= (n)-1 &&
      0 <= (cnt) && (cnt) <= (i) &&
      (current_x) >= 0 &&
      2 <= (n) && (n) <= 100000 &&
      \valid((a)+(0..(n)-2)) &&
      \forall integer j; 0 <= j < (n)-1 ==> 1 <= (a)[j] && (a)[j] <= 1000000000);
        loop assigns i, cnt, current_x;
        loop variant n - i;
    */
    while (i < n - 1) {
        long ai = a[i];
        
        //@ assert 0 <= i && i < n-1;
        //@ assert 1 <= ai && ai <= 1000000000;
        //@ assert ai != x;
        
        if (current_x - ai >= 0) {
            //@ assert current_x >= ai;
            current_x = current_x - ai;
            cnt = cnt + 1;
        }
        
        i = i + 1;
        //@ assert cnt <= i;
    }
    
    //@ assert i == n-1;
    //@ assert 0 <= cnt && cnt <= n-1;
    return cnt;
}
