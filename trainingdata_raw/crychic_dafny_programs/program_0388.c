// Generated C + ACSL

/*@
    requires values_len > 0;
    requires \valid_read(values + (0 .. values_len-1));
    assigns \nothing;
    ensures \exists integer i; 0 <= i < values_len && values[i] == \result;
    ensures \forall integer i; 0 <= i < values_len ==> values[i] <= \result;
*/
int Maximum(int* values, int values_len)
{
  int max = values[0];
  int idx = 0;
/*@
  loop invariant 0 <= idx <= values_len;
  loop invariant max == values[0] || \exists integer i; 1 <= i < idx && values[i] == max;
  loop invariant \forall integer j; 0 <= j < idx ==> values[j] <= max;
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
  /*@ assert max == values[0] || \exists integer i; 1 <= i < values_len && values[i] == max; */
  return max;
}