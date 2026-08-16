// Generated C + ACSL

/*@
  predicate upperbound(int *s, integer len, integer max) =
    \forall integer i; 0 <= i && i < len ==> s[i] <= max;
*/

/*@
  predicate member(int *s, integer len, integer n) =
    \exists integer i; 0 <= i && i < len && s[i] == n;
*/

/*@
    requires s != \null;
    requires s_len > 0;
    requires \valid_read(s + (0 .. s_len-1));
    assigns \nothing;
    ensures \exists integer k; 0 <= k < s_len && \result == s[k];
    ensures \forall integer j; 0 <= j < s_len ==> s[j] <= \result;
*/
int Max1(int* s, int s_len)
{
  /*@ assert (s_len > 0); */
  //@ assert 0 < 1 <= s_len && member(s, 1, s[0]);
  int max = s[0];
  //@ assert \exists integer k; 0 <= k < 1 && s[k] == max;
  //@ assert 0 < 1 <= s_len && (\exists integer i; 0 <= i < 1 && s[i] == max);
  int i = 1;
  //@ assert 0 < i <= s_len && (\exists integer k; 0 <= k < i && s[k] == max);
/*@
  loop invariant 0 < i <= s_len;
  loop invariant \exists integer k; 0 <= k < i && s[k] == max;
  loop invariant \forall integer k; 0 <= k < i ==> s[k] <= max;
  loop invariant max == \at(max, LoopEntry) || (\exists integer k; \at(i, LoopEntry) <= k < i && s[k] == max);
  loop assigns i, max;
  loop variant s_len - i;
*/
  while ((i != s_len))
    {
      //@ assert 0 < i <= s_len && (\exists integer k; 0 <= k < i && s[k] == max) && i != s_len;
      //@ assert s[i] > max ==> 0 < i + 1 <= s_len && (\exists integer k; 0 <= k < i + 1 && s[k] == s[i]);
      if ((s[i] > max))
      {
        //@ assert 0 < i + 1 <= s_len && (\exists integer k; 0 <= k < i + 1 && s[k] == s[i]);
        max = s[i];
        //@ assert 0 < i + 1 <= s_len && (\exists integer k; 0 <= k < i + 1 && s[k] == max);
      }
      //@ assert 0 < i + 1 <= s_len && (\exists integer k; 0 <= k < i + 1 && s[k] == max);
      i = (i + 1);
      //@ assert 0 < i <= s_len && (\exists integer k; 0 <= k < i && s[k] == max);
    }
  //@ assert member(s, i, max) && i <= s_len && i == s_len;
  /*@ assert member(s, s_len, max); */
  return max;
}

/*@
    requires s_len > 0;
    requires s != \null;
    requires \valid_read(s + (0 .. s_len-1));
    assigns \nothing;
    ensures 0 <= \result < s_len;
    ensures \forall integer i; 0 <= i < s_len ==> s[i] <= s[\result];
*/
int MaxInd(int* s, int s_len)
{
  int maxind = 0;
  /*@ assert maxind >= 0 && maxind <= 2147483647; */
  int i = 1;
/*@
  loop invariant 0 < i <= s_len;
  loop invariant 0 <= maxind < s_len;
  loop invariant \at(maxind, LoopEntry) < s_len;
  loop invariant \forall integer k; 0 <= k < i ==> s[k] <= s[maxind];
  loop invariant \forall integer k; 0 <= k < \at(i, LoopEntry) ==> s[k] <= s[\at(maxind, LoopEntry)] || maxind != \at(maxind, LoopEntry);
  loop assigns i, maxind;
  loop variant s_len - i;
*/
  while ((i < s_len))
    {
      if ((s[i] > s[maxind]))
      {
        maxind = i;
      }
      i = (i + 1);
    }
  return maxind;
}