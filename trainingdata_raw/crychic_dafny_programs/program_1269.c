// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid_read(a + (0 .. a_len-1));
    requires \forall integer i, j; 0 <= i < j < a_len ==> a[i] <= a[j];
    assigns \nothing;
    ensures 0 <= \result <= a_len;
    ensures \forall integer i; 0 <= i < a_len ==> a[i] == \old(a[i]);
    ensures \result > 0 ==> a[\result - 1] <= x;
    ensures \result < a_len ==> a[\result] >= x;
*/
int binarySearch(int* a, int a_len, int x)
{
  int low = 0;
  int high = a_len;
/*@
  loop invariant 0 <= low <= high <= a_len;
  loop invariant low > 0 ==> a[low - 1] <= x;
  loop invariant high < a_len ==> a[high] >= x;
  loop assigns low, high;
  loop variant high - low;
*/
  while ((low < high))
    {
      int mid = (low + ((high - low) / 2));
      if (a[mid] < x) {
        low = mid + 1;
      } else if (a[mid] > x) {
        high = mid;
      } else {
        return mid;
      }
    }
  return low;
}

/*@
    assigns \nothing;
*/
void testBinarySearch(void)
{
  int a_vals[] = {1, 3};
  int* a = a_vals;
  int a_len = 2;
  int id0 = binarySearch(a, a_len, 0);
  /*@ assert (id0 == 0); */
  int id1 = binarySearch(a, a_len, 1);
  //@ assert id1 == 0 || id1 == 1;
  int id2 = binarySearch(a, a_len, 2);
  /*@ assert (id2 == 1); */
  int id3 = binarySearch(a, a_len, 3);
  //@ assert id3 == 1 || id3 == 2;
  int id4 = binarySearch(a, a_len, 4);
  /*@ assert (id4 == 2); */
}