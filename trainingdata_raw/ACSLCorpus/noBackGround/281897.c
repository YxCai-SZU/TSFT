#include <stdbool.h>

/*@
  requires 1 <= n <= 100;
  requires 1 <= m <= 100;
  requires 1 <= x <= n-1;
  requires \valid(an + (0..n-1));
  requires (((n)) == (n) &&
      \forall integer i; 0 <= i < ((n)) ==> 1 <= (an)[i] && (an)[i] <= (n) &&
      (\forall integer i; 0 <= i < (((n)))-1 ==> ((an))[i] < ((an))[i+1]));
  requires \valid(am + (0..m-1));
  requires ((m) == (n) &&
      \forall integer i; 0 <= i < (m) ==> 1 <= (am)[i] && (am)[i] <= (n) && (am)[i] != (x) &&
      (\forall integer i; 0 <= i < ((m))-1 ==> ((am))[i] < ((am))[i+1]));
  ensures 0 <= \result <= m;
*/
int func(int n, int m, int x, int *an, int *am) {
    int ans_n = 0;
    int ans_m = 0;
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= ans_n <= i;
      loop invariant \forall integer j; 0 <= j < i ==> an[j] < x;
      loop invariant (((n)) == (n) &&
      \forall integer i; 0 <= i < ((n)) ==> 1 <= (an)[i] && (an)[i] <= (n) &&
      (\forall integer i; 0 <= i < (((n)))-1 ==> ((an))[i] < ((an))[i+1]));
      loop invariant 1 <= n <= 100;
      loop invariant 1 <= m <= 100;
      loop invariant 1 <= x <= n-1;
      loop assigns i, ans_n;
    */
    while (i < n && an[i] < x) {
        //@ assert an[i] < x;
        ans_n++;
        i++;
    }
    
    i = 0;
    
    /*@
      loop invariant 0 <= i <= m;
      loop invariant 0 <= ans_m <= i;
      loop invariant \forall integer j; 0 <= j < i ==> am[j] < x;
      loop invariant ((m) == (n) &&
      \forall integer i; 0 <= i < (m) ==> 1 <= (am)[i] && (am)[i] <= (n) && (am)[i] != (x) &&
      (\forall integer i; 0 <= i < ((m))-1 ==> ((am))[i] < ((am))[i+1]));
      loop invariant 1 <= n <= 100;
      loop invariant 1 <= m <= 100;
      loop invariant 1 <= x <= n-1;
      loop assigns i, ans_m;
    */
    while (i < m && am[i] < x) {
        //@ assert am[i] < x;
        ans_m++;
        i++;
    }
    
    int min_ans = (ans_n < ans_m) ? ans_n : ans_m;
    
    //@ assert 0 <= min_ans <= m;
    return min_ans;
}
