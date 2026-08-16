// Generated C + ACSL

/*@
    requires pairs != \null;
    requires pairs_len >= 0;
    requires \valid_read(pairs + (0 .. pairs_len-1));
    assigns \nothing;
*/
void PrintEnumeratedPairs(int* pairs, int pairs_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= pairs_len;
  loop invariant \at(pairs_len, LoopEntry) == pairs_len;
  loop assigns i;
  loop variant pairs_len - i;
*/
  while ((i < pairs_len))
    {
      /* unsupported stmt: print "a : ", i, "\n"; */
      /* unsupported stmt: print "b : [", pairs[i].first, ", ", pairs[i].second, "]\n"; */
      i = (i + 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int trainingBatch = 0;
  PrintEnumeratedPairs(&trainingBatch, 1);;
}