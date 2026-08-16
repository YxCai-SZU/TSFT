// Generated C + ACSL

/*@
    requires n >= 0;
    assigns \nothing;
*/
void PrintMultiplicationTable(int n)
{
  int i = 10;
/*@
  loop invariant 0 <= i <= 10;
  loop invariant i <= \at(i, LoopEntry);
  loop assigns i;
  loop variant i;
*/
  while ((i > 0))
    {
      /* unsupported stmt: print n, " x ", i, " = ", n * i, "\n"; */
      i = (i - 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int input;
  /* unsupported stmt: print "Enter the number: "; */
  input = 5;
  PrintMultiplicationTable(input);;
}
