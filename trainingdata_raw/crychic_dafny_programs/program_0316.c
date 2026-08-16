// Generated C + ACSL

/*@
    requires str1 != \null;
    requires str2 != \null;
    requires str1_len >= 0;
    requires str2_len >= 0;
    requires \valid_read(str1 + (0 .. str1_len-1));
    requires \valid_read(str2 + (0 .. str2_len-1));
    assigns \nothing;
    ensures \result == \null;
*/
int* LongestCommonPrefix(int* str1, int str1_len, int* str2, int str2_len)
{
  int* prefix = (int*)0;
  int minLength = ((str1_len < str2_len)) ? (str1_len) : (str2_len);
  /*@ assert prefix == \null; */
  /*@ assert minLength == (str1_len < str2_len ? str1_len : str2_len); */
  /*@ assert minLength <= str1_len && minLength <= str2_len; */
  {
    int idx = 0;
/*@
  loop invariant 0 <= idx <= minLength + 1;
  loop invariant minLength <= str1_len;
  loop invariant minLength <= str2_len;
  loop invariant prefix == \null;
  loop invariant \forall integer k; 0 <= k < idx && idx <= minLength ==> str1[k] == str2[k];
  loop invariant \valid_read(str1 + (0 .. str1_len-1));
  loop invariant \valid_read(str2 + (0 .. str2_len-1));
  loop assigns idx;
  loop variant minLength + 1 - idx;
*/
    while ((idx <= minLength))
      {
        if ((str1[idx] != str2[idx]))
        {
          /*@ assert prefix == \null; */
          return prefix;
        }
        idx = (idx + 1);
      }
  }
  /*@ assert prefix == \null; */
  return prefix;
}