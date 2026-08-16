// Generated C + ACSL

/*@
    assigns \nothing;
*/
void m(void)
{
  int i = 0;
  int n = 20;
/*@
  loop invariant 0 <= i <= n;
  loop assigns i;
  loop variant n - i;
*/
  while ((i != n))
    {
      i = (i + 1);
    }
}
