// Generated C + ACSL

/*@
    requires n >= 0;
    assigns \nothing;
*/
void PrintAlternatingBits(int n)
{
  int i = 1;
/*@
  loop invariant 1 <= i <= n + 1;
  loop invariant i == \at(i, LoopEntry) + (\at(i, LoopEntry) <= n ? (i - \at(i, LoopEntry)) : 0);
  loop assigns i;
  loop variant n - i + 1;
*/
  while ((i <= n))
    {
      if (((i % 2) == 1))
      {
        /* unsupported stmt: print "1 "; */
      }
      else
      {
        /* unsupported stmt: print "0 "; */
      }
      i = (i + 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  /* unsupported stmt: print "Please input the number of 1's and 0's you want to print: "; */
  int n = 5;
  PrintAlternatingBits(n);;
}
