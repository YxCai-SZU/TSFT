// Generated C + ACSL

typedef struct {
    char* matricula;
    char* password;
} User;

#define MAX_USERS 100
User users[MAX_USERS];
int users_count = 0;
int users_len = 0;

int ExistsUser(char* matricula, int matricula_len);

/*@
    requires \valid_read(&user);
    requires users_count >= 0 && users_count < MAX_USERS;
    assigns users[0 .. MAX_USERS-1], users_count;
    ensures (\result == 1) ==>
            (\exists integer i; 0 <= i < users_count && users[i].matricula == user.matricula);
    ensures users_count == \old(users_count) + (\result == 1 ? 1 : 0);
*/
int AddUser(User user)
{
  int existsUser = ExistsUser(user.matricula, 0);
  int success;
  if (!(existsUser))
  {
    users[users_count] = user;
    users_count++;
    /*@ assert users_count >= 0 && users_count <= 2147483647; */
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
    requires matricula != \null;
    requires matricula_len >= 0;
    requires \valid_read(matricula + (0 .. matricula_len-1));
    requires users_len >= 0;
    requires \valid_read(users + (0 .. users_len-1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int ExistsUser(char* matricula, int matricula_len)
{
  int found = 0;
  /*@ assert found >= 0 && found <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= users_len;
  loop invariant found == 0 || found == 1;
  loop invariant found == 1 <==> (\exists integer j; 0 <= j < i && users[j].matricula == matricula);
  loop invariant found == 0 <==> (\forall integer j; 0 <= j < i ==> users[j].matricula != matricula);
  loop invariant \valid_read(users + (0 .. users_len - 1));
  loop assigns i, found;
  loop variant users_len - i;
*/
  while ((i < users_len))
    {
      if ((users[i].matricula == matricula))
      {
        found = 1;
        return found;
      }
      i = (i + 1);
    }
  return found;
}

/*@
    requires matricula != \null;
    requires matricula_len >= 0;
    requires \valid_read(matricula + (0 .. matricula_len-1));
    requires password != \null;
    requires password_len >= 0;
    requires \valid_read(password + (0 .. password_len-1));
    requires users_len >= 0;
    requires \valid_read(users + (0 .. users_len-1));
    assigns \nothing;
*/
void Authenticate(char* matricula, int matricula_len, char* password, int password_len)
{
  User user = {0};
  /*@ assert \valid(&user); */
  int success = 0;
  /*@ assert success >= 0 && success <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= users_len;
  loop invariant success == 0 || success == 1;
  loop invariant success == 1 ==>
    \exists integer k; 0 <= k < i &&
    users[k].matricula == matricula &&
    users[k].password == password;
  loop invariant success == 0 ==>
    \forall integer k; 0 <= k < i ==>
    !(users[k].matricula == matricula && users[k].password == password);
  loop assigns i, success, user;
  loop variant users_len - i;
*/
  while ((i < users_len))
    {
      if (((users[i].matricula == matricula) && (users[i].password == password)))
      {
        success = 1;
        user = users[i];
        return;
      }
      i = (i + 1);
    }
}