// Generated C + ACSL

/*@
    requires s != \null;
    requires s_len >= 0;
    requires \valid_read(s + (0 .. s_len-1));
    assigns \nothing;
*/
void FindFirstRepeatedChar(char* s, int s_len)
{
  int c = ' ';
  /*@ assert c >= 0 && c <= 2147483647; */
  int found = 0;
  /*@ assert found >= 0 && found <= 2147483647; */
  int inner_found = 0;
  int i = 0;
/*@
  loop invariant 0 <= i <= s_len;
  loop invariant found == 0 || found == 1;
  loop invariant found == inner_found;
  loop invariant found == 1 ==>
    (\exists integer ii, jj; 0 <= ii < i && ii < jj < s_len &&
     s[ii] == s[jj] && s[ii] == c &&
     (\forall integer k, l; 0 <= k < l < jj && s[k] == s[l] ==> k >= ii));
  loop invariant found == 0 ==>
    (\forall integer ii, jj; 0 <= ii < i && ii < jj < s_len ==> s[ii] != s[jj]);
  loop invariant found == 0 ==> c == \at(c, LoopEntry);
  loop invariant \valid_read(s + (0..s_len-1));
  loop assigns i, found, inner_found, c;
  loop variant s_len - i;
*/
  while (((i < s_len) && !(found)))
    {
      int j = (i + 1);
/*@
  loop invariant i < j <= s_len;
  loop invariant inner_found == 0 || inner_found == 1;
  loop invariant inner_found == 1 ==>
    (\exists integer k; i < k < j && s[i] == s[k] && s[i] == c);
  loop invariant inner_found == 0 ==>
    (\forall integer k; i < k < j ==> s[i] != s[k]);
  loop invariant inner_found == 0 ==> c == \at(c, LoopEntry);
  loop invariant inner_found == 1 ==> c == s[i];
  loop assigns j, inner_found, c;
  loop variant s_len - j;
*/
      while (((j < s_len) && !(inner_found)))
        {
          if ((s[i] == s[j]))
          {
            inner_found = 1;
            c = s[i];
          }
          j = (j + 1);
        }
      found = inner_found;
      i = (i + 1);
    }
}