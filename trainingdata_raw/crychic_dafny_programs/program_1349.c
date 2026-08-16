// Generated C + ACSL

/*@
    requires pre != \null;
    requires str != \null;
    requires pre_len > 0;
    requires str_len > 0;
    requires str_len >= pre_len;
    requires \valid_read(pre + (0 .. pre_len-1));
    requires \valid_read(str + (0 .. str_len-1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 <==> (\forall integer k; 0 <= k < pre_len ==> str[k] == pre[k]);
*/
int isPrefix(char* pre, int pre_len, char* str, int str_len)
{
  int i = 0;
  int count = 0;
/*@
  loop invariant 0 <= i <= pre_len;
  loop invariant 0 <= count <= i;
  loop invariant count == i <==> (\forall integer k; 0 <= k < i ==> str[k] == pre[k]);
  loop invariant count < i ==> (\exists integer k; 0 <= k < i && str[k] != pre[k]);
  loop assigns i, count;
  loop variant pre_len - i;
*/
  while ((i < pre_len))
    {
      if ((str[i] == pre[i]))
      {
        count = (count + 1);
      }
      i = (i + 1);
    }
  int res = 0;
  /*@ assert res >= 0 && res <= 2147483647; */
  if ((count == pre_len))
  {
    res = 1;
  }
  return res;  // Dafny implicit return
}