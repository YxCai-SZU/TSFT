// Generated C + ACSL

typedef struct {
  char* name;
  char* description;
  char* state;
  int principalMeridianCode;
  int townshipNumber;
  int townshipFraction;
  int rangeNumber;
  int rangeFraction;
  int section;
  int townshipDuplicate;
  int isOnMap;
  char* quadName;
} Cave;

void UpdateLocation(Cave* this, int township, int range, int section);
void SetQuadrangleInfo(Cave* this, int isOnMap, char* quadName, int quadName_len);

/*@
    assigns \nothing;
*/
void Main(void)
{
  Cave cave_obj = {
    .name = "Example Cave",
    .description = "",
    .state = "MO",
    .principalMeridianCode = 5,
    .townshipNumber = 0,
    .townshipFraction = 0,
    .rangeNumber = 0,
    .rangeFraction = 0,
    .section = 0,
    .townshipDuplicate = 0,
    .isOnMap = 0,
    .quadName = ""
  };
  Cave* cave = &cave_obj;
  UpdateLocation(cave, 37, 10, 16);
  SetQuadrangleInfo(cave, 0, "Waynesville", 11);
}

/*@
  predicate Valid(char *name, integer name_len,
                  char *description, integer desc_len,
                  char *state, integer state_len,
                  integer principalMeridianCode,
                  integer townshipNumber,
                  integer townshipFraction,
                  integer rangeNumber,
                  integer rangeFraction,
                  integer section,
                  integer townshipDuplicate) =
    name_len > 0 &&
    desc_len > 0 &&
    state_len == 2 && state[0] == 'M' && state[1] == 'O' &&
    principalMeridianCode == 5 &&
    townshipNumber >= 0 &&
    townshipFraction >= 0 &&
    rangeNumber >= 0 &&
    rangeFraction >= 0 &&
    section >= 0 &&
    townshipDuplicate >= 0;
*/

/*@
    requires township > 0 && range > 0 && section > 0;
    requires section <= 36;
    requires \valid(this);
    requires \valid_read(this->name);
    assigns this->townshipNumber, this->rangeNumber, this->section;
    ensures this->townshipNumber == township;
    ensures this->rangeNumber == range;
    ensures this->section == section;
    ensures this->name == \old(this->name);
*/
void UpdateLocation(Cave* this, int township, int range, int section)
{
  this->townshipNumber = township;
  this->rangeNumber = range;
  this->section = section;
}

/*@
    requires quadName != \null;
    requires quadName_len > 0;
    requires \valid_read(quadName + (0 .. quadName_len-1));
    assigns this->isOnMap, this->quadName;
*/
void SetQuadrangleInfo(Cave* this, int isOnMap, char* quadName, int quadName_len)
{
  this->isOnMap = isOnMap;
  this->quadName = quadName;
}