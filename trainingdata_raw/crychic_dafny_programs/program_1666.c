// Generated C + ACSL

/*@
    requires start <= end;
    assigns \nothing;
*/
void PrintNumbersInRange(int start, int end)
{
  int n = start;
/*@
  loop invariant start <= n <= end;
  loop invariant \at(start, LoopEntry) <= n <= \at(end, LoopEntry);
  loop assigns n;
  loop variant end - n;
*/
  while ((n < end))
    {
      if (((n % 2) == 0))
      {
        /* unsupported stmt: print "found an even number ", n, "\n"; */
      }
      else
      {
        /* unsupported stmt: print "found a number ", n, "\n"; */
      }
      n = (n + 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  PrintNumbersInRange(2, 10);;
}
