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

/*@ logic integer factorial_logic(integer n) =
      (n <= 0) ? 1 : n * factorial_logic(n - 1);
*/

/*@
    requires n >= 0;
    requires n <= 12;
    assigns \nothing;
    ensures \result == factorial_logic(n);
    ensures \result >= 1;
*/
int factorial(int n)
{
  int i = 1;
  int res = 1;
  /*@ assert res == 1; */
  /*@ assert i == 1; */
  /*@ assert res == factorial_logic(0); */
/*@
  loop invariant 1 <= i <= n + 1;
  loop invariant res >= 1;
  loop invariant res == factorial_logic(i - 1);
  loop assigns i, res;
  loop variant n + 1 - i;
*/
  while ((i < (n + 1)))
    {
      /*@ assert res == factorial_logic(i - 1); */
      res = (i * res);
      /*@ assert res == i * factorial_logic(i - 1); */
      i = (i + 1);
      /*@ assert res == factorial_logic(i - 1); */
    }
  /*@ assert i == n + 1; */
  /*@ assert res == factorial_logic(n); */
  return res;  // Dafny implicit return
}