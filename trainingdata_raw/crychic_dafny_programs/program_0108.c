// Generated C + ACSL

/*@
    requires s != \null;
    requires s_len >= 0;
    requires \valid(s + (0 .. s_len-1));
    assigns s[0 .. s_len-1];
*/
void AbsIt(int* s, int s_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= s_len;
  loop invariant \forall integer k; 0 <= k < i ==>
                   (\at(s[k], LoopEntry) < 0 ==> s[k] == -\at(s[k], LoopEntry));
  loop invariant \forall integer k; 0 <= k < i ==>
                   (\at(s[k], LoopEntry) >= 0 ==> s[k] == \at(s[k], LoopEntry));
  loop invariant \forall integer k; i <= k < s_len ==>
                   s[k] == \at(s[k], LoopEntry);
  loop assigns i, s[0..s_len-1];
  loop variant s_len - i;
*/
  while ((i < s_len))
    {
      if ((s[i] < 0))
      {
        s[i] = -s[i];
      }
      i = (i + 1);
    }
}
