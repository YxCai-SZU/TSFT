// Generated C + ACSL

/*@
    requires results != \null;
    requires results_len > 0;
    requires \valid_read(results + (0 .. results_len-1));
    requires \forall integer i; 0 <= i < results_len ==> results[i] >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures \forall integer i; 0 <= i < results_len ==> \result >= results[i];
*/
int ComputeMaxRValue(int* results, int results_len)
{
  int maxR = results[0];
  /*@ assert maxR >= 0 && maxR <= 2147483647; */
  int i = 1;
/*@
  loop invariant 0 <= i <= results_len;
  loop invariant maxR >= 0.0;
  loop invariant \forall integer k; 0 <= k < i ==> maxR >= results[k];
  loop invariant \forall integer k; 0 <= k < i ==> results[k] >= 0.0;
  loop assigns i, maxR;
  loop variant results_len - i;
*/
  while ((i < results_len))
    {
      if ((results[i] > maxR))
      {
        maxR = results[i];
      }
      i = (i + 1);
    }
  return maxR;  // Dafny implicit return
}