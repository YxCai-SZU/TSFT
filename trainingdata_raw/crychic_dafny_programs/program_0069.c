// Generated C + ACSL

/*@ logic integer Sum(integer n) = (n == 0) ? 0 : n + Sum(n - 1); */

/*@
  requires n >= 0;
  decreases n;
  ensures \result == Sum(n);
*/
int Sum(int n)
{
  return ((n == 0)) ? (0) : ((n + Sum((n - 1))));
}

/*@
  requires n >= 0;
  requires n <= 65535;
  ensures \result == n * (n + 1) / 2;
*/
int ComputeSum(int n)
{
  int s = 0;
  /*@ assert s >= 0 && s <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= n;
  loop invariant s == i * (i + 1) / 2;
  loop invariant s == Sum(i);
  loop invariant 0 <= s <= i * (i + 1) / 2;
  loop invariant i <= 65535;
  loop invariant s <= 2147483647;
  loop assigns i, s;
  loop variant n - i;
*/
  while ((i < n))
    {
      /*@ assert i < n; */
      /*@ assert s == i * (i + 1) / 2; */
      i = (i + 1);
      /*@ assert s == (i - 1) * i / 2; */
      /*@ assert i * (i + 1) / 2 == (i - 1) * i / 2 + i; */
      s = (s + i);
      /*@ assert s == i * (i + 1) / 2; */
    }
  /*@ assert i == n; */
  /*@ assert s == n * (n + 1) / 2; */
  return s;
}