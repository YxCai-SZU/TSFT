// Generated C + ACSL

/*@
    assigns \nothing;
*/
void CountDown(void)
{
  int i = 100;
/*@
  loop invariant -1 <= i <= \at(i, LoopEntry);
  loop assigns i;
  loop variant i + 1;
*/
  while ((i >= 0))
    {
      /* unsupported stmt: print i, "\n"; */
      i = (i - 1);
    }
  /* unsupported stmt: print i, "\n"; */
}

/*@
    requires \true;
    assigns \nothing;
*/
void Main(void)
{
  CountDown();;
}
