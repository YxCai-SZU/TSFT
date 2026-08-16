#include <stdbool.h>
#include <stddef.h>

/*@
  requires 1 <= h <= 100000;
  requires 1 <= a <= 100000;
  ensures \result == (h >= a);
*/
bool check_rideable(int h, int a) {
    //@ assert h >= 1 && h <= 100000;
    return h >= a;
}

/*@
  requires 1 <= h <= 100000;
  requires 1 <= a <= 100000;
  ensures \result == (h <= a);
*/
bool check_blue(int h, int a) {
    //@ assert a >= 1 && a <= 100000;
    return h <= a;
}

/*@
  requires N >= 1 && N <= 100000;
  requires \valid(H + (0 .. N-1));
  requires (\forall integer i; 0 <= i < (N) ==> 1 <= (H)[i] <= 100000);
  ensures \result <= N - 1;
*/
int func(int N, int *H) {
    int max_val;
    int min_val;
    int ans;
    int i;
    
    //@ assert (\forall integer i; 0 <= i < (N) ==> 1 <= (H)[i] <= 100000);
    
    max_val = H[0];
    min_val = H[0];
    ans = 0;
    i = 1;
    
    /*@
      loop invariant 1 <= i <= N;
      loop invariant 0 <= ans <= i - 1;
      loop invariant \forall integer j; 0 <= j < i ==> H[j] >= 1 && H[j] <= 100000;
      loop assigns i, max_val, min_val, ans;
      loop variant N - i;
    */
    while (i < N) {
        //@ assert ans >= 0 && ans <= i - 1;
        
        if (H[i] >= max_val) {
            max_val = H[i];
        } else if (H[i] < min_val) {
            min_val = H[i];
            ans += 1;
        }
        i += 1;
    }
    
    //@ assert ans <= N - 1;
    return ans;
}
