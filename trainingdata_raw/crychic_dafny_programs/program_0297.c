// Generated C + ACSL

/*@ logic integer sum(integer n); */

/*@ axiomatic SumAxioms {
  @ axiom sum_base: sum(0) == 0;
  @ axiom sum_rec: \forall integer n; n > 0 ==> sum(n) == n + sum(n-1);
  @ }
  @*/

/*@ requires n >= 0;
  @ decreases n;
  @ ensures \result == sum(n);
  @*/
int sum(int n)
{
  return ((n == 0)) ? (0) : ((n + sum((n - 1))));
}

/*@ requires n >= 0;
  @ requires n <= 2147483647;
  @ ensures \result == sum(n);
  @*/
int Sum(int n)
{
  int x = 0;
  /*@ assert x >= 0 && x <= 2147483647; */
  int y = 1;
  /*@ assert y >= 0 && y <= 2147483647; */
  int k = n;
  /*@ assert k >= 0 && k <= 2147483647; */
/*@
  loop invariant sum(n) == x + y * sum(k);
  loop invariant 0 <= k <= n;
  loop invariant y == 1;
  loop invariant x >= 0;
  loop assigns x, k;
  loop variant k;
*/
  while ((k > 0))
    {
      /*@ assert (sum(n) == (x + (y * sum(k)))); */
      /*@ assert k > 0 ==> sum(k) == k + sum(k-1); */
      /*@ assert (sum(n) == (x + (y * (k + sum((k - 1)))))); */
      /*@ assert (sum(n) == ((x + (y * k)) + (y * sum((k - 1))))); */
      x = (x + (y * k));
      /*@ assert (sum(n) == (x + (y * sum((k - 1))))); */
      /*@ assert (sum(n) == (x + (y * sum((k - 1))))); */
      k = (k - 1);
      /*@ assert (sum(n) == (x + (y * sum(k)))); */
    }
  /*@ assert (k == 0); */
  /*@ assert sum(0) == 0; */
  /*@ assert (sum(n) == (x + (y * sum(0)))); */
  /*@ assert (sum(n) == (x + (y * 0))); */
  /*@ assert sum(n) == x; */
  int s = x;
  /*@ assert s >= 0 && s <= 2147483647; */
  /*@ assert (sum(n) == s); */
  return s;  // Dafny implicit return
}