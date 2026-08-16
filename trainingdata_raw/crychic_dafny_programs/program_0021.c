// Generated C + ACSL

/*@
    requires s != \null;
    requires s_len > 0;
    requires \valid_read(s + (0 .. s_len-1));
    requires \forall integer i; 0 <= i < s_len ==> s[i] != \null;
    assigns \nothing;
    ensures \exists integer k; 0 <= k < s_len && \result == s[k];
*/
int* MinLengthSublist(int** s, int s_len)
{
  int* minSublist = s[0];
  {
    int i = 1;
/*@
  loop invariant 1 <= i <= s_len;
  loop invariant \exists integer k; 0 <= k < i && minSublist == s[k];
  loop assigns i, minSublist;
  loop variant s_len - i;
*/
    while ((i < s_len))
      {
        if ((s[i] < minSublist))
        {
          minSublist = s[i];
        }
        i = (i + 1);
      }
  }
  return minSublist;
}