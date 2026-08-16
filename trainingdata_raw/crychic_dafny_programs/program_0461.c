// Generated C + ACSL

/*@
    requires i >= 0;
    assigns \nothing;
*/
void FizzBuzz(int i)
{
  if (((i % 15) == 0))
  {
    /* unsupported stmt: print "FizzBuzz\n"; */
  }
  else
  if (((i % 3) == 0))
  {
    /* unsupported stmt: print "Fizz\n"; */
  }
  else
  if (((i % 5) == 0))
  {
    /* unsupported stmt: print "Buzz\n"; */
  }
  else
  {
    /* unsupported stmt: print i, "\n"; */
  }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= 100;
  loop assigns i;
  loop variant 100 - i;
*/
  while ((i < 100))
    {
      i = (i + 1);
      //@ assert 1 <= i <= 100;
      FizzBuzz(i);;
    }
  //@ assert i == 100;
}