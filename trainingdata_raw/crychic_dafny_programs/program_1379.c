// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result ==> \result < a_len && a[\result] == key;
    ensures \result < 0 ==> \forall integer k; 0 <= k < a_len ==> a[k] != key;
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
  while (index < a_len)
    {
      if (a[index] == key)
      {
        return index;
      }
      index = (index + 1);
    }
  index = -1;
  return index;  // Dafny implicit return
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int a[5];
  a[0] = 12;
  a[1] = 3;
  a[2] = 5;
  a[3] = 2;
  a[4] = 1;
  int b = Find(a, 5, 5);
  /* unsupported stmt: print "Index: ", b; */
}