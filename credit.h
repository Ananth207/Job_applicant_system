#include "job_profile.h"
#include "register.h"
#include "sekp1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void credit_calc(char uname[]) {
  FILE *fp_work, *edu1, *work1, *jobs1, *cllg, *fp_print, *matches, *job_match;
  cllg = fopen("files/clg.txt", "r");
  edu1 = fopen("files/education.txt", "r");
  work1 = fopen("files/workplace.txt", "r");
  fp_work = fopen("files/comp_compare.txt", "r");
  fp_print = fopen("files/comp_print.txt", "r");
  matches = fopen("files/Matched_Companies.txt", "a+");
  job_match = fopen("files/JobMatch.txt", "a+");

  struct personal record_1;
  struct education record_2;
  struct workplace record_3;
  struct sign_up username_company, username;
  Company comp_intro_print;
  // int choice = r1;
  // int ls = r2;
  char deg1[MAX_ARRAY_LENGTH];
  Skills key_skills1;
  Requirement other1;
  char *certi_arr[100]; // Assuming a maximum of 100 words
  char *skill_arr[100];
  char college_check[200];

  int credit_score = 0;

  while (!feof(edu1)) {
    // To retrieve the details of job seeker from the necessary //files using
    // fcanf
    fscanf(edu1, "%[^,],%[^,],%d,%[^,],%[^,],%f,%[^,],%[^,],%[^,],\n",
           username.user, record_2.school_name, &record_2.mark,
           record_2.college, record_2.degree, &record_2.cgpa,
           record_2.course_name, record_2.specializtion,
           record_2.certification);
    // Storing workplace details
    fscanf(work1, "%[^,],%[^,],%[^,],%[^,],%d,\n", username.user, record_3.work,
           record_3.pastwork, record_3.wdesig, &record_3.wexp);

    char *token = strtok(record_2.certification, "-"); // Split by spaces
    int i = 0;
    while (token != NULL) {
      certi_arr[i] = token;
      i++;
      token = strtok(NULL, "-");
    }

    if (strcmp(username.user, uname) == 0)

    {

      while (!feof(fp_work)) {
        // Retrieving the required details of the company from the file
        credit_score = 0;
        fscanf(fp_print, "%[^,],%[^,],%[^,],%[^,],\n", username_company.user,
               comp_intro_print.company_name, comp_intro_print.designation,
               comp_intro_print.details);
        fscanf(fp_work, "%[^,],%[^,],%d,%[^,],%d,%[^,],%d,%[^,],\n", deg1,
               other1.field_of_expertise, &key_skills1.num_skills,
               key_skills1.skills, &other1.experience, other1.shift,
               &other1.salaryRange, other1.employmentType);

        // Assuming a maximum of 100 words

        char *token1 = strtok(key_skills1.skills, "-"); // Split by spaces

        int j = 0;
        while (token1 != NULL) {
          skill_arr[j] = token1;
          j++;
          token1 = strtok(NULL, "-");
        }
        // Credit score calculation based on certification skills.
        for (int x = 0; x < key_skills1.num_skills; x++) {
          if (strcmp(skill_arr[x], certi_arr[1]) == 0) {
            credit_score += 10;
          }
        }

        int check_variable = 0;
        // Credit score calculation based on certification company
        char companies_courses[100][100] = {"Google", "IBM", "Microsoft",
                                            "NPTEL",  "MIT", "UCA"};
        for (int v = 0; v < 6; v++) {
          if (strcmp(companies_courses[v], certi_arr[0]) == 0) {
            credit_score += 10;
            check_variable = 1;
            break;
          }
        }
        if ((check_variable == 0) &&
            (strcmp(record_2.certification, "NIL") != 0)) {
          credit_score += 5;
        }
        // Declaring top companies for calculationg part of credit system for
        // certification company
        char top_companies[100][100] = {"Meta",    "Apple",       "Amazon",
                                        "Netflix", "Google",      "HCL",
                                        "IBM",     "GoldmanSachs"};

        if (strcmp(record_3.work, "YES") == 0) {

          credit_score += 7;

          for (int v = 0; v < 8; v++) {
            if (strcmp(top_companies[v], record_3.pastwork) == 0) {
              credit_score += 5;
            }
          }
          // Credit score calculation based on work experience
          if (record_3.wexp >= other1.experience) {
            credit_score += 12;
          } else {
            credit_score += 8;
          }
        }

        int check = 1;
        // credsit system calculation based on college where job seeker had
        // studied.
        while (!feof(cllg)) {
          fscanf(cllg, "%199[^\n]\n", college_check);
          if (strcmp(record_2.college, college_check) == 0) {
            break;
          }
          check++;
        }

        if (check <= 5) {
          credit_score += 20;
        } else if (check <= 10) {
          credit_score += 16;
        } else if (check <= 15) {
          credit_score += 12;
        } else if (check <= 20) {
          credit_score += 8;
        } else if (check <= 25) {
          credit_score += 4;
        }
        rewind(cllg);

        if (strcmp(record_2.specializtion, other1.field_of_expertise) == 0) {
          credit_score += 15;
        }
        // Credit score based on cgpa of the job seeker

        if (record_2.cgpa > 8.0) {
          credit_score += 10;
        }

        if (credit_score > 50) {
          printf("\n----------------------------------------------\n");
          printf("\nCompany Name: %s", comp_intro_print.company_name);
          printf("\nJob Available: %s", comp_intro_print.designation);
          printf("\nDetails: %s", comp_intro_print.details);
          printf("\nJob Match Percentage: %d", credit_score);
          fprintf(matches, "%s,%s,%d,%d,\n", username.user,
                  username_company.user, credit_score, 0);
        }
      }
      printf("\n----------------------------------------------\n");
      break;
    }
  }
  char job[100];
  char *job1[100];
  printf(
      "\nEnter the company names that you wish to apply for separated by - : ");
  printf("\n----------------------------------------------\n");
  scanf("\n%[^\n]", job);
  char *token1 = strtok(job, "-"); // Split by spaces
  int apply = 0;
  while (token1 != NULL) {
    job1[apply] = token1;
    apply++;
    token1 = strtok(NULL, "-");
  }

  // Storing the job seeker username and the company's username in a file in
  // each line .
  printf("%s %s", job1[0], job1[1]);
  for (int e = 0; e < apply; e++) {
    rewind(fp_print);
    while (!feof(fp_print)) {
      fscanf(fp_print, "%[^,],%[^,],%[^,],%[^,],\n", username_company.user,
             comp_intro_print.company_name, comp_intro_print.designation,
             comp_intro_print.details);
      if (strcmp(job1[e], comp_intro_print.company_name) == 0) {
        fprintf(job_match, "%s,%s,\n", username.user, username_company.user);
        printf("\nSent Profile to Company %s !", comp_intro_print.company_name);
        printf("\n----------------------------------------------\n");
        break;
      }
    }
  }
  // Closing all the opened files using fclose
  fclose(cllg);
  fclose(edu1);
  fclose(work1);
  fclose(fp_work);
  fclose(fp_print);
  fclose(matches);
  fclose(job_match);
}
