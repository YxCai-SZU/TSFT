// Generated C + ACSL

/*@ axiomatic Fibonacci {
  @   logic integer fib(integer n);
  @   axiom fib_base_0: fib(0) == 0;
  @   axiom fib_base_1: fib(1) == 1;
  @   axiom fib_rec: \forall integer n; n >= 2 ==> fib(n) == fib(n-1) + fib(n-2);
  @ }
  @*/

/*@ requires n >= 0;
  @ requires n <= 46;
  @ ensures \result == fib(n);
  @*/
int ComputeFib(int n)
{
  int i = 0;
  int b = 0;
  /*@ assert b >= 0 && b <= 2147483647; */
  int c = 1;
  
  /*@ assert fib(0) == 0; */
  /*@ assert fib(1) == 1; */
  /*@ assert b == fib(0); */
  /*@ assert c == fib(1); */
  
/*@
  loop invariant 0 <= i <= n;
  loop invariant b == fib(i);
  loop invariant c == fib(i + 1);
  loop invariant b >= 0;
  loop invariant c >= 0;
  loop invariant i < n ==> c >= b;
  loop assigns i, b, c;
  loop variant n - i;
*/
  while ((i < n))
    {
      /*@ assert i < n; */
      /*@ assert b == fib(i); */
      /*@ assert c == fib(i + 1); */
      
      // Simultaneous assignment: b, c := c, c + b
      int temp = c;
      /*@ assert temp == fib(i + 1); */
      c = c + b;
      /*@ assert c == fib(i + 1) + fib(i); */
      /*@ assert i + 1 >= 1; */
      /*@ assert c == fib(i + 2); */
      b = temp;
      /*@ assert b == fib(i + 1); */
      
      i = (i + 1);
      /*@ assert b == fib(i); */
      /*@ assert c == fib(i + 1); */
    }
  
  /*@ assert i == n; */
  /*@ assert b == fib(n); */
  
  return b;
}