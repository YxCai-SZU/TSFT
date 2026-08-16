// Generated C + ACSL

/*@ logic integer Fat(integer n) =
      (n <= 0) ? 1 : n * Fat(n - 1);
*/

/*@ requires n >= 0;
    decreases n;
    ensures \result == Fat(n);
    assigns \nothing;
*/
int Fat(int n)
{
  return ((n == 0)) ? (1) : ((n * Fat((n - 1))));
}

/*@ requires n >= 0;
    requires n <= 12;
    ensures \result == Fat(n);
    assigns \nothing;
*/
int Fatorial(int n)
{
  int f = 1;
  /*@ assert f == 1; */
  /*@ assert f == Fat(0); */
  int i = 1;
  /*@ assert i == 1; */
  /*@ assert f == Fat(i - 1); */
/*@
  loop invariant 1 <= i <= n + 1;
  loop invariant f == Fat(i - 1);
  loop invariant i <= n + 1;
  loop assigns i, f;
  loop variant n - i + 1;
*/
  while ((i <= n))
    {
      /*@ assert i <= n; */
      /*@ assert f == Fat(i - 1); */
      f = (f * i);
      /*@ assert f == Fat(i - 1) * i; */
      /*@ assert f == Fat(i); */
      i = (i + 1);
      /*@ assert f == Fat(i - 1); */
    }
  /*@ assert i == n + 1; */
  /*@ assert f == Fat(n); */
  return f;
}