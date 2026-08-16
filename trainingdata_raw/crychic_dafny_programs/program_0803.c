// Generated C + ACSL

/*@
    requires stars > 0;
    requires spaces >= 0;
    assigns \nothing;
*/
void PrintLineWithSpaces(int spaces, int stars)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= spaces;
  loop invariant i == \at(i, LoopEntry) + (\at(i, LoopEntry) - \at(i, LoopEntry)) + (i - \at(i, LoopEntry));
  loop assigns i;
  loop variant spaces - i;
*/
  while ((i < spaces))
    {
      /* unsupported stmt: print " "; */
      i = (i + 1);
    }
  int j = 0;
/*@
  loop invariant 0 <= j <= stars;
  loop assigns j;
  loop variant stars - j;
*/
  while ((j < stars))
    {
      if ((j > 0))
      {
        /* unsupported stmt: print " "; */
      }
      /* unsupported stmt: print "*"; */
      j = (j + 1);
    }
  /* unsupported stmt: print "\n"; */
}

/*@
    assigns \nothing;
*/
void PrintPyramid(void)
{
  PrintLineWithSpaces(2, 1);;
  PrintLineWithSpaces(1, 2);;
  PrintLineWithSpaces(0, 3);;
}