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
  loop invariant sum == \at(sum, LoopEntry) + (i * (i - 1)) / 2;
  loop invariant sum >= 0;
  loop invariant i >= 0 ==> sum == (i * (i - 1)) / 2;
  loop invariant \forall integer k; 0 <= k < i ==> k < i;
  loop assigns i, sum;
  loop variant n - i;
*/
  while ((i < n))
    {
      /*@ assert sum == (i * (i - 1)) / 2; */
      sum = (sum + i);
      /*@ assert sum == (i * (i + 1)) / 2; */
      i = (i + 1);
      /*@ assert sum == (i * (i - 1)) / 2; */
    }
  /*@ assert i == n; */
  /*@ assert sum == (n * (n - 1)) / 2; */
}