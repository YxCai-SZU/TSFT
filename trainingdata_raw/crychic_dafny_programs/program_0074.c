// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid_read(a + (0 .. a_len-1));
    requires \forall integer i, j; 0 <= i < j < a_len ==> a[i] <= a[j];
    assigns \nothing;
    ensures (0 <= \result < a_len) ==> a[\result] == val;
    ensures (\result < 0 || \result >= a_len) ==>
            (\forall integer i; 0 <= i < a_len ==> a[i] != val);
*/
int binarySearch(int* a, int a_len, int val)
{
  int left = 0;
  int right = a_len;
  if (((a[left] > val) || (a[(right - 1)] < val)))
  {
    return -1;
  }
/*@
  loop invariant 0 <= left <= right <= a_len;
  loop invariant \forall integer i; 0 <= i < a_len && !(left <= i < right) ==> a[i] != val;
  loop assigns left, right;
  loop variant right - left;
*/
  while ((left < right))
    {
      int med = ((left + right) / 2);
      /*@ assert left <= med <= right; */
      if ((a[med] < val))
      {
        left = (med + 1);
      }
      else
      if ((a[med] > val))
      {
        right = med;
      }
      else
      {
        /*@ assert (a[med] == val); */
        int pos = med;
        /*@ assert pos >= 0 && pos <= 2147483647; */
        return pos;
      }
    }
  return -1;
}