// Generated C + ACSL

/*@ axiomatic Fibonacci {
  @   logic integer fib(integer n);
  @   axiom fib_base_0: fib(0) == 0;
  @   axiom fib_base_1: fib(1) == 1;
  @   axiom fib_rec: \forall integer n; n >= 2 ==> fib(n) == fib(n-1) + fib(n-2);
  @ }
  */

/*@ requires n >= 0;
  @ ensures \result == fib(n);
  */
int computeFib(int n)
{
  int i = 0;
  int x = 0;
  /*@ assert x == 0; */
  int y = 1;
  /*@ assert x == fib(0); */
  /*@ assert y == fib(1); */
  
/*@
  loop invariant 0 <= i <= n;
  loop invariant x == fib(i);
  loop invariant y == fib(i + 1);
  loop invariant i < n ==> x >= 0;
  loop invariant i < n ==> y >= 0;
  loop invariant i >= 1 ==> x <= y;
  loop assigns i, x, y;
  loop variant n - i;
*/
  while ((i < n))
    {
      /*@ assert x == fib(i); */
      /*@ assert y == fib(i + 1); */
      /*@ assert i + 1 <= n; */
      
      // Implement: x, y := y, x + y
      int temp = x;
      /*@ assert temp == fib(i); */
      x = y;
      /*@ assert x == fib(i + 1); */
      y = temp + y;
      /*@ assert y == fib(i) + fib(i + 1); */
      /*@ assert i + 2 >= 2 ==> y == fib(i + 2); */
      
      i = (i + 1);
      /*@ assert x == fib(i); */
      /*@ assert y == fib(i + 1); */
    }
  /*@ assert i == n; */
  /*@ assert x == fib(n); */
  return x;
}