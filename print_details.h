#include "job_profile.h"
#include "register.h"
#include "sekp1.h"
#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_LENGTH 100

void printing(int ls, char *uname) {

  if (ls == 1) {

    FILE *fp_work = fopen("files/comp_compare.txt", "r");
    FILE *fp_print = fopen("files/comp_print.txt", "r");
    Company comp_intro;
    char deg[MAX_ARRAY_LENGTH];
    Skills key_skills;
    FILE *per, *edu, *work;
    Requirement other;
    struct sign_up username;
    while (!feof(fp_work)) {
      fscanf(fp_print, "%[^,],%[^,],%[^,],%[^,],\n", username.user,
             comp_intro.company_name, comp_intro.designation,
             comp_intro.details);

      fscanf(fp_work, "%[^,],%[^,],%d,%[^,],%d,%[^,],%d,%[^,],\n", deg,
             other.field_of_expertise, &key_skills.num_skills,
             key_skills.skills, &other.experience, other.shift,
             &other.salaryRange, other.employmentType);

      if (strcmp(uname, username.user) == 0) {

        printf("\n----------------------------------------------\n");
        printf("\nCompany Name: %s", comp_intro.company_name);
        printf("\nAvailable jobs: %s", comp_intro.designation);
        printf("\nJob Details: %s", comp_intro.details);
        printf("\n----------------------------------------------\n");
        printf("\nMin Degree: %s", deg);
        printf("\nField of Expertise: %s", other.field_of_expertise);
        printf("\nNumber of key skills entered: %d", key_skills.num_skills);
        printf("\nKey skills: %s", key_skills.skills);
        printf("\nMinimum experience: %d", other.experience);
        printf("\nShift: %s", other.shift);
        printf("\nMin Salary Offer: %d", other.salaryRange);
        printf("\nEmployment Type: %s", other.employmentType);
        printf("\n----------------------------------------------\n");
        break;
      }
    }
    fclose(fp_work);
    fclose(fp_print);
  }

  else {

    struct personal record_1;
    struct education record_2;
    struct workplace record_3;
    struct sign_up username;

    FILE *per;
    FILE *edu;
    FILE *work;
    per = fopen("files/personal.txt", "r");
    edu = fopen("files/education.txt", "r");
    work = fopen("files/workplace.txt", "r");
    while (!feof(per)) {
      fscanf(per, "%[^,],%[^,],%[^,],%d,%[^,],%[^,],%d,%[^,],%d,%[^,],\n",
             username.user, record_1.name, record_1.gender, &record_1.age,
             record_1.father, record_1.mother, &record_1.DOB, record_1.address,
             &record_1.ph_no, record_1.email_id);

      fscanf(edu, "%[^,],%[^,],%d,%[^,],%[^,],%f,%[^,],%[^,],%[^,],\n",
             username.user, record_2.school_name, &record_2.mark,
             record_2.college, record_2.degree, &record_2.cgpa,
             record_2.course_name, record_2.specializtion,
             record_2.certification);

      fscanf(work, "%[^,],%[^,],%[^,],%[^,],%d,\n", username.user,
             record_3.work, record_3.pastwork, record_3.wdesig, &record_3.wexp);

      if (strcmp(uname, username.user) == 0) {
        printf("\n----------------------------------------------\n");
        printf("\nName: %s", record_1.name);
        printf("\nGender: %s", record_1.gender);
        printf("\nAge: %d", record_1.age);
        printf("\nFather Name: %s", record_1.father);
        printf("\nMother Name: %s", record_1.mother);
        printf("\nDate of Birth %d", record_1.DOB);
        printf("\nAddress: %s", record_1.address);
        printf("\nPhone Number: %d", record_1.ph_no);
        printf("\nEmail-ID: %s", record_1.email_id);
        printf("\n----------------------------------------------\n");
        printf("\nSchool Name: %s", record_2.school_name);
        printf("\n12th Mark: %d", record_2.mark);
        printf("\nCollege Name: %s", record_2.college);
        printf("\nDegree: %s", record_2.degree);
        printf("\nCGPA: %f", record_2.cgpa);
        printf("\nCourse Name: %s", record_2.course_name);
        printf("\nSpecialization: %s", record_2.specializtion);
        printf("\nCertification: %s", record_2.certification);
        printf("\n----------------------------------------------\n");
        printf("\n----------------------------------------------\n");
        printf("\nPast Company Name: %s", record_3.pastwork);
        printf("\nDesignation: %s", record_3.wdesig);
        printf("\nWork Experience: %d", record_3.wexp);
        break;
      }
    }

    fclose(per);
    fclose(edu);
    fclose(work);
  }
}