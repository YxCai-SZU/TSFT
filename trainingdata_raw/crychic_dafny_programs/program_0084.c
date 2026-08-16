// Generated C + ACSL

/*@
    requires a_len > 0;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result < a_len;
    ensures \forall integer j; 0 <= j < a_len ==> a[\result] >= a[j];
*/
int FindMax(int* a, int a_len)
{
  int max_idx = 0;
  /*@ assert max_idx >= 0 && max_idx <= 2147483647; */
  int i = 1;
  /*@ assert i >= 0 && i <= 2147483647; */
/*@
  loop invariant 1 <= i <= a_len;
  loop invariant 0 <= max_idx < i;
  loop invariant \forall integer j; 0 <= j < i ==> a[max_idx] >= a[j];
  loop assigns i, max_idx;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((a[i] > a[max_idx]))
      {
        max_idx = i;
      }
      i = (i + 1);
    }
  return max_idx;
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int arr_vals[] = {1, 1, 25, 7, 2, -2, 3, 3, 20};
  int* arr = arr_vals;
  int arr_len = 9;
  int idx = FindMax(arr, arr_len);
  /*@ assert \forall integer i; 0 <= i < arr_len ==> arr[idx] >= arr[i]; */
}