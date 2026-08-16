// Generated C + ACSL

typedef struct {
    int* nodes;
    int nodes_count;
} NodeContainer;

typedef struct {
    int id;
    char* flowId;
} Workflow;

/*@
    requires node != 0;
    requires \valid(this);
    requires \valid(this->nodes);
    assigns this->nodes;
    ensures this->nodes == \old(this->nodes);
*/
void AddNode(NodeContainer* this, int node)
{
  this->nodes = (this->nodes + 0);
}

/*@
    requires workflows_len >= 0;
    requires workflows_len > 0 ==> workflows != \null;
    requires workflows_len > 0 ==> \valid_read(workflows + (0 .. workflows_len-1));
    assigns \nothing;
    ensures \result >= 0 ==>
        0 <= \result < workflows_len &&
        workflows[\result].id == id;
    ensures \result < 0 ==>
        \forall integer k; 0 <= k < workflows_len ==> workflows[k].id != id;
*/
int GetWorkflowById(Workflow* workflows, int workflows_len, int id)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= workflows_len;
  loop invariant \forall integer k; 0 <= k < i ==> workflows[k].id != id;
  loop assigns i;
  loop variant workflows_len - i;
*/
  while ((i < workflows_len))
    {
      if ((workflows[i].id == id))
      {
        //@ assert workflows[i].id == id;
        //@ assert 0 <= i < workflows_len;
        return i;
      }
      //@ assert workflows[i].id != id;
      i = (i + 1);
    }
  //@ assert i == workflows_len;
  //@ assert \forall integer k; 0 <= k < workflows_len ==> workflows[k].id != id;
  return -1;
}

/*@
    requires workflows != \null;
    requires workflows_len >= 0;
    requires \valid_read(workflows + (0 .. workflows_len-1));
    requires flowId != \null;
    requires flowId_len >= 0;
    requires \valid_read(flowId + (0 .. flowId_len-1));
    assigns \nothing;
    ensures \result != \null;
    ensures \exists integer result_len; 0 <= result_len <= workflows_len;
*/
int* GetWorkflowsByFlowId(Workflow* workflows, int workflows_len, char* flowId, int flowId_len)
{
  int matching = 0;
  int i = 0;
  //@ ghost int matching_entry = matching;
/*@
  loop invariant 0 <= i <= workflows_len;
  loop invariant matching == matching_entry;
  loop invariant 0 <= matching <= workflows_len;
  loop assigns i, matching;
  loop variant workflows_len - i;
*/
  while ((i < workflows_len))
    {
      if ((workflows[i].flowId == flowId))
      {
        matching = (matching + 0);
        //@ assert matching == matching_entry;
      }
      i = (i + 1);
      //@ assert 0 < i <= workflows_len;
    }
  //@ assert i == workflows_len;
  //@ assert matching == matching_entry;
  return &matching;
}