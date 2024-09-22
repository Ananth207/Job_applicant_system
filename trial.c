// #include <limits.h>
// #include <stdio.h>
// #include <stdlib.h>

// void readInput(int *frames, int *n, int referenceString[], int *free_f) {
//   printf("Enter the number of free frames: ");
//   scanf("%d", free_f);
//   printf("Enter the number of frames required by each process: ");
//   scanf("%d", frames);
//   printf("Enter the number of pages(in the reference string): ");
//   scanf("%d", n);
//   printf("Enter the reference string: ");
//   for (int i = 0; i < *n; i++) {
//     scanf("%d", &referenceString[i]);
//   }
// }

// // FIFO Replacement Algorithm
// void fifo(int incomingStream[], int pages, int frames) {
//   int pageFaults = 0;
//   int temp[frames];
//   int m, n, s;

//   for (m = 0; m < frames; m++) {
//     temp[m] = -1;
//   }
//   printf("Page\t");
//   for (int i = 1; i <= frames; i++) {
//     printf("Frame%d\t", i);
//   }
//   printf("\n");

//   for (m = 0; m < pages; m++) {
//     s = 0;
//     for (n = 0; n < frames; n++) {
//       if (incomingStream[m] == temp[n]) {
//         s++;
//         pageFaults--;
//       }
//     }
//     pageFaults++;
//     if ((pageFaults <= frames) && (s == 0)) {
//       temp[m] = incomingStream[m];
//     } else if (s == 0) {
//       temp[(pageFaults - 1) % frames] = incomingStream[m];
//     }
//     printf("%d\t\t", incomingStream[m]);
//     for (n = 0; n < frames; n++) {
//       if (temp[n] != -1)
//         printf("%d\t\t", temp[n]);
//       else
//         printf("-\t\t");
//     }
//     printf("\n");
//   }
//   printf("Total Page Faults:\t%d\n", pageFaults);
// }

// // Optimal Replacement Algorithm
// int search(int key, int frame_items[], int frame_occupied) {
//   for (int i = 0; i < frame_occupied; i++)
//     if (frame_items[i] == key)
//       return 1;
//   return 0;
// }

// int predict(int ref_str[], int frame_items[], int refStrLen, int index,
//             int frame_occupied) {
//   int result = -1, farthest = index;
//   for (int i = 0; i < frame_occupied; i++) {
//     int j;
//     for (j = index; j < refStrLen; j++) {
//       if (frame_items[i] == ref_str[j]) {
//         if (j > farthest) {
//           farthest = j;
//           result = i;
//         }
//         break;
//       }
//     }
//     if (j == refStrLen)
//       return i;
//   }
//   return (result == -1) ? 0 : result;
// }

// void optimal(int ref_str[], int refStrLen, int frames) {
//   int frame_items[frames];
//   int frame_occupied = 0;
//   int hits = 0;

//   printf("Page\t");
//   for (int i = 1; i <= frames; i++) {
//     printf("Frame%d\t", i);
//   }
//   printf("\n");

//   for (int i = 0; i < refStrLen; i++) {
//     printf("%d\t\t", ref_str[i]);
//     if (search(ref_str[i], frame_items, frame_occupied)) {
//       hits++;
//     } else {
//       if (frame_occupied < frames) {
//         frame_items[frame_occupied++] = ref_str[i];
//       } else {
//         int pos =
//             predict(ref_str, frame_items, refStrLen, i + 1, frame_occupied);
//         frame_items[pos] = ref_str[i];
//       }
//     }
//     for (int j = 0; j < frames; j++) {
//       if (j < frame_occupied)
//         printf("%d\t\t", frame_items[j]);
//       else
//         printf("-\t\t");
//     }
//     printf("\n");
//   }
//   printf("Total Page Faults:\t%d\n", refStrLen - hits);
// }

// // LRU Replacement Algorithm
// int checkHit(int incomingPage, int queue[], int occupied) {
//   for (int i = 0; i < occupied; i++) {
//     if (incomingPage == queue[i])
//       return 1;
//   }
//   return 0;
// }

// void lru(int incomingStream[], int n, int frames) {
//   int queue[frames];
//   int distance[frames];
//   int occupied = 0;
//   int pagefault = 0;

//   printf("Page\t");
//   for (int i = 1; i <= frames; i++) {
//     printf("Frame%d\t", i);
//   }
//   printf("\n");

//   for (int i = 0; i < n; i++) {
//     printf("%d\t\t", incomingStream[i]);
//     if (checkHit(incomingStream[i], queue, occupied)) {
//       // Print the frames as they are (no replacement)
//     } else if (occupied < frames) {
//       queue[occupied++] = incomingStream[i];
//       pagefault++;
//     } else {
//       int max = INT_MIN, index;
//       for (int j = 0; j < frames; j++) {
//         distance[j] = 0;
//         for (int k = i - 1; k >= 0; k--) {
//           distance[j]++;
//           if (queue[j] == incomingStream[k])
//             break;
//         }
//         if (distance[j] > max) {
//           max = distance[j];
//           index = j;
//         }
//       }
//       queue[index] = incomingStream[i];
//       pagefault++;
//     }
//     for (int j = 0; j < frames; j++) {
//       if (j < occupied)
//         printf("%d\t\t", queue[j]);
//       else
//         printf("-\t\t");
//     }
//     printf("\n");
//   }
//   printf("Total Page Faults:\t%d\n", pagefault);
// }

// // LFU Replacement Algorithm
// void lfu(int referenceString[], int n, int frames) {
//   int pageFaults = 0, count[100] = {0};
//   int temp[frames];
//   int m, n1, s;

//   for (m = 0; m < frames; m++) {
//     temp[m] = -1;
//   }
//   printf("Page\t");
//   for (int i = 1; i <= frames; i++) {
//     printf("Frame%d\t", i);
//   }
//   printf("\n");

//   for (m = 0; m < n; m++) {
//     printf("%d\t\t", referenceString[m]);
//     s = 0;
//     for (n1 = 0; n1 < frames; n1++) {
//       if (referenceString[m] == temp[n1]) {
//         s++;
//         pageFaults--;
//         count[referenceString[m]]++;
//       }
//     }
//     pageFaults++;
//     if ((pageFaults <= frames) && (s == 0)) {
//       temp[m] = referenceString[m];
//       count[referenceString[m]]++;
//     } else if (s == 0) {
//       int min = INT_MAX, index = -1;
//       for (int j = 0; j < frames; j++) {
//         if (count[temp[j]] < min) {
//           min = count[temp[j]];
//           index = j;
//         }
//       }
//       temp[index] = referenceString[m];
//       count[referenceString[m]]++;
//     }
//     for (n1 = 0; n1 < frames; n1++) {
//       if (temp[n1] != -1)
//         printf("%d\t\t", temp[n1]);
//       else
//         printf("-\t\t");
//     }
//     printf("\n");
//   }
//   printf("Total Page Faults:\t%d\n", pageFaults);
// }

// int main() {
//   int frames, n, free_f;
//   int referenceString[100];

//   readInput(&frames, &n, referenceString, &free_f);

//   while (1) {
//     int choice;
//     printf("\nPAGE REPLACEMENT ALGORITHMS\n");
//     printf("1. FIFO\n");
//     printf("2. OPTIMAL\n");
//     printf("3. LRU\n");
//     printf("4. LFU\n");
//     printf("5. EXIT\n");
//     printf("Enter your option: ");
//     scanf("%d", &choice);

//     switch (choice) {
//     case 1:
//       fifo(referenceString, n, frames);
//       break;
//     case 2:
//       optimal(referenceString, n, frames);
//       break;
//     case 3:
//       lru(referenceString, n, frames);
//       break;
//     case 4:
//       lfu(referenceString, n, frames);
//       break;
//     case 5:
//       exit(0);
//     default:
//       printf("Invalid option! Please try again.\n");
//     }
//   }

//   return 0;
// }

// // 1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void readInput(int *frames, int *n, int referenceString[], int *free_f) {
  printf("Enter the number of free frames: ");
  scanf("%d", free_f);
  printf("Enter the number of frames required by each process: ");
  scanf("%d", frames);
  printf("Enter the number of pages (in the reference string): ");
  scanf("%d", n);
  printf("Enter the reference string: ");
  for (int i = 0; i < *n; i++) {
    scanf("%d", &referenceString[i]);
  }
}

// FIFO Replacement Algorithm
void fifo(int incomingStream[], int pages, int frames) {
  int pageFaults = 0;
  int temp[frames];
  int m, n, s, index = 0;

  for (m = 0; m < frames; m++) {
    temp[m] = -1;
  }
  printf("Page\t");
  for (int i = 1; i <= frames; i++) {
    printf("Frame%d\t", i);
  }
  printf("Status\n");

  for (m = 0; m < pages; m++) {
    s = 0;
    for (n = 0; n < frames; n++) {
      if (incomingStream[m] == temp[n]) {
        s++;
        pageFaults--;
      }
    }
    pageFaults++;
    if ((pageFaults <= frames) && (s == 0)) {
      temp[index] = incomingStream[m];
      index = (index + 1) % frames;
    } else if (s == 0) {
      temp[index] = incomingStream[m];
      index = (index + 1) % frames;
    }
    printf("%d\t\t", incomingStream[m]);
    for (n = 0; n < frames; n++) {
      if (temp[n] != -1)
        printf("%d\t\t", temp[n]);
      else
        printf("-\t\t");
    }
    if (s == 0)
      printf("PF\n");
    else
      printf("PH\n");
  }
  printf("Total Page Faults:\t%d\n", pageFaults);
}

// Optimal Replacement Algorithm
int search(int key, int frame_items[], int frame_occupied) {
  for (int i = 0; i < frame_occupied; i++)
    if (frame_items[i] == key)
      return 1;
  return 0;
}

int predict(int ref_str[], int frame_items[], int refStrLen, int index,
            int frame_occupied) {
  int result = -1, farthest = index;
  for (int i = 0; i < frame_occupied; i++) {
    int j;
    for (j = index; j < refStrLen; j++) {
      if (frame_items[i] == ref_str[j]) {
        if (j > farthest) {
          farthest = j;
          result = i;
        }
        break;
      }
    }
    if (j == refStrLen)
      return i;
  }
  return (result == -1) ? 0 : result;
}

void optimal(int ref_str[], int refStrLen, int frames) {
  int frame_items[frames];
  int frame_occupied = 0;
  int hits = 0;

  printf("Page\t");
  for (int i = 1; i <= frames; i++) {
    printf("Frame%d\t", i);
  }
  printf("Status\n");

  for (int i = 0; i < refStrLen; i++) {
    printf("%d\t\t", ref_str[i]);
    if (search(ref_str[i], frame_items, frame_occupied)) {
      hits++;
      for (int j = 0; j < frames; j++) {
        if (j < frame_occupied)
          printf("%d\t\t", frame_items[j]);
        else
          printf("-\t\t");
      }
      printf("PH\n");
    } else {
      if (frame_occupied < frames) {
        frame_items[frame_occupied++] = ref_str[i];
      } else {
        int pos =
            predict(ref_str, frame_items, refStrLen, i + 1, frame_occupied);
        frame_items[pos] = ref_str[i];
      }
      for (int j = 0; j < frames; j++) {
        if (j < frame_occupied)
          printf("%d\t\t", frame_items[j]);
        else
          printf("-\t\t");
      }
      printf("PF\n");
    }
  }
  printf("Total Page Faults:\t%d\n", refStrLen - hits);
}

// LRU Replacement Algorithm
int checkHit(int incomingPage, int queue[], int occupied) {
  for (int i = 0; i < occupied; i++) {
    if (incomingPage == queue[i])
      return 1;
  }
  return 0;
}

void lru(int incomingStream[], int n, int frames) {
  int queue[frames];
  int distance[frames];
  int occupied = 0;
  int pagefault = 0;

  printf("Page\t");
  for (int i = 1; i <= frames; i++) {
    printf("Frame%d\t", i);
  }
  printf("Status\n");

  for (int i = 0; i < n; i++) {
    printf("%d\t\t", incomingStream[i]);
    if (checkHit(incomingStream[i], queue, occupied)) {
      for (int j = 0; j < frames; j++) {
        if (j < occupied)
          printf("%d\t\t", queue[j]);
        else
          printf("-\t\t");
      }
      printf("PH\n");
    } else if (occupied < frames) {
      queue[occupied++] = incomingStream[i];
      pagefault++;
      for (int j = 0; j < frames; j++) {
        if (j < occupied)
          printf("%d\t\t", queue[j]);
        else
          printf("-\t\t");
      }
      printf("PF\n");
    } else {
      int max = INT_MIN, index;
      for (int j = 0; j < frames; j++) {
        distance[j] = 0;
        for (int k = i - 1; k >= 0; k--) {
          distance[j]++;
          if (queue[j] == incomingStream[k])
            break;
        }
        if (distance[j] > max) {
          max = distance[j];
          index = j;
        }
      }
      queue[index] = incomingStream[i];
      pagefault++;
      for (int j = 0; j < frames; j++) {
        if (j < occupied)
          printf("%d\t\t", queue[j]);
        else
          printf("-\t\t");
      }
      printf("PF\n");
    }
  }
  printf("Total Page Faults:\t%d\n", pagefault);
}

// LFU Replacement Algorithm
void lfu(int referenceString[], int n, int frames) {
  int pageFaults = 0, count[100] = {0};
  int temp[frames];
  int m, n1, s;

  for (m = 0; m < frames; m++) {
    temp[m] = -1;
  }
  printf("Page\t");
  for (int i = 1; i <= frames; i++) {
    printf("Frame%d\t", i);
  }
  printf("Status\n");

  for (m = 0; m < n; m++) {
    printf("%d\t\t", referenceString[m]);
    s = 0;
    for (n1 = 0; n1 < frames; n1++) {
      if (referenceString[m] == temp[n1]) {
        s++;
        pageFaults--;
        count[referenceString[m]]++;
      }
    }
    pageFaults++;
    if ((pageFaults <= frames) && (s == 0)) {
      temp[m] = referenceString[m];
      count[referenceString[m]]++;
    } else if (s == 0) {
      int min = INT_MAX, index = -1;
      for (int j = 0; j < frames; j++) {
        if (count[temp[j]] < min) {
          min = count[temp[j]];
          index = j;
        }
      }
      temp[index] = referenceString[m];
      count[referenceString[m]]++;
    }
    for (n1 = 0; n1 < frames; n1++) {
      if (temp[n1] != -1)
        printf("%d\t\t", temp[n1]);
      else
        printf("-\t\t");
    }
    if (s == 0)
      printf("PF\n");
    else
      printf("PH\n");
  }
  printf("Total Page Faults:\t%d\n", pageFaults);
}

int main() {
  int frames, n, free_f;
  int referenceString[100];

  readInput(&frames, &n, referenceString, &free_f);

  while (1) {
    int choice;
    printf("\nPAGE REPLACEMENT ALGORITHMS\n");
    printf("1. FIFO\n");
    printf("2. OPTIMAL\n");
    printf("3. LRU\n");
    printf("4. LFU\n");
    printf("5. EXIT\n");
    printf("Enter your option: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      fifo(referenceString, n, frames);
      break;
    case 2:
      optimal(referenceString, n, frames);
      break;
    case 3:
      lru(referenceString, n, frames);
      break;
    case 4:
      lfu(referenceString, n, frames);
      break;
    case 5:
      exit(0);
    default:
      printf("Invalid option! Please try again.\n");
    }
  }

  return 0;
}
