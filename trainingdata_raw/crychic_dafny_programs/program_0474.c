// Generated C + ACSL

/*@
    requires a_len > 0;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result < a_len;
    ensures \forall integer k; 0 <= k < a_len ==> a[\result] >= a[k];
*/
int FindMax(int* a, int a_len)
{
  int count = 0;
  int i = 0;
  /*@ assert i >= 0 && i <= 2147483647; */
/*@
  loop invariant 0 <= count <= a_len;
  loop invariant 0 <= i < a_len;
  loop invariant \forall integer k; 0 <= k < count ==> a[i] >= a[k];
  loop assigns count, i;
  loop variant a_len - count;
*/
  while ((count < a_len))
    {
      if ((a[count] >= a[i]))
      {
        i = count;
      }
      count = (count + 1);
    }
  return i;  // Dafny implicit return
}

/*@
    requires a_len > 0;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \forall integer k; 0 < k < a_len ==> \result >= a[k];
*/
int FindMaxi(int* a, int a_len)
{
  int index = 0;
  int max = a[0];
  /*@ assert max == a[0]; */
/*@
  loop invariant 0 <= index <= a_len;
  loop invariant \forall integer k; 0 < k < index ==> max >= a[k];
  loop invariant max == a[0] || \exists integer k; 0 < k < index && max == a[k];
  loop assigns index, max;
  loop variant a_len - index;
*/
  while ((index < a_len))
    {
      if ((a[index] >= max))
      {
        max = a[index];
      }
      index = (index + 1);
    }
  /*@ assert index == a_len; */
  /*@ assert \forall integer k; 0 < k < a_len ==> max >= a[k]; */
  return max;  // Dafny implicit return
}