// Generated C + ACSL

/*@
    requires a_len >= 0;
    requires a_len > 0 ==> a != \null;
    requires a_len > 0 ==> \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result <= a_len;
    ensures \result < a_len ==> a[\result] == e;
    ensures \result == a_len ==> (\forall integer i; 0 <= i < a_len ==> a[i] != e);
*/
int LinearSearch(int* a, int a_len, int e)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant \forall integer j; 0 <= j < i ==> a[j] != e;
  loop assigns i;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((a[i] == e))
      {
        return i;
      }
      i = (i + 1);
    }
  return a_len;
}
