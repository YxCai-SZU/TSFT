// Generated C + ACSL

/*@ logic integer f(integer n); */

/*@ 
  axiomatic FunctionF {
    axiom f_base_case1: \forall integer n; n < 0 ==> f(n) == 1 - n;
    axiom f_base_case2: f(0) == 1;
    axiom f_base_case3: f(1) == 0;
    axiom f_recursive: \forall integer n; n >= 2 ==> 
                       f(n) == 2 * f(n-1) + f(n-2) + n;
  }
*/

/*@
  requires \true;
  decreases n >= 2 ? n : 0;
  assigns \nothing;
  ensures \result == f(n);
*/
int f(int n)
{
  return ((n <= 1)) ? ((1 - n)) : ((((2 * f((n - 1))) + f((n - 2))) + n));
}

/*@
  requires n >= 0;
  assigns \nothing;
  ensures \result == f(n);
*/
int computeF(int n)
{
  int x = 0;
  int y = 1;
  int k = 0;
/*@
  loop invariant 0 <= k <= n;
  loop invariant x == f(k + 1);
  loop invariant y == f(k);
  loop invariant k >= 0 ==> f(k) >= 0;
  loop invariant k >= 0 ==> f(k+1) >= 0;
  loop invariant x >= 0;
  loop invariant y >= 0;
  loop invariant x <= 2147483647;
  loop invariant y <= 2147483647;
  loop assigns k, x, y;
  loop variant n - k;
*/
  while ((k < n))
    {
      /*@ assert k >= 0; */
      /*@ assert k < n; */
      /*@ assert x == f(k + 1); */
      /*@ assert y == f(k); */
      /*@ assert k + 2 >= 2; */
      /*@ assert f(k + 2) == 2 * f(k + 1) + f(k) + (k + 2); */
      /*@ assert f(k + 2) == 2 * x + y + k + 2; */
      int temp = x;
      x = 2 * x + y + k + 2;
      y = temp;
      /*@ assert y == f(k + 1); */
      /*@ assert x == f(k + 2); */
      k = (k + 1);
      /*@ assert k >= 1; */
      /*@ assert x == f(k + 1); */
      /*@ assert y == f(k); */
    }
  /*@ assert k == n; */
  /*@ assert x == f(n + 1); */
  /*@ assert y == f(n); */
  int a = y;
  /*@ assert a == f(n); */
  /*@ assert n >= 0 ==> f(n) >= 0; */
  /*@ assert a >= 0 && a <= 2147483647; */
  return a;
}