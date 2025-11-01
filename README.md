🎓 Student Feedback Tracking System (C Program)
📋 Overview

The Student Feedback Tracking System is a console-based C program designed to manage and analyze student feedback for different courses using linked lists.
It allows you to dynamically add, search, analyze, and clone feedback records — ideal for practicing data structures and memory management concepts in C.

🧩 Features

✅ Add Feedback – Dynamically insert new feedback entries (Student ID, Course Code, Rating, Comments)
🔍 Search Feedback – Search feedback by Student ID or Course Code
📊 Average Rating Calculation – Compute the average feedback rating for each course
🔁 Reverse Display – Display all feedbacks in reverse order using recursion
📋 Clone Feedback List – Create a duplicate copy of all feedback records
📂 Display All Feedback – View all feedbacks currently stored in the system

🧠 Data Structure Used

The program uses a Singly Linked List for dynamic storage of feedback entries.
Each node contains:

studentId (string)

courseCode (string)

rating (integer 1–5)

comments (string)

next pointer (to next feedback node)

⚙️ How to Run

Clone or download the repository:

git clone https://github.com/your-username/student-feedback-tracking-system.git
cd student-feedback-tracking-system


Compile the code:

gcc feedback_system.c -o feedback_system


Run the program:

./feedback_system

🧾 Example Menu Output
--- Student Feedback Tracking System ---
1. Add Feedback
2. Search by Student ID
3. Search by Course Code
4. Calculate Average Rating per Course
5. Display Feedbacks in Reverse Order
6. Clone Feedback List
7. Display All Feedbacks
8. Exit
Enter your choice:

🧑‍💻 Sample Input & Output

Input Example

Enter Student ID: S101
Enter Course Code: CS101
Enter Rating (1–5): 4
Enter Comments: Very informative course!


Output Example

Feedback added successfully!
Average Rating for CS101: 4.00

🧰 Tech Stack

Language: C

Data Structure: Linked List

Concepts Used: Dynamic Memory Allocation, Recursion, Structs, Deep Copy

📚 Learning Objectives

This project helps you:

Understand linked list manipulation in C

Practice dynamic memory allocation and pointer handling

Learn recursive operations for list traversal

Implement deep cloning and aggregation operations

🏁 Future Enhancements

Add file handling to save/load feedback data

Implement feedback deletion or update options

Add average report for all courses in one view
