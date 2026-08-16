#include <stddef.h>

#define MAX_DEMANDS 1000
#define MAX_USERS 1000
#define MAX_EMAIL_LEN 256

typedef struct {
    int id;
    char email[MAX_EMAIL_LEN];
    int email_len;
} User;

typedef struct {
    int id;
    int userId;
    int isActive;
} Demand;

typedef struct {
    int is_some;
    User user;
} OptionUser;

typedef struct {
    int is_some;
    Demand demand;
} OptionDemand;

User users[MAX_USERS];
int users_len = 0;
int users_count = 0;

Demand demands[MAX_DEMANDS];
int demands_len = 0;
int demands_count = 0;

OptionUser FindUserByEmail(char* email, int email_len);
OptionUser GetUser(int userId);
OptionDemand GetActiveDemandForUser(int userId);

/*@
    requires email != \null;
    requires email_len > 0;
    requires email_len <= MAX_EMAIL_LEN;
    requires \valid_read(email + (0 .. email_len-1));
    requires 0 <= users_count < MAX_USERS;
    requires 0 <= users_len < MAX_USERS;
    requires users_count == users_len;
    assigns users[0 .. users_count];
    assigns users_count, users_len;
    ensures \result.id == -1 || (0 <= \result.id < users_count);
    ensures \result.id == -1 || users_count == \old(users_count) + 1;
    ensures \result.id == -1 || users_len == \old(users_len) + 1;
    ensures \result.id != -1 ==> users_count <= MAX_USERS;
*/
User CreateUser(char* email, int email_len)
{
  User result;
  OptionUser existingUser = FindUserByEmail(email, email_len);
  if (existingUser.is_some)
  {
    result.id = -1;
    /*@
      loop invariant 0 <= i <= email_len;
      loop invariant i <= MAX_EMAIL_LEN;
      loop invariant \forall int k; 0 <= k < i ==> result.email[k] == email[k];
      loop assigns i, result.email[0 .. MAX_EMAIL_LEN - 1];
      loop variant email_len - i;
    */
    for (int i = 0; i < email_len && i < MAX_EMAIL_LEN; i++) {
        result.email[i] = email[i];
    }
    result.email_len = email_len;
    return result;
  }
  //@ assert users_len < MAX_USERS;
  int newId = users_len;
  //@ assert newId < MAX_USERS;
  result.id = newId;
  /*@
    loop invariant 0 <= i <= email_len;
    loop invariant i <= MAX_EMAIL_LEN;
    loop invariant \forall int k; 0 <= k < i ==> result.email[k] == email[k];
    loop assigns i, result.email[0 .. MAX_EMAIL_LEN - 1];
    loop variant email_len - i;
  */
  for (int i = 0; i < email_len && i < MAX_EMAIL_LEN; i++) {
      result.email[i] = email[i];
  }
  result.email_len = email_len;
  //@ assert 0 <= users_len < MAX_USERS;
  users[users_len++] = result;
  users_count++;
  //@ assert users_count <= MAX_USERS;
  //@ assert 0 <= result.id < users_count;
  return result;
}

/*@
    requires email != \null;
    requires email_len > 0;
    requires \valid_read(email + (0 .. email_len-1));
    requires 0 <= users_len <= MAX_USERS;
    requires \valid_read(users + (0 .. users_len-1));
    assigns \nothing;
*/
OptionUser FindUserByEmail(char* email, int email_len)
{
  OptionUser result;
  int i = 0;
  /*@
    loop invariant 0 <= i <= users_len;
    loop assigns i;
    loop variant users_len - i;
  */
  while ((i < users_len))
    {
      int match = 1;
      if (users[i].email_len == email_len) {
          /*@
            loop invariant 0 <= j <= email_len;
            loop invariant match == 0 || match == 1;
            loop invariant match == 1 ==> (\forall int k; 0 <= k < j ==> users[i].email[k] == email[k]);
            loop assigns j, match;
            loop variant email_len - j;
          */
          for (int j = 0; j < email_len; j++) {
              if (users[i].email[j] != email[j]) {
                  match = 0;
                  break;
              }
          }
          if (match) {
              result.is_some = 1;
              result.user = users[i];
              return result;
          }
      }
      i = (i + 1);
    }
  result.is_some = 0;
  return result;
}

/*@
    requires userId >= 0;
    requires users != \null;
    requires 0 <= users_len <= MAX_USERS;
    requires \valid_read(users + (0 .. users_len-1));
    assigns \nothing;
*/
OptionUser GetUser(int userId)
{
  OptionUser result;
  int i = 0;
  /*@
    loop invariant 0 <= i <= users_len;
    loop assigns i;
    loop variant users_len - i;
  */
  while ((i < users_len))
    {
      if ((users[i].id == userId))
      {
        result.is_some = 1;
        result.user = users[i];
        return result;
      }
      i = (i + 1);
    }
  result.is_some = 0;
  return result;
}

/*@
    requires userId >= 0;
    requires 0 <= demands_count < MAX_DEMANDS;
    requires 0 <= demands_len < MAX_DEMANDS;
    requires demands_count == demands_len;
    requires \valid(demands + (0 .. demands_count));
    assigns demands[0 .. MAX_DEMANDS - 1], demands_count, demands_len;
    ensures \result.id == -1 || demands_count == \old(demands_count) + 1;
    ensures \result.id == -1 || demands_len == \old(demands_len) + 1;
*/
Demand CreateDemand(int userId)
{
  Demand result;
  OptionDemand existingDemand = GetActiveDemandForUser(userId);
  if (existingDemand.is_some)
  {
    result.id = -1;
    result.userId = userId;
    result.isActive = 0;
    return result;
  }
  //@ assert demands_len < MAX_DEMANDS;
  int newId = demands_len;
  //@ assert newId < MAX_DEMANDS;
  result.id = newId;
  result.userId = userId;
  result.isActive = 1;
  //@ assert 0 <= demands_len < MAX_DEMANDS;
  demands[demands_len++] = result;
  demands_count++;
  //@ assert demands_count <= MAX_DEMANDS;
  return result;
}

/*@
    requires userId >= 0;
    requires 0 <= demands_len <= MAX_DEMANDS;
    requires \valid_read(demands + (0 .. demands_len-1));
    assigns \nothing;
*/
OptionDemand GetActiveDemandForUser(int userId)
{
  OptionDemand result;
  int i = 0;
  /*@
    loop invariant 0 <= i <= demands_len;
    loop assigns i;
    loop variant demands_len - i;
  */
  while ((i < demands_len))
    {
      if (((demands[i].userId == userId) && demands[i].isActive))
      {
        result.is_some = 1;
        result.demand = demands[i];
        return result;
      }
      i = (i + 1);
    }
  result.is_some = 0;
  return result;
}