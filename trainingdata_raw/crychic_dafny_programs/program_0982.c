// Generated C + ACSL
#include <string.h>

typedef struct {
    int dummy;
} Reader;

typedef struct {
    int dummy;
} JsonValue;

int OpenFile(char* filename, int filename_len);
JsonValue ParseJson(void);
int* GetIntents(JsonValue json);

/*@
    assigns \nothing;
*/
void Main(void)
{
  Reader reader;
  int success = OpenFile("intents.json", 13);
  if (success)
  {
    JsonValue jsonData = ParseJson();
    int* intents = GetIntents(jsonData);
    /* unsupported stmt: print "Intents: ", intents, "\n"; */
  }
}

/*@
    requires filename != \null;
    requires filename_len > 0;
    requires \valid_read(filename + (0 .. filename_len-1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int OpenFile(char* filename, int filename_len)
{
  int success = 1;
  /*@ assert success >= 0 && success <= 2147483647; */
  if (success)
  {
    int isOpen = 1;
    /*@ assert isOpen >= 0 && isOpen <= 2147483647; */
    char* contents = "{}";
    /*@ assert contents != \null; */
  }
  return success;
}

/*@
    assigns \nothing;
    ensures \result.dummy == 1;
*/
JsonValue ParseJson(void)
{
  JsonValue result;
  result.dummy = 1;
  return result;
}

/*@
    assigns \nothing;
    ensures \result != \null;
*/
int* GetIntents(JsonValue json)
{
  static int empty[1] = {0};
  return empty;
}