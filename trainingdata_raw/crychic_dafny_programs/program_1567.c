// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures -1 <= \result < a_len;
    ensures \result != -1 ==> a[\result] == key;
    ensures \result == -1 ==> (\forall integer i; 0 <= i < a_len ==> a[i] != key);
*/
int Find(int* a, int a_len, int key)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant \forall integer j; 0 <= j < i ==> a[j] != key;
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
