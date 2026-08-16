// Generated C + ACSL

/*@ logic integer isPrefix(char* pre, integer pre_len, char* str, integer str_len); */

/*@
    requires pre != \null;
    requires str != \null;
    requires pre_len > 0;
    requires str_len > 0;
    requires pre_len <= str_len;
    requires \valid_read(pre + (0 .. pre_len-1));
    requires \valid_read(str + (0 .. str_len-1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 <==> (\forall integer i; 0 <= i < pre_len ==> pre[i] == str[i]);
*/
int isPrefix(char* pre, int pre_len, char* str, int str_len)
{
  int i;
  /*@
    loop invariant 0 <= i <= pre_len;
    loop invariant \forall integer k; 0 <= k < i ==> pre[k] == str[k];
    loop assigns i;
    loop variant pre_len - i;
  */
  for (i = 0; i < pre_len; i++)
  {
    if (pre[i] != str[i])
    {
      //@ assert pre[i] != str[i];
      //@ assert \exists integer k; 0 <= k < pre_len && pre[k] != str[k];
      return 0;
    }
  }
  //@ assert i == pre_len;
  //@ assert \forall integer k; 0 <= k < pre_len ==> pre[k] == str[k];
  return 1;
}

/*@ logic integer isSubstring(char* sub, integer sub_len, char* str, integer str_len); */

/*@
    requires sub != \null;
    requires str != \null;
    requires sub_len <= str_len;
    requires 0 < sub_len;
    requires 0 < str_len;
    requires \valid_read(sub + (0 .. sub_len-1));
    requires \valid_read(str + (0 .. str_len-1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int isSubstring(char* sub, int sub_len, char* str, int str_len)
{
  int i = 0;
  int j = (str_len - sub_len);
  int temp;
/*@
  loop invariant 0 <= i <= j + 1;
  loop invariant i >= \at(i, LoopEntry);
  loop assigns i, temp;
  loop variant j - i + 1;
*/
  while ((i <= j))
    {
      temp = isPrefix(sub, sub_len, str + i, str_len - i);
      if (temp)
      {
        return 1;
      }
      else
      {
        i = (i + 1);
      }
    }
  return 0;
}

/*@ logic integer haveCommonKSubstring(integer k, char* str1, integer str1_len, char* str2, integer str2_len); */

/*@
    requires str1_len > 0;
    requires str2_len > 0;
    requires k > 0;
    requires k <= str1_len;
    requires k <= str2_len;
    requires str1 != \null;
    requires str2 != \null;
    requires \valid_read(str1 + (0 .. str1_len-1));
    requires \valid_read(str2 + (0 .. str2_len-1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int haveCommonKSubstring(int k, char* str1, int str1_len, char* str2, int str2_len)
{
  int i = 0;
  int endIndex = (str1_len - k);
  int temp;
/*@
  loop invariant 0 <= i <= endIndex;
  loop invariant \at(i, LoopEntry) <= i;
  loop assigns i, temp;
  loop variant endIndex - i;
*/
  while ((i < endIndex))
    {
      temp = isSubstring(str1 + i, k, str2, str2_len);
      if (temp)
      {
        return 1;
      }
      else
      {
        i = (i + 1);
      }
    }
  return 0;
}

/*@
    requires str1 != \null;
    requires str2 != \null;
    requires str1_len > 0;
    requires str2_len > 0;
    requires \valid_read(str1 + (0 .. str1_len-1));
    requires \valid_read(str2 + (0 .. str2_len-1));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= str1_len;
    ensures \result <= str2_len;
*/
int maxCommonSubstringLength(char* str1, int str1_len, char* str2, int str2_len)
{
  int commonSubstrLength = 0;
  int hasCommonSubstring = 0;
  int i = 1;
/*@
  loop invariant 0 <= i <= str1_len + 1;
  loop invariant 0 <= i <= str2_len + 1;
  loop invariant 0 <= commonSubstrLength < i;
  loop invariant commonSubstrLength <= str1_len;
  loop invariant commonSubstrLength <= str2_len;
  loop invariant \at(i, LoopEntry) <= i;
  loop assigns i, hasCommonSubstring, commonSubstrLength;
  loop variant (str1_len < str2_len ? str1_len - i + 1 : str2_len - i + 1);
*/
  while (((i <= str1_len) && (i <= str2_len)))
    {
      hasCommonSubstring = haveCommonKSubstring(i, str1, str1_len, str2, str2_len);
      if (hasCommonSubstring == 0)
      {
        //@ assert commonSubstrLength < i;
        //@ assert commonSubstrLength <= str1_len;
        //@ assert commonSubstrLength <= str2_len;
        return commonSubstrLength;
      }
      else
      {
        commonSubstrLength = i;
        //@ assert commonSubstrLength == i;
        //@ assert commonSubstrLength <= str1_len;
        //@ assert commonSubstrLength <= str2_len;
        i = (i + 1);
      }
    }
  //@ assert commonSubstrLength < i;
  //@ assert i > str1_len || i > str2_len;
  //@ assert commonSubstrLength <= str1_len;
  //@ assert commonSubstrLength <= str2_len;
  return commonSubstrLength;
}