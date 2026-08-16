// Generated C + ACSL

typedef struct {
    char* email;
    int email_len;
    char* password;
    int password_len;
} Student;

Student* students;
int students_count = 0;
int students_len = 0;

/*@
    requires students_count >= 0;
    requires students_len >= students_count;
    requires \valid(students + (0 .. students_len-1));
    assigns students[students_count], students_count;
    ensures \result == 0 || \result == 1;
    ensures students_count == \old(students_count) + (\result == 1 ? 1 : 0);
*/
int AddStudent(Student student)
{
  int i = 0;
  int emailExists = 0;
  int success = 0;
/*@
  loop invariant 0 <= i <= students_len;
  loop invariant emailExists == 0 || emailExists == 1;
  loop invariant \forall integer k; 0 <= k < students_len ==> students[k] == \at(students[k], Pre);
  loop invariant students_count == \at(students_count, Pre);
  loop invariant emailExists == 0 ==> (\forall integer k; 0 <= k < i ==> students[k].email != student.email);
  loop invariant emailExists == 1 ==> (\exists integer k; 0 <= k < i && students[k].email == student.email);
  loop assigns i, emailExists;
  loop variant students_len - i;
*/
  while ((i < students_len))
    {
      if ((students[i].email == student.email))
      {
        emailExists = 1;
        break;
      }
      i = (i + 1);
    }
  /*@ assert emailExists == 0 ==> (\forall integer k; 0 <= k < students_len ==> students[k].email != student.email); */
  /*@ assert \forall integer k; 0 <= k < students_len ==> students[k] == \at(students[k], Pre); */
  /*@ assert students_count == \at(students_count, Pre); */
  if (!(emailExists))
  {
    students[students_count] = student;
    students_count = students_count + 1;
    /*@ assert students_count >= 0 && students_count <= 2147483647; */
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
    requires email != \null;
    requires password != \null;
    requires email_len > 0;
    requires password_len > 0;
    requires \valid_read(email + (0 .. email_len-1));
    requires \valid_read(password + (0 .. password_len-1));
    requires students_count >= 0;
    requires students_len >= students_count;
    requires \valid_read(students + (0 .. students_len-1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int ValidateLogin(char* email, int email_len, char* password, int password_len)
{
  int i = 0;
  int valid = 0;
  /*@ assert valid >= 0 && valid <= 2147483647; */
/*@
  loop invariant 0 <= i <= students_len;
  loop invariant valid == 0 || valid == 1;
  loop invariant \at(valid, LoopEntry) == 1 ==> valid == 1;
  loop assigns i, valid;
  loop variant students_len - i;
*/
  while ((i < students_len))
    {
      if (((students[i].email == email) && (students[i].password == password)))
      {
        valid = 1;
        break;
      }
      i = (i + 1);
    }
  return valid;
}