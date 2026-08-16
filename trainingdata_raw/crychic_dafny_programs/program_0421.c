// Generated C + ACSL

/*@ axiomatic FLogic {
  @   logic integer f(integer n);
  @   logic integer fSum(integer n);
  @   
  @   axiom f_base: \forall integer n; n <= 0 ==> f(n) == 1;
  @   axiom f_rec: \forall integer n; n > 0 ==> f(n) == n + f(n-1) * f(n-2);
  @   
  @   axiom fSum_base: \forall integer n; n <= 0 ==> fSum(n) == 0;
  @   axiom fSum_rec: \forall integer n; n > 0 ==> fSum(n) == f(n-1) + fSum(n-1);
  @   
  @   axiom f_positive: \forall integer n; n >= 0 ==> f(n) >= 1;
  @   axiom fSum_nonneg: \forall integer n; n >= 0 ==> fSum(n) >= 0;
  @ }
  */

/*@ requires n >= -1000 && n <= 1000;
  @ decreases n;
  @ ensures n <= 0 ==> \result == 1;
  @ ensures n > 0 ==> \result == n + f(n-1) * f(n-2);
  @ ensures \result == f(n);
  @ ensures \result >= 1;
  */
int f(int n)
{
  return ((n <= 0)) ? (1) : ((n + (f((n - 1)) * f((n - 2)))));
}

/*@ requires n >= -1000 && n <= 1000;
  @ decreases n;
  @ ensures n <= 0 ==> \result == 0;
  @ ensures n > 0 ==> \result == f(n-1) + fSum(n-1);
  @ ensures \result == fSum(n);
  @ ensures \result >= 0;
  */
int fSum(int n)
{
  return ((n <= 0)) ? (0) : ((f((n - 1)) + fSum((n - 1))));
}

/*@ requires n >= 0 && n <= 100;
  @ ensures \result == fSum(n);
  */
int problem6(int n)
{
  int a = 0;
  /*@ assert a >= 0 && a <= 2147483647; */
  int k = 0;
  int x = 1;
  int y = 2;
  /*@ assert k == 0; */
  /*@ assert x == 1; */
  /*@ assert y == 2; */
  /*@ assert x == f(0); */
  /*@ assert y == f(1); */
  /*@ assert a == fSum(0); */
/*@
  loop invariant 0 <= k <= n;
  loop invariant x == f(k);
  loop invariant y == f(k + 1);
  loop invariant a == fSum(k);
  loop invariant x >= 1;
  loop invariant y >= 1;
  loop invariant a >= 0;
  loop assigns k, x, y, a;
  loop variant n - k;
*/
  while ((k < n))
    {
      /*@ assert (((x == f(k)) && (y == f((k + 1)))) && (a == fSum(k))); */
      /*@ assert k < n; */
      /*@ assert 0 <= k < n; */
      k = (k + 1);
      /*@ assert (((x == f((k - 1))) && (y == f(k))) && (a == fSum((k - 1)))); */
      /*@ assert (((x == f((k - 1))) && (y == f(k))) && (a == (fSum(k) - f((k - 1))))); */
      a = (a + x);
      /*@ assert (((x == f((k - 1))) && (y == f(k))) && (a == ((fSum(k) - f((k - 1))) + f((k - 1))))); */
      /*@ assert (((x == f((k - 1))) && (y == f(k))) && (a == fSum(k))); */
      /*@ assert a == fSum(k); */
      /*@ assert x == f(k-1); */
      /*@ assert y == f(k); */
      int temp_x = y;
      int temp_y = k + 1 + x * y;
      /*@ assert temp_x == f(k); */
      /*@ assert temp_y == k + 1 + f(k-1) * f(k); */
      x = temp_x;
      y = temp_y;
      /*@ assert x == f(k); */
      /*@ assert y == k + 1 + f(k-1) * f(k); */
      /*@ assert k > 0 ==> y == k + 1 + f((k+1)-2) * f((k+1)-1); */
      /*@ assert k > 0 ==> y == f(k+1); */
      /*@ assert (((x == f(k)) && (y == ((k + 1) + (f((k - 1)) * f(k))))) && (a == fSum(k))); */
      /*@ assert (((x == f(k)) && (y == ((k + 1) + (f(((k + 1) - 2)) * f(((k + 1) - 1)))))) && (a == fSum(k))); */
      /*@ assert (((x == f(k)) && (y == f((k + 1)))) && (a == fSum(k))); */
    }
  /*@ assert k == n; */
  /*@ assert (a == fSum(k)); */
  /*@ assert a == fSum(n); */
  return a;
}