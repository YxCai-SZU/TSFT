// Generated C + ACSL

/*@
    requires values != \null;
    requires values_len > 0;
    requires \valid_read(values + (0 .. values_len-1));
    assigns \nothing;
    ensures \exists integer k; 0 <= k < values_len && \result == values[k];
    ensures \forall integer i; 0 <= i < values_len ==> values[i] <= \result;
*/
int Maximum(int* values, int values_len)
{
  int max = values[0];
  int idx = 0;
/*@
  loop invariant 0 <= idx <= values_len;
  loop invariant \exists integer k; 0 <= k < values_len && max == values[k];
  loop invariant \forall integer j; 0 <= j < idx ==> values[j] <= max;
  loop invariant idx == 0 ==> max == values[0];
  loop assigns idx, max;
  loop variant values_len - idx;
*/
  while ((idx < values_len))
    {
      if ((values[idx] > max))
      {
        max = values[idx];
      }
      idx = (idx + 1);
    }
  /*@ assert idx == values_len; */
  /*@ assert \forall integer j; 0 <= j < values_len ==> values[j] <= max; */
  return max;  // Dafny implicit return
}