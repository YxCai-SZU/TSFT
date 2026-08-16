// Generated C + ACSL

void PrintTableMethod1(void);
void PrintTableMethod2(void);
void PrintTableMethod3(void);

/*@
    assigns \nothing;
*/
void MultiplicationTable(void)
{
  PrintTableMethod1();;
  /* unsupported stmt: print "\n"; */
  PrintTableMethod2();;
  /* unsupported stmt: print "\n"; */
  PrintTableMethod3();;
}

/*@
    assigns \nothing;
*/
void PrintTableMethod1(void)
{
  int i = 1;
/*@
  loop invariant 1 <= i <= 10;
  loop invariant \at(i, LoopEntry) <= i <= 10;
  loop invariant i >= \at(i, LoopEntry);
  loop assigns i;
  loop variant 10 - i;
*/
  while ((i < 10))
    {
      int j = 1;
/*@
  loop invariant 1 <= j <= i + 1;
  loop invariant \at(i, LoopEntry) == i;
  loop invariant j >= \at(j, LoopEntry);
  loop assigns j;
  loop variant i + 1 - j;
*/
      while ((j <= i))
        {
          /* unsupported stmt: print j, "x", i, "=", i * j, "\t"; */
          j = (j + 1);
        }
      /* unsupported stmt: print "\n"; */
      i = (i + 1);
    }
}

/*@
    assigns \nothing;
*/
void PrintTableMethod2(void)
{
  int i = 1;
/*@
  loop invariant 1 <= i <= 10;
  loop assigns i;
  loop variant 10 - i;
*/
  while ((i < 10))
    {
      int j = 1;
/*@
  loop invariant 1 <= j <= i + 1;
  loop invariant i == \at(i, LoopEntry);
  loop invariant \at(i, LoopEntry) >= 1;
  loop assigns j;
  loop variant i + 1 - j;
*/
      while ((j <= i))
        {
          if ((j == i))
          {
            /* unsupported stmt: print j, "x", i, "=", i * j, "\n"; */
          }
          else
          {
            /* unsupported stmt: print j, "x", i, "=", i * j, "\t"; */
          }
          j = (j + 1);
        }
      i = (i + 1);
    }
}

/*@
    assigns \nothing;
*/
void PrintTableMethod3(void)
{
  int y = 1;
/*@
  loop invariant 1 <= y <= 10;
  loop invariant \at(y, LoopEntry) <= y;
  loop assigns y;
  loop variant 10 - y;
*/
  while ((y < 10))
    {
      int x = 1;
/*@
  loop invariant 1 <= x <= y + 1;
  loop invariant 1 <= \at(y, LoopEntry) <= y;
  loop invariant y == \at(y, LoopEntry);
  loop assigns x;
  loop variant y + 1 - x;
*/
      while ((x <= y))
        {
          /* unsupported stmt: print x, "x", y, "=", x * y; */
          if ((x != y))
          {
            /* unsupported stmt: print "\t"; */
          }
          x = (x + 1);
        }
      /* unsupported stmt: print "\n"; */
      y = (y + 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  MultiplicationTable();;
}