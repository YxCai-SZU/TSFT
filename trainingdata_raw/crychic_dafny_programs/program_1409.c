// Generated C + ACSL

/*@
    requires chars != \null;
    requires chars_len >= 0;
    requires \valid_read(chars + (0 .. chars_len-1));
    assigns \nothing;
    ensures \result == 1 <==>
        (\forall integer x; 0 <= x < chars_len ==>
            chars[x] == chars[chars_len - (x + 1)]);
    ensures \result == 0 || \result == 1;
*/
int isPalindrome(int* chars, int chars_len)
{
  int i = 0;
  /*@ assert i >= 0 && i <= 2147483647; */
  int j = chars_len;
  /*@ assert j >= 0 && j <= 2147483647; */
/*@
  loop invariant i + j == \at(i, LoopEntry) + \at(j, LoopEntry);
  loop invariant 0 <= i <= \at(j, LoopEntry);
  loop invariant 0 <= j <= \at(j, LoopEntry);
  loop invariant i >= \at(i, LoopEntry);
  loop invariant j <= \at(j, LoopEntry);
  loop invariant \forall integer k; 0 <= k < i ==> chars[k] == chars[\at(i, LoopEntry) + \at(j, LoopEntry) - k - 1];
  loop assigns i, j;
  loop variant j - i;
*/
  while ((i < j))
    {
      j = (j - 1);
      if ((chars[i] != chars[j]))
      {
        return 0;
      }
      i = (i + 1);
    }
  return 1;
}
