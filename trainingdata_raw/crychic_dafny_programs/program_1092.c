// Generated C + ACSL

/*@
    requires n >= 0;
    assigns \nothing;
*/
void PrintFibonacci(int n)
{
  int x = 0;
  int y = 1;
  int remaining = n;
/*@
  loop invariant 0 <= remaining <= \at(remaining, LoopEntry);
  loop invariant remaining <= n;
  loop invariant x >= 0;
  loop invariant y >= 0;
  loop assigns remaining, x, y;
  loop variant remaining;
*/
  while ((remaining > 0))
    {
      /* unsupported stmt: print y, " "; */
      /* unsupported stmt: x, y := y, x + y; */
      remaining = (remaining - 1);
    }
}

/*@ logic integer Fib(integer n); */
/*@
    requires n >= 0;
    decreases n;
    assigns \nothing;
*/
int Fib(int n)
{
  return ((n == 0)) ? (0) : (((n == 1)) ? (1) : ((Fib((n - 1)) + Fib((n - 2)))));
}