#include "Header.h"

//=======================================
//---------------functions---------------
//=======================================
void help() {
    printf( "\nHelp :\n"
       "\t~$ ./main [Inputoptions]\n"
       "\t**For setting the length, input after Inputoptions**\n"
       "\t-len , length\n"
       "\t> Sets the length of the password (defaultL 8).\n"
       "InputOPTION :\n"
       "\t-a , all\n"
       "\t> Creates a random password using all the characters on the keyboard.\n"
       "\t-u , upper\n"
       "\t> Makes random passwords using uppercase English letters.\n"
       "\t-l , lower\n"
       "\t> Makes random passwords using lowercase English letters.\n"
       "\t-n , number\n"
       "\t> Generates random passwords using numbers.\n"
       "\t-s , sign\n"
       "\t> Generate random passwords using the sign.\n"
       "\t-ul , upperlower\n"
       "\t> Generates random passwords using uppercase and lowercase English letters.\n"
       "\t-uln , upperlowernumber\n"
       "\t> Generate random passwords using uppercase English letters and lowercase letters and numbers.\n");
}

char* all() {
    char* pass;
    pass = (char*) malloc(sizeof(char)*100);

    strcat(uppercases, lowercases);
    strcat(uppercases, numbers);
    strcat(uppercases, signs);

    srand(time(0));
    for (int i = 0; i < length; i++) {
        pass[i] = uppercases[rand() % strlen(uppercases)];
    }

    pass[length] = '\0';

    return pass;
}

char* upper() {
    char* pass;
    pass = (char*) malloc(sizeof(char)*100);

    srand(time(0));
    for (int i = 0; i < length; i++) {
        pass[i] = uppercases[rand() % strlen(uppercases)];
    }

    pass[length] = '\0';

    return pass;
}

char* lower() {
    char* pass;
    pass = (char*) malloc(sizeof(char)*100);

    srand(time(0));
    for (int i = 0; i < length; i++) {
        pass[i] = lowercases[rand() % strlen(lowercases)];
    }

    pass[length] = '\0';

    return pass;
}

char* number() {
    char* pass;
    pass = (char*) malloc(sizeof(char)*100);

    srand(time(0));
    for (int i = 0; i < length; i++) {
        pass[i] = numbers[rand() % strlen(numbers)];
    }

    pass[length] = '\0';

    return pass;
}

char* sign() {
    char* pass;
    pass = (char*) malloc(sizeof(char)*100);

    srand(time(0));
    for (int i = 0; i < length; i++) {
        pass[i] = signs[rand() % strlen(signs)];
    }

    pass[length] = '\0';

    return pass;
}

char* upperlower() {
    char* pass;
    pass = (char*) malloc(sizeof(char)*100);

    strcat(uppercases, lowercases);

    srand(time(0));
    for (int i = 0; i < length; i++) {
        pass[i] = uppercases[rand() % strlen(uppercases)];
    }

    pass[length] = '\0';

    return pass;
}

char* upperlowernumber() {
    char* pass;
    pass = (char*) malloc(sizeof(char)*100);

    strcat(uppercases, lowercases);
    strcat(uppercases, numbers);

    srand(time(0));
    for (int i = 0; i < length; i++) {
        pass[i] = uppercases[rand() % strlen(uppercases)];
    }

    pass[length] = '\0';

    return pass;
}

char* generatePass(char psd[100]) {
    int lenPsd = strlen(psd);
    int count = 0;

    char* result = (char*)malloc(sizeof(char)*100);

    while (count <= lenPsd) {
        int k = 7;
        int val = (int)psd[count];
        int dup = k;

        if(val + k > 122){
            k -= (122-val);
            k = k % 26;
            result[count] = (char)96 + k;
        }
        else
           result[count] = (char)val + k;
 
        k = dup;
        count++;
    }
    
    return result;
}