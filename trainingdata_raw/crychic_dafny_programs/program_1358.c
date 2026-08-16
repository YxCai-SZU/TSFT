// Generated C + ACSL

/*@
    assigns \nothing;
*/
void GetNext(int i)
{
  int possible;
  int j;

  if (i == 1)
  {
    possible = 0;
    /*@ assert possible >= 0 && possible <= 2147483647; */
    j = 0;
    /*@ assert j >= 0 && j <= 2147483647; */
  }
  else
  {
    possible = 1;
    j = (((i % 2) == 0)) ? ((i / 2)) : (((i * 3) + 1));
  }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int i = 10;
  int k = 27;
  int newK;
  int possible;
/*@
  loop invariant i >= 0;
  loop invariant i <= \at(i, LoopEntry);
  loop assigns i, k, newK, possible;
  loop variant i;
*/
  while ((i > 0))
    {
      if (!(possible))
      {
        break;
      }
      k = newK;
      /* unsupported stmt: print k; */
      i = (i - 1);
    }
}