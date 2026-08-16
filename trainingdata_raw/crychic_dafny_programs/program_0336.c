// Generated C + ACSL

/*@
    requires PlanSet != \null;
    requires PlanSet_len > 0;
    requires \valid(PlanSet + (0 .. PlanSet_len-1));
    requires \forall integer i; 0 <= i < PlanSet_len ==>
             (PlanSet[i] == \null || \valid(PlanSet[i]));
    requires \exists integer i; 0 <= i < PlanSet_len && PlanSet[i] == \null;
    assigns \nothing;
*/
void PlanReasoningAgent(int** PlanSet, int PlanSet_len, int threshold, int b)
{
  int* plan = PlanSet[0];
  int plan_len = 0;
  /*@ assert plan == \null || \valid(plan); */
  int recharge = 0;
  /*@ assert recharge >= 0 && recharge <= 2147483647; */
  if ((b < threshold))
  {
    recharge = 1;
    plan_len = 0;
  }
  else
  if ((threshold >= b))
  {
    int i = 0;
/*@
  loop invariant 0 <= i <= PlanSet_len;
  loop invariant plan_len >= 0;
  loop invariant \exists integer k; 0 <= k < PlanSet_len && plan == PlanSet[k];
  loop invariant \forall integer x; i <= x < PlanSet_len ==> (PlanSet[x] == \null || \valid(PlanSet[x]));
  loop assigns i, plan, plan_len;
  loop variant PlanSet_len - i;
*/
    while ((i < PlanSet_len))
      {
        int current_len = 0;
        if ((current_len < plan_len))
        {
          plan = PlanSet[i];
          plan_len = current_len;
        }
        i = (i + 1);
      }
  }
}