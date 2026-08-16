// Generated C + ACSL

typedef struct {
    char* name;
    int name_len;
} Permission;

typedef struct {
    char* getLatestBy;
    int getLatestBy_len;
    char** ordering;
    int ordering_len;
    Permission* permissions;
    int permissions_len;
    char* verboseName;
    int verboseName_len;
    char* verboseNamePlural;
    int verboseNamePlural_len;
} Options;

Options* this;

/*@
    requires orderingFields != \null;
    requires orderingFields_len > 0;
    requires \valid(orderingFields + (0 .. orderingFields_len-1));
    requires latestBy_len >= 0 ==> \valid_read(latestBy + (0 .. latestBy_len-1));
    requires perms_len > 0 ==> \valid(perms + (0 .. perms_len-1));
    requires vName != \null;
    requires vName_len > 0;
    requires \valid_read(vName + (0 .. vName_len-1));
    requires vNamePlural != \null;
    requires vNamePlural_len > 0;
    requires \valid_read(vNamePlural + (0 .. vNamePlural_len-1));
    assigns this->getLatestBy, this->getLatestBy_len, this->ordering, this->ordering_len, this->permissions, this->permissions_len, this->verboseName, this->verboseName_len, this->verboseNamePlural, this->verboseNamePlural_len;
*/
void AlterModelOptions(char* latestBy, int latestBy_len, char** orderingFields, int orderingFields_len, Permission* perms, int perms_len, char* vName, int vName_len, char* vNamePlural, int vNamePlural_len)
{
  this->getLatestBy = latestBy;
  this->getLatestBy_len = latestBy_len;
  this->ordering = orderingFields;
  this->ordering_len = orderingFields_len;
  this->permissions = perms;
  this->permissions_len = perms_len;
  this->verboseName = vName;
  this->verboseName_len = vName_len;
  this->verboseNamePlural = vNamePlural;
  this->verboseNamePlural_len = vNamePlural_len;
}

/*@
    requires permName != \null;
    requires permName_len >= 0;
    requires \valid_read(permName + (0 .. permName_len-1));
    requires this->permissions_len >= 0;
    requires this->permissions_len > 0 ==> \valid_read(this->permissions + (0 .. this->permissions_len-1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int HasPermission(char* permName, int permName_len)
{
  int found = 0;
  int i = 0;
/*@
  loop invariant 0 <= i <= this->permissions_len;
  loop invariant found == 0 || found == 1;
  loop assigns i, found;
  loop variant this->permissions_len - i;
*/
  while ((i < this->permissions_len))
    {
      if ((this->permissions[i].name == permName))
      {
        found = 1;
        break;
      }
      i = (i + 1);
    }
  return found;
}

/*@
    assigns this->getLatestBy, this->getLatestBy_len, this->ordering, this->ordering_len, this->permissions, this->permissions_len, this->verboseName, this->verboseName_len, this->verboseNamePlural, this->verboseNamePlural_len;
*/
void Main(void)
{
  Permission perms[1];
  char* ordering[] = {"-last_message"};
  AlterModelOptions("", 0, ordering, 1, perms, 0, "Freedom of Information Request", 31, "Freedom of Information Requests", 32);
}