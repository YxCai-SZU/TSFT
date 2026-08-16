// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \result == -1 || (0 <= \result < a_len && a[\result] == key);
*/
int Find(int* a, int a_len, int key)
{
  int index = 0;
  /*@ assert index >= 0 && index <= 2147483647; */
/*@
  loop invariant 0 <= index <= a_len;
  loop invariant \forall integer k; 0 <= k < index ==> a[k] != key;
  loop assigns index;
  loop variant a_len - index;
*/
  while ((index < a_len))
    {
      if ((a[index] == key))
      {
        return index;
      }
      index = (index + 1);
    }
  return -1;
}
