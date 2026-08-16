// Generated C + ACSL

/*@ axiomatic Fibonacci {
  @   logic integer fib(integer n);
  @   axiom fib_base_0: fib(0) == 0;
  @   axiom fib_base_1: fib(1) == 1;
  @   axiom fib_rec: \forall integer n; n >= 2 ==> fib(n) == fib(n-1) + fib(n-2);
  @   axiom fib_positive: \forall integer n; n >= 0 ==> fib(n) >= 0;
  @   axiom fib_monotone: \forall integer n; n >= 1 ==> fib(n) >= fib(n-1);
  @ }
  */

/*@ requires n >= 0;
  @ requires n <= 46;
  @ ensures \result == fib(n);
  @ assigns \nothing;
  */
int Fib(int n)
{
  if ((n == 0))
  {
    return 0;
  }
  int a = 0;
  int b = 1;
  /*@ assert a == 0; */
  /*@ assert b == 1; */
  /*@ assert a == fib(0); */
  /*@ assert b == fib(1); */
  int i = 1;
/*@
  loop invariant 1 <= i <= n;
  loop invariant a == fib(i - 1);
  loop invariant b == fib(i);
  loop invariant 0 <= a;
  loop invariant 0 <= b;
  loop invariant a <= b;
  loop invariant b <= 2147483647;
  loop assigns i, a, b;
  loop variant n - i;
*/
  while ((i < n))
    {
      int temp = a + b;
      /*@ assert temp == a + b; */
      /*@ assert a == fib(i-1); */
      /*@ assert b == fib(i); */
      /*@ assert i >= 1; */
      /*@ assert temp == fib(i-1) + fib(i); */
      /*@ assert i + 1 >= 2; */
      /*@ assert temp == fib(i+1); */
      a = b;
      b = temp;
      /*@ assert a == fib(i); */
      /*@ assert b == fib(i+1); */
      i = (i + 1);
      /*@ assert a == fib(i-1); */
      /*@ assert b == fib(i); */
    }
  /*@ assert i == n; */
  /*@ assert b == fib(n); */
  return b;
}