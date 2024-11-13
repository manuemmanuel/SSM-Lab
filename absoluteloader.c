#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() {
    FILE *oc;
    int i, j, length;
    char line[50], arr[60];

    oc = fopen("objectcode.txt", "r");
    if (oc == NULL) {
        perror("Error opening file");
        return;
    }

    fscanf(oc, "%s", line);
    printf("The Program name is: ");
    for (int i = 2; i < 5; i++) {
        printf("%c", line[i]);
    }
    printf("\n");

    fscanf(oc, "%s", line);  // Initial read for the while loop

    while (!feof(oc)) {
        if (line[0] == 'T') {
            for (i = 0; i < 6; i++) {
                arr[i] = line[i + 2];
            }
            arr[i] = '\0';
            length = atoi(arr);
            i = 12;

            while (line[i] != '\0') {
                if (line[i] != '^') {
                    printf("%d: %c%c\n", length, line[i], line[i + 1]);
                    length++;
                    i += 2;
                } else {
                    i++;
                }
            }
        } else if (line[0] == 'E') {
            break;
        }

        fscanf(oc, "%s", line);  // Read the next line at the end of the loop
    }

    fclose(oc);
}
