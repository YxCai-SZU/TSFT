// Generated C + ACSL

/*@
    requires s != \null;
    requires p != \null;
    requires s_len == p_len;
    requires s_len >= 0;
    requires \valid_read(s + (0 .. s_len-1));
    requires \valid_read(p + (0 .. p_len-1));
    assigns \nothing;
    ensures \result == 1 <==>
        (\forall integer n; 0 <= n < s_len ==> s[n] == p[n] || p[n] == '?');
    ensures \result == 0 || \result == 1;
*/
int Match(char* s, int s_len, char* p, int p_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= s_len;
  loop invariant \forall integer n; 0 <= n < i ==> (s[n] == p[n] || p[n] == '?');
  loop assigns i;
  loop variant s_len - i;
*/
  while ((i < s_len))
    {
      if (((s[i] != p[i]) && (p[i] != '?')))
      {
        return 0;
      }
      i = (i + 1);
    }
  return 1;
}
