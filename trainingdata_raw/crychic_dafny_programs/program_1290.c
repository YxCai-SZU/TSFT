// Generated C + ACSL

/*@
  predicate sorted(int *a, integer len, integer min, integer max) =
    \forall integer j, k; min <= j && j < k && k < max ==> a[j] <= a[k];
*/

/*@
    requires a_len >= 1;
    requires a != \null;
    requires \valid(a + (0 .. a_len-1));
    requires 0 <= from < a_len;
    assigns \nothing;
    ensures from <= \result < a_len;
    ensures \forall integer k; from <= k < a_len ==> a[k] >= a[\result];
*/
int FindMin(int* a, int a_len, int from)
{
  int i = from;
  int min = from;
  /*@ assert min >= 0 && min <= 2147483647; */
/*@
  loop invariant from <= i <= a_len;
  loop invariant from <= min < a_len;
  loop invariant \forall integer k; from <= k < i ==> a[k] >= a[min];
  loop assigns i, min;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((a[i] <= a[min]))
      {
        min = i;
      }
      i = (i + 1);
    }
  return min;
}

/*@
    requires a != \null;
    requires a_len >= 1;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
*/
void SelectionSort(int* a, int a_len)
{
  int min = 0;
  int current = 0;
/*@
  loop invariant 0 <= current <= a_len;
  loop invariant \forall integer i, j;
    0 <= i < current <= j < a_len ==> a[i] <= a[j];
  loop invariant \forall integer i, j;
    0 <= i < j < current ==> a[i] <= a[j];
  loop assigns current, min, a[0..a_len-1];
  loop variant a_len - current;
*/
  while ((current < a_len))
    {
      min = FindMin(a, a_len, current);
      /*@ assert current <= min < a_len; */
      /*@ assert \forall integer k; current <= k < a_len ==> a[k] >= a[min]; */
      /*@ assert \forall integer i; 0 <= i < current ==> a[i] <= a[min]; */
      
      // Store values before swap
      /*@ ghost int temp_min = a[min]; */
      /*@ ghost int temp_current = a[current]; */
      
      /*@ assert temp_min <= temp_current; */
      
      // Swap: a[min], a[current] := a[current], a[min];
      int tmp = a[min];
      a[min] = a[current];
      a[current] = tmp;
      
      /*@ assert a[current] == temp_min; */
      /*@ assert a[min] == temp_current; */
      /*@ assert a[current] <= a[min]; */
      /*@ assert \forall integer k; current < k < a_len ==> a[k] >= a[current]; */
      /*@ assert \forall integer i; 0 <= i < current ==> a[i] <= a[current]; */
      
      current = (current + 1);
      
      /*@ assert \forall integer i; 0 <= i < current ==> 
            \forall integer j; current <= j < a_len ==> a[i] <= a[j]; */
      /*@ assert \forall integer i, j; 0 <= i < j < current ==> a[i] <= a[j]; */
    }
}