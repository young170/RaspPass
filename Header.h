#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <mysql/mysql.h>

void help();
char* all();
char* upper();
char* lower();
char* number();
char* sign();
char* upperlower();
char* upperlowernumber();
char* upperlowernumbersign();
char* generatePass(char psd[100]);

char uppercases[100] = "ABCDEFGHIJKLMNOPQRSTUWXYZ";
char lowercases[100] = "abcdefghijklmnopqrstuwxyz";
char numbers[100] = "1234567890";
char signs[100] = "!@#$\%^&()_+~*/-?:;.<,'\\][{}>";