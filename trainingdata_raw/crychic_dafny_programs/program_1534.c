// Generated C + ACSL

/*@
    assigns \nothing;
*/
void IAmTestNo7(void)
{
  int a = 1;
  /*@ assert a >= 0 && a <= 1; */
  int b = 2;
  /*@ assert b >= 0 && b <= 2147483647; */
  if (0)
  {
    /* unsupported stmt: print a; */
    int a = 99;
    /* unsupported stmt: print a; */
  }
  else
  if ((!(1) || (a && (b == 2))))
  {
    /* unsupported stmt: print a; */
    int a = 99;
    /* unsupported stmt: print a; */
  }
  else
  {
    /* unsupported stmt: print a; */
    int a = 99;
    /* unsupported stmt: print a; */
  }
/*@
  loop invariant \at(b, LoopEntry) <= b <= 10;
  loop invariant b >= \at(b, LoopEntry);
  loop assigns b;
  loop variant 10 - b;
*/
  while ((b < 10))
    {
      b = (b + 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  IAmTestNo7();;
}
