// Generated C + ACSL

/*@
    requires s != \null;
    requires s_len >= 0;
    requires \valid_read(s + (0 .. s_len-1));
    assigns \nothing;
    ensures \result == 1 ==>
        \forall integer i, j;
            0 <= i < s_len && 0 <= j < s_len ==> s[i] == s[j];
    ensures \result == 0 ==>
        s_len > 1 &&
        \exists integer i, j;
            0 <= i < s_len && 0 <= j < s_len && i != j && s[i] != s[j];
*/
int AllCharactersSame(char* s, int s_len)
{
  if ((s_len <= 1))
  {
    return 1;
  }
  int firstChar = s[0];
  int result = 1;
  /*@ assert s_len > 1; */
  /*@ assert firstChar == s[0]; */
  {
    int i = 1;
/*@
  loop invariant 1 <= i <= s_len;
  loop invariant firstChar == s[0];
  loop invariant result == 0 || result == 1;
  loop invariant result == 0 ==> \exists integer k; 1 <= k < i && s[k] != firstChar;
  loop invariant result == 1 ==> \forall integer k; 1 <= k < i ==> s[k] == firstChar;
  loop invariant result == 1 ==> \forall integer k; 0 <= k < i ==> s[k] == firstChar;
  loop assigns i, result;
  loop variant s_len - i;
*/
    while ((i < s_len))
      {
        /*@ assert 1 <= i < s_len; */
        /*@ assert \valid_read(&s[i]); */
        if ((s[i] != firstChar))
        {
          result = 0;
          /*@ assert s[i] != s[0]; */
          /*@ assert s[i] != firstChar; */
          /*@ assert 0 <= 0 < s_len && 0 <= i < s_len && 0 != i && s[0] != s[i]; */
          break;;
        }
        /*@ assert s[i] == firstChar; */
        i = (i + 1);
      }
  }
  /*@ assert result == 0 || result == 1; */
  /*@ assert result == 1 ==> \forall integer k; 0 <= k < s_len ==> s[k] == s[0]; */
  /*@ assert result == 1 ==> \forall integer k, j; 0 <= k < s_len && 0 <= j < s_len ==> s[k] == s[j]; */
  /*@ assert result == 0 ==> \exists integer k; 0 <= k < s_len && k != 0 && s[k] != s[0]; */
  return result;  // Dafny implicit return
}