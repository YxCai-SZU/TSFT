// Generated C + ACSL

/*@
    requires s != \null;
    requires s_len > 0;
    requires \valid_read(s + (0 .. s_len-1));
    assigns \nothing;
    ensures 0 <= \result < s_len;
    ensures \forall integer i; 0 <= i < s_len ==> s[i] <= s[\result];
*/
int findMax(int* s, int s_len)
{
  /*@ assert (s_len > 0); */
  int lo = 0;
  /*@ assert lo >= 0 && lo <= 2147483647; */
  /*@ assert 0 <= lo < s_len &&
             (\forall integer k; 0 <= k < 1 ==> s[k] <= s[lo]); */
  int hi = (s_len - 1);
  /*@ assert (0 <= hi < s_len); */
  /*@ assert ((hi - lo) >= 0); */
/*@
  loop invariant 0 <= lo <= hi < s_len;
  loop invariant \at(lo, LoopEntry) <= lo;
  loop invariant hi <= \at(hi, LoopEntry);
  loop invariant (\forall integer k; 0 <= k < lo ==> s[k] <= s[lo] || s[k] <= s[hi]) ||
                 (\forall integer k; 0 <= k < lo ==> s[k] <= s[\at(lo, LoopEntry)] || s[k] <= s[\at(hi, LoopEntry)]);
  loop invariant (\forall integer k; hi < k < s_len ==> s[k] <= s[lo] || s[k] <= s[hi]) ||
                 (\forall integer k; hi < k < s_len ==> s[k] <= s[\at(lo, LoopEntry)] || s[k] <= s[\at(hi, LoopEntry)]);
  loop invariant (\forall integer k; 0 <= k < lo ==> s[k] <= s[lo]) &&
                 (\forall integer k; hi < k < s_len ==> s[k] <= s[lo]) ||
                 (\forall integer k; 0 <= k < lo ==> s[k] <= s[hi]) &&
                 (\forall integer k; hi < k < s_len ==> s[k] <= s[hi]);
  loop assigns lo, hi;
  loop variant hi - lo;
*/
  while ((lo < hi))
    {
      if ((s[lo] <= s[hi]))
      {
        lo = (lo + 1);
      }
      else
      {
        hi = (hi - 1);
      }
    }
  return lo;
}

/*@
  predicate isMax2(int *s, integer len, integer lo, integer hi, integer max) =
    0 <= max && max < len &&
    0 <= lo && lo <= hi && hi < len &&
    \forall integer x; lo <= x && x <= hi ==> s[max] >= s[x];
*/

/*@
  predicate isMax(int *s, integer len, integer lo) =
    0 <= lo && lo < len &&
    \forall integer x; 0 <= x && x < len ==> s[lo] >= s[x];
*/