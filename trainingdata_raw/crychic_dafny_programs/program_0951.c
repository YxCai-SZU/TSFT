// Generated C + ACSL

/*@
    requires duration >= 0;
    requires timeSeries_len >= 0;
    requires timeSeries_len == 0 || (timeSeries != \null && \valid_read(timeSeries + (0 .. timeSeries_len-1)));
    requires \forall integer i, j; 0 <= i < j < timeSeries_len ==> timeSeries[i] <= timeSeries[j];
    requires \forall integer i; 0 <= i < timeSeries_len ==> timeSeries[i] >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures timeSeries_len == 0 ==> \result == 0;
    ensures timeSeries_len > 0 ==> \result <= timeSeries[timeSeries_len - 1] - timeSeries[0] + duration;
*/
int FindPoisonedDuration(int* timeSeries, int timeSeries_len, int duration)
{
  int total = 0;
  /*@ assert total >= 0 && total <= 2147483647; */
  if (timeSeries_len == 0)
  {
    return 0;
  }
  int start = timeSeries[0];
  int end = (timeSeries[0] + duration);
  int i = 1;
/*@
  loop invariant 1 <= i <= timeSeries_len;
  loop invariant start == timeSeries[i - 1];
  loop invariant end == timeSeries[i - 1] + duration;
  loop invariant total >= 0;
  loop invariant i == 1 ==> total == 0;
  loop invariant i > 1 ==> total <= timeSeries[i - 1] - timeSeries[0];
  loop invariant \forall integer k; 0 <= k < i - 1 ==>
                 timeSeries[k] <= timeSeries[k + 1];
  loop invariant start >= 0;
  loop invariant end >= start;
  loop invariant end == start + duration;
  loop assigns i, start, end, total;
  loop variant timeSeries_len - i;
*/
  while ((i < timeSeries_len))
    {
      if ((timeSeries[i] <= end))
      {
        end = (timeSeries[i] + duration);
        start = timeSeries[i];
      }
      else
      {
        total = (total + (end - start));
        start = timeSeries[i];
        end = (timeSeries[i] + duration);
      }
      i = (i + 1);
    }
  total = (total + (end - start));
  return total;  // Dafny implicit return
}