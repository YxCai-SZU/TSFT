// Generated C + ACSL

/*@
  predicate Valid(int *content, integer content_len, char *name, char *owner) =
    content_len >= 0 &&
    name[0] != '\0' &&
    owner[0] != '\0';
*/

/*@
    requires \true;
    assigns \nothing;
    ensures \result == 1 ==>
        ((date >> 16) & 0xFFFF) >= 1900 &&
        ((date >> 16) & 0xFFFF) <= 9999 &&
        ((date >> 8) & 0xFF) >= 1 &&
        ((date >> 8) & 0xFF) <= 12 &&
        (date & 0xFF) >= 1 &&
        (date & 0xFF) <= 31;
*/
int IsValidDate(int date)
{
  int year = (date >> 16) & 0xFFFF;
  int month = (date >> 8) & 0xFF;
  int day = date & 0xFF;
  int isValid = ((((((year >= 1900) && (year <= 9999)) && (month >= 1)) && (month <= 12)) && (day >= 1)) && (day <= 31));
  /*@ assert isValid >= 0 && isValid <= 2147483647; */
  return isValid;  // Dafny implicit return
}

/*@
    requires content_len >= 0;
    requires name != \null;
    requires \valid_read(name + (0 .. name_len-1));
    requires owner != \null;
    requires \valid_read(owner + (0 .. owner_len-1));
    requires content != \null;
    requires \valid_read(content + (0 .. content_len-1));
    requires source != \null;
    requires \valid_read(source + (0 .. source_len-1));
    assigns \nothing;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> name_len > 0 && owner_len > 0;
*/
int UploadFile(char* name, int name_len, char* owner, int owner_len, int date, int* content, int content_len, char* source, int source_len)
{
  int dateValid = IsValidDate(date);
  int file = 0;
  if (((dateValid && (name_len > 0)) && (owner_len > 0)))
  {
    /* unsupported stmt: file := new File(name, owner, date, content, source); */
    file = 1;
  }
  else
  {
    file = 0;
    /*@ assert file >= 0 && file <= 2147483647; */
  }
  return file;  // Dafny implicit return
}