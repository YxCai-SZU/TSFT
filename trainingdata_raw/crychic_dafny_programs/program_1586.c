// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    requires \forall integer i, j; 0 <= i < j < a_len ==> a[i] <= a[j];
    assigns \nothing;
    ensures -1 <= \result < a_len;
    ensures \result == -1 ==> (\forall integer i; 0 <= i < a_len ==> a[i] != key);
    ensures \result != -1 ==> a[\result] == key;
*/
int BinarySearch(int* a, int a_len, int key)
{
  int low = 0;
  int high = a_len;
/*@
  loop invariant 0 <= low <= high <= a_len;
  loop invariant \forall integer i; 0 <= i < low ==> a[i] < key;
  loop invariant \forall integer i; high <= i < a_len ==> key < a[i];
  loop assigns low, high;
  loop variant high - low;
*/
  while ((low < high))
    {
      int mid = (low + ((high - low) / 2));
      if ((a[mid] < key))
      {
        low = (mid + 1);
      }
      else
      if ((key < a[mid]))
      {
        high = mid;
      }
      else
      {
        return mid;
      }
    }
  return -1;
}