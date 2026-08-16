// Generated C + ACSL

/*@
  predicate member(integer n, int *s, integer len) =
    \exists integer i; 0 <= i && i < len && s[i] == n;
*/

/*@
  predicate notmember(integer n, int *s, integer len) =
    \forall integer i; 0 <= i && i < len ==> s[i] != n;
*/

/*@
    requires s_len >= 0;
    requires s_len > 0 ==> s != \null;
    requires s_len > 0 ==> \valid_read(s + (0 .. s_len-1));
    assigns \nothing;
    ensures \result == 1 ==> \exists integer i; 0 <= i < s_len && s[i] == m;
    ensures \result == 0 ==> \forall integer i; 0 <= i < s_len ==> s[i] != m;
*/
int isMember(int m, int* s, int s_len)
{
  int ismember = 0;
  /*@ assert ismember >= 0 && ismember <= 2147483647; */
  int i = 0;
  //@ assert \forall integer k; 0 <= k < i ==> s[k] != m;
/*@
  loop invariant 0 <= i <= s_len;
  loop invariant \forall integer k; 0 <= k < i ==> s[k] != m;
  loop invariant ismember ==> i < s_len;
  loop invariant ismember ==> \exists integer k; 0 <= k <= i && s[k] == m;
  loop invariant !ismember ==> \forall integer k; 0 <= k < i ==> s[k] != m;
  loop assigns i, ismember;
  loop variant s_len - i + (ismember ? 0 : 1);
*/
  while (((i < s_len) && !(ismember)))
    {
      /*@ assert \forall integer k; 0 <= k < i ==> s[k] != m; */
      /*@ assert ((i < s_len) && !(ismember)); */
      //@ assert s[i] == m ==> (\forall integer k; 0 <= k < i ==> s[k] != m);
      //@ assert s[i] != m ==> (\forall integer j; 0 <= j <= i ==> s[j] != m);
      //@ assert s[i] == m ==> \exists integer k; 0 <= k <= i && s[k] == m;
      if ((s[i] == m))
      {
        //@ assert \exists integer k; 0 <= k <= i && s[k] == m;
        //@ assert \true ==> (\exists integer k; 0 <= k <= i && s[k] == m);
        //@ assert \forall integer k; 0 <= k < i ==> s[k] != m;
        ismember = 1;
        //@ assert ismember ==> \exists integer k; 0 <= k <= i && s[k] == m;
        //@ assert \forall integer k; 0 <= k < i ==> s[k] != m;
      }
      else
      {
        //@ assert ismember ==> (\exists integer k; 0 <= k < i && s[k] == m);
        //@ assert \forall integer k; 0 <= k <= i ==> notmember(m, s, k);
        i = (i + 1);
        //@ assert ismember ==> \exists integer k; 0 <= k < i && s[k] == m;
        /*@ assert \forall integer k; 0 <= k < i ==> s[k] != m; */
      }
      //@ assert ismember ==> \exists integer k; 0 <= k <= i && s[k] == m;
      //@ assert \forall integer j; 0 <= j < i ==> s[j] != m;
    }
  //@ assert !member(m, s, i) && !(i < s_len && !ismember);
  //@ assert ismember ==> member(m, s, i + 1) && !(i < s_len && !ismember);
  return ismember;
}