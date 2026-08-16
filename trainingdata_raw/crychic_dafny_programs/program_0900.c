// Generated C + ACSL

/*@ axiomatic Fibonacci {
  @   logic integer Fib(integer n);
  @   
  @   axiom Fib_base1: Fib(1) == 1;
  @   axiom Fib_base2: Fib(2) == 1;
  @   axiom Fib_rec: \forall integer n; n > 2 ==> Fib(n) == Fib(n-1) + Fib(n-2);
  @   axiom Fib_positive: \forall integer n; n > 0 ==> Fib(n) >= 1;
  @ }
  */

/*@
    requires n > 0;
    assigns \nothing;
    ensures \result == Fib(n);
    ensures \result >= 1;
*/
int Fibonacci(int n)
{
  if (((n == 1) || (n == 2)))
  {
    //@ assert Fib(n) == 1;
    return 1;
  }
  //@ assert n > 2;
  //@ assert Fib(n) == Fib(n-1) + Fib(n-2);
  int prev1 = 1;
  int prev2 = 1;
  int i = 2;
  //@ assert prev1 == Fib(1);
  //@ assert prev2 == Fib(2);
  //@ assert i == 2;
/*@
  loop invariant 2 <= i <= n;
  loop invariant prev1 == Fib(i - 1);
  loop invariant prev2 == Fib(i);
  loop invariant prev1 >= 1;
  loop invariant prev2 >= 1;
  loop assigns i, prev1, prev2;
  loop variant n - i;
*/
  while ((i < n))
    {
      //@ assert i < n;
      //@ assert prev1 == Fib(i-1);
      //@ assert prev2 == Fib(i);
      int temp = prev2;
      prev2 = (prev1 + prev2);
      //@ assert prev2 == Fib(i-1) + Fib(i);
      //@ assert prev2 == Fib(i+1);
      prev1 = temp;
      //@ assert prev1 == Fib(i);
      i = (i + 1);
      //@ assert i <= n;
      //@ assert prev1 == Fib(i-1);
      //@ assert prev2 == Fib(i);
    }
  //@ assert i == n;
  //@ assert prev2 == Fib(n);
  return prev2;
}

/*@
    requires n > 0;
    decreases n;
    assigns \nothing;
    ensures \result >= 1;
    ensures \result == Fib(n);
*/
int Fib(int n)
{
  return (((n == 1) || (n == 2))) ? (1) : ((Fib((n - 1)) + Fib((n - 2))));
}

/*@
    requires n > 0;
    assigns \nothing;
*/
void PrintFibonacciSequence(int n)
{
  int i = 1;
/*@
  loop invariant 1 <= i <= n + 1;
  loop assigns i;
  loop variant n + 1 - i;
*/
  while ((i <= n))
    {
      int fib = Fibonacci(i);
      //@ assert fib == Fib(i);
      //@ assert fib >= 1;
      /* unsupported stmt: print fib, " "; */
      i = (i + 1);
    }
  /* unsupported stmt: print "\n"; */
}

/*@
    requires \true;
    assigns \nothing;
*/
void Main(void)
{
  /* unsupported stmt: print "Fibonacci Sequence:\n"; */
  PrintFibonacciSequence(10);;
  /* unsupported stmt: print "10th Fibonacci number: "; */
  int tenth = Fibonacci(10);
  /* unsupported stmt: print tenth, "\n"; */
}