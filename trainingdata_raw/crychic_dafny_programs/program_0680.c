// Generated C + ACSL

#include <stddef.h>

typedef struct {
  int node;
  int target;
  int Valid;
  int timer;
  int destroy;
} State;

int lifespan = 100;

/*@
    requires \valid(this);
    requires n >= 0 && n <= 2147483647;
    assigns this->node, this->target, this->Valid, this->timer, this->destroy;
    ensures this->node == n;
    ensures this->Valid == 1;
    ensures this->timer == 0;
    ensures this->destroy == 0;
*/
void Init(State* this, int n)
{
  this->node = n;
  /*@ assert this->node >= 0 && this->node <= 2147483647; */
  this->target = 0;
  /*@ assert this->target >= 0 && this->target <= 2147483647; */
  this->Valid = 1;
  /*@ assert this->Valid >= 0 && this->Valid <= 2147483647; */
  this->timer = 0;
  this->destroy = 0;
}

/*@
    requires \valid(this);
    requires n >= 0 && n <= 2147483647;
    assigns this->node;
    ensures this->node == n;
*/
void setStartNode(State* this, int n)
{
  this->node = n;
  /*@ assert this->node >= 0 && this->node <= 2147483647; */
}

/*@
    requires \valid(this);
    requires dt >= 0;
    requires this->Valid == 1;
    requires this->timer >= 0;
    requires this->timer + dt <= 2147483647;
    assigns this->timer, this->destroy;
    ensures this->timer == \old(this->timer) + dt;
    ensures (this->destroy == 1) <==> (this->timer >= lifespan);
    ensures this->Valid == 1;
*/
void update(State* this, int dt)
{
  this->timer = (this->timer + dt);
  /*@ assert this->timer >= 0 && this->timer <= 2147483647; */
  this->destroy = (this->timer >= lifespan);
  /*@ assert this->destroy >= 0 && this->destroy <= 2147483647; */
}

/*@
    requires \valid_read(this);
    requires dt >= 0;
    assigns \nothing;
*/
void update_debug(State* this, int dt)
{
  if ((this->node != 0))
  {
    /* unsupported stmt: print "Current position: ", node.position, "\n"; */
  }
  if ((this->target != 0))
  {
    /* unsupported stmt: print "Target position: ", target.position, "\n"; */
  }
  /* unsupported stmt: print "Goal position: ", goal, "\n"; */
  /* unsupported stmt: print "\n"; */
}