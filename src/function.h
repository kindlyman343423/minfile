#include "Main.h"

/*OTHER FUNCTIONS*/

bool wildcard(char);
bool checkValid(char*);
int sha(char*);

/*RESERVED FUNCTIONS*/

bool reservedHTML(char*);
bool reservedJS(char*);
bool reservedC(char*);
bool reservedCPP(char*);
bool reservedJAVA(char*);
bool reservedCSharp(char*);

/*BUILD TREE FUNCTIONS*/

void buildHTML();
void buildJS();
void buildC();
void buildCPP();
void buildJAVA();
void buildCSharp();