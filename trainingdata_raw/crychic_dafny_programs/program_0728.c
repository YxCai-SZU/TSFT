// Generated C + ACSL

#define MAX_ID_LENGTH 50
#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_REASON_LENGTH 200

/*@
  predicate IsValidEmail(char *email, integer len) =
    \exists integer i; 0 <= i && i < len && email[i] == '@' && i > 0 && i < len - 1;
*/

/*@
    requires uid != \null;
    requires uid_len > 0;
    requires \valid_read(uid + (0 .. uid_len-1));
    requires n != \null;
    requires \valid_read(n + (0 .. n_len-1));
    requires e != \null;
    requires \valid_read(e + (0 .. e_len-1));
    requires pwd != \null;
    requires \valid_read(pwd + (0 .. pwd_len-1));
    requires r != \null;
    requires \valid_read(r + (0 .. r_len-1));
    assigns \nothing;
    ensures \result == 1 ==>
        (uid_len <= MAX_ID_LENGTH && uid_len > 0 &&
         n_len <= MAX_NAME_LENGTH && n_len > 0 &&
         e_len <= MAX_EMAIL_LENGTH && e_len > 0 &&
         pwd_len <= MAX_PASSWORD_LENGTH && pwd_len > 0 &&
         r_len <= MAX_REASON_LENGTH);
    ensures \result == 0 ==>
        !(uid_len <= MAX_ID_LENGTH && uid_len > 0 &&
          n_len <= MAX_NAME_LENGTH && n_len > 0 &&
          e_len <= MAX_EMAIL_LENGTH && e_len > 0 &&
          pwd_len <= MAX_PASSWORD_LENGTH && pwd_len > 0 &&
          r_len <= MAX_REASON_LENGTH);
    ensures \result == 0 || \result == 1;
*/
int CreateUser(char* uid, int uid_len, char* n, int n_len, char* e, int e_len, char* pwd, int pwd_len, char* r, int r_len)
{
  int user = 0;
  if ((((((((((uid_len <= MAX_ID_LENGTH) && (uid_len > 0)) && (n_len <= MAX_NAME_LENGTH)) && (n_len > 0)) && (e_len <= MAX_EMAIL_LENGTH)) && (e_len > 0)) && (pwd_len <= MAX_PASSWORD_LENGTH)) && (pwd_len > 0)) && (r_len <= MAX_REASON_LENGTH)))
  {
    /* unsupported stmt: user := new User(uid, n, e, pwd, r); */
    user = 1;
  }
  else
  {
    user = 0;
    /*@ assert user >= 0 && user <= 2147483647; */
  }
  return user;
}