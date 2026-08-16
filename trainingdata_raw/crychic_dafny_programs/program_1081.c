// Generated C + ACSL

/*@
    requires w >= 1;
    assigns \nothing;
    ensures \result <==> (w > 2 && w % 2 == 0);
*/
int CanSplitIntoTwoEvenNumbers(int w)
{
  if (((w <= 2) || ((w % 2) != 0)))
  {
    return 0;
  }
  return 1;
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  /* unsupported stmt: print "Enter a number: "; */
  int w = 1;
  int canSplit = CanSplitIntoTwoEvenNumbers(w);
  if (canSplit)
  {
    /* unsupported stmt: print "YES\n"; */
  }
  else
  {
    /* unsupported stmt: print "NO\n"; */
  }
}
