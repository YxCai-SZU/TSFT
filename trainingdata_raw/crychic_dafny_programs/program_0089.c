// Generated C + ACSL

/*@
    requires s != \null;
    requires s_len >= 0;
    requires \valid(s + (0 .. s_len-1));
    assigns s[0 .. s_len-1];
*/
void double_array_elements(int* s, int s_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= s_len;
  loop invariant \forall integer x; i <= x < s_len ==> s[x] == \at(s[x], LoopEntry);
  loop invariant \forall integer x; 0 <= x < i ==> s[x] == 2 * \at(s[x], LoopEntry);
  loop assigns i, s[0..s_len-1];
  loop variant s_len - i;
*/
  while ((i < s_len))
    {
      s[i] = (2 * s[i]);
      i = (i + 1);
    }
}
