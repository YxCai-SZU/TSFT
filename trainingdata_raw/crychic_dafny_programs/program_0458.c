// Generated C + ACSL

/*@
    assigns \nothing;
*/
void Sum(void)
{
  int n = 0;
  int s = 0;
/*@
  loop invariant 0 <= n <= 33;
  loop invariant s == n * (n + 1) / 2;
  loop invariant n <= 33;
  loop assigns n, s;
  loop variant 33 - n;
*/
  while ((n != 33))
    {
      n = (n + 1);
      /*@ assert n >= 0 && n <= 2147483647; */
      s = (s + n);
      /*@ assert s >= 0 && s <= 2147483647; */
    }
}