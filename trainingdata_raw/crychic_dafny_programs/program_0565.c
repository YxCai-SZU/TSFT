// Generated C + ACSL

/*@
  predicate Sorted(int *a, integer len, integer low, integer high) =
    0 <= low && low <= high && high <= len &&
    \forall integer i, j; low <= i && i < j && j < high ==> a[i] <= a[j];
*/

/*@
  predicate MinElementIndex(int *a, integer len, integer low, integer high, integer index) =
    low >= 0 && high < len && low <= index && index < len &&
    \forall integer i; low <= i && i <= high ==> a[i] >= a[index];
*/

/*@
    requires a != \null;
    requires a_len > 1;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
*/
void SelectionSort(int* a, int a_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant \forall integer x; 0 <= x < i - 1 ==>
                   a[x] <= a[x + 1];
  loop invariant \forall integer x; 0 <= x < i ==>
                   \forall integer y; i <= y < a_len ==> a[x] <= a[y];
  loop invariant Sorted(a, a_len, 0, i);
  loop assigns i, a[0..a_len-1];
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      int min_element_index = i;
      int j = i;
/*@
  loop invariant i <= j <= a_len;
  loop invariant i <= min_element_index < a_len;
  loop invariant \forall integer x; 0 <= x < i ==>
                   \forall integer y; i <= y < a_len ==> a[x] <= a[y];
  loop invariant \forall integer k; i <= k < j ==>
                   a[min_element_index] <= a[k];
  loop invariant i <= min_element_index < j || (j == i && min_element_index == i);
  loop invariant Sorted(a, a_len, 0, i);
  loop assigns j, min_element_index;
  loop variant a_len - j;
*/
      while ((j < a_len))
        {
          if ((a[j] < a[min_element_index]))
          {
            min_element_index = j;
          }
          j = (j + 1);
        }
      
      /*@ assert i <= min_element_index < a_len; */
      /*@ assert \forall integer k; i <= k < a_len ==> a[min_element_index] <= a[k]; */
      /*@ assert \forall integer x; 0 <= x < i ==>
                   \forall integer y; i <= y < a_len ==> a[x] <= a[y]; */
      
      // Store values before swap
      /*@ ghost int old_a_i = a[i]; */
      /*@ ghost int old_a_min = a[min_element_index]; */
      
      /* unsupported stmt: a[i], a[min_element_index] := a[min_element_index], a[i]; */
      int temp = a[i];
      a[i] = a[min_element_index];
      a[min_element_index] = temp;
      
      /*@ assert a[i] == old_a_min; */
      /*@ assert a[min_element_index] == old_a_i; */
      /*@ assert \forall integer k; i < k < a_len ==> a[i] <= a[k]; */
      /*@ assert \forall integer x; 0 <= x < i ==> a[x] <= a[i]; */
      /*@ assert \forall integer x; 0 <= x < i ==>
                   \forall integer y; i < y < a_len ==> a[x] <= a[y]; */
      /*@ assert \forall integer x; 0 <= x <= i ==>
                   \forall integer y; i < y < a_len ==> a[x] <= a[y]; */
      
      i = (i + 1);
    }
}