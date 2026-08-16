// Generated C + ACSL

/*@
    requires arr != \null;
    requires arr_len >= 0;
    requires \valid(arr + (0 .. arr_len-1));
    assigns arr[0 .. arr_len-1];
    ensures \forall integer i; 0 <= i < arr_len ==>
        (\old(arr[i]) > k ==> arr[i] == -1);
    ensures \forall integer i; 0 <= i < arr_len ==>
        (\old(arr[i]) <= k ==> arr[i] == \old(arr[i]));
*/
void replace(int* arr, int arr_len, int k)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= arr_len;
  loop invariant \forall integer j; 0 <= j < i ==>
    (\at(arr[j], LoopEntry) > k ==> arr[j] == -1);
  loop invariant \forall integer j; 0 <= j < i ==>
    (\at(arr[j], LoopEntry) <= k ==> arr[j] == \at(arr[j], LoopEntry));
  loop invariant \forall integer j; i <= j < arr_len ==>
    arr[j] == \at(arr[j], LoopEntry);
  loop assigns i, arr[0..arr_len-1];
  loop variant arr_len - i;
*/
  while ((i < arr_len))
    {
      if ((arr[i] > k))
      {
        arr[i] = -1;
      }
      i = (i + 1);
    }
}
