// Generated C + ACSL

/*@
    requires s != \null;
    requires 1 <= s_len <= 200000;
    requires \valid_read(s + (0 .. s_len-1));
    assigns \nothing;
    ensures \result == 1 <==>
        (\forall integer i; 0 <= i < s_len / 2 ==> s[i] == s[s_len - 1 - i]);
    ensures \result == 0 || \result == 1;
*/
int isPalindrome(int* s, int s_len)
{
  int length = s_len;
  int i = 0;
/*@
  loop invariant 0 <= i <= length / 2;
  loop invariant \forall integer j; 0 <= j < i ==> s[j] == s[length - 1 - j];
  loop assigns i;
  loop variant (length / 2) - i;
*/
  while ((i < (length / 2)))
    {
      if ((s[i] != s[((length - 1) - i)]))
      {
        return 0;
      }
      i = (i + 1);
    }
  return 1;
}
