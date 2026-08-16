// Generated C + ACSL

/*@
  predicate member(int *s, integer len, integer n) =
    \exists integer i; 0 <= i && i < len && s[i] == n;
*/

/*@
    requires s != \null;
    requires s_len >= 0;
    requires \valid_read(s + (0 .. s_len-1));
    assigns \nothing;
*/
void linsearch(int* s, int s_len, int n)
{
  int ind = 0;
  /*@ assert ind >= 0 && ind <= 2147483647; */
  int found = 0;
  /*@ assert found >= 0 && found <= 2147483647; */
/*@
  loop invariant 0 <= ind <= s_len;
  loop invariant \forall integer k; 0 <= k < ind ==> s[k] != n;
  loop invariant found == 1 ==> \exists integer k; 0 <= k < s_len && s[k] == n;
  loop invariant found == 0 || found == 1;
  loop invariant found == 1 ==> ind < s_len && s[ind] == n;
  loop assigns ind, found;
  loop variant s_len - ind + (found == 0 ? 1 : 0);
*/
  while (((ind < s_len) && !(found)))
    {
      if ((s[ind] == n))
      {
        found = 1;
      }
      else
      {
        ind = (ind + 1);
      }
    }
}

/*@
    requires s != \null;
    requires s_len >= 0;
    requires \valid_read(s + (0 .. s_len-1));
    assigns \nothing;
*/
void linsearchInd(int* s, int s_len, int n)
{
  int ind = 0;
  /*@ assert ind >= 0 && ind <= 2147483647; */
  int found = 0;
  /*@ assert found >= 0 && found <= 2147483647; */
/*@
  loop invariant 0 <= ind <= s_len;
  loop invariant \forall integer k; 0 <= k < ind ==> s[k] != n;
  loop invariant found == 1 ==> \exists integer k; 0 <= k < s_len && s[k] == n;
  loop invariant found == 0 || found == 1;
  loop invariant found == 1 ==> ind < s_len && s[ind] == n;
  loop assigns ind, found;
  loop variant s_len - ind + (found == 0 ? 1 : 0);
*/
  while (((ind < s_len) && !(found)))
    {
      if ((s[ind] == n))
      {
        found = 1;
      }
      else
      {
        ind = (ind + 1);
      }
    }
}
