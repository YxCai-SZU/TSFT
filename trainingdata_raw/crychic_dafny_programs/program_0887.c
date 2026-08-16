// Generated C + ACSL

struct Model {
  int *fields;
};

/*@
    requires model != \null;
    requires model_fields_length >= 2;
    requires \valid(model->fields + (0 .. model_fields_length-1));
    requires bannerField != 0;
    requires runSheetField != 0;
    requires model_fields_0_fieldType == 0;
    requires model_fields_1_fieldType == 1;
    assigns model->fields[0 .. 1];
    ensures \result == 1;
    ensures \result == 1 ==> model->fields[0] != 0;
    ensures \result == 1 ==> model->fields[1] != 0;
    ensures \result == 1 ==> model_fields_0_fieldType == 0;
    ensures \result == 1 ==> model_fields_1_fieldType == 1;
*/
int AlterFields(struct Model *model, int model_fields_length, int model_fields_0_fieldType, int model_fields_1_fieldType, int bannerField, int runSheetField)
{
  /*@ assert bannerField != 0; */
  /*@ assert runSheetField != 0; */
  model->fields[0] = bannerField;
  /*@ assert model->fields[0] == bannerField; */
  /*@ assert model->fields[0] != 0; */
  model->fields[1] = runSheetField;
  /*@ assert model->fields[1] == runSheetField; */
  /*@ assert model->fields[1] != 0; */
  int success = 1;
  /*@ assert success >= 0 && success <= 2147483647; */
  /*@ assert model->fields[0] != 0; */
  /*@ assert model->fields[1] != 0; */
  /*@ assert model_fields_0_fieldType == 0; */
  /*@ assert model_fields_1_fieldType == 1; */
  return success;  // Dafny implicit return
}

/*@
    requires \valid(eventModel);
    requires \valid(eventModel->fields + (0 .. 1));
    requires bannerField != 0;
    requires runSheetField != 0;
    assigns eventModel->fields[0 .. 1];
    ensures \result == 1;
*/
int ExecuteMigration(int bannerField, int runSheetField, struct Model *eventModel)
{
  /*@ assert \valid(eventModel); */
  /*@ assert \valid(eventModel->fields + (0 .. 1)); */
  /*@ assert bannerField != 0; */
  /*@ assert runSheetField != 0; */
  int migrationResult = AlterFields(eventModel, 2, 0, 1, bannerField, runSheetField);
  /*@ assert migrationResult == 1; */
  int result = migrationResult;
  /*@ assert result >= 0 && result <= 2147483647; */
  /*@ assert result == 1; */
  return result;  // Dafny implicit return
}