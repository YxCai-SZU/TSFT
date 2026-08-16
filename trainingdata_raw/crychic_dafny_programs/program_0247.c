// Generated C + ACSL

/*@
    requires arr != \null;
    requires arr_len > 0;
    requires \valid_read(arr + (0 .. arr_len-1));
    requires \forall integer i, j; 0 <= i < j < arr_len ==> arr[i] <= arr[j];
    assigns \nothing;
    ensures \result == -1 ||
            (0 <= \result < arr_len &&
             arr[\result] == elem &&
             (\result >= arr_len - 1 || arr[\result + 1] > elem));
    ensures \forall integer i; 0 <= i < arr_len ==> arr[i] == \old(arr[i]);
*/
int LastPosition(int* arr, int arr_len, int elem)
{
  int pos = -1;
  /*@ assert pos == -1; */
  {
    int i = 0;
/*@
  loop invariant 0 <= i <= arr_len;
  loop invariant pos == -1 || (0 <= pos < i && pos < arr_len);
  loop invariant pos == -1 || arr[pos] == elem;
  loop invariant pos == -1 || (\forall integer k; pos < k < i ==> arr[k] != elem);
  loop invariant pos == -1 ==> (\forall integer k; 0 <= k < i ==> arr[k] != elem);
  loop invariant pos != -1 ==> (\forall integer k; 0 <= k < i && arr[k] == elem ==> k <= pos);
  loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], LoopEntry);
  loop assigns i, pos;
  loop variant arr_len - i;
*/
    while ((i <= (arr_len - 1)))
      {
        if ((arr[i] == elem))
        {
          pos = i;
        }
        i = (i + 1);
      }
    /*@ assert i == arr_len; */
    /*@ assert pos == -1 ==> (\forall integer k; 0 <= k < arr_len ==> arr[k] != elem); */
    /*@ assert pos != -1 ==> (0 <= pos < arr_len && arr[pos] == elem); */
    /*@ assert pos != -1 ==> (\forall integer k; pos < k < arr_len ==> arr[k] != elem); */
    /*@ assert pos != -1 ==> (pos >= arr_len - 1 || arr[pos + 1] != elem); */
    /*@ assert pos != -1 ==> (pos >= arr_len - 1 || arr[pos + 1] > elem); */
  }
  return pos;  // Dafny implicit return
}