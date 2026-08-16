// Generated C + ACSL

/*@
    requires rows > 0;
    requires cols > 0;
    assigns \nothing;
*/
void PrintSolidRectangle(int rows, int cols)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= rows;
  loop assigns i;
  loop variant rows - i;
*/
  while ((i < rows))
    {
      int j = 0;
/*@
  loop invariant 0 <= j <= cols;
  loop assigns j;
  loop variant cols - j;
*/
      while ((j < cols))
        {
          /* unsupported stmt: print "*"; */
          j = (j + 1);
        }
      /* unsupported stmt: print "\n"; */
      i = (i + 1);
    }
}

/*@
    requires rows >= 2;
    requires cols >= 2;
    assigns \nothing;
*/
void PrintHollowRectangle(int rows, int cols)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= rows;
  loop invariant \valid(&i);
  loop assigns i;
  loop variant rows - i;
*/
  while ((i < rows))
    {
      int j = 0;
/*@
  loop invariant 0 <= j <= cols;
  loop invariant 0 <= i <= rows;
  loop invariant i == \at(i, LoopEntry);
  loop assigns j;
  loop variant cols - j;
*/
      while ((j < cols))
        {
          if (((((i == 0) || (i == (rows - 1))) || (j == 0)) || (j == (cols - 1))))
          {
            /* unsupported stmt: print "*"; */
          }
          else
          {
            /* unsupported stmt: print " "; */
          }
          j = (j + 1);
        }
      /* unsupported stmt: print "\n"; */
      i = (i + 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  PrintSolidRectangle(5, 5);;
  /* unsupported stmt: print "\n"; */
  PrintHollowRectangle(5, 5);;
}
