// Generated C + ACSL

typedef struct {
  char* firstName;
  char* lastName;
  char* email;
  int cellPhone;
  char** skills;
  char* userPhoto;
} UserProfile;

typedef struct {
  char* name;
  char* mediaType;
  char* mediaUrl;
  int userId;
} UserMedia;

/*@
    requires newEmail != \null;
    requires newEmail_len > 0;
    requires \valid_read(newEmail + (0 .. newEmail_len-1));
    requires newCellPhone >= 0;
    requires newFirstName != \null;
    requires newFirstName_len >= 0;
    requires \valid_read(newFirstName + (0 .. newFirstName_len-1));
    requires newLastName != \null;
    requires newLastName_len >= 0;
    requires \valid_read(newLastName + (0 .. newLastName_len-1));
    requires newSkills != \null;
    requires newSkills_len >= 0;
    requires \valid_read(newSkills + (0 .. newSkills_len-1));
    requires newPhoto != \null;
    requires newPhoto_len >= 0;
    requires \valid_read(newPhoto + (0 .. newPhoto_len-1));
    assigns \nothing;
*/
UserProfile UpdateUserProfile(UserProfile profile, char* newFirstName, int newFirstName_len, char* newLastName, int newLastName_len, char* newEmail, int newEmail_len, int newCellPhone, char** newSkills, int newSkills_len, char* newPhoto, int newPhoto_len)
{
  profile.firstName = newFirstName;
  profile.lastName = newLastName;
  profile.email = newEmail;
  profile.cellPhone = newCellPhone;
  profile.skills = newSkills;
  profile.userPhoto = newPhoto;
  UserProfile updatedProfile = profile;
  return updatedProfile;
}

/*@
    requires newSkill != \null;
    requires newSkill_len > 0;
    requires \valid_read(newSkill + (0 .. newSkill_len-1));
    assigns \nothing;
*/
void AddSkillToProfile(UserProfile profile, char* newSkill, int newSkill_len)
{
  profile.skills = (profile.skills + 0);
}

/*@
    requires name != \null;
    requires name_len > 0;
    requires \valid_read(name + (0 .. name_len-1));
    requires mediaType != \null;
    requires mediaType_len > 0;
    requires \valid_read(mediaType + (0 .. mediaType_len-1));
    requires mediaUrl != \null;
    requires mediaUrl_len > 0;
    requires \valid_read(mediaUrl + (0 .. mediaUrl_len-1));
    requires userId > 0;
    assigns \nothing;
*/
UserMedia CreateUserMedia(char* name, int name_len, char* mediaType, int mediaType_len, char* mediaUrl, int mediaUrl_len, int userId)
{
  UserMedia media;
  media.name = name;
  media.mediaType = mediaType;
  media.mediaUrl = mediaUrl;
  media.userId = userId;
  return media;
}