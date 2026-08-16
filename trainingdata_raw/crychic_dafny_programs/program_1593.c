// Generated C + ACSL

/*@
    requires n >= 0;
    assigns \nothing;
*/
void PrintRange(int n)
{
  /* unsupported stmt: print "*****\n"; */
  int i = 0;
/*@
  loop invariant 0 <= i <= n;
  loop assigns i;
  loop variant n - i;
*/
  while ((i < n))
    {
      /* unsupported stmt: print i, " "; */
      i = (i + 1);
    }
  /* unsupported stmt: print "\n"; */
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  PrintRange(5);;
}
