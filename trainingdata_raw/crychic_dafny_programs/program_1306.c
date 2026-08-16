// Generated C + ACSL

/*@
  predicate isMax(char *s, integer len, integer lo) =
    0 <= lo && lo < len &&
    \forall integer i; 0 <= i && i < len ==> s[i] <= s[lo];
*/

/*@
    requires s != \null;
    requires s_len > 0;
    requires \valid_read(s + (0 .. s_len-1));
    assigns \nothing;
    ensures 0 <= \result < s_len;
    ensures \forall integer i; 0 <= i < s_len ==> s[i] <= s[\result];
*/
int findMax(char* s, int s_len)
{
  int lo = 0;
  /*@ assert lo >= 0 && lo <= 2147483647; */
  int hi = (s_len - 1);
  /*@ assert hi >= 0 && hi <= 2147483647; */
  int max = ((s[lo] >= s[hi])) ? (lo) : (hi);
/*@
  loop invariant 0 <= lo <= hi && hi < s_len;
  loop invariant lo == max || hi == max;
  loop invariant \forall integer i; (0 <= i < lo || hi < i < s_len) ==> s[i] <= s[max];
  loop invariant 0 <= max < s_len;
  loop invariant max == \at(max, LoopEntry) || max == lo || max == hi;
  loop assigns lo, hi, max;
  loop variant hi - lo;
*/
  while ((lo < hi))
    {
      if ((s[lo] <= s[hi]))
      {
        lo = (lo + 1);
        max = hi;
        if ((s[lo] >= s[max]))
        {
          max = lo;
        }
      }
      else
      {
        hi = (hi - 1);
        max = lo;
        if ((s[hi] >= s[max]))
        {
          max = hi;
        }
      }
    }
  return lo;
}