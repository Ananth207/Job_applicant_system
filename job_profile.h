#ifndef JOB_PROFILEH
#define JOB_PROFILEH

#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_LENGTH 100

// Company Details
typedef struct {
  char company_name[MAX_ARRAY_LENGTH];
  char designation[MAX_ARRAY_LENGTH];
  char details[MAX_ARRAY_LENGTH];
} Company;

// Getting degree input
void degree(char education[]) {
  int degree;
  printf("Minimum Qualification Required:");
  printf("\n1. B.E\n2. B.Tech\n3. M.E\n4. M.Tech\n5. MBA\n6. 12th pass\n");
  printf("\nEnter your choice: ");
  scanf("\n%d", &degree);
  printf("\n");

  switch (degree) {
  case 1:
    strcpy(education, "B.E");
    break;
  case 2:
    strcpy(education, "B.Tech");
    break;
  case 3:
    strcpy(education, "M.E");
    break;
  case 4:
    strcpy(education, "M.Tech");
    break;
  case 5:
    strcpy(education, "MBA");
    break;
  case 6:
    strcpy(education, "12th_pass");
    break;
  }
}

// Key skills
typedef struct {
  int num_skills;
  char skills[MAX_ARRAY_LENGTH];
} Skills;

typedef struct {
  char field_of_expertise[MAX_ARRAY_LENGTH];
  int experience;
  char shift[MAX_ARRAY_LENGTH];
  int salaryRange;
  char employmentType[MAX_ARRAY_LENGTH];
} Requirement;

void job_profile(char uname[]) {
  Company comp_intro;
  char deg[MAX_ARRAY_LENGTH];
  Skills key_skills;
  FILE *fp, *fp1;
  Requirement other;
  printf("\n**************************************************\n");
  printf("Enter company name: ");
  scanf("\n%[^\n]", comp_intro.company_name);

  printf("Enter designation: ");
  scanf("\n%[^\n]", comp_intro.designation);

  printf("Enter job details: ");
  scanf("\n%[^\n]", comp_intro.details);

  printf("\n**************************************************\n");

  // Writing company info for display
  fp = fopen("files/comp_print.txt", "a");
  fprintf(fp, "%s,%s,%s,%s,\n", uname, comp_intro.company_name,
          comp_intro.designation, comp_intro.details);

  degree(deg);

  printf("\n**************************************************\n");
  printf("Enter Field of Expertise Required: ");
  scanf("\n%[^\n]", other.field_of_expertise);

  fp1 = fopen("files/comp_compare.txt", "a");
  fprintf(fp1, "%s,%s,", deg, other.field_of_expertise);

  key_skills.num_skills = 0;
  printf("\nEnter number of key skills: ");
  scanf("\n%d", &key_skills.num_skills);
  printf("\nEnter key skills (separated by -): ");
  scanf("\n%[^\n]", key_skills.skills);

  fprintf(fp1, "%d,%s,", key_skills.num_skills, key_skills.skills);

  printf("\nMinimum work experience:");
  scanf("\n%d", &other.experience);
  getchar();

  printf("Enter shift details: ");
  scanf("\n%[^\n]", other.shift);
  getchar();

  printf("Enter Starting salary: ");
  scanf("\n%d", &other.salaryRange);
  getchar();

  printf("Enter employment type (full-time/part-time): ");
  scanf("\n%[^\n]", other.employmentType);
  getchar();
  printf("\n**************************************************\n");

  // Writing job requirements
  fprintf(fp1, "%d,%s,%d,%s,\n", other.experience, other.shift,
          other.salaryRange, other.employmentType);
  fclose(fp);
  fclose(fp1);
}
#endif
