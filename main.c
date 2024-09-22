#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "credit.h"
#include "job_profile.h"
#include "print_details.h"
#include "register.h"
#include "sekp1.h"

typedef struct { // for getting details
  char jobsekp[100];
  char jobprofile[100];
} job_seekers;

int main(void) {

  int cl[5];
  char uname[30];
  char cname[30];
  FILE *clg;
  int r1 = 0;
  int r2 = 0;
  int opt;
  printf("\n==================== WELCOME TO =====================\n");
  printf("\n===============JOB SEEKING APPLICATION================\n");
  Register(cl, uname);//login system

  if (cl[3] == 1) {    //if the login is valid
    if (cl[1] == 2) //&&(cl[2]==2)
    {
      while (1) { //menu driven for job seeker
        r1 = cl[1];
        r2 = cl[2];
        printf("\n==============================================\n");
        printf("\nWelcome %s", uname);
        printf("\n1.Create profile");
        printf("\n2. Display existing profile");
        printf("\n3. Search for jobs");
        printf("\n4. Quit");
        printf("\nEnter your choice : ");
        scanf("%d", &opt);
        printf("\n==============================================\n");

        if (opt == 1) {    //entering details seeker
          sekp(r1, r2, uname, cname);
        } else if (opt == 2) { //display the details
          printing(r1, uname);
        } else if (opt == 3) {
          credit_calc(uname);    //credit calculation to recommend job
        } else if (opt == 4) { // want to quit
          break;
        } else {
          break;
        }
      }
    }

    if (cl[1] == 1) {     //menu driven for Admin
      while (1) {
        r1 = cl[1];
        r2 = cl[2];
        printf("\n=================== HOMEPAGE ===================\n");
        printf("\n============================================+===\n");
        printf("\nWelcome %s", uname);
        printf("\n1. Create profile");
        printf("\n2. Display existing jobs");
        printf("\n3. Search for candidates");
        printf("\n4. Quit");
        printf("\nEnter your choice : ");
        scanf("%d", &opt);
        printf("\n==============================================\n");

        /*if ){
        printf("Want to create a Job application (Y or N): ");
        char choice;
        scanf("\n%c",&choice);*/
        if (opt == 1) {    //posting jobs
          job_profile(uname);
        }

        else if (opt == 2) {    //display the job details
          printing(r1, uname);

        } else if (opt == 3) {
          FILE *candidates = fopen("files/JobMatch.txt", "r");
          FILE *seeker_personal_retrieval = fopen("files/personal.txt", "r");
          FILE *seeker_education_retrieval = fopen("files/education.txt", "r");
          FILE *seeker_work_retrieval = fopen("files/workplace.txt", "r");

          struct personal personal_retrieval;
          struct education education_retrieval;
          struct sign_up username_retrieval;

          job_seekers job_seek;
          while (!feof(candidates)) {
            fscanf(candidates, "%[^,],%[^,],\n", job_seek.jobsekp,
                   job_seek.jobprofile);

            rewind(seeker_personal_retrieval);
            rewind(seeker_education_retrieval);

            while (!feof(seeker_personal_retrieval)) {
              fscanf(seeker_personal_retrieval,
                     "%[^,],%[^,],%[^,],%d,%[^,],%[^,],%d,%[^,],%d,%[^,],\n",
                     username_retrieval.user, personal_retrieval.name,
                     personal_retrieval.gender, &personal_retrieval.age,
                     personal_retrieval.father, personal_retrieval.mother,
                     &personal_retrieval.DOB, personal_retrieval.address,
                     &personal_retrieval.ph_no, personal_retrieval.email_id);

              fscanf(seeker_education_retrieval,
                     "%[^,],%[^,],%d,%[^,],%[^,],%f,%[^,],%[^,],%[^,],\n",
                     username_retrieval.user, education_retrieval.school_name,
                     &education_retrieval.mark, education_retrieval.college,
                     education_retrieval.degree, &education_retrieval.cgpa,
                     education_retrieval.course_name,
                     education_retrieval.specializtion,
                     education_retrieval.certification);
              if (strcmp(uname, job_seek.jobprofile) == 0 &&
                  (strcmp(job_seek.jobsekp, username_retrieval.user) == 0)) {
                printf("\n--------------CANDIDATE DETAILS-----------------\n");
                printf("\nCandidate Name: %s", personal_retrieval.name);
                printf("\nCandidate College: %s", education_retrieval.college);
                printf("\nCandidate CGPA: %f ", education_retrieval.cgpa);
                printf("\nCandidate Specialization: %s",
                       education_retrieval.specializtion);
                printf("\n-------------------------------------------------\n");
                printf("\n%s wishes to apply for interview: ",
                       personal_retrieval.name);
                printf("\nAccept Candidate (YES/NO): ");
                printf("\n----------------------------------------------\n");
                char select[100];
                scanf("\n%[^\n]", select);
                if (strcmp(select, "YES") == 0) {
                  printf("\nSucessfull....Called candidate for interview");
                  printf("\n----------------------------------------------\n");
                }
              }
            }
          }
          // credit_calc(uname);
        } else if (opt == 4) {    // want to quit
          break;
        } else {
          break;
        }
      }
    }
  }

  // clg=fopen("clg.txt","r");
}