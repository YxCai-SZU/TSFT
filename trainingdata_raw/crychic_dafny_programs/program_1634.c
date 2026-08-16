// Generated C + ACSL

/*@
    assigns \nothing;
*/
void Main(void)
{
  int b = 1;
  if (b)
  {
    /* unsupported stmt: print "Python in Easy steps\n"; */
  }
  else
  {
  }
}

/*@
    assigns \nothing;
*/
void ContinueExample(void)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= 5;
  loop assigns i;
  loop variant 5 - i;
*/
  while ((i < 5))
    {
      i = (i + 1);
      if ((i == 3))
      {
        continue;;
      }
      /* unsupported stmt: print i, "\n"; */
    }
}

/*@
    assigns \nothing;
*/
void Program(void)
{
  Main();;
  ContinueExample();;
}
