// Generated C + ACSL

/*@
    requires n > 0;
    assigns \nothing;
*/
void PrintNumbers(int n)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= n;
  loop assigns i;
  loop variant n - i;
*/
  while ((i < n))
    {
      /* unsupported stmt: print (i + 1, "\n"); */
      i = (i + 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  /* unsupported stmt: print "Super Sweet Open Source Project!\n"; */
  /* unsupported stmt: print "Now includes my excellent new feature...\n"; */
  PrintNumbers(3);;
}
