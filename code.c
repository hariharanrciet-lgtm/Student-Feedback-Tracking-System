#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a feedback node
struct Feedback {
    char studentId[20];
    char courseCode[20];
    int rating;
    char comments[100];
    struct Feedback *next;
};

// Function prototypes
struct Feedback* addFeedback(struct Feedback *head);
void searchByStudent(struct Feedback *head, char *studentId);
void searchByCourse(struct Feedback *head, char *courseCode);
void calculateAverage(struct Feedback *head, char *courseCode);
void reverseDisplay(struct Feedback *head);
void reverseDisplayRec(struct Feedback *node);
struct Feedback* cloneFeedbackList(struct Feedback *head);
void displayAll(struct Feedback *head);
void freeList(struct Feedback *head);

// Function to create and add a new feedback dynamically
struct Feedback* addFeedback(struct Feedback *head) {
    struct Feedback *newNode = (struct Feedback*)malloc(sizeof(struct Feedback));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return head;
    }

    printf("Enter Student ID: ");
    scanf("%s", newNode->studentId);
    printf("Enter Course Code: ");
    scanf("%s", newNode->courseCode);
    printf("Enter Rating (1–5): ");
    scanf("%d", &newNode->rating);
    getchar(); // consume newline
    printf("Enter Comments: ");
    fgets(newNode->comments, sizeof(newNode->comments), stdin);
    newNode->comments[strcspn(newNode->comments, "\n")] = '\0'; // remove newline

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Feedback *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Feedback added successfully!\n");
    return head;
}

// Search feedback by student ID
void searchByStudent(struct Feedback *head, char *studentId) {
    struct Feedback *temp = head;
    int found = 0;
    printf("\nFeedback for Student ID: %s\n", studentId);
    while (temp != NULL) {
        if (strcmp(temp->studentId, studentId) == 0) {
            printf("Course: %s | Rating: %d | Comments: %s\n", temp->courseCode, temp->rating, temp->comments);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found)
        printf("No feedback found for this student.\n");
}

// Search feedback by course code
void searchByCourse(struct Feedback *head, char *courseCode) {
    struct Feedback *temp = head;
    int found = 0;
    printf("\nFeedback for Course: %s\n", courseCode);
    while (temp != NULL) {
        if (strcmp(temp->courseCode, courseCode) == 0) {
            printf("Student: %s | Rating: %d | Comments: %s\n", temp->studentId, temp->rating, temp->comments);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found)
        printf("No feedback found for this course.\n");
}

// Calculate average rating for a given course
void calculateAverage(struct Feedback *head, char *courseCode) {
    struct Feedback *temp = head;
    int total = 0, count = 0;
    while (temp != NULL) {
        if (strcmp(temp->courseCode, courseCode) == 0) {
            total += temp->rating;
            count++;
        }
        temp = temp->next;
    }
    if (count > 0)
        printf("Average Rating for %s: %.2f\n", courseCode, (double)total / count);
    else
        printf("No feedback available for this course.\n");
}

// Reverse display (recursive)
void reverseDisplay(struct Feedback *head) {
    printf("\nFeedbacks in Reverse Order:\n");
    reverseDisplayRec(head);
}

void reverseDisplayRec(struct Feedback *node) {
    if (node == NULL)
        return;
    reverseDisplayRec(node->next);
    printf("Student: %s | Course: %s | Rating: %d | Comments: %s\n",
           node->studentId, node->courseCode, node->rating, node->comments);
}

// Clone feedback list
struct Feedback* cloneFeedbackList(struct Feedback *head) {
    if (head == NULL)
        return NULL;

    struct Feedback *cloneHead = NULL, *cloneTail = NULL, *temp = head;

    while (temp != NULL) {
        struct Feedback *newNode = (struct Feedback*)malloc(sizeof(struct Feedback));
        strcpy(newNode->studentId, temp->studentId);
        strcpy(newNode->courseCode, temp->courseCode);
        newNode->rating = temp->rating;
        strcpy(newNode->comments, temp->comments);
        newNode->next = NULL;

        if (cloneHead == NULL) {
            cloneHead = newNode;
            cloneTail = newNode;
        } else {
            cloneTail->next = newNode;
            cloneTail = newNode;
        }
        temp = temp->next;
    }

    printf("\nFeedback list cloned successfully.\n");
    return cloneHead;
}

// Display all feedback
void displayAll(struct Feedback *head) {
    struct Feedback *temp = head;
    if (temp == NULL) {
        printf("No feedbacks available.\n");
        return;
    }
    printf("\nAll Feedback Entries:\n");
    while (temp != NULL) {
        printf("Student: %s | Course: %s | Rating: %d | Comments: %s\n",
               temp->studentId, temp->courseCode, temp->rating, temp->comments);
        temp = temp->next;
    }
}

// Free memory
void freeList(struct Feedback *head) {
    struct Feedback *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    struct Feedback *head = NULL, *clonedList = NULL;
    int choice;
    char searchKey[50];

    do {
        printf("\n--- Student Feedback Tracking System ---\n");
        printf("1. Add Feedback\n");
        printf("2. Search by Student ID\n");
        printf("3. Search by Course Code\n");
        printf("4. Calculate Average Rating per Course\n");
        printf("5. Display Feedbacks in Reverse Order\n");
        printf("6. Clone Feedback List\n");
        printf("7. Display All Feedbacks\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                head = addFeedback(head);
                break;
            case 2:
                printf("Enter Student ID: ");
                scanf("%s", searchKey);
                searchByStudent(head, searchKey);
                break;
            case 3:
                printf("Enter Course Code: ");
                scanf("%s", searchKey);
                searchByCourse(head, searchKey);
                break;
            case 4:
                printf("Enter Course Code: ");
                scanf("%s", searchKey);
                calculateAverage(head, searchKey);
                break;
            case 5:
                reverseDisplay(head);
                break;
            case 6:
                clonedList = cloneFeedbackList(head);
                printf("Displaying cloned list:\n");
                displayAll(clonedList);
                break;
            case 7:
                displayAll(head);
                break;
            case 8:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 8);

    freeList(head);
    freeList(clonedList);
    return 0;
}
