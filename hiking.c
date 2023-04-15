#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct hiking {
    char *name;
    float length, height;
    struct hiking *next;
} HIKE;

HIKE *hikes = NULL;

char end[3] = "END";

float totalLength = 0.00;
float totalHeight = 0.00;

// creates a new element given the text, length and height values
HIKE *newelement(char *text, float length, float height) {
	HIKE *newp;
	newp = (HIKE *) malloc (sizeof(HIKE));
	newp->name = (char *) malloc(strlen(text) + 1);
        strcpy(newp->name, text);
        newp->length = length;
        newp->height = height;
        newp->next = NULL;
    totalLength = totalLength + length;
    totalHeight = totalHeight + height;
	return newp;
}

// appending a new hike element to the linked list
HIKE *append (HIKE *head, HIKE *newp) {
	HIKE *p2; 	
	if (head == NULL)
		return newp;
    // finding the end of list
	for (p2 = head; p2->next != NULL; p2 = p2->next);
	p2->next = newp;
	return head;
}

// using pointer-to-pointer to print out the result
void printEndResult(HIKE **toPrint) {
	HIKE **nextHike = toPrint;
    printf("---------------------------------------------- \n PRINTING ALL REGISTERED HIKES \n Total length: %.2f \n Total height: %.2f \n---------------------------------------------- \n", totalLength, totalHeight);
    int i = 1;
	while ((*nextHike) != NULL) {
		printf(" Hike number %d: \n Hike: %s \n Length: %.2f \n Height: %.2f \n---------------------------------------------- \n", i, (*nextHike)->name, (*nextHike)->length, (*nextHike)->height);
		nextHike = &(*nextHike)->next;
        i++;
	}
    exit(0);
}

// checks if the string is "END", and parses it to a float value if not
float parse_float(char* string) {
    string[strcspn(string, "\n")] = '\0';
    if(strcmp(string, end) == 0) {
        printEndResult(&hikes);
    }

    return atof(string);
}


// main method, will take the inputs and call other functions as needed. Will run until the program exits (upon "END"-input)
int main() {
    float length, height;
    char name[30];
    char input[10];

    printf("Register new hike, type %s to print all registered hikes \n---------------------------------------------- \n", end);
    while(1) {
        printf("Hike name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        if(strcmp(name, end) == 0) {
            printEndResult(&hikes);
        }

        printf("Hike length (in kilometers): ");
        fgets(input, sizeof(input), stdin);
        length = parse_float(input);

        printf("Hike height (in kilometers): ");
        fgets(input, sizeof(input), stdin);
        height = parse_float(input);

        hikes = append(hikes, newelement(name, length, height));
        printf("---------------------------------------------- \n");
    }
}