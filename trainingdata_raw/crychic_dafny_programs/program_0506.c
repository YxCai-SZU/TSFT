// Generated C + ACSL

/*@
    requires s_len >= 0;
    requires s_len == 0 || (s != \null && \valid_read(s + (0 .. s_len-1)));
    assigns \nothing;
    ensures \result == 1 <==>
        (\forall integer k; 0 <= k < s_len ==> s[k] == s[s_len - k - 1]);
    ensures \result == 0 || \result == 1;
*/
int checkPalindrome(int* s, int s_len)
{
  int res = 1;
  /*@ assert res >= 0 && res <= 2147483647; */
  int i = 0;
  int j = (s_len - 1);
  /*@ assert i == 0 && j == s_len - 1; */
  /*@ assert i + j == s_len - 1; */
/*@
  loop invariant i + j == s_len - 1;
  loop invariant 0 <= i <= s_len;
  loop invariant -1 <= j < s_len;
  loop invariant i <= j + 1;
  loop invariant res == 0 || res == 1;
  loop invariant (res == 1) ==> (\forall integer k; 0 <= k < i ==> s[k] == s[s_len - k - 1]);
  loop invariant (res == 0) ==> (\exists integer k; 0 <= k < i && s[k] != s[s_len - k - 1]);
  loop invariant i > 0 ==> (res == 1 ==> s[i-1] == s[j+1]);
  loop invariant i > 0 ==> (res == 0 ==> s[i-1] != s[j+1]);
  loop invariant \forall integer k; 0 <= k < i ==> 0 <= s_len - k - 1 < s_len;
  loop assigns i, j, res;
  loop variant j - i + 1;
*/
  while (((i < j) && (res == 1)))
    {
      /*@ assert 0 <= i < s_len && 0 <= j < s_len; */
      /*@ assert i < j; */
      /*@ assert res == 1; */
      /*@ assert \forall integer k; 0 <= k < i ==> s[k] == s[s_len - k - 1]; */
      
      if ((s[i] != s[j]))
      {
        res = 0;
        /*@ assert s[i] != s[j]; */
        /*@ assert s[i] != s[s_len - i - 1]; */
      }
      else
      {
        /*@ assert s[i] == s[j]; */
        /*@ assert s[i] == s[s_len - i - 1]; */
      }
      
      /*@ assert (res == 1) ==> s[i] == s[j]; */
      /*@ assert (res == 0) ==> s[i] != s[j]; */
      /*@ assert (res == 1) ==> (\forall integer k; 0 <= k <= i ==> s[k] == s[s_len - k - 1]); */
      
      i = (i + 1);
      j = (j - 1);
      
      /*@ assert i + j == s_len - 1; */
    }
  
  /*@ assert i >= j || res == 0; */
  /*@ assert (res == 1) ==> (\forall integer k; 0 <= k < i ==> s[k] == s[s_len - k - 1]); */
  /*@ assert (res == 1 && i >= j) ==> (\forall integer k; 0 <= k < s_len ==> s[k] == s[s_len - k - 1]); */
  
  return res;  // Dafny implicit return
}

/*@
  predicate palindrome(int *s1, integer len1, int *s2, integer len2) =
    len1 == len2 &&
    \forall integer x; 0 <= x && x < len1 ==> s1[x] == s2[len2 - x - 1];
*/

/*@
  predicate isPalindrome(int *s, integer len) =
    \forall integer x; 0 <= x && x < len ==> s[x] == s[len - x - 1];
*/