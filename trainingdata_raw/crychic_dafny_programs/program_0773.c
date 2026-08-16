// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
*/
void PrintStopItOrLoopFailed(void)
{
  int i = 0;
  int loopCompleted = 0;
/*@
  loop invariant 0 <= i <= 20;
  loop invariant loopCompleted == \at(loopCompleted, LoopEntry);
  loop invariant loopCompleted == \false;
  loop assigns i;
  loop variant 20 - i;
*/
  while ((i < 20))
    {
      if (((i % 20) == 0))
      {
        /* unsupported stmt: print "Stop It\n"; */
      }
      i = (i + 1);
    }
  loopCompleted = 1;
  if (!(loopCompleted))
  {
    /* unsupported stmt: print "The For Loop Failed\n"; */
  }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  PrintStopItOrLoopFailed();;
}
