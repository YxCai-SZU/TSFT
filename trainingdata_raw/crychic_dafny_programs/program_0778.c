// Generated C + ACSL

/*@
    requires width > 0;
    assigns \nothing;
*/
void PrintAlternatingLine(int width)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= width;
  loop assigns i;
  loop variant width - i;
*/
  while ((i < width))
    {
      /* unsupported stmt: print "#."; */
      i = (i + 1);
    }
  /* unsupported stmt: print "\n"; */
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  /* unsupported stmt: print "2000 2000\n"; */
  int row = 0;
/*@
  loop invariant 0 <= row <= 2000;
  loop assigns row;
  loop variant 2000 - row;
*/
  while ((row < 2000))
    {
      PrintAlternatingLine(1000);;
      row = (row + 1);
    }
}

/*@
    assigns \nothing;
*/
void Program(void)
{
  Main();;
}
