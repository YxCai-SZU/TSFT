// Generated C + ACSL

/*@ logic integer factorial(integer n) =
      (n <= 0) ? 1 : n * factorial(n - 1);
*/

/*@
  requires n >= 0;
  decreases n;
  ensures \result == factorial(n);
*/
int Factorial(int n)
{
  return ((n == 0)) ? (1) : ((n * Factorial((n - 1))));
}

/*@
  requires n >= 0;
  ensures \result == factorial(n);
*/
int IterativeFactorial(int n)
{
  int result = 1;
  /*@ assert result == 1; */
  /*@ assert result == factorial(0); */
  int i = 1;
  /*@ assert i == 1; */
  /*@ assert result == factorial(i - 1); */
/*@
  loop invariant 1 <= i <= n + 1;
  loop invariant result == factorial(i - 1);
  loop invariant i > n ==> result == factorial(n);
  loop assigns i, result;
  loop variant n - i + 1;
*/
  while ((i <= n))
    {
      /*@ assert i <= n; */
      /*@ assert result == factorial(i - 1); */
      result = (result * i);
      /*@ assert result == factorial(i - 1) * i; */
      /*@ assert result == factorial(i); */
      i = (i + 1);
      /*@ assert result == factorial(i - 1); */
    }
  /*@ assert i == n + 1; */
  /*@ assert result == factorial(n); */
  return result;
}