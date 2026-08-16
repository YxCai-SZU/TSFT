// Generated C + ACSL

/*@ logic integer Fib(integer n); */

/*@
  requires n >= 0;
  ensures \result == Fib(n);
*/
int Fibonacci(int n)
{
  if (n == 0)
  {
    return 2;
  }
  else
  if (n == 1)
  {
    return 1;
  }
  else
  {
    int l_b = 2;
    int l = 1;
    int i = 2;
/*@
  loop invariant 2 <= i <= n + 1;
  loop invariant l == Fib(i - 1);
  loop invariant l_b == Fib(i - 2);
  loop assigns i, l, l_b;
  loop variant n - i + 1;
*/
    while (i <= n)
      {
        int l_bb = l_b;
        l_b = l;
        l = (l + l_bb);
        i = (i + 1);
      }
    return l;
  }
}

/*@
  axiomatic FibDef {
    axiom Fib0: Fib(0) == 2;
    axiom Fib1: Fib(1) == 1;
    axiom FibRec: \forall integer n; n >= 2 ==> Fib(n) == Fib(n-1) + Fib(n-2);
  }
*/