// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures (0 <= \result < a_len) ==> a[\result] == key;
    ensures (\result == -1) ==> (\forall integer z; 0 <= z < a_len ==> a[z] != key);
*/
int Find(int* a, int a_len, int key)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] != key;
  loop assigns i;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((a[i] == key))
      {
        return i;
      }
      i = (i + 1);
    }
  return -1;
}
