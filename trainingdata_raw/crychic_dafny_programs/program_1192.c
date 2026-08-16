// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
*/
void NestedLoops(void)
{
  int i = 1;
/*@
  loop invariant 1 <= i <= 4;
  loop assigns i;
  loop variant 4 - i;
*/
  while ((i <= 3))
    {
      /* unsupported stmt: print "yao is a good man ", i, "\n"; */
      int j = 1;
/*@
  loop invariant 1 <= j <= 4;
  loop invariant \at(i, LoopEntry) == i;
  loop assigns j;
  loop variant 4 - j;
*/
      while ((j <= 3))
        {
          /* unsupported stmt: print "yao is a nice man ", i, " ", j, "\n"; */
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
  NestedLoops();;
}
