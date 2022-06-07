#include "Header.h"

int length = 8;

int main(int argc, char* argv[]) {
    if(argc == 1) {
        printf("Please enter argv to access program.\n");
        return 0;
    }

    char* result;

    if(argc == 3) {
        if(strcmp(argv[2], "len") == 0 || strcmp(argv[2], "length") == 0) {
            printf("Enter desired length of password: ");
            scanf("%d", &length);
        }
    }

    if(strcmp(argv[1], "h") == 0 || strcmp(argv[1], "help") == 0) {
        help();
        return 0;
    }

    if(strcmp(argv[1], "a") == 0 || strcmp(argv[1], "all") == 0) {
        result = all();
    }
    if(strcmp(argv[1], "u") == 0 || strcmp(argv[1], "upper") == 0) {
        result = upper();
    }
    if(strcmp(argv[1], "l") == 0 || strcmp(argv[1], "lower") == 0) {
        result = lower();
    }
    if(strcmp(argv[1], "n") == 0 || strcmp(argv[1], "number") == 0) {
        result = number();
    }
    if(strcmp(argv[1], "s") == 0 || strcmp(argv[1], "sign") == 0) {
        result = sign();
    }
    if(strcmp(argv[1], "ul") == 0 || strcmp(argv[1], "upperlower") == 0) {
        result = upperlower();
    }
    if(strcmp(argv[1], "uln") == 0 || strcmp(argv[1], "upperlowernumber") == 0) {
        result = upperlowernumber();
    }

    printf("\nCopy random generated password: %s\n\n", result);
}

void help() {
    printf( "Help :\n"
       "\t~$ ./main [options]\n"
       "\t**For setting the length, input after options**\n"
       "\t-len , length\n"
       "\t> Sets the length of the password (defaultL 8).\n"
       "OPTION :\n"
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