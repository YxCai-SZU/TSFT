// Generated C + ACSL

typedef struct {
    char* name;
} Field;

typedef struct {
    Field* fields;
    int fields_len;
} Model;

/*@
    requires oldName != \null;
    requires newName != \null;
    requires oldName_len > 0;
    requires newName_len > 0;
    requires \valid_read(oldName + (0 .. oldName_len-1));
    requires \valid_read(newName + (0 .. newName_len-1));
    requires \valid(model.fields + (0 .. model.fields_len-1));
    requires model.fields_len >= 0;
    requires \forall integer i; 0 <= i < oldName_len ==>
                 \forall integer j; 0 <= j < newName_len ==>
                     !(i == oldName_len-1 && j == newName_len-1) ||
                     oldName[i] != newName[j] || oldName_len != newName_len;
    assigns model.fields[0..model.fields_len-1].name;
    ensures \result == 0 || \result == 1;
*/
int RenameField(Model model, char* oldName, int oldName_len, char* newName, int newName_len)
{
  int i = 0;
  int success = 0;
  /*@ assert success >= 0 && success <= 2147483647; */
/*@
  loop invariant 0 <= i <= model.fields_len;
  loop invariant success == 0 || success == 1;
  loop assigns i, success, model.fields[0..model.fields_len-1].name;
  loop variant model.fields_len - i;
*/
  while ((i < model.fields_len))
    {
      if ((model.fields[i].name == oldName))
      {
        model.fields[i].name = newName;
        success = 1;
        break;;
      }
      i = (i + 1);
    }
  return success;
}

/*@
    requires model.fields_len > 0;
    requires \valid(model.fields + (0 .. model.fields_len-1));
    assigns model.fields[0 .. model.fields_len-1].name;
    ensures \result == 0 || \result == 1;
*/
int Apply(Model model)
{
  int success = RenameField(model, "category", 8, "department", 10);
  /*@ assert success >= 0 && success <= 2147483647; */
  return success;
}