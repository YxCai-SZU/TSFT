// Generated C + ACSL

/*@
    requires arr != \null;
    requires arr_len >= 0;
    requires \valid(arr + (0 .. arr_len-1));
    assigns arr[0 .. arr_len-1];
*/
void init_array(int* arr, int arr_len)
{
  int i = 0;
  int high = arr_len;
/*@
  loop invariant 0 <= i <= high;
  loop invariant \forall integer k; 0 <= k < i ==> arr[k] == 0;
  loop assigns i, arr[0..high-1];
  loop variant high - i;
*/
  while ((i < high))
    {
      arr[i] = 0;
      i = (i + 1);
    }
}
