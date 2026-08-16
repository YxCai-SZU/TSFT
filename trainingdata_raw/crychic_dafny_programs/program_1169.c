// Generated C + ACSL

/*@
    requires n > 0;
    assigns \nothing;
*/
void FizzBuzz(int n)
{
  int i = 1;
/*@
  loop invariant 1 <= i <= n;
  loop assigns i;
  loop variant n - i;
*/
  while ((i < n))
    {
      if ((((i % 3) == 0) && ((i % 5) != 0)))
      {
        /* unsupported stmt: print "Fizz\n"; */
      }
      else
      if ((((i % 3) != 0) && ((i % 5) == 0)))
      {
        /* unsupported stmt: print "Buzz\n"; */
      }
      else
      if ((((i % 3) == 0) && ((i % 5) == 0)))
      {
        /* unsupported stmt: print "FizzBuzz\n"; */
      }
      else
      {
        /* unsupported stmt: print i, "\n"; */
      }
      i = (i + 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  FizzBuzz(101);;
}
