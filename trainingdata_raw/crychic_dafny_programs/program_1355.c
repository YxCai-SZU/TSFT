// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result <= a_len;
    ensures \result < a_len ==> a[\result] == key;
*/
int find(int* a, int a_len, int key)
{
  int index = 0;
  /*@ assert index >= 0 && index <= 2147483647; */
/*@
  loop invariant 0 <= index <= a_len;
  loop invariant \forall integer x; 0 <= x < index ==> a[x] != key;
  loop assigns index;
  loop variant a_len - index;
*/
  while (((index < a_len) && (a[index] != key)))
    {
      index = (index + 1);
    }
  return index;  // Dafny implicit return
}
