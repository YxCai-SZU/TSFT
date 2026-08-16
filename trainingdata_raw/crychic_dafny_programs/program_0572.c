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
  /*@ assert max == values[0]; */
  /*@ assert \exists integer k; 0 <= k < values_len && max == values[k]; */
  /*@ assert \forall integer j; 0 <= j < 1 ==> values[j] <= max; */
  int idx = 0;
/*@
  loop invariant 0 <= idx <= values_len;
  loop invariant \valid_read(values + (0 .. values_len - 1));
  loop invariant \exists integer k; 0 <= k < values_len && max == values[k];
  loop invariant \forall integer j; 0 <= j < idx ==> values[j] <= max;
  loop invariant idx > 0 ==> (\exists integer k; 0 <= k < idx && max == values[k]);
  loop invariant idx == 0 ==> max == values[0];
  loop assigns idx, max;
  loop variant values_len - idx;
*/
  while ((idx < values_len))
    {
      /*@ assert values[idx] <= max || values[idx] > max; */
      if ((values[idx] > max))
      {
        max = values[idx];
        /*@ assert max == values[idx]; */
        /*@ assert \exists integer k; 0 <= k < values_len && max == values[k]; */
      }
      /*@ assert \forall integer j; 0 <= j < idx ==> values[j] <= max; */
      /*@ assert values[idx] <= max; */
      idx = (idx + 1);
      /*@ assert \forall integer j; 0 <= j < idx ==> values[j] <= max; */
    }
  /*@ assert idx == values_len; */
  /*@ assert \forall integer j; 0 <= j < values_len ==> values[j] <= max; */
  /*@ assert \exists integer k; 0 <= k < values_len && max == values[k]; */
  return max;  // Dafny implicit return
}