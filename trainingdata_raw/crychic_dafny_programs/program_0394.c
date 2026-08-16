// Generated C + ACSL

/*@
    requires a_len >= 0;
    requires a_len > 0 ==> a != \null;
    requires a_len > 0 ==> \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result <= a_len;
    ensures \result < a_len ==> a[\result] == key;
    ensures \result == a_len ==> (\forall integer i; 0 <= i < a_len ==> a[i] != key);
*/
int find(int* a, int a_len, int key)
{
  int index = 0;
  /*@ assert index >= 0 && index <= 2147483647; */
  /*@ assert 0 <= index <= a_len; */
/*@
  loop invariant 0 <= index <= a_len;
  loop invariant \forall integer i; 0 <= i < index ==> a[i] != key;
  loop assigns index;
  loop variant a_len - index;
*/
  while (((index < a_len) && (a[index] != key)))
    {
      int Vzero = (a_len - index);
      /*@ assert (((index < a_len) && 0 <= index <= a_len) && ((a_len - index) == Vzero)); */
      index = (index + 1);
      /*@ assert (0 <= index <= a_len && 0 <= a_len - index < Vzero); */
    }
  /*@ assert ((!((index < a_len))) || ((a[index] == key))); */
  return index;  // Dafny implicit return
}
