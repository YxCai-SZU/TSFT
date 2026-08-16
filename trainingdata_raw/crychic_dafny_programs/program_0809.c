// Generated C + ACSL

/*@
    assigns \nothing;
*/
void PrintMultiplicationTable(void)
{
  int i = 1;
  int j = 1;
/*@
  loop invariant 1 <= i <= 10;
  loop assigns i, j;
  loop variant 10 - i;
*/
  while ((i <= 9))
    {
      j = 1;
/*@
  loop invariant 1 <= j <= 10;
  loop invariant i == \at(i, LoopEntry);
  loop assigns j;
  loop variant 10 - j;
*/
      while ((j <= 9))
        {
          /* unsupported stmt: print i, "*", j, "=", i * j, "\n"; */
          j = (j + 1);
        }
      i = (i + 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  PrintMultiplicationTable();;
}
