#include "header.h"
#define MAX_STRING 128

int length = 8;
char query[MAX_STRING] = {0};

int main(int argc, char* argv[]) {
    //=============================
    //------------DB---------------
    //=============================
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *server = "172.17.161.85";     //your ip.
    char *user = "oss";                  //your db id.
    char *password = "your_password";   //your db password.
    char *database = "pwdb";            //your db name

    conn = mysql_init(NULL);

    /* Connect to database */
    if (mysql_real_connect(conn, server, user, password, database, 0, NULL, 0) == NULL) {
        printf("Failed to connect MySQL Server %s. Error: %s\n", server, mysql_error(conn));
        return 0;
    }
    //=============================
    //------------DB---------------
    //=============================
    int inputOption;
    char passOption[20];
    char site[100];

    printf("Hello!\n\n");

    while(1) {
        printf("Enter 0 to quit\n");
        printf("Enter 1 for creating a random generated password.\n");
        printf("Enter 2 to access your Master password.\n");
        printf("Input: ");
        scanf("%d", &inputOption);

        if(inputOption == 1) {
            help();
            int cont;

            while(1) {
                printf("\nEnter name of password's site: ");
                scanf("%s", &site);
                printf("Enter desired length of password: ");
                scanf("%d", &length);
                printf("Enter desired option for password: ");
                scanf("%s", &passOption);

                char* result;

                if(strcmp(passOption, "h") == 0 || strcmp(passOption, "help") == 0) {
                    help();
                    return 0;
                }

                if(strcmp(passOption, "a") == 0 || strcmp(passOption, "all") == 0) {
                    result = all();
                }
                if(strcmp(passOption, "u") == 0 || strcmp(passOption, "upper") == 0) {
                    result = upper();
                }
                if(strcmp(passOption, "l") == 0 || strcmp(passOption, "lower") == 0) {
                    result = lower();
                }
                if(strcmp(passOption, "n") == 0 || strcmp(passOption, "number") == 0) {
                    result = number();
                }
                if(strcmp(passOption, "s") == 0 || strcmp(passOption, "sign") == 0) {
                    result = sign();
                }
                if(strcmp(passOption, "ul") == 0 || strcmp(passOption, "upperlower") == 0) {
                    result = upperlower();
                }
                if(strcmp(passOption, "uln") == 0 || strcmp(passOption, "upperlowernumber") == 0) {
                    result = upperlowernumber();
                }

                printf("\nCopy random generated password: %s\n", result);

                char db[100] = {"INSERT INTO user(name, password) VALUES('"};

                strcat(db, site);
                strcat(db, "', '");
                strcat(db, result);
                strcat(db, "')");

                mysql_query(conn, db);
                printf("\nContinue? (0: quit, 1: continue): ");
                scanf("%d", &cont);
                if(cont == 0) break;
            }
        } else if(inputOption == 2){
            char* pass;
            char psd[100];

            printf("Enter your pseudo password (length of pseudo password == length of resulting password): ");
            scanf("%s", psd);

            pass = generatePass(psd);

            printf("Master Password: %s\n", pass);
        } else if(inputOption == 0) {
            break;
        } else {
            printf("Error!\n");
            printf("Input again.\n");
        }
    }

    mysql_close(conn);
    printf("Have a good day:)\n");
}


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