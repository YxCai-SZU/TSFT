// Generated C + ACSL

/*@ axiomatic MaxDef {
      logic boolean isMax_ax(int* s, integer len, integer idx);
      axiom isMax_def:
        \forall int* s, integer len, integer idx;
          isMax_ax(s, len, idx) <==>
            (0 <= idx < len &&
             \forall integer i; 0 <= i < len ==> s[i] <= s[idx]);
    }
*/

/*@
  predicate isMax(int *s, integer len, integer lo) =
    0 <= lo && lo < len &&
    \forall integer x; 0 <= x && x < len ==> s[lo] >= s[x];
*/

/*@
  predicate isMax2(int *s, integer len, integer lo, integer hi, integer max) =
    0 <= max && max < len && 0 <= lo && lo <= hi && hi < len &&
    \forall integer x; lo <= x && x <= hi ==> s[max] >= s[x];
*/

/*@
  requires s_len > 0;
  requires \valid(s + (0 .. s_len - 1));
  assigns \nothing;
  ensures 0 <= \result < s_len;
  ensures \forall integer i; 0 <= i < s_len ==> s[i] <= s[\result];
*/
int findMax(int* s, int s_len)
{
  /*@ assert (s_len > 0); */
  int lo = 0;
  /*@ assert lo >= 0 && lo <= 2147483647; */
  int hi = (s_len - 1);
  /*@ assert (0 <= hi < s_len); */
  /*@ assert ((hi - lo) >= 0); */
/*@
  loop invariant 0 <= lo <= hi < s_len;
  loop invariant \at(lo, LoopEntry) <= lo;
  loop invariant hi <= \at(hi, LoopEntry);
  loop invariant \forall integer k; 0 <= k < lo ==> s[k] <= s[lo] || s[k] <= s[hi];
  loop invariant \forall integer k; hi < k < s_len ==> s[k] <= s[lo] || s[k] <= s[hi];
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