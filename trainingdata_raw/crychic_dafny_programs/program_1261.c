// Generated C + ACSL

/*@
  predicate isMax(int *s, integer len, integer lo) =
    0 <= lo && lo < len &&
    \forall integer i; 0 <= i && i < len ==> s[i] <= s[lo];
*/

/*@
    requires s_len >= 0;
    requires s_len == 0 || (\valid(s + (0 .. s_len-1)) && s != \null);
    assigns \nothing;
*/
void findMax(int* s, int s_len)
{
  if (s_len == 0) return;
  
  int lo = 0;
  /*@ assert lo >= 0 && lo <= 2147483647; */
  int hi = (s_len - 1);
  /*@ assert hi >= 0 && hi <= 2147483647; */
/*@
  loop invariant 0 <= lo;
  loop invariant hi < s_len;
  loop invariant lo <= hi + 1;
  loop invariant \at(lo, LoopEntry) <= lo;
  loop invariant hi <= \at(hi, LoopEntry);
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
}

/*@
  predicate isPal(int *s, integer Length) =
    \forall integer i; 0 <= i && i < Length ==> s[i] == s[Length - i - 1];
*/

/*@
    requires s_len >= 0;
    requires s_len == 0 || (s != \null && \valid(s + (0 .. s_len-1)));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> (\forall integer k; 0 <= k < s_len ==> s[k] == s[s_len - 1 - k]);
    ensures \result == 0 ==> (\exists integer k; 0 <= k < s_len && s[k] != s[s_len - 1 - k]);
*/
int checkPalindrome(int* s, int s_len)
{
  int res = 1;
  /*@ assert res >= 0 && res <= 2147483647; */
  int i = 0;
  int j = (s_len - 1);
/*@
  loop invariant 0 <= i <= s_len;
  loop invariant -1 <= j < s_len;
  loop invariant i + j == s_len - 1;
  loop invariant res == 0 || res == 1;
  loop invariant res == 1 ==> \forall integer k; 0 <= k < i ==> s[k] == s[s_len - 1 - k];
  loop invariant res == 0 ==> \exists integer k; 0 <= k < i && s[k] != s[s_len - 1 - k];
  loop invariant s_len > 0 ==> \valid_read(s + (0 .. s_len - 1));
  loop invariant i <= j + 1;
  loop assigns i, j, res;
  loop variant j - i;
*/
  while (((i < j) && (res == 1)))
    {
      if ((s[i] != s[j]))
      {
        res = 0;
        /*@ assert s[i] != s[j]; */
        /*@ assert s[i] != s[s_len - 1 - i]; */
      }
      else
      {
        /*@ assert s[i] == s[j]; */
      }
      i = (i + 1);
      j = (j - 1);
    }
  /*@ assert res == 0 ==> \exists integer k; 0 <= k < s_len && s[k] != s[s_len - 1 - k]; */
  /*@ assert res == 1 ==> \forall integer k; 0 <= k < s_len ==> s[k] == s[s_len - 1 - k]; */
  return res;
}