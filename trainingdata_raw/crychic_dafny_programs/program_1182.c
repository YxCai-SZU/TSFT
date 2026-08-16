// Generated C + ACSL

/*@
    requires numbers_len >= 0;
    requires numbers_len > 0 ==> numbers != \null;
    requires numbers_len > 0 ==> \valid_read(numbers + (0 .. numbers_len-1));
    requires \forall integer i, j; 0 <= i < j < numbers_len ==> numbers[i] <= numbers[j];
    assigns \nothing;
    ensures \result == -1 ==> \forall integer i; 0 <= i < numbers_len ==> numbers[i] != target;
    ensures 0 <= \result < numbers_len ==> numbers[\result] == target;
*/
int BinarySearchIterative(int* numbers, int numbers_len, int target)
{
  if (numbers_len == 0)
  {
    return -1;
  }
  int start = 0;
  int end = (numbers_len - 1);
/*@
  loop invariant 0 <= start <= numbers_len;
  loop invariant -1 <= end < numbers_len;
  loop invariant \forall integer i; 0 <= i < start ==> numbers[i] < target;
  loop invariant \forall integer i; end < i < numbers_len ==> target < numbers[i];
  loop assigns start, end;
  loop variant end - start + 1;
*/
  while ((start <= end))
    {
      int mid = (start + ((end - start) / 2));
      if (numbers[mid] == target)
      {
        return mid;
      }
      else
      if ((numbers[mid] < target))
      {
        start = (mid + 1);
      }
      else
      {
        end = (mid - 1);
      }
    }
  return -1;
}

/*@
    requires numbers != \null;
    requires numbers_len >= 0;
    requires \valid_read(numbers + (0 .. numbers_len-1));
    requires \forall integer i, j; 0 <= i < j < numbers_len ==> numbers[i] <= numbers[j];
    requires 0 <= start <= numbers_len;
    requires -1 <= end < numbers_len;
    decreases end - start + 2;
    assigns \nothing;
    ensures \result == -1 ==>
        (\forall integer i; start <= i <= end ==> numbers[i] != target);
    ensures start <= \result <= end ==> numbers[\result] == target;
    ensures (\result < start || \result > end) ==> \result == -1;
    ensures -1 <= \result < numbers_len;
    ensures \result >= -1;
*/
int BinarySearchRecursiveHelper(int* numbers, int numbers_len, int target, int start, int end)
{
  if ((start > end))
  {
    return -1;
  }
  int mid = (start + ((end - start) / 2));
  //@ assert start <= mid <= end;
  //@ assert 0 <= mid < numbers_len;
  
  if (numbers[mid] == target)
  {
    return mid;
  }
  else
  if ((numbers[mid] < target))
  {
    //@ assert mid + 1 <= numbers_len;
    //@ assert end - (mid + 1) + 2 < end - start + 2;
    int position = BinarySearchRecursiveHelper(numbers, numbers_len, target, (mid + 1), end);
    /*@ assert -1 <= position < numbers_len; */
    /*@ assert position == -1 || (mid + 1 <= position <= end); */
    return position;
  }
  else
  {
    //@ assert numbers[mid] > target;
    //@ assert (mid - 1) - start + 2 < end - start + 2;
    int position = BinarySearchRecursiveHelper(numbers, numbers_len, target, start, (mid - 1));
    /*@ assert -1 <= position < numbers_len; */
    /*@ assert position == -1 || (start <= position <= mid - 1); */
    return position;
  }
}

/*@
    requires numbers_len >= 0;
    requires numbers_len == 0 || (numbers != \null && \valid_read(numbers + (0 .. numbers_len-1)));
    requires \forall integer i, j; 0 <= i < j < numbers_len ==> numbers[i] <= numbers[j];
    assigns \nothing;
    ensures \result == -1 ==> (\forall integer i; 0 <= i < numbers_len ==> numbers[i] != target);
    ensures 0 <= \result < numbers_len ==> numbers[\result] == target;
*/
int BinarySearchRecursive(int* numbers, int numbers_len, int target)
{
  if (numbers_len == 0) {
    return -1;
  }
  //@ assert numbers != \null;
  //@ assert 0 <= 0 <= numbers_len;
  //@ assert -1 <= numbers_len - 1 < numbers_len;
  int position = BinarySearchRecursiveHelper(numbers, numbers_len, target, 0, (numbers_len - 1));
  /*@ assert -1 <= position < numbers_len; */
  /*@ assert position == -1 || (0 <= position < numbers_len && numbers[position] == target); */
  return position;
}