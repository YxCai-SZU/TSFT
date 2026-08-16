#include <stdbool.h>

/*@
  requires (2 <= (n) && (n) <= 100 &&
      1 <= (x) && (x) <= 100 &&
      1 <= (y) && (y) <= 100);
  requires \valid(A + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (A)[i] && (A)[i] <= 100);
  ensures \result >= 0;
*/
int func(int n, int x, int y, int *A)
{
    int answer = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n - 1;
        loop invariant answer >= 0;
        loop invariant answer <= i * 200;
        loop assigns i, answer;
        loop variant n - i;
    */
    while (i < n - 1) {
        int j = A[i];
        
        if (j >= y && y >= x) {
            answer += x;
        } else if (j >= y) {
            answer += j - y + x;
        } else if (y >= j && x > j) {
            answer += x - j;
        }
        
        //@ assert answer >= 0;
        i += 1;
    }
    
    //@ assert answer >= 0;
    return answer;
}
