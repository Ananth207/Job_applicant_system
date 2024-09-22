// this is the csv file format of sekp.h
// Guys if this runs up crctly, change the name of this file to sekp.h and
// discaerd the existing previous sekp.h

/*#ifndef SEKPH
#define SEKPH*/
#ifndef SEKP1H
#define SEKP1H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct personal { //for personal details
  char name[30];
  char gender[3];
  int age;
  char father[30];
  char mother[30];
  int DOB;
  char address[100];
  int ph_no;
  char email_id[30];
};

struct education { //for eduction details
  char school_name[100];
  int mark;
  char college[100];
  char degree[100];
  float cgpa;
  char course_name[100];
  char specializtion[100];
  char certification[100];
};

struct workplace {    //for past work details
  char work[100];
  char pastwork[100];
  int wexp;
  char wdesig[100];
  char intern[100];
  char company_name[100];
  char idesig[100];
  int iexp;
};
/*#include "login.h"
#include "new.h"*/
int sekp(int choice, int ls, char *uname,
         char *cname) { // A single function for sekp
                        // r1== TAT or jobseeker, r2==login or signup

  // loginheader();
  // printf("%d %d");
  struct personal record_1; //variable assignment for struct
  struct education record_2;
  struct workplace record_3;
  // int choice = r1;
  // int ls = r2;
  FILE *per;
  FILE *edu;
  FILE *work;
  per = fopen("files/personal.txt", "a+");    //
  fprintf(per, "%s,", uname);
  edu = fopen("files/education.txt", "a+");
  fprintf(edu, "%s,", uname);
  work = fopen("files/workplace.txt", "a+");
  fprintf(work, "%s,", uname);
  if (choice == 2) {
    if (ls == 2) {
      printf("\n**************************************************\n");
      printf("Enter your name : ");
      scanf("\n%[^\n]", record_1.name);
      fprintf(per, "%s,", record_1.name);

      printf("Enter Gender (M or F or (Don't specify)DN) : ");
      scanf("\n%s", record_1.gender);
      fprintf(per, "%s,", record_1.gender);

      printf("Enter Age (YY) :");
      scanf("\n%d", &record_1.age);
      fprintf(per, "%d,", record_1.age);

      printf("Enter Father name :");
      scanf("\n%[^\n]", record_1.father);
      fprintf(per, "%s,", record_1.father);

      printf("Enter Mother name : ");
      scanf("\n%[^\n]", record_1.mother);
      fprintf(per, "%s,", record_1.mother);

      printf("Enter DOB (DDMMYYYY) : ");
      record_1.DOB = 0;
      scanf("\n%d", &record_1.DOB);
      fprintf(per, "%d,", record_1.DOB);

      printf("Enter Address : ");
      scanf("\n%[^\n]", record_1.address);
      fprintf(per, "%s,", record_1.address);

      record_1.ph_no = 0;
      printf("Enter Phone number : ");
      scanf("\n%d", &record_1.ph_no);
      // printf("\n%d",*(record_1.ph_no));
      fprintf(per, "%d,", record_1.ph_no);

      printf("Enter Email ID : ");
      scanf("\n%s", record_1.email_id);
      fprintf(per, "%s,\n", record_1.email_id);

      printf("\n**************************************************\n");

      printf("Enter School name : ");
      scanf("\n%[^\n]", record_2.school_name);
      fprintf(edu, "%s,", record_2.school_name);

      printf("Enter 12th Mark : ");
      scanf("\n %d", &record_2.mark);
      fprintf(edu, "%d,", record_2.mark);

      printf("Enter College name : ");
      scanf("\n%[^\n]", record_2.college);
      fprintf(edu, "%s,", record_2.college);

      printf("Enter Degree : ");
      scanf("\n%[^\n]", record_2.degree);
      fprintf(edu, "%s,", record_2.degree);

      printf("Enter CGPA : ");
      scanf("\n%f", &record_2.cgpa);
      fprintf(edu, "%f,", record_2.cgpa);

      printf("Enter Course name : ");
      scanf("\n%[^\n]", record_2.course_name);
      fprintf(edu, "%s,", record_2.course_name);

      printf("Enter Specialization : ");
      scanf("\n%[^\n]", record_2.specializtion);
      fprintf(edu, "%s,", record_2.specializtion);

      printf("Enter Certificate courses : ");
      scanf("\n%[^\n]", record_2.certification);
      fprintf(edu, "%s,\n", record_2.certification);

      printf("\n**************************************************\n");

      printf("Enter Work experience (YES or NO) : ");
      scanf("\n%s", record_3.work);
      fprintf(work, "%s,", record_3.work);

      if (strcmp(record_3.work, "YES") == 0) {
        printf("Enter Past Company Name : ");
        scanf("\n%[^\n]", record_3.pastwork);
        fprintf(work, "%s,", record_3.pastwork);

        printf("Enter Designation : ");
        scanf("\n%[^\n]", record_3.wdesig);
        fprintf(work, "%s,", record_3.wdesig);

        printf("Enter Work Experience (yrs) : ");
        scanf("\n%d", &record_3.wexp);
        fprintf(work, "%d,\n", record_3.wexp);

      } else {
        strcpy(record_3.pastwork, "NIL");
        fprintf(work, "%s,", record_3.pastwork);

        strcpy(record_3.wdesig, "NIL");
        fprintf(work, "%s,", record_3.wdesig);

        record_3.wexp = 0;
        fprintf(work, "%d,\n", record_3.wexp);
      }
      printf("\n**************************************************\n");

    }
  }
  // char some[100];
  // fseek(per,"%s",&some);
  // printf("%s ",some);
  fclose(edu);
  fclose(per);
  fclose(work);
  return 0;
}

#endif