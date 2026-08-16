// Generated C + ACSL

/*@
    assigns \nothing;
*/
void MultiplicationTable(int n)
{
  /* unsupported stmt: print "Multiplication table for ", n, ":\n"; */
  int x = 1;
/*@
  loop invariant 1 <= x <= 13;
  loop assigns x;
  loop variant 13 - x;
*/
  while ((x < 13))
    {
      /* unsupported stmt: print n, " x ", x, " = ", n * x, "\n"; */
      x = (x + 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  /* unsupported stmt: print "Enter any int number:\n"; */
  MultiplicationTable(5);;
}
