#include "Header.h"
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
    MYSQL_ROW record;

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

    MYSQL_RES* rs = mysql_store_result(conn);
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
        printf("Enter 3 to print out current state of table.\n");
        printf("Enter 4 to delete row int database table.\n");
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
        } else if(inputOption == 3){
            while(record = mysql_fetch_row(rs)) {   //until null = print all
                printf("Site: %s, Password: %s\n", record[0], record[1]);
            }
        } else if(inputOption == 4){
            char index[20];
            char rem[100] = {"DELETE FROM user WHERE id = "};

            printf("Enter the id of the element to remove: ");
            scanf("%s", &index);

            strcat(rem, index);

            mysql_query(conn, rem);
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