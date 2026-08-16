// Generated C + ACSL

/*@ logic integer fact(integer n) =
      n <= 0 ? 1 : n * fact(n - 1);
*/
/*@ requires n >= 0;
    decreases n;
*/
int fact(int n)
{
  return ((n <= 0)) ? (1) : ((n * fact((n - 1))));
}

/*@ axiomatic Factorial {
      logic integer fact_ax(integer n);
      axiom fact_base:
        fact_ax(0) == 1;
      axiom fact_rec:
        \forall integer n; n > 0 ==> fact_ax(n) == n * fact_ax(n - 1);
    }
*/
/*@ requires n >= 0;
    requires n <= 12;
    ensures \result == fact_ax(n);
*/
int Factorial(int n)
{
  int i = 1;
  int p = 1;
  /*@ assert i >= 0 && i <= 2147483647; */
  /*@ assert p == 1; */
  /*@ assert p == fact_ax(0); */
  /* unsupported stmt: i, p := 1, 1; */
/*@
  loop invariant 1 <= i <= n + 1;
  loop invariant p >= 1;
  loop invariant p == fact_ax(i - 1);
  loop invariant i > n ==> p == fact_ax(n);
  loop assigns i, p;
  loop variant n + 1 - i;
*/
  while ((i <= n))
    {
      /*@ assert i <= n; */
      /*@ assert p == fact_ax(i - 1); */
      /*@ assert 1 <= i <= n; */
      p = (p * i);
      /*@ assert p == fact_ax(i - 1) * i; */
      /*@ assert p == fact_ax(i); */
      /*@ assert p >= 0 && p <= 2147483647; */
      i = (i + 1);
      /*@ assert p == fact_ax(i - 1); */
    }
  /*@ assert i == n + 1; */
  /*@ assert p == fact_ax(n); */
  return p;  // Dafny implicit return
}