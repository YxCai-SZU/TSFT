#include <stdbool.h>

/*@ predicate is_valid_n(integer n) = 1 <= n && n <= 100; */

/*@ predicate is_valid_array(integer n, int *a) =
      \forall integer j; 0 <= j < n ==> 1 <= a[j] && a[j] <= 100; */

/*@ lemma ans_bounds:
      \forall integer n, integer i, integer ans;
      is_valid_n(n) && 0 <= i <= n && 0 <= ans <= i ==> 0 <= ans <= n; */

/*@ requires is_valid_n(n);
    requires \valid(a+(0..n-1));
    requires is_valid_array(n, a);
    ensures 0 <= \result <= n; */
int func(int n, int *a)
{
  int ans = 0;
  int i = 0;
  /*@ loop invariant 0 <= i <= n;
      loop invariant 0 <= ans <= i;
      loop assigns i, ans;
      loop variant n - i; */
  while (i < n)
  {
    int v = a[i];
    //@ assert 1 <= v && v <= 100;
    if ((i & 1) == 0 && (v & 1) == 1)
    {
      ans += 1;
    }
    i += 1;
  }
  //@ assert 0 <= ans <= n;
  return ans;
}
