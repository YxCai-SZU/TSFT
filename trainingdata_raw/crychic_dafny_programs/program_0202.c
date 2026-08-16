// Generated C + ACSL

/*@
    requires n >= 0;
    decreases n;
    assigns \nothing;
    ensures \result >= 1;
*/
int fact(int n)
{
  return ((n == 0)) ? (1) : ((n * fact((n - 1))));
}

/*@ logic integer factorial(integer n) =
      n <= 0 ? 1 : n * factorial(n - 1);
*/

/*@
    requires n >= 0;
    requires n <= 12;  // Prevent overflow for int
    assigns \nothing;
    ensures \result >= 1;
    ensures \result == factorial(n);
*/
int factorial(int n)
{
  int i = 1;
  int res = 1;
  /*@ assert res == 1; */
  /*@ assert i == 1; */
  /*@ assert res == factorial(0); */
  
/*@
  loop invariant 1 <= i <= n + 1;
  loop invariant res >= 1;
  loop invariant res == factorial(i - 1);
  loop assigns i, res;
  loop variant n + 1 - i;
*/
  while ((i < (n + 1)))
    {
      /*@ assert 1 <= i <= n; */
      /*@ assert res == factorial(i - 1); */
      res = (i * res);
      /*@ assert res == i * factorial(i - 1); */
      /*@ assert res == factorial(i); */
      i = (i + 1);
      /*@ assert res == factorial(i - 1); */
    }
  /*@ assert i == n + 1; */
  /*@ assert res == factorial(n); */
  return res;
}