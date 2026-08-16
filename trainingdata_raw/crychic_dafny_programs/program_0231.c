// Generated C + ACSL

/*@
    requires n >= 0;
    assigns \nothing;
    ensures \result == n * (n + 1) / 2;
*/
int Gauss(int n)
{
  int sum = 0;
  /*@ assert sum >= 0 && sum <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= n;
  loop invariant sum == i * (i + 1) / 2;
  loop invariant sum >= 0;
  loop assigns i, sum;
  loop variant n - i;
*/
  while ((i < n))
    {
      /*@ assert sum == i * (i + 1) / 2; */
      /*@ assert i + 1 <= n; */
      i = (i + 1);
      /*@ assert sum == (i - 1) * i / 2; */
      /*@ assert i * (i + 1) / 2 == (i - 1) * i / 2 + i; */
      sum = (sum + i);
      /*@ assert sum == i * (i + 1) / 2; */
    }
  return sum;  // Dafny implicit return
}

/*@
    requires n >= 0;
    assigns \nothing;
    ensures \result == n * n;
*/
int sumOdds(int n)
{
  int sum = 0;
  /*@ assert sum >= 0 && sum <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= n;
  loop invariant sum == i * i;
  loop assigns i, sum;
  loop variant n - i;
*/
  while ((i < n))
    {
      sum = ((sum + (2 * i)) + 1);
      i = (i + 1);
    }
  return sum;  // Dafny implicit return
}