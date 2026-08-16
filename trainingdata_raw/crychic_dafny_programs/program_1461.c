// Generated C + ACSL

/*@
    requires arr != \null;
    requires arr_len >= 1;
    requires \valid(arr + (0 .. arr_len-1));
    assigns arr[0 .. arr_len-1];
    ensures \forall integer m, n;
        0 <= m <= n <= arr_len - 1 ==> arr[m] <= arr[n];
*/
void BubbleSort(int* arr, int arr_len)
{
  int last = (arr_len - 1);
/*@
  loop invariant 0 <= last <= arr_len - 1;
  loop invariant \forall integer m, nn;
      0 <= last < m <= nn < arr_len ==> arr[m] <= arr[nn];
  loop invariant \forall integer c, c_prime;
      0 <= c <= last < c_prime < arr_len ==> arr[c] <= arr[c_prime];
  loop assigns last, arr[0..arr_len-1];
  loop variant last;
*/
  while ((last > 0))
    {
      int index = 0;
/*@
  loop invariant 0 <= index <= last;
  loop invariant 0 < last < arr_len;
  loop invariant \forall integer m, n;
      0 <= last < m <= n < arr_len ==> arr[m] <= arr[n];
  loop invariant \forall integer c, c_prime;
      0 <= c <= last < c_prime < arr_len ==> arr[c] <= arr[c_prime];
  loop invariant \forall integer c;
      0 <= c < index ==> arr[c] <= arr[index];
  loop assigns index, arr[0..arr_len-1];
  loop variant last - index;
*/
      while ((index < last))
        {
          if ((arr[index] > arr[(index + 1)]))
          {
            int tmp = arr[index];
            arr[index] = arr[(index + 1)];
            arr[(index + 1)] = tmp;
          }
          index = (index + 1);
        }
      last = (last - 1);
    }
}