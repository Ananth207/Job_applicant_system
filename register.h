#ifndef REGISTERH
#define REGISTERH

#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct sign_up {
  char user[30];
  char pass[15];
  int spl_pass;
};

void Register(int *chl, char *uname) {
  int choice = 0;
  int lg = 0;
  int log_sin = 0;
  int count = 0;
  FILE *log;
  struct sign_up s1;
  struct sign_up s2;

  printf("\n**************************************************\n");

  printf("\nEnter 1 if you are Admin, Enter 2 if you are Job seeker : ");
  scanf("\n%d", &choice);

  if (choice == 1) {
    log = fopen("files/admin.txt", "a+");
  } else {
    log = fopen("files/user.txt", "a+");
  }

  while (lg == 0) {
    printf("================== LOGIN / SIGNUP =================\n");
    printf("\n**************************************************\n");
    printf("\nChoose 1.Login/ 2.Signup : ");
    scanf("%d", &log_sin);
    printf("\nEnter your User name : ");
    scanf("\n%s", s1.user);
    printf("\n----------------------------------------------\n");
    printf("\nMinimum conditions required:");
    printf("\n    1.Must contain atleast 1 uppercase character, lowercase "
           "character, number");
    printf("\n    2. It must contain a special character from (@,#,&,$)\n");
    printf("\n----------------------------------------------\n");

    printf("Enter Password : ");
    scanf("\n%s", s1.pass);

    printf("\n**************************************************\n");

    if (log_sin == 2) // signup
    {
      int ucase = 0, lcase = 0, spl = 0, num = 0,
          o = strlen(s1.pass); // constraint

      for (int i = 0; i < strlen(s1.pass); i++) {
        if (isupper((char)s1.pass[i])) {
          ucase += 1;
        } else if (islower((char)s1.pass[i])) {
          lcase += 1;
        } else if (isdigit(s1.pass[i])) {
          num += 1;
        } else if (((char)s1.pass[i] == '@') || ((char)s1.pass[i] == '#') ||
                   ((char)s1.pass[i] == '$') || ((char)s1.pass[i] == '&')) {
          spl += 1;
        } else {
          printf("Password not accepted\n");
          printf("\n**************************************************\n");
          break;
        }
      }

      if ((ucase == 0) || (lcase == 0) || (num == 0) ||
          (spl == 0)) // for checking constraints
      {
        printf("Password not accepted\n");
        printf("\n**************************************************\n");
        break;
      } else {
        count = 1;
      }

      if (choice == 1) // admin spl
      {
        printf("Enter Special Password : ");
        scanf("\n%d", &s1.spl_pass);
        fprintf(log, "%s,%s,%d,\n", s1.user, s1.pass, s1.spl_pass);
        printf("\n**************************************************\n");
      } else {
        fprintf(log, "%s,%s,\n", s1.user, s1.pass);
      }
      lg = 1;
    }

    else {
      if (choice == 1) // admin login
      {
        printf("Enter special pwd:");
        scanf("\n%d", &s1.spl_pass);
        printf("\n**************************************************\n");
        // printf("%d",s1.spl_pass);

        int k = 0;
        rewind(log);
        while (!feof(log)) {
          if (choice == 1) // admin login
          {
            fscanf(log, "%[^,],%[^,],%d,\n", s2.user, s2.pass, &s2.spl_pass);

            if ((strcmp(s1.user, s2.user) == 0) &&
                (strcmp(s1.pass, s2.pass) == 0) &&
                (s1.spl_pass == s2.spl_pass)) {
              printf("Logged in\n");
              printf("\n**************************************************\n");
              count = 1;
              lg = 1;
              k = 0;
              break;
            } else {
              k = 1;
            }
          }
        }
        if (k == 1) {
          printf("Wrong credentials!!\n");
          printf("\n**************************************************\n");
          lg = 1;
          break;
        }
      }

      else if (choice == 2) // job seeker login
      {
        int k = 0;
        while (!feof(log)) {
          fscanf(log, "%[^,],%[^,],\n", s2.user, s2.pass);
          // printf("%s\n%s\n", s2.user, s2.pass);
          //  count+=1;
          if ((strcmp(s1.user, s2.user) == 0) &&
              (strcmp(s1.pass, s2.pass) == 0)) {
            k = 1;
            // printf("%d ", k);
            lg = 1;
            // break;
          }
          if (k == 1) {
            count = 1;
            printf("Logged in\n");
            printf("\n**************************************************\n");
            count = 1;
            lg = 1;
            break;
          }
        }
        if (k == 0) {
          printf("Wrong credentials!!\n");
          printf("\n**************************************************\n");
          lg = 1;
          break;
        }
      }
    }

    if (lg == 0) {
      printf("Invalid...try again\n");
      printf("\n**************************************************\n");
      break;
    }
  }
  fclose(log);
  chl[1] = choice;
  chl[2] = log_sin;
  chl[3] = count;
  strcpy(uname, s1.user);
}

#endif




