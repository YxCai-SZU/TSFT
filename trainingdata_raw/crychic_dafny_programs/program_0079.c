// Generated C + ACSL

/*@
    requires n >= 0;
    assigns \nothing;
*/
void dafny_main(int n)
{
  int sum = 0;
  /*@ assert sum >= 0 && sum <= 2147483647; */
  int i = 0;
  /*@ assert i >= 0 && i <= 2147483647; */
/*@
  loop invariant 0 <= i <= n;
  loop invariant sum >= 0;
  loop invariant sum == i * (i - 1) / 2;
  loop assigns i, sum;
  loop variant n - i;
*/
  while ((i < n))
    {
      sum = (sum + i);
      i = (i + 1);
    }
}
