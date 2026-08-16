#include <string.h>

typedef struct {
    char* name;
    int name_len;
    char* version;
    int version_len;
    char* description;
    int description_len;
    char* author;
    int author_len;
    char* authorEmail;
    int authorEmail_len;
    char** modules;
    int modules_len;
} Package;

static Package pkg_instance;

/*@
  requires email_len >= 0;
  requires \valid_read(email + (0 .. email_len - 1));
  assigns \nothing;
  ensures \result == 0 || \result == 1;
  ensures \result == 1 ==> 
    (\exists integer j; 0 < j < email_len - 1 && email[j] == '@');
  ensures \result == 0 ==> 
    (\forall integer j; 0 <= j < email_len ==> 
      !(email[j] == '@' && j > 0 && j < email_len - 1));
*/
int IsValidEmail(char* email, int email_len)
{
    /*@
      loop invariant 0 <= i <= email_len;
      loop invariant \forall integer k; 0 <= k < i ==> 
        !(email[k] == '@' && k > 0 && k < email_len - 1);
      loop assigns i;
      loop variant email_len - i;
    */
    for (int i = 0; i < email_len; i++) {
        if (email[i] == '@' && i > 0 && i < email_len - 1) {
            return 1;
        }
    }
    return 0;
}

/*@
  requires \valid(this);
  requires name_len >= 0 && \valid_read(name + (0 .. name_len - 1));
  requires version_len >= 0 && \valid_read(version + (0 .. version_len - 1));
  requires description_len >= 0 && \valid_read(description + (0 .. description_len - 1));
  requires author_len >= 0 && \valid_read(author + (0 .. author_len - 1));
  requires authorEmail_len >= 0 && \valid_read(authorEmail + (0 .. authorEmail_len - 1));
  requires modules_len >= 0 && \valid_read(modules + (0 .. modules_len - 1));
  assigns this->name, this->name_len, this->version, this->version_len,
          this->description, this->description_len, this->author, this->author_len,
          this->authorEmail, this->authorEmail_len, this->modules, this->modules_len;
  ensures this->name == name;
  ensures this->name_len == name_len;
  ensures this->version == version;
  ensures this->version_len == version_len;
  ensures this->description == description;
  ensures this->description_len == description_len;
  ensures this->author == author;
  ensures this->author_len == author_len;
  ensures this->authorEmail == authorEmail;
  ensures this->authorEmail_len == authorEmail_len;
  ensures this->modules == modules;
  ensures this->modules_len == modules_len;
*/
void Init(Package* this, char* name, int name_len, char* version, int version_len, char* description, int description_len, char* author, int author_len, char* authorEmail, int authorEmail_len, char** modules, int modules_len)
{
    this->name = name;
    this->name_len = name_len;
    this->version = version;
    this->version_len = version_len;
    this->description = description;
    this->description_len = description_len;
    this->author = author;
    this->author_len = author_len;
    this->authorEmail = authorEmail;
    this->authorEmail_len = authorEmail_len;
    this->modules = modules;
    this->modules_len = modules_len;
}

/*@
  requires name_len >= 0 && \valid_read(name + (0 .. name_len - 1));
  requires version_len >= 0 && \valid_read(version + (0 .. version_len - 1));
  requires description_len >= 0 && \valid_read(description + (0 .. description_len - 1));
  requires author_len >= 0 && \valid_read(author + (0 .. author_len - 1));
  requires authorEmail_len >= 0 && \valid_read(authorEmail + (0 .. authorEmail_len - 1));
  requires modules_len >= 0 && \valid_read(modules + (0 .. modules_len - 1));
  assigns pkg_instance;
  ensures \result == 0 || \result == 1;
  ensures \result == 1 ==> name_len > 0 && version_len > 0 && modules_len > 0;
  ensures \result == 0 ==> !(name_len > 0 && version_len > 0 && modules_len > 0);
*/
int Setup(char* name, int name_len, char* version, int version_len, char* description, int description_len, char* author, int author_len, char* authorEmail, int authorEmail_len, char** modules, int modules_len)
{
    if ((name_len > 0) && (version_len > 0) && (modules_len > 0))
    {
        Init(&pkg_instance, name, name_len, version, version_len, description, description_len, author, author_len, authorEmail, authorEmail_len, modules, modules_len);
        return 1;
    }
    return 0;
}

/*@
  requires pkg_instance.authorEmail_len >= 0;
  requires \valid_read(pkg_instance.authorEmail + (0 .. pkg_instance.authorEmail_len - 1));
  assigns \nothing;
  ensures \result == 0 || \result == 1;
*/
int ValidateConfig(void)
{
    int isValid = ((pkg_instance.name_len > 0) && (pkg_instance.version_len > 0) && IsValidEmail(pkg_instance.authorEmail, pkg_instance.authorEmail_len) && (pkg_instance.modules_len > 0));
    return isValid;
}