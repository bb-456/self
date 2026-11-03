// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData {
    // C++ Structure
    struct Student {
        int rollNo;
        string name;
        int marks;
    }

    // Array of Students
    Student[] public students;

    function addStudent(int rollNo, string memory name, int marks) public {
        students.push(Student(rollNo, name, marks));
    }
}