// Generated C + ACSL

typedef enum {
  NEW,
  ASSIGNED,
  DONE
} TaskStatus;

typedef struct {
  TaskStatus status;
  int owner;
} Task;

/*@
    requires \valid(task);
    requires user >= 0 && user <= 2147483647;
    assigns task->status, task->owner;
    ensures \old(task->status) == NEW ==> task->status == ASSIGNED && task->owner == user;
    ensures \old(task->status) != NEW ==> task->status == \old(task->status) && task->owner == \old(task->owner);
    ensures \result == 1 <==> \old(task->status) == NEW;
*/
int Assign(Task *task, int user)
{
  int success;
  if ((task->status == NEW))
  {
    task->status = ASSIGNED;
    /*@ assert task->status >= 0 && task->status <= 2147483647; */
    task->owner = user;
    /*@ assert task->owner >= 0 && task->owner <= 2147483647; */
    success = 1;
    /*@ assert success >= 0 && success <= 2147483647; */
  }
  else
  {
    success = 0;
  }
  return success;
}

/*@
    requires \valid(task);
    requires user >= 0 && user <= 2147483647;
    assigns task->status;
    ensures (\old(task->status) == ASSIGNED && \old(task->owner) == user) ==> (task->status == DONE);
    ensures (\old(task->status) != ASSIGNED || \old(task->owner) != user) ==> (task->status == \old(task->status));
    ensures \result == 1 <==> (\old(task->status) == ASSIGNED && \old(task->owner) == user);
*/
int Complete(Task *task, int user)
{
  int success;
  if (((task->status == ASSIGNED) && (task->owner == user)))
  {
    task->status = DONE;
    /*@ assert task->status >= 0 && task->status <= 2147483647; */
    success = 1;
    /*@ assert success >= 0 && success <= 2147483647; */
  }
  else
  {
    success = 0;
  }
  return success;
}

/*@
    requires \true;
    assigns \nothing;
    ensures \result == 1;
*/
int TestTaskAssignment(void)
{
  int user = 1;
  /*@ assert user >= 0 && user <= 2147483647; */
  Task task = {NEW, 0};
  /*@ assert (task.status == NEW); */
  int assignResult = Assign(&task, user);
  /*@ assert assignResult; */
  /*@ assert (task.status == ASSIGNED); */
  /*@ assert (task.owner == user); */
  int completeResult = Complete(&task, user);
  /*@ assert completeResult; */
  /*@ assert (task.status == DONE); */
  return 1;
}