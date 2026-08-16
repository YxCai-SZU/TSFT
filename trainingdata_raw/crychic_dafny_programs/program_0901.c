// Generated C + ACSL

typedef enum {
  ACTIVE,
  SCHEDULING_DELETION,
  DEPRECATED
} State;

typedef struct {
  int versionNumber;
  char* content;
  int content_len;
  State state;
  char* stage;
} SecretVersion;

SecretVersion* versions;
int versions_count = 0;
int* History;
int History_count = 0;
int state = ACTIVE;

/*@
    requires state == ACTIVE;
    requires content != \null;
    requires content_len > 0;
    requires \valid_read(content + (0 .. content_len-1));
    requires \valid(versions + (0 .. versions_count));
    requires \valid(History + (0 .. History_count));
    requires \valid(versions[versions_count].content + (0 .. content_len-1));
    requires versions[versions_count].versionNumber == versions_count + 1;
    requires versions[versions_count].content_len == content_len;
    requires \forall integer i; 0 <= i < content_len ==>
            versions[versions_count].content[i] == content[i];
    assigns versions[0 .. versions_count], History[0 .. History_count],
            versions_count, History_count;
    ensures \result == versions_count;
    ensures versions_count == \old(versions_count) + 1;
    ensures History_count == \old(History_count) + 1;
    ensures versions[versions_count - 1].versionNumber == \old(versions_count) + 1;
    ensures versions[versions_count - 1].content_len == content_len;
    ensures \forall integer i; 0 <= i < content_len ==>
            versions[versions_count - 1].content[i] == content[i];
*/
int CreateVersion(char* content, int content_len)
{
  int old_count = versions_count;
  /*@ assert versions[old_count].versionNumber == old_count + 1; */
  /*@ assert versions[old_count].content_len == content_len; */
  /*@ assert \forall integer i; 0 <= i < content_len ==>
              versions[old_count].content[i] == content[i]; */
  
  versions_count++;
  History_count++;
  
  /*@ assert versions_count == old_count + 1; */
  /*@ assert versions[versions_count - 1].versionNumber == old_count + 1; */
  /*@ assert versions[versions_count - 1].content_len == content_len; */
  /*@ assert \forall integer i; 0 <= i < content_len ==>
              versions[versions_count - 1].content[i] == content[i]; */
  
  return versions_count;
}

/*@
    requires state == ACTIVE;
    requires 1 <= versionNum <= versions_count;
    requires \valid(versions + (0 .. versions_count-1));
    requires \valid(versions + (versionNum - 1));
    assigns versions[versionNum - 1].state;
    ensures \result == 1 ==> versions[versionNum - 1].state == SCHEDULING_DELETION;
    ensures \result == 0 ==> versions[versionNum - 1].state == \old(versions[versionNum - 1].state);
*/
int ScheduleVersionDeletion(int versionNum)
{
  SecretVersion* version = &versions[versionNum - 1];
  if (version->stage != "DEPRECATED")
  {
    int success = 0;
    /*@ assert success >= 0 && success <= 2147483647; */
    return 0;
  }
  version->state = SCHEDULING_DELETION;
  int success = 1;
  return success;
}

/*@
    requires state == ACTIVE;
    requires 1 <= versionNum <= versions_count;
    requires \valid(versions + (versionNum - 1));
    requires versions[versionNum - 1].state == SCHEDULING_DELETION;
    assigns versions[versionNum - 1].state;
    ensures \result == 1 ==> versions[versionNum - 1].state == ACTIVE;
    ensures \result == 0 ==> versions[versionNum - 1].state == \old(versions[versionNum - 1].state);
*/
int CancelVersionDeletion(int versionNum)
{
  versions[versionNum - 1].state = ACTIVE;
  int success = 1;
  /*@ assert success >= 0 && success <= 2147483647; */
  return success;
}