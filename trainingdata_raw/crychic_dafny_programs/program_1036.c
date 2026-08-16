// Generated C + ACSL

/*@
    requires classes != \null;
    requires counts != \null;
    requires classes_len == counts_len;
    requires classes_len > 0;
    requires \valid_read(classes + (0 .. classes_len-1));
    requires \valid_read(counts + (0 .. counts_len-1));
    assigns \nothing;
    ensures \result == 1 ==>
        (\forall integer i; 0 <= i < counts_len ==> counts[i] >= 0);
    ensures \result == 0 || \result == 1;
*/
int PlotClassCounts(char** classes, int classes_len, int* counts, int counts_len)
{
  if ((classes_len != counts_len))
  {
    int success = 0;
    /*@ assert success >= 0 && success <= 2147483647; */
    return 0;
  }
  int i = 0;
/*@
  loop invariant 0 <= i <= counts_len;
  loop invariant \forall integer k; 0 <= k < i ==> counts[k] >= 0;
  loop assigns i;
  loop variant counts_len - i;
*/
  while ((i < counts_len))
    {
      if ((counts[i] < 0))
      {
        return 0;
      }
      i = (i + 1);
    }
  return 1;
}

/*@
    requires runtime != \null;
    requires runtime_len > 0;
    requires \valid(runtime + (0 .. runtime_len-1));
    assigns \nothing;
    ensures \result == 1 ==>
        (\forall integer i; 0 <= i < runtime_len ==> runtime[i] >= 0);
    ensures \result == 0 || \result == 1;
*/
int PlotRuntimeDistribution(int* runtime, int runtime_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= runtime_len;
  loop invariant \forall integer k; 0 <= k < i ==> runtime[k] >= 0;
  loop assigns i;
  loop variant runtime_len - i;
*/
  while ((i < runtime_len))
    {
      if ((runtime[i] < 0))
      {
        int success = 0;
        /*@ assert success >= 0 && success <= 2147483647; */
        return 0;
      }
      i = (i + 1);
    }
  return 1;
}

/*@
    requires dataset >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int ComputeCorrelationMatrix(int dataset)
{
  /* unsupported stmt: correlation := new real[dataset.cols, dataset.cols]; */
  int i = 0;
/*@
  loop invariant 0 <= i;
  loop assigns i;
  loop variant 1;
*/
  while (0)
    {
      int j = 0;
/*@
  loop invariant 0 <= j;
  loop assigns j;
  loop variant 1;
*/
      while (0)
        {
          j = (j + 1);
        }
      i = (i + 1);
    }
  return 0;
}

/*@
  predicate ValidState(int *data, integer rows, integer cols, integer data_len0, integer data_len1) =
    data != \null &&
    rows == data_len0 &&
    cols == data_len1 &&
    rows > 0 &&
    cols > 0;
*/