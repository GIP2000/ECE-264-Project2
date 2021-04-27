// THIS IS THE PROVIDED CODE FOR PROGRAM #2, DSA 1, SPRING 2021

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

// A simple class; each object holds four public fields
class Data {
public:
  string lastName;
  string firstName;
  string ssn;
};

// Load the data from a specified input file
void loadDataList(list<Data *> &l, const string &filename) {

  ifstream input(filename);
  if (!input) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // The first line indicates the size
  string line;
  getline(input, line);
  stringstream ss(line);
  int size;
  ss >> size;

  // Load the data
  for (int i = 0; i < size; i++) {
    getline(input, line);
    stringstream ss2(line);
    Data *pData = new Data();
    ss2 >> pData->lastName >> pData->firstName >> pData->ssn;
    l.push_back(pData);
  }

  input.close();
}

// Output the data to a specified output file
void writeDataList(const list<Data *> &l, const string &filename) {

  ofstream output(filename);
  if (!output) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // Write the size first
  int size = l.size();
  output << size << "\n";

  // Write the data
  for (auto pData:l) {
    output << pData->lastName << " " 
	   << pData->firstName << " " 
	   << pData->ssn << "\n";
  }

  output.close();
}

// Sort the data according to a specified field
// (Implementation of this function will be later in this file)
void sortDataList(list<Data *> &);

// The main function calls routines to get the data, sort the data,
// and output the data. The sort is timed according to CPU time.
int main() {
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;
  list<Data *> theList;
  loadDataList(theList, filename);

  cout << "Data loaded.\n";

  cout << "Executing sort...\n";
  clock_t t1 = clock();
  sortDataList(theList);
  clock_t t2 = clock();
  double timeDiff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;

  cout << "Sort finished. CPU time was " << timeDiff << " seconds.\n";

  cout << "Enter name of output file: ";
  cin >> filename;
  writeDataList(theList, filename);

  return 0;
}

// -------------------------------------------------
// YOU MAY NOT CHANGE OR ADD ANY CODE ABOVE HERE !!!
// -------------------------------------------------
#include<unordered_map>
#include<tuple> 


bool compare(Data * d1, Data * d2); 

class StartAndEnd{
  public:
    list<Data *>::iterator start;
    list<Data *>::iterator end;
};

string orderedLastNames[500] = {"ACOSTA","ADAMS","ADKINS","AGUILAR","AGUIRRE","ALEXANDER","ALLEN","ALVARADO","ALVAREZ","ANDERSON","ANDREWS","ARMSTRONG","ARNOLD","AUSTIN","AVILA","AYALA","BAILEY","BAKER","BALDWIN","BANKS","BARBER","BARKER","BARNES","BARNETT","BARRETT","BARTON","BATES","BECK","BECKER","BELL","BENNETT","BENSON","BERRY","BISHOP","BLACK","BLAIR","BLAKE","BOWEN","BOWMAN","BOYD","BRADLEY","BRADY","BREWER","BROOKS","BROWN","BRYANT","BURGESS","BURKE","BURNS","BURTON","BUSH","BUTLER","BYRD","CABRERA","CALDERON","CALDWELL","CAMACHO","CAMPBELL","CAMPOS","CANNON","CARDENAS","CARLSON","CARPENTER","CARR","CARRILLO","CARROLL","CARTER","CASTANEDA","CASTILLO","CASTRO","CERVANTES","CHAMBERS","CHAN","CHANDLER","CHANG","CHAPMAN","CHAVEZ","CHEN","CHRISTENSEN","CLARK","CLARKE","COHEN","COLE","COLEMAN","COLLINS","COLON","CONTRERAS","COOK","COOPER","CORTEZ","COX","CRAIG","CRAWFORD","CROSS","CRUZ","CUMMINGS","CUNNINGHAM","CURRY","CURTIS","DANIEL","DANIELS","DAVIDSON","DAVIS","DAWSON","DAY","DEAN","DELACRUZ","DELEON","DELGADO","DENNIS","DIAZ","DIXON","DOMINGUEZ","DOUGLAS","DOYLE","DUNCAN","DUNN","DURAN","EDWARDS","ELLIOTT","ELLIS","ERICKSON","ESPINOZA","ESTRADA","EVANS","FARMER","FERGUSON","FERNANDEZ","FIELDS","FIGUEROA","FISCHER","FISHER","FITZGERALD","FLEMING","FLETCHER","FLORES","FORD","FOSTER","FOWLER","FOX","FRANCIS","FRANCO","FRANK","FRANKLIN","FRAZIER","FREEMAN","FUENTES","FULLER","GALLAGHER","GALLEGOS","GARCIA","GARDNER","GARNER","GARRETT","GARZA","GEORGE","GIBSON","GILBERT","GILL","GOMEZ","GONZALES","GONZALEZ","GOODMAN","GOODWIN","GORDON","GRAHAM","GRANT","GRAVES","GRAY","GREEN","GREENE","GREGORY","GRIFFIN","GRIFFITH","GROSS","GUERRA","GUERRERO","GUTIERREZ","GUZMAN","HAIL","HALE","HALL","HAMILTON","HAMMOND","HAMPTON","HANSEN","HANSON","HARDY","HARMON","HARPER","HARRINGTON","HARRIS","HARRISON","HART","HARVEY","HAWKINS","HAYES","HAYNES","HENDERSON","HENRY","HERNANDEZ","HERRERA","HICKS","HIGGINS","HILL","HINES","HODGES","HOFFMAN","HOLLAND","HOLMES","HOLT","HOPKINS","HORTON","HOWARD","HOWELL","HUANG","HUBBARD","HUDSON","HUGHES","HUNT","HUNTER","INGRAM","JACKSON","JACOBS","JAMES","JENKINS","JENNINGS","JENSEN","JIMENEZ","JOHNSON","JOHNSTON","JONES","JORDAN","JOSEPH","JUAREZ","KELLER","KELLEY","KELLY","KENNEDY","KHAN","KIM","KING","KLEIN","KNIGHT","LAMBERT","LANE","LARA","LARSON","LAWRENCE","LAWSON","LE","LEE","LEON","LEONARD","LEWIS","LI","LIN","LITTLE","LIU","LOGAN","LONG","LOPEZ","LOVE","LOWE","LUCAS","LUNA","LYNCH","LYONS","MACK","MALDONADO","MALONE","MANN","MANNING","MARQUEZ","MARSHALL","MARTIN","MARTINEZ","MASON","MATTHEWS","MAXWELL","MAY","MCCARTHY","MCCOY","MCDANIEL","MCDONALD","MCGEE","MCKINNEY","MCLAUGHLIN","MEDINA","MEJIA","MENDEZ","MENDOZA","MEYER","MILES","MILLER","MILLS","MIRANDA","MITCHELL","MOLINA","MONTGOMERY","MONTOYA","MOORE","MORALES","MORAN","MORENO","MORGAN","MORRIS","MORRISON","MOSS","MULLINS","MUNOZ","MURPHY","MURRAY","MYERS","NAVARRO","NEAL","NELSON","NEWMAN","NEWTON","NGUYEN","NICHOLS","NORMAN","NORRIS","NUNEZ","OBRIEN","OCHOA","OCONNOR","OLIVER","OLSON","ORTEGA","ORTIZ","OWENS","PACHECO","PADILLA","PAGE","PALMER","PARK","PARKER","PARKS","PARSONS","PATEL","PATTERSON","PAUL","PAYNE","PEARSON","PENA","PEREZ","PERKINS","PERRY","PERSON","PETERS","PETERSON","PHAM","PHILLIPS","PIERCE","PORTER","POTTER","POWELL","POWERS","PRICE","QUINN","RAMIREZ","RAMOS","RAMSEY","RAY","REED","REESE","REEVES","REID","REYES","REYNOLDS","RHODES","RICE","RICHARDS","RICHARDSON","RILEY","RIOS","RIVAS","RIVERA","ROBBINS","ROBERTS","ROBERTSON","ROBINSON","ROBLES","RODGERS","RODRIGUEZ","ROGERS","ROJAS","ROMAN","ROMERO","ROSALES","ROSE","ROSS","ROWE","RUIZ","RUSSELL","RYAN","SALAZAR","SALINAS","SANCHEZ","SANDERS","SANDOVAL","SANTIAGO","SANTOS","SAUNDERS","SCHMIDT","SCHNEIDER","SCHROEDER","SCHULTZ","SCHWARTZ","SCOTT","SERRANO","SHARP","SHAW","SHELTON","SHERMAN","SILVA","SIMMONS","SIMON","SIMPSON","SIMS","SINGH","SMITH","SNYDER","SOLIS","SOTO","SPENCER","STANLEY","STEELE","STEPHENS","STEVENS","STEVENSON","STEWART","STONE","STRICKLAND","SULLIVAN","SUTTON","SWANSON","TATE","TAYLOR","TERRY","THOMAS","THOMPSON","THORNTON","TODD","TORRES","TOWNSEND","TRAN","TRUJILLO","TUCKER","TURNER","VALDEZ","VALENCIA","VARGAS","VASQUEZ","VAUGHN","VAZQUEZ","VEGA","VELASQUEZ","WADE","WAGNER","WALKER","WALLACE","WALSH","WALTERS","WALTON","WANG","WARD","WARNER","WARREN","WASHINGTON","WATERS","WATKINS","WATSON","WATTS","WEAVER","WEBB","WEBER","WEBSTER","WELCH","WELLS","WEST","WHEELER","WHITE","WILLIAMS","WILLIAMSON","WILLIS","WILSON","WISE","WOLF","WOLFE","WONG","WOOD","WOODS","WRIGHT","WU","YANG","YOUNG","ZHANG","ZIMMERMAN"};
string orderedFirstNames[494] = {"AALIYAH","AARON","ABEL","ABIGAIL","ABRAHAM","ADALINE","ADALYN","ADALYNN","ADAM","ADDISON","ADELINE","ADELYN","ADRIAN","ADRIANA","AIDAN","AIDEN","ALAINA","ALAN","ALANA","ALAYNA","ALEJANDRO","ALEX","ALEXA","ALEXANDER","ALEXANDRA","ALEXIS","ALICE","ALINA","ALIVIA","ALIYAH","ALLISON","ALYSSA","AMARA","AMAYA","AMELIA","AMIR","AMY","ANA","ANASTASIA","ANDREA","ANDRES","ANDREW","ANGEL","ANGELA","ANGELINA","ANNA","ANNABELLE","ANTHONY","ANTONIO","ARABELLA","ARIA","ARIANA","ARIANNA","ARIEL","ARTHUR","ARYA","ASHER","ASHLEY","ASHTON","ATHENA","AUBREE","AUBREY","AUDREY","AUGUST","AURORA","AUSTIN","AUTUMN","AVA","AVERY","AXEL","AYDEN","AYLA","BAILEY","BARRETT","BEAU","BECKETT","BELLA","BENJAMIN","BENNETT","BENTLEY","BLAKE","BRADLEY","BRADY","BRANDON","BRANTLEY","BRAXTON","BRAYDEN","BRIAN","BRIANNA","BRIELLE","BRODY","BROOKE","BROOKLYN","BROOKLYNN","BROOKS","BRYAN","BRYCE","BRYNLEE","BRYSON","CADEN","CALEB","CALLIE","CALVIN","CAMDEN","CAMERON","CAMILA","CARLOS","CAROLINE","CARSON","CARTER","CATHERINE","CAYDEN","CECILIA","CHARLES","CHARLIE","CHARLOTTE","CHASE","CHLOE","CHRISTIAN","CHRISTOPHER","CLAIRE","CLARA","CLAYTON","COLE","COLIN","COLTON","CONNOR","COOPER","CORA","DAISY","DAKOTA","DALEYZA","DAMIAN","DANIEL","DANIELA","DAVID","DAWSON","DEAN","DECLAN","DELANEY","DELILAH","DEREK","DESTINY","DIANA","DIEGO","DOMINIC","DYLAN","EASTON","EDEN","EDWARD","ELEANOR","ELENA","ELI","ELIANA","ELIAS","ELIJAH","ELISE","ELIZA","ELIZABETH","ELLA","ELLIANA","ELLIE","ELLIOT","ELLIOTT","ELOISE","EMERSON","EMERSYN","EMERY","EMILIA","EMILIANO","EMILY","EMMA","EMMANUEL","EMMETT","ERIC","ESTHER","ETHAN","EVA","EVAN","EVELYN","EVERETT","EVERLY","EZEKIEL","EZRA","FAITH","FELIX","FINLEY","FINN","FIONA","GABRIEL","GABRIELLA","GAEL","GAVIN","GENESIS","GENEVIEVE","GEORGE","GEORGIA","GIANNA","GIOVANNI","GRACE","GRACIE","GRAHAM","GRANT","GRAYSON","GREYSON","GRIFFIN","HADLEY","HAILEY","HANNAH","HARLEY","HARMONY","HARPER","HARRISON","HAYDEN","HAZEL","HENRY","HOLDEN","HUDSON","HUNTER","IAN","IRIS","ISAAC","ISABEL","ISABELLA","ISABELLE","ISAIAH","ISLA","ISRAEL","IVAN","IVY","JACE","JACK","JACKSON","JACOB","JADE","JADEN","JAKE","JAMES","JAMESON","JASMINE","JASON","JASPER","JAVIER","JAX","JAXON","JAXSON","JAYCE","JAYDEN","JAYLA","JEREMIAH","JEREMY","JESSE","JESSICA","JESUS","JOANNA","JOCELYN","JOEL","JOHN","JONAH","JONATHAN","JORDAN","JORDYN","JORGE","JOSE","JOSEPH","JOSEPHINE","JOSHUA","JOSIAH","JOSIE","JOSUE","JUAN","JUDAH","JUDE","JULIA","JULIAN","JULIANA","JULIANNA","JULIET","JULIETTE","JUNE","JUSTIN","KADEN","KAI","KAIDEN","KALEB","KARTER","KATHERINE","KAYDEN","KAYLA","KAYLEE","KENDALL","KENNEDY","KENNETH","KEVIN","KHLOE","KILLIAN","KIMBERLY","KING","KINGSTON","KINSLEY","KNOX","KYLE","KYLIE","KYRIE","LAILA","LANDON","LAUREN","LAYLA","LEAH","LEILA","LEILANI","LEO","LEON","LEONARDO","LEVI","LIAM","LILA","LILIANA","LILLIAN","LILLY","LILY","LINCOLN","LOGAN","LOLA","LONDON","LONDYN","LORENZO","LUCA","LUCAS","LUCIA","LUCY","LUIS","LUKAS","LUKE","LUNA","LYDIA","LYLA","MACKENZIE","MADDOX","MADELINE","MADELYN","MADISON","MAGGIE","MAKAYLA","MALACHI","MALIA","MARCUS","MARGARET","MARIA","MARIAH","MARK","MARLEY","MARY","MASON","MATEO","MATIAS","MATTEO","MATTHEW","MAVERICK","MAX","MAXIMUS","MAXWELL","MAYA","MCKENZIE","MELANIE","MELODY","MESSIAH","MIA","MICAH","MICHAEL","MICHELLE","MIGUEL","MILA","MILES","MILO","MOLLY","MORGAN","MYA","MYLES","NAOMI","NATALIA","NATALIE","NATHAN","NATHANIEL","NEVAEH","NICHOLAS","NICOLAS","NICOLE","NOAH","NOELLE","NOLAN","NORA","NORAH","NOVA","OLIVER","OLIVIA","OMAR","OSCAR","OWEN","PAIGE","PAISLEY","PARKER","PATRICK","PAUL","PAXTON","PAYTON","PENELOPE","PETER","PEYTON","PIPER","PRESLEY","PRESTON","QUINN","RACHEL","RAELYNN","REAGAN","REBECCA","REESE","REMI","REMINGTON","RHETT","RICHARD","RILEY","RIVER","ROBERT","ROMAN","ROSALIE","ROSE","ROWAN","RUBY","RYAN","RYDER","RYKER","RYLEE","RYLEIGH","SADIE","SAMANTHA","SAMUEL","SANTIAGO","SARA","SARAH","SAVANNAH","SAWYER","SCARLETT","SEBASTIAN","SELENA","SERENITY","SIENNA","SILAS","SKYLAR","SLOANE","SOFIA","SOPHIA","SOPHIE","STELLA","STEVEN","SUMMER","SYDNEY","TAYLOR","TEAGAN","TESSA","THEODORE","THIAGO","THOMAS","TIMOTHY","TRINITY","TRISTAN","TUCKER","TYLER","VALENTINA","VALERIA","VALERIE","VANESSA","VICTOR","VICTORIA","VINCENT","VIOLET","VIVIAN","WAYLON","WESLEY","WESTON","WILLIAM","WILLOW","WYATT","XANDER","XAVIER","XIMENA","ZACHARY","ZANDER","ZANE","ZAYDEN","ZION","ZOE","ZOEY"};
unordered_map<string,list<Data *>> firstNameBuckets = {{"AALIYAH", {}},{"AARON", {}},{"ABEL", {}},{"ABIGAIL", {}},{"ABRAHAM", {}},{"ADALINE", {}},{"ADALYN", {}},{"ADALYNN", {}},{"ADAM", {}},{"ADDISON", {}},{"ADELINE", {}},{"ADELYN", {}},{"ADRIAN", {}},{"ADRIANA", {}},{"AIDAN", {}},{"AIDEN", {}},{"ALAINA", {}},{"ALAN", {}},{"ALANA", {}},{"ALAYNA", {}},{"ALEJANDRO", {}},{"ALEX", {}},{"ALEXA", {}},{"ALEXANDER", {}},{"ALEXANDRA", {}},{"ALEXIS", {}},{"ALICE", {}},{"ALINA", {}},{"ALIVIA", {}},{"ALIYAH", {}},{"ALLISON", {}},{"ALYSSA", {}},{"AMARA", {}},{"AMAYA", {}},{"AMELIA", {}},{"AMIR", {}},{"AMY", {}},{"ANA", {}},{"ANASTASIA", {}},{"ANDREA", {}},{"ANDRES", {}},{"ANDREW", {}},{"ANGEL", {}},{"ANGELA", {}},{"ANGELINA", {}},{"ANNA", {}},{"ANNABELLE", {}},{"ANTHONY", {}},{"ANTONIO", {}},{"ARABELLA", {}},{"ARIA", {}},{"ARIANA", {}},{"ARIANNA", {}},{"ARIEL", {}},{"ARTHUR", {}},{"ARYA", {}},{"ASHER", {}},{"ASHLEY", {}},{"ASHTON", {}},{"ATHENA", {}},{"AUBREE", {}},{"AUBREY", {}},{"AUDREY", {}},{"AUGUST", {}},{"AURORA", {}},{"AUSTIN", {}},{"AUTUMN", {}},{"AVA", {}},{"AVERY", {}},{"AXEL", {}},{"AYDEN", {}},{"AYLA", {}},{"BAILEY", {}},{"BARRETT", {}},{"BEAU", {}},{"BECKETT", {}},{"BELLA", {}},{"BENJAMIN", {}},{"BENNETT", {}},{"BENTLEY", {}},{"BLAKE", {}},{"BRADLEY", {}},{"BRADY", {}},{"BRANDON", {}},{"BRANTLEY", {}},{"BRAXTON", {}},{"BRAYDEN", {}},{"BRIAN", {}},{"BRIANNA", {}},{"BRIELLE", {}},{"BRODY", {}},{"BROOKE", {}},{"BROOKLYN", {}},{"BROOKLYNN", {}},{"BROOKS", {}},{"BRYAN", {}},{"BRYCE", {}},{"BRYNLEE", {}},{"BRYSON", {}},{"CADEN", {}},{"CALEB", {}},{"CALLIE", {}},{"CALVIN", {}},{"CAMDEN", {}},{"CAMERON", {}},{"CAMILA", {}},{"CARLOS", {}},{"CAROLINE", {}},{"CARSON", {}},{"CARTER", {}},{"CATHERINE", {}},{"CAYDEN", {}},{"CECILIA", {}},{"CHARLES", {}},{"CHARLIE", {}},{"CHARLOTTE", {}},{"CHASE", {}},{"CHLOE", {}},{"CHRISTIAN", {}},{"CHRISTOPHER", {}},{"CLAIRE", {}},{"CLARA", {}},{"CLAYTON", {}},{"COLE", {}},{"COLIN", {}},{"COLTON", {}},{"CONNOR", {}},{"COOPER", {}},{"CORA", {}},{"DAISY", {}},{"DAKOTA", {}},{"DALEYZA", {}},{"DAMIAN", {}},{"DANIEL", {}},{"DANIELA", {}},{"DAVID", {}},{"DAWSON", {}},{"DEAN", {}},{"DECLAN", {}},{"DELANEY", {}},{"DELILAH", {}},{"DEREK", {}},{"DESTINY", {}},{"DIANA", {}},{"DIEGO", {}},{"DOMINIC", {}},{"DYLAN", {}},{"EASTON", {}},{"EDEN", {}},{"EDWARD", {}},{"ELEANOR", {}},{"ELENA", {}},{"ELI", {}},{"ELIANA", {}},{"ELIAS", {}},{"ELIJAH", {}},{"ELISE", {}},{"ELIZA", {}},{"ELIZABETH", {}},{"ELLA", {}},{"ELLIANA", {}},{"ELLIE", {}},{"ELLIOT", {}},{"ELLIOTT", {}},{"ELOISE", {}},{"EMERSON", {}},{"EMERSYN", {}},{"EMERY", {}},{"EMILIA", {}},{"EMILIANO", {}},{"EMILY", {}},{"EMMA", {}},{"EMMANUEL", {}},{"EMMETT", {}},{"ERIC", {}},{"ESTHER", {}},{"ETHAN", {}},{"EVA", {}},{"EVAN", {}},{"EVELYN", {}},{"EVERETT", {}},{"EVERLY", {}},{"EZEKIEL", {}},{"EZRA", {}},{"FAITH", {}},{"FELIX", {}},{"FINLEY", {}},{"FINN", {}},{"FIONA", {}},{"GABRIEL", {}},{"GABRIELLA", {}},{"GAEL", {}},{"GAVIN", {}},{"GENESIS", {}},{"GENEVIEVE", {}},{"GEORGE", {}},{"GEORGIA", {}},{"GIANNA", {}},{"GIOVANNI", {}},{"GRACE", {}},{"GRACIE", {}},{"GRAHAM", {}},{"GRANT", {}},{"GRAYSON", {}},{"GREYSON", {}},{"GRIFFIN", {}},{"HADLEY", {}},{"HAILEY", {}},{"HANNAH", {}},{"HARLEY", {}},{"HARMONY", {}},{"HARPER", {}},{"HARRISON", {}},{"HAYDEN", {}},{"HAZEL", {}},{"HENRY", {}},{"HOLDEN", {}},{"HUDSON", {}},{"HUNTER", {}},{"IAN", {}},{"IRIS", {}},{"ISAAC", {}},{"ISABEL", {}},{"ISABELLA", {}},{"ISABELLE", {}},{"ISAIAH", {}},{"ISLA", {}},{"ISRAEL", {}},{"IVAN", {}},{"IVY", {}},{"JACE", {}},{"JACK", {}},{"JACKSON", {}},{"JACOB", {}},{"JADE", {}},{"JADEN", {}},{"JAKE", {}},{"JAMES", {}},{"JAMESON", {}},{"JASMINE", {}},{"JASON", {}},{"JASPER", {}},{"JAVIER", {}},{"JAX", {}},{"JAXON", {}},{"JAXSON", {}},{"JAYCE", {}},{"JAYDEN", {}},{"JAYLA", {}},{"JEREMIAH", {}},{"JEREMY", {}},{"JESSE", {}},{"JESSICA", {}},{"JESUS", {}},{"JOANNA", {}},{"JOCELYN", {}},{"JOEL", {}},{"JOHN", {}},{"JONAH", {}},{"JONATHAN", {}},{"JORDAN", {}},{"JORDYN", {}},{"JORGE", {}},{"JOSE", {}},{"JOSEPH", {}},{"JOSEPHINE", {}},{"JOSHUA", {}},{"JOSIAH", {}},{"JOSIE", {}},{"JOSUE", {}},{"JUAN", {}},{"JUDAH", {}},{"JUDE", {}},{"JULIA", {}},{"JULIAN", {}},{"JULIANA", {}},{"JULIANNA", {}},{"JULIET", {}},{"JULIETTE", {}},{"JUNE", {}},{"JUSTIN", {}},{"KADEN", {}},{"KAI", {}},{"KAIDEN", {}},{"KALEB", {}},{"KARTER", {}},{"KATHERINE", {}},{"KAYDEN", {}},{"KAYLA", {}},{"KAYLEE", {}},{"KENDALL", {}},{"KENNEDY", {}},{"KENNETH", {}},{"KEVIN", {}},{"KHLOE", {}},{"KILLIAN", {}},{"KIMBERLY", {}},{"KING", {}},{"KINGSTON", {}},{"KINSLEY", {}},{"KNOX", {}},{"KYLE", {}},{"KYLIE", {}},{"KYRIE", {}},{"LAILA", {}},{"LANDON", {}},{"LAUREN", {}},{"LAYLA", {}},{"LEAH", {}},{"LEILA", {}},{"LEILANI", {}},{"LEO", {}},{"LEON", {}},{"LEONARDO", {}},{"LEVI", {}},{"LIAM", {}},{"LILA", {}},{"LILIANA", {}},{"LILLIAN", {}},{"LILLY", {}},{"LILY", {}},{"LINCOLN", {}},{"LOGAN", {}},{"LOLA", {}},{"LONDON", {}},{"LONDYN", {}},{"LORENZO", {}},{"LUCA", {}},{"LUCAS", {}},{"LUCIA", {}},{"LUCY", {}},{"LUIS", {}},{"LUKAS", {}},{"LUKE", {}},{"LUNA", {}},{"LYDIA", {}},{"LYLA", {}},{"MACKENZIE", {}},{"MADDOX", {}},{"MADELINE", {}},{"MADELYN", {}},{"MADISON", {}},{"MAGGIE", {}},{"MAKAYLA", {}},{"MALACHI", {}},{"MALIA", {}},{"MARCUS", {}},{"MARGARET", {}},{"MARIA", {}},{"MARIAH", {}},{"MARK", {}},{"MARLEY", {}},{"MARY", {}},{"MASON", {}},{"MATEO", {}},{"MATIAS", {}},{"MATTEO", {}},{"MATTHEW", {}},{"MAVERICK", {}},{"MAX", {}},{"MAXIMUS", {}},{"MAXWELL", {}},{"MAYA", {}},{"MCKENZIE", {}},{"MELANIE", {}},{"MELODY", {}},{"MESSIAH", {}},{"MIA", {}},{"MICAH", {}},{"MICHAEL", {}},{"MICHELLE", {}},{"MIGUEL", {}},{"MILA", {}},{"MILES", {}},{"MILO", {}},{"MOLLY", {}},{"MORGAN", {}},{"MYA", {}},{"MYLES", {}},{"NAOMI", {}},{"NATALIA", {}},{"NATALIE", {}},{"NATHAN", {}},{"NATHANIEL", {}},{"NEVAEH", {}},{"NICHOLAS", {}},{"NICOLAS", {}},{"NICOLE", {}},{"NOAH", {}},{"NOELLE", {}},{"NOLAN", {}},{"NORA", {}},{"NORAH", {}},{"NOVA", {}},{"OLIVER", {}},{"OLIVIA", {}},{"OMAR", {}},{"OSCAR", {}},{"OWEN", {}},{"PAIGE", {}},{"PAISLEY", {}},{"PARKER", {}},{"PATRICK", {}},{"PAUL", {}},{"PAXTON", {}},{"PAYTON", {}},{"PENELOPE", {}},{"PETER", {}},{"PEYTON", {}},{"PIPER", {}},{"PRESLEY", {}},{"PRESTON", {}},{"QUINN", {}},{"RACHEL", {}},{"RAELYNN", {}},{"REAGAN", {}},{"REBECCA", {}},{"REESE", {}},{"REMI", {}},{"REMINGTON", {}},{"RHETT", {}},{"RICHARD", {}},{"RILEY", {}},{"RIVER", {}},{"ROBERT", {}},{"ROMAN", {}},{"ROSALIE", {}},{"ROSE", {}},{"ROWAN", {}},{"RUBY", {}},{"RYAN", {}},{"RYDER", {}},{"RYKER", {}},{"RYLEE", {}},{"RYLEIGH", {}},{"SADIE", {}},{"SAMANTHA", {}},{"SAMUEL", {}},{"SANTIAGO", {}},{"SARA", {}},{"SARAH", {}},{"SAVANNAH", {}},{"SAWYER", {}},{"SCARLETT", {}},{"SEBASTIAN", {}},{"SELENA", {}},{"SERENITY", {}},{"SIENNA", {}},{"SILAS", {}},{"SKYLAR", {}},{"SLOANE", {}},{"SOFIA", {}},{"SOPHIA", {}},{"SOPHIE", {}},{"STELLA", {}},{"STEVEN", {}},{"SUMMER", {}},{"SYDNEY", {}},{"TAYLOR", {}},{"TEAGAN", {}},{"TESSA", {}},{"THEODORE", {}},{"THIAGO", {}},{"THOMAS", {}},{"TIMOTHY", {}},{"TRINITY", {}},{"TRISTAN", {}},{"TUCKER", {}},{"TYLER", {}},{"VALENTINA", {}},{"VALERIA", {}},{"VALERIE", {}},{"VANESSA", {}},{"VICTOR", {}},{"VICTORIA", {}},{"VINCENT", {}},{"VIOLET", {}},{"VIVIAN", {}},{"WAYLON", {}},{"WESLEY", {}},{"WESTON", {}},{"WILLIAM", {}},{"WILLOW", {}},{"WYATT", {}},{"XANDER", {}},{"XAVIER", {}},{"XIMENA", {}},{"ZACHARY", {}},{"ZANDER", {}},{"ZANE", {}},{"ZAYDEN", {}},{"ZION", {}},{"ZOE", {}},{"ZOEY", {}}};
unordered_map<string,list<Data *>> lastNameBuckets = {{"ACOSTA",{}},{"ADAMS",{}},{"ADKINS",{}},{"AGUILAR",{}},{"AGUIRRE",{}},{"ALEXANDER",{}},{"ALLEN",{}},{"ALVARADO",{}},{"ALVAREZ",{}},{"ANDERSON",{}},{"ANDREWS",{}},{"ARMSTRONG",{}},{"ARNOLD",{}},{"AUSTIN",{}},{"AVILA",{}},{"AYALA",{}},{"BAILEY",{}},{"BAKER",{}},{"BALDWIN",{}},{"BANKS",{}},{"BARBER",{}},{"BARKER",{}},{"BARNES",{}},{"BARNETT",{}},{"BARRETT",{}},{"BARTON",{}},{"BATES",{}},{"BECK",{}},{"BECKER",{}},{"BELL",{}},{"BENNETT",{}},{"BENSON",{}},{"BERRY",{}},{"BISHOP",{}},{"BLACK",{}},{"BLAIR",{}},{"BLAKE",{}},{"BOWEN",{}},{"BOWMAN",{}},{"BOYD",{}},{"BRADLEY",{}},{"BRADY",{}},{"BREWER",{}},{"BROOKS",{}},{"BROWN",{}},{"BRYANT",{}},{"BURGESS",{}},{"BURKE",{}},{"BURNS",{}},{"BURTON",{}},{"BUSH",{}},{"BUTLER",{}},{"BYRD",{}},{"CABRERA",{}},{"CALDERON",{}},{"CALDWELL",{}},{"CAMACHO",{}},{"CAMPBELL",{}},{"CAMPOS",{}},{"CANNON",{}},{"CARDENAS",{}},{"CARLSON",{}},{"CARPENTER",{}},{"CARR",{}},{"CARRILLO",{}},{"CARROLL",{}},{"CARTER",{}},{"CASTANEDA",{}},{"CASTILLO",{}},{"CASTRO",{}},{"CERVANTES",{}},{"CHAMBERS",{}},{"CHAN",{}},{"CHANDLER",{}},{"CHANG",{}},{"CHAPMAN",{}},{"CHAVEZ",{}},{"CHEN",{}},{"CHRISTENSEN",{}},{"CLARK",{}},{"CLARKE",{}},{"COHEN",{}},{"COLE",{}},{"COLEMAN",{}},{"COLLINS",{}},{"COLON",{}},{"CONTRERAS",{}},{"COOK",{}},{"COOPER",{}},{"CORTEZ",{}},{"COX",{}},{"CRAIG",{}},{"CRAWFORD",{}},{"CROSS",{}},{"CRUZ",{}},{"CUMMINGS",{}},{"CUNNINGHAM",{}},{"CURRY",{}},{"CURTIS",{}},{"DANIEL",{}},{"DANIELS",{}},{"DAVIDSON",{}},{"DAVIS",{}},{"DAWSON",{}},{"DAY",{}},{"DEAN",{}},{"DELACRUZ",{}},{"DELEON",{}},{"DELGADO",{}},{"DENNIS",{}},{"DIAZ",{}},{"DIXON",{}},{"DOMINGUEZ",{}},{"DOUGLAS",{}},{"DOYLE",{}},{"DUNCAN",{}},{"DUNN",{}},{"DURAN",{}},{"EDWARDS",{}},{"ELLIOTT",{}},{"ELLIS",{}},{"ERICKSON",{}},{"ESPINOZA",{}},{"ESTRADA",{}},{"EVANS",{}},{"FARMER",{}},{"FERGUSON",{}},{"FERNANDEZ",{}},{"FIELDS",{}},{"FIGUEROA",{}},{"FISCHER",{}},{"FISHER",{}},{"FITZGERALD",{}},{"FLEMING",{}},{"FLETCHER",{}},{"FLORES",{}},{"FORD",{}},{"FOSTER",{}},{"FOWLER",{}},{"FOX",{}},{"FRANCIS",{}},{"FRANCO",{}},{"FRANK",{}},{"FRANKLIN",{}},{"FRAZIER",{}},{"FREEMAN",{}},{"FUENTES",{}},{"FULLER",{}},{"GALLAGHER",{}},{"GALLEGOS",{}},{"GARCIA",{}},{"GARDNER",{}},{"GARNER",{}},{"GARRETT",{}},{"GARZA",{}},{"GEORGE",{}},{"GIBSON",{}},{"GILBERT",{}},{"GILL",{}},{"GOMEZ",{}},{"GONZALES",{}},{"GONZALEZ",{}},{"GOODMAN",{}},{"GOODWIN",{}},{"GORDON",{}},{"GRAHAM",{}},{"GRANT",{}},{"GRAVES",{}},{"GRAY",{}},{"GREEN",{}},{"GREENE",{}},{"GREGORY",{}},{"GRIFFIN",{}},{"GRIFFITH",{}},{"GROSS",{}},{"GUERRA",{}},{"GUERRERO",{}},{"GUTIERREZ",{}},{"GUZMAN",{}},{"HAIL",{}},{"HALE",{}},{"HALL",{}},{"HAMILTON",{}},{"HAMMOND",{}},{"HAMPTON",{}},{"HANSEN",{}},{"HANSON",{}},{"HARDY",{}},{"HARMON",{}},{"HARPER",{}},{"HARRINGTON",{}},{"HARRIS",{}},{"HARRISON",{}},{"HART",{}},{"HARVEY",{}},{"HAWKINS",{}},{"HAYES",{}},{"HAYNES",{}},{"HENDERSON",{}},{"HENRY",{}},{"HERNANDEZ",{}},{"HERRERA",{}},{"HICKS",{}},{"HIGGINS",{}},{"HILL",{}},{"HINES",{}},{"HODGES",{}},{"HOFFMAN",{}},{"HOLLAND",{}},{"HOLMES",{}},{"HOLT",{}},{"HOPKINS",{}},{"HORTON",{}},{"HOWARD",{}},{"HOWELL",{}},{"HUANG",{}},{"HUBBARD",{}},{"HUDSON",{}},{"HUGHES",{}},{"HUNT",{}},{"HUNTER",{}},{"INGRAM",{}},{"JACKSON",{}},{"JACOBS",{}},{"JAMES",{}},{"JENKINS",{}},{"JENNINGS",{}},{"JENSEN",{}},{"JIMENEZ",{}},{"JOHNSON",{}},{"JOHNSTON",{}},{"JONES",{}},{"JORDAN",{}},{"JOSEPH",{}},{"JUAREZ",{}},{"KELLER",{}},{"KELLEY",{}},{"KELLY",{}},{"KENNEDY",{}},{"KHAN",{}},{"KIM",{}},{"KING",{}},{"KLEIN",{}},{"KNIGHT",{}},{"LAMBERT",{}},{"LANE",{}},{"LARA",{}},{"LARSON",{}},{"LAWRENCE",{}},{"LAWSON",{}},{"LE",{}},{"LEE",{}},{"LEON",{}},{"LEONARD",{}},{"LEWIS",{}},{"LI",{}},{"LIN",{}},{"LITTLE",{}},{"LIU",{}},{"LOGAN",{}},{"LONG",{}},{"LOPEZ",{}},{"LOVE",{}},{"LOWE",{}},{"LUCAS",{}},{"LUNA",{}},{"LYNCH",{}},{"LYONS",{}},{"MACK",{}},{"MALDONADO",{}},{"MALONE",{}},{"MANN",{}},{"MANNING",{}},{"MARQUEZ",{}},{"MARSHALL",{}},{"MARTIN",{}},{"MARTINEZ",{}},{"MASON",{}},{"MATTHEWS",{}},{"MAXWELL",{}},{"MAY",{}},{"MCCARTHY",{}},{"MCCOY",{}},{"MCDANIEL",{}},{"MCDONALD",{}},{"MCGEE",{}},{"MCKINNEY",{}},{"MCLAUGHLIN",{}},{"MEDINA",{}},{"MEJIA",{}},{"MENDEZ",{}},{"MENDOZA",{}},{"MEYER",{}},{"MILES",{}},{"MILLER",{}},{"MILLS",{}},{"MIRANDA",{}},{"MITCHELL",{}},{"MOLINA",{}},{"MONTGOMERY",{}},{"MONTOYA",{}},{"MOORE",{}},{"MORALES",{}},{"MORAN",{}},{"MORENO",{}},{"MORGAN",{}},{"MORRIS",{}},{"MORRISON",{}},{"MOSS",{}},{"MULLINS",{}},{"MUNOZ",{}},{"MURPHY",{}},{"MURRAY",{}},{"MYERS",{}},{"NAVARRO",{}},{"NEAL",{}},{"NELSON",{}},{"NEWMAN",{}},{"NEWTON",{}},{"NGUYEN",{}},{"NICHOLS",{}},{"NORMAN",{}},{"NORRIS",{}},{"NUNEZ",{}},{"OBRIEN",{}},{"OCHOA",{}},{"OCONNOR",{}},{"OLIVER",{}},{"OLSON",{}},{"ORTEGA",{}},{"ORTIZ",{}},{"OWENS",{}},{"PACHECO",{}},{"PADILLA",{}},{"PAGE",{}},{"PALMER",{}},{"PARK",{}},{"PARKER",{}},{"PARKS",{}},{"PARSONS",{}},{"PATEL",{}},{"PATTERSON",{}},{"PAUL",{}},{"PAYNE",{}},{"PEARSON",{}},{"PENA",{}},{"PEREZ",{}},{"PERKINS",{}},{"PERRY",{}},{"PERSON",{}},{"PETERS",{}},{"PETERSON",{}},{"PHAM",{}},{"PHILLIPS",{}},{"PIERCE",{}},{"PORTER",{}},{"POTTER",{}},{"POWELL",{}},{"POWERS",{}},{"PRICE",{}},{"QUINN",{}},{"RAMIREZ",{}},{"RAMOS",{}},{"RAMSEY",{}},{"RAY",{}},{"REED",{}},{"REESE",{}},{"REEVES",{}},{"REID",{}},{"REYES",{}},{"REYNOLDS",{}},{"RHODES",{}},{"RICE",{}},{"RICHARDS",{}},{"RICHARDSON",{}},{"RILEY",{}},{"RIOS",{}},{"RIVAS",{}},{"RIVERA",{}},{"ROBBINS",{}},{"ROBERTS",{}},{"ROBERTSON",{}},{"ROBINSON",{}},{"ROBLES",{}},{"RODGERS",{}},{"RODRIGUEZ",{}},{"ROGERS",{}},{"ROJAS",{}},{"ROMAN",{}},{"ROMERO",{}},{"ROSALES",{}},{"ROSE",{}},{"ROSS",{}},{"ROWE",{}},{"RUIZ",{}},{"RUSSELL",{}},{"RYAN",{}},{"SALAZAR",{}},{"SALINAS",{}},{"SANCHEZ",{}},{"SANDERS",{}},{"SANDOVAL",{}},{"SANTIAGO",{}},{"SANTOS",{}},{"SAUNDERS",{}},{"SCHMIDT",{}},{"SCHNEIDER",{}},{"SCHROEDER",{}},{"SCHULTZ",{}},{"SCHWARTZ",{}},{"SCOTT",{}},{"SERRANO",{}},{"SHARP",{}},{"SHAW",{}},{"SHELTON",{}},{"SHERMAN",{}},{"SILVA",{}},{"SIMMONS",{}},{"SIMON",{}},{"SIMPSON",{}},{"SIMS",{}},{"SINGH",{}},{"SMITH",{}},{"SNYDER",{}},{"SOLIS",{}},{"SOTO",{}},{"SPENCER",{}},{"STANLEY",{}},{"STEELE",{}},{"STEPHENS",{}},{"STEVENS",{}},{"STEVENSON",{}},{"STEWART",{}},{"STONE",{}},{"STRICKLAND",{}},{"SULLIVAN",{}},{"SUTTON",{}},{"SWANSON",{}},{"TATE",{}},{"TAYLOR",{}},{"TERRY",{}},{"THOMAS",{}},{"THOMPSON",{}},{"THORNTON",{}},{"TODD",{}},{"TORRES",{}},{"TOWNSEND",{}},{"TRAN",{}},{"TRUJILLO",{}},{"TUCKER",{}},{"TURNER",{}},{"VALDEZ",{}},{"VALENCIA",{}},{"VARGAS",{}},{"VASQUEZ",{}},{"VAUGHN",{}},{"VAZQUEZ",{}},{"VEGA",{}},{"VELASQUEZ",{}},{"WADE",{}},{"WAGNER",{}},{"WALKER",{}},{"WALLACE",{}},{"WALSH",{}},{"WALTERS",{}},{"WALTON",{}},{"WANG",{}},{"WARD",{}},{"WARNER",{}},{"WARREN",{}},{"WASHINGTON",{}},{"WATERS",{}},{"WATKINS",{}},{"WATSON",{}},{"WATTS",{}},{"WEAVER",{}},{"WEBB",{}},{"WEBER",{}},{"WEBSTER",{}},{"WELCH",{}},{"WELLS",{}},{"WEST",{}},{"WHEELER",{}},{"WHITE",{}},{"WILLIAMS",{}},{"WILLIAMSON",{}},{"WILLIS",{}},{"WILSON",{}},{"WISE",{}},{"WOLF",{}},{"WOLFE",{}},{"WONG",{}},{"WOOD",{}},{"WOODS",{}},{"WRIGHT",{}},{"WU",{}},{"YANG",{}},{"YOUNG",{}},{"ZHANG",{}},{"ZIMMERMAN",{}},};
// You may add global variables, functions, and/or
// class defintions here if you wish.

string removeDashSSN(string ssn){
  return ssn.substr(0,3) + ssn.substr(4,2) + ssn.substr(8); 
}


int convertSSNToInt(string ssn){
  ssn = removeDashSSN(ssn); 
  return stoi(ssn); 
}

bool checkIfSortedSSN(list<Data *> &l){
  for(list<Data *>::iterator it = l.begin(); it != l.end();++it){
    list<Data *>::iterator nextIt = it; 
    ++nextIt;
    if(nextIt == l.end()) return true; 
    if(convertSSNToInt((*it)->ssn) > convertSSNToInt((*nextIt)->ssn)) return false; 
  } return true; 
}

list<Data *> byte0arr[256] = {{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{}}; 
list<Data *> byte1arr[256] = {{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{}}; 
list<Data *> byte2arr[256] = {{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{}}; 
list<Data *> byte3arr[256] = {{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{}}; 



void radixByteWiseSort(list<Data *> &l){


  for(auto data: l){
    string ssn = data->ssn;
    char charArr[9]= {ssn[0] , ssn[1] , ssn[2] , ssn[4] , ssn[5] , ssn[7] , ssn[8] , ssn[9] , ssn[10]};
    unsigned int number = stol(charArr);
    unsigned char byte0 = (number) & 0xFFu; 
    // unsigned char byte1 = (number >> 8u) & 0xFFu; 
    // unsigned char byte2 = (number >> 16u) & 0xFFu; 
    // unsigned char byte3 = (number >> 24u) & 0xFFu; 
    // cout << (unsigned int)byte1 << endl; 
    // byte0arr[(unsigned int)byte0].push_back(data);
    // byte1arr[(unsigned int)byte1].push_back(data);
    // byte2arr[(unsigned int)byte2].push_back(data);
    byte0arr[(unsigned int)byte0].push_back(data);
    // (currentbyteArrPtr + (unsigned int)(byte1))->push_back(data); 

  }
  list<Data *>::iterator it = l.begin(); 
  for(int i = 0; i < 256; i++){
    list<Data *> innerList= byte0arr[i]; 
    innerList.sort(compare); 
    for(auto data: innerList){
      *it = data;
      ++it; 
    }
  }

  





  
}




void radixSSNSort(list<Data *> &l, list<Data *>::iterator start,list<Data *>::iterator end,int digit = 0){ //0-7 inclusive 
  if(digit > 7) return (void)"";
  list<Data *> bins[10]; 
  for(list<Data *>::iterator it = start; it !=end; ++it){
    bins[(removeDashSSN((*it)->ssn))[digit] -'0'].push_back(*it); 
  }
  list<Data *>::iterator it = start;
  for(int j = 0; j<10; j++){
    list<Data *> innerList = bins[j]; 
    if(innerList.size() > 1)
      radixSSNSort(innerList,innerList.begin(),innerList.end(),digit+1); 
    for (auto data: innerList){
      *it = data; 
      ++it; 
    }
    
  }
  
}



void radixSSNSort(list<Data *> &l,int digit = 0){ //0-7 inclusive 
  auto start = l.begin();
  auto end = l.end(); 
  if(digit > 7) return (void)"";
  list<Data *> bins[10]; 
  for(list<Data *>::iterator it = start; it !=end; ++it){
    bins[(removeDashSSN((*it)->ssn))[digit] -'0'].push_back(*it); 
  }
  list<Data *>::iterator it = start;
  for(int j = 0; j<10; ++j){
    list<Data *> innerList = bins[j]; 
    if(innerList.size() > 1)
      radixSSNSort(innerList,digit+1); 
    for (auto data: innerList){
      *it = data; 
      ++it; 
    }
    
  }
  
}




tuple<bool,bool, list<StartAndEnd*>> checkIfSorted(list<Data *> &l){
  bool allSameBroken = false; 
  bool fAndLSortedBroken = false; 
  list<Data *>::iterator start = l.begin();
  list<StartAndEnd *> stes; 
  for(list<Data *>::iterator it = l.begin(); it != l.end();++it){
    if(allSameBroken && fAndLSortedBroken) return {!allSameBroken,!fAndLSortedBroken,stes}; 
    if(next(it) == l.end()) break; 
    if(!fAndLSortedBroken && (*it)->lastName.compare((*next(it))->lastName) > 0 && (*it)->firstName.compare((*next(it))->firstName) > 0) fAndLSortedBroken = true; 
    if((*it)->lastName != (*next(it))->lastName && (*it)->firstName != (*next(it))->firstName) {
      allSameBroken = true;
      StartAndEnd * stae = new StartAndEnd(); 
      stae->start = start;
      stae->end = it; 
      stes.push_back(stae);
      start = it; 
    }
  }
  return {!allSameBroken,!fAndLSortedBroken,stes}; 
  

}

void firstNameSort(list<Data *> &l){

  for(auto data: l){  // this should give me worst case O(nlog(n)) and average case O(n)
    // cout << data->lastName << "\n"; 
    firstNameBuckets[data->firstName].push_back(data); 
  }
  list<Data *>::iterator it = l.begin();
  for(auto name: orderedFirstNames){
      list<Data *> innerList = firstNameBuckets[name];
      switch(innerList.size()) {
          case 0: continue;
          case 1: *it = innerList.front();++it; continue; 
          default: for(auto data: innerList){ *it = data; ++it;}; continue; 
      }
  }
}

bool compare(Data* first, Data* second) {
	int l = strcmp(first->lastName.c_str(), second->lastName.c_str());
	if (l != 0)
		return l < 0;
	int f = strcmp(first->firstName.c_str(), second->firstName.c_str());
	if (f != 0)
		return f < 0;
	return strcmp(first->ssn.c_str(), second->ssn.c_str()) < 0;
}

void sortDataList(list<Data *> &l) {
  // Fill this in
  radixByteWiseSort(l); 
  // l.sort(compare); 

  // auto [allSame,sorted,indexes] = checkIfSorted(l); 
  // if(allSame){l.sort(compare);/*radixSSNSort(l);*/ return(void)"";}
  // if(sorted){
  //   l.sort(compare);
  //   // for(auto data:indexes)
  //   //   radixSSNSort(l,data->start,data->end); 
  //   return(void)"";
  // } 
  // // firstNameSort(l); 

  // for(auto data: l)  // this should give me worst case O(nlog(n)) and average case O(n)
  //   lastNameBuckets[data->lastName].push_back(data); 
  // list<Data *>::iterator it = l.begin();
  // for(auto name: orderedLastNames){
  //     list<Data *> innerList = lastNameBuckets[name];
  //     innerList.sort(compare); 
      // switch(innerList.size()) {
      //     case 0: continue;
      //     case 1: *it = innerList.front();++it; continue; 
      //     default: {
      //       for(list<Data *>::iterator innerIt = innerList.begin(); innerIt != innerList.end(); ++innerIt){ 
      //         bool notDuplicate = true; 
      //         list<Data *>::iterator startIt = innerIt; 
      //         for(innerIt; next(innerIt) != innerList.end() && (*innerIt)->firstName  == (*next(innerIt))->firstName; ++innerIt){
      //           notDuplicate = false;
      //         }
      //         if(notDuplicate){
      //           *it = *innerIt; 
      //           ++it;
      //         } else {
      //           radixSSNSort(innerList,startIt,next(innerIt)); 
      //           for(startIt; startIt!=innerIt; ++startIt) {*it = *startIt; ++it;}
      //           innerIt--; 
      //         }
      //       }; 
      //       continue;
      //     } 
      // }
  // }

}
