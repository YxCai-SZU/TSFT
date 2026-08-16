// Generated C + ACSL

/*@
    assigns \nothing;
*/
void Main(void)
{
  int s_len = 10;
  int s[10] = {0};
  int i = 0;
  int j = 0;
/*@
  loop invariant 0 <= i <= j;
  loop invariant j < s_len;
  loop invariant j == \at(j, LoopEntry) + 2 * (i - \at(i, LoopEntry));
  loop invariant i == \at(i, LoopEntry) + (j - \at(j, LoopEntry)) / 2;
  loop assigns i, j;
  loop variant s_len - j - 1;
*/
  while (((j + 2) < s_len))
    {
      j = (j + 2);
      i = (i + 1);
    }
  /*@ assert 0 <= i <= j < s_len; */
  int returnVal = s[i];
  /* unsupported stmt: print returnVal; */
}