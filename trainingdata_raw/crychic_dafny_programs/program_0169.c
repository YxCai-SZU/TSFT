// Generated C + ACSL

/*@ axiomatic Fibonacci {
      logic integer fib(integer n);
      axiom fib_base_0: fib(0) == 0;
      axiom fib_base_1: fib(1) == 1;
      axiom fib_recursive: \forall integer n; n >= 2 ==> fib(n) == fib(n-1) + fib(n-2);
      
      // Helper axioms to aid proving
      axiom fib_non_negative: \forall integer n; n >= 0 ==> fib(n) >= 0;
      axiom fib_monotonic: \forall integer n; n >= 0 ==> fib(n+1) >= fib(n);
    }
*/

/*@ requires n >= 0;
    requires n <= 46; // Ensure result fits in int
    decreases n;
    ensures \result == fib(n);
*/
int fib(int n)
{
  return ((n == 0)) ? (0) : (((n == 1)) ? (1) : ((fib((n - 1)) + fib((n - 2)))));
}

/*@ requires n >= 0;
    requires n <= 46; // Ensure result fits in int
    ensures \result == fib(n);
    ensures \result >= 0;
*/
int ComputeFib(int n)
{
  int f;
  if (n == 0)
  {
    f = 0;
    /*@ assert f >= 0 && f <= 2147483647; */
    /*@ assert f == fib(0); */
  }
  else
  {
    int i = 1;
    int f_2 = 0;
    int f_1 = 0;
    f = 1;
    /*@ assert i == 1; */
    /*@ assert f_1 == 0 && f_1 == fib(0); */
    /*@ assert f == 1 && f == fib(1); */
    /*@ assert f_2 == 0; */
/*@
  loop invariant 1 <= i <= n;
  loop invariant i >= \at(i, LoopEntry);
  loop invariant f_1 == fib(i - 1);
  loop invariant f == fib(i);
  loop invariant f_2 == (i >= 2 ? fib(i - 2) : 0);
  loop invariant f >= 0;
  loop invariant f_1 >= 0;
  loop invariant f_2 >= 0;
  loop invariant f >= f_1;
  loop invariant f_1 >= f_2;
  loop assigns i, f, f_1, f_2;
  loop variant n - i;
*/
    while (i < n)
      {
        f_2 = f_1;
        f_1 = f;
        f = (f_1 + f_2);
        i = (i + 1);
        /*@ assert f_2 == fib(i - 2); */
        /*@ assert f_1 == fib(i - 1); */
        /*@ assert f == fib(i); */
      }
    /*@ assert i == n; */
    /*@ assert f == fib(n); */
  }
  return f;
}