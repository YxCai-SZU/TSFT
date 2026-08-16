// Generated C + ACSL

typedef struct {
    int isActive;
    int isAdmin;
    int isStaff;
    int dateJoined;
} User;

void AddDateJoined_User(User* user, int currentTime);
void SetActive_User(User* user, int active);
void SetAdmin_User(User* user, int admin);
void SetStaff_User(User* user, int staff);

/*@
    assigns \nothing;
*/
void Main(void)
{
  User user = {1, 0, 0, 0};
  /*@ assert (user.isActive == 1); */
  /*@ assert (user.isAdmin == 0); */
  /*@ assert (user.isStaff == 0); */
  AddDateJoined_User(&user, 100);
  /*@ assert (user.dateJoined == 100); */
  SetAdmin_User(&user, 1);
  /*@ assert (user.isAdmin == 1); */
}

/*@
    requires currentTime >= 0;
    requires currentTime <= 2147483647;
    assigns user->dateJoined;
    ensures user->dateJoined == currentTime;
*/
void AddDateJoined_User(User* user, int currentTime)
{
  user->dateJoined = currentTime;
  /*@ assert user->dateJoined >= 0 && user->dateJoined <= 2147483647; */
}

/*@
    requires active >= 0;
    requires active <= 2147483647;
    assigns user->isActive;
    ensures user->isActive == active;
*/
void SetActive_User(User* user, int active)
{
  user->isActive = active;
  /*@ assert user->isActive == active; */
  /*@ assert user->isActive >= 0 && user->isActive <= 2147483647; */
}

/*@
    requires admin >= 0;
    requires admin <= 2147483647;
    assigns user->isAdmin;
    ensures user->isAdmin == admin;
*/
void SetAdmin_User(User* user, int admin)
{
  user->isAdmin = admin;
  /*@ assert user->isAdmin == admin; */
  /*@ assert user->isAdmin >= 0 && user->isAdmin <= 2147483647; */
}

/*@
    requires staff >= 0;
    requires staff <= 2147483647;
    assigns user->isStaff;
    ensures user->isStaff == staff;
*/
void SetStaff_User(User* user, int staff)
{
  user->isStaff = staff;
  /*@ assert user->isStaff == staff; */
  /*@ assert user->isStaff >= 0 && user->isStaff <= 2147483647; */
}