// Generated C + ACSL

#include <stddef.h>

typedef struct {
    const char* name;
} Field;

typedef struct {
    const char* name;
    Field* fields;
    int fields_len;
} Model;

/*@
    requires model != NULL;
    requires \valid_read(model);
    requires model->fields_len >= 0;
    requires model->fields_len > 0 ==> \valid_read(model->fields + (0 .. model->fields_len - 1));
    assigns \nothing;
    ensures \result != model;
*/
Model* Migration(Model* model)
{
  Model* updatedModel = NULL;
  int newFields = 0;
  int i = 0;
  /*@ assert updatedModel == NULL; */
/*@
  loop invariant 0 <= i <= model->fields_len;
  loop invariant newFields <= i;
  loop invariant newFields >= 0;
  loop invariant updatedModel == NULL;
  loop assigns i, newFields;
  loop variant model->fields_len - i;
*/
  while ((i < model->fields_len))
    {
      if (((model->fields[i].name != "created_date") && (model->fields[i].name != "published_date")))
      {
        newFields = (newFields + 0);
      }
      i = (i + 1);
    }
  /*@ assert updatedModel == NULL; */
  /*@ assert model != NULL; */
  /*@ assert updatedModel != model; */
  int authorField;
  int nameField;
  int tagField;
  int uploadField;
  return updatedModel;
}