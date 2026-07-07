[7 Jul 2026 8:19 pm] Emmanuel Sarkodie: #include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int numberOfSemesters;
string course[] = {"course1", "course2", "course3", "course4", "course5", "course6", "course7", "course8"};
string courseSem2[] = {"course1.1", "course2.1", "course3.1", "course4.1", "course5.1", "course6.1", "course7.1", "course8.1"};
string courseSem3[] = {"course1.2", "course2.2", "course3.2", "course4.2", "course5.2", "course6.2", "course7.2", "course8.2"};
int creditHours[8];
int creditHoursSem2[8];
int creditHoursSem3[8];
float score[8];
float scoreSem2[8];
float scoreSem3[8];
string grade[8];
string gradeSem2[8];
string gradeSem3[8];
float gradePoint[8];
float gradePointSem2[8];
float gradePointSem3[8];
float gpa, gpaSem2, gpaSem3, cgpa;
string gpaClass;
string cgpaClass;
void validateInt(int& input) {
    int fails;
    fails = 0;
    while (true) {
        cin >>input;
        if (cin.fail()) {
            fails++;
            if (fails == 3) {
                cout <<"You don't seem to understand..."<<endl;
                cout <<"Try again later!"<<endl;
                return;
            }
            cin.clear();
            cin.ignore(1000, '\n');
            cout <<"Error: Invalid option!"<<endl;
            cout <<"Try again:"<<endl;
        } else {
            break;
        }
    }
}
void validateScore(float& input) {
    int fails;
    fails = 0;
    while (true) {
        cin >>input;
        if (cin.fail()) {
            fails++;
            if (fails == 3) {
                cout <<"You don't seem to understand..."<<endl;
                cout <<"Try again later!"<<endl;
                return;
            }
            cin.clear();
            cin.ignore(1000, '\n');
            cout <<"Error: Invalid option!"<<endl;
            cout <<"Try again:"<<endl;
        } else {
            if (input < 0 || input > 100) {
                fails++;
                if (fails == 3) {
                    cout <<"You don't seem to understand..."<<endl;
                    cout <<"Try again later!"<<endl;
                    return;
                }
                cout <<"Score must be between 0 and 100"<<endl;
                cout <<"Try again:"<<endl;
            } else {
                break;
            }
        }
    }
}
void determineGPAClass() {
    if (gpa >= 3.60) {
        gpaClass = "First Class";
    } else if (gpa >= 3.00) {
        gpaClass = "Second Class Upper";
    } else if (gpa >= 2.00) {
        gpaClass = "Second Class Lower";
    } else if (gpa >= 1.00) {
        gpaClass = "Third Class";
    } else {
        gpaClass = "Fail";
    }
}
void determineCGPAClass() {
    if (cgpa >= 3.60) {
        cgpaClass = "First Class";
    } else if (cgpa >= 3.00) {
        cgpaClass = "Second Class Upper";
    } else if (cgpa >= 2.00) {
        cgpaClass = "Second Class Lower";
    } else if (cgpa >= 1.00) {
        cgpaClass = "Third Class";
    } else {
        cgpaClass = "Fail";
    }
}
void readCourses(string course[]) {
    cout <<"Please, Input the course codes;"<<endl;
    for(int i=0; i<8; i++) {
        cout <<"Course "<<i+1<<":"<<endl;
        cin >>course[i];
    }
}
void readMultipleSemCourses(string courseSem2[], string courseSem3[]) {
    cout <<"Please, Input the course codes for Semester 2;"<<endl;
    for(int i=0; i<8; i++) {
        cout <<"Course "<<i+1<<":"<<endl;
        cin >>courseSem2[i];
    }
    cout <<"Please, Input the course codes for Semester 3;"<<endl;
    for(int i=0; i<8; i++) {
        cout <<"Course "<<i+1<<":"<<endl;
        cin >>courseSem3[i];
    }
}
void readCreditHours(int creditHours[]) {
    cout <<"Please, Input the credit for each course respectively."<<endl;
    for(int i=0; i<8; i++) {
        cout <<"Credit "<<i+1<<":"<<endl;
        while (true) {
            validateInt(creditHours[i]);
[7 Jul 2026 8:19 pm] Emmanuel Sarkodie: if (creditHours[i] < 1 || creditHours[i] > 4) {
                int fails = 0;
                fails++;
                if (fails == 3) {
                    cout <<"You don't seem to understand..."<<endl;
                    cout <<"Try again later!"<<endl;
                    return;
                }
                cout <<"Credit hours must be between 1 and 4!"<<endl;
                cout <<"Try again:"<<endl;
            } else {
                break;
            }
        }
    }
}
void readMultipleSemCreditHours(int creditHoursSem2[], int creditHoursSem3[]) {
    cout <<"Please, Input the credit for each course respectively for Semester 2."<<endl;
    for(int i=0; i<8; i++) {
        cout <<"Credit "<<i+1<<":"<<endl;
        while (true) {
            validateInt(creditHoursSem2[i]);
            if (creditHoursSem2[i] < 1 || creditHoursSem2[i] > 4) {
                int fails = 0;
                fails++;
                if (fails == 3) {
                    cout <<"You don't seem to understand..."<<endl;
                    cout <<"Try again later!"<<endl;
                    return;
                }
                cout <<"Credit hours must be between 1 and 4!"<<endl;
                cout <<"Try again:"<<endl;
            } else {
                break;
            }
        }
    }
    cout <<"Please, Input the credit for each course respectively for Semester 3."<<endl;
    for(int i=0; i<8; i++) {
        cout <<"Credit "<<i+1<<":"<<endl;
        while (true) {
            validateInt(creditHoursSem3[i]);
            if (creditHoursSem3[i] < 1 || creditHoursSem3[i] > 4) {
                int fails = 0;
                fails++;
                if (fails == 3) {
                    cout <<"You don't seem to understand..."<<endl;
                    cout <<"Try again later!"<<endl;
                    return;
                }
                cout <<"Credit hours must be between 1 and 4!"<<endl;
                cout <<"Try again:"<<endl;
            } else {
                break;
            }
        }
    }
}
void assignGradesGCTU() {
    cout <<"Let's go ahead and record your scores for each course!"<<endl;
    for (int i=0; i<8; i++) {
        cout <<"Score "<<i+1<<":"<<endl;
        validateScore(score[i]);
        if (score[i] >= 80) {
            grade[i] = "A";
            gradePoint[i] = 4.0;
        } else if (score[i] >= 75) {
            grade[i] = "A-";
            gradePoint[i] = 3.75;
        } else if (score[i] >= 70) {
            grade[i] = "B+";
            gradePoint[i] = 3.50;
        } else if (score[i] >= 65) {
            grade[i] = "B";
            gradePoint[i] = 3.25;
        } else if (score[i] >= 60) {
            grade[i] = "B-";
            gradePoint[i] = 3.0;
        } else if (score[i] >= 55) {
            grade[i] = "C+";
            gradePoint[i] = 2.75;
        } else if (score[i] >= 50) {
            grade[i] = "C";
            gradePoint[i] = 2.5;
        } else if (score[i] >= 45) {
            grade[i] = "C-";
            gradePoint[i] = 2.0;
        } else if (score[i] >= 40) {
            grade[i] = "D";
            gradePoint[i] = 1.5;
        } else {
            grade[i] = "F";
            gradePoint[i] = 0;
        }
    }
}
void assignGradesUCC() {
    cout <<"Let's go ahead and record your scores for each course!"<<endl;
    for (int i=0; i<8; i++) {
        cout <<"Score "<<i+1<<":"<<endl;
        validateScore(score[i]);
        if (score[i] >= 80) {
            grade[i] = "A";
            gradePoint[i] = 4.0;
        } else if (score[i] >= 75) {
            grade[i] = "B+";
            gradePoint[i] = 3.5;
        } else if (score[i] >= 70) {
            grade[i] = "B";
            gradePoint[i] = 3.0;
        } else if (score[i] >= 65) {
            grade[i] = "C+";
[7 Jul 2026 8:19 pm] Emmanuel Sarkodie: gradePoint[i] = 2.5;
        } else if (score[i] >= 60) {
            grade[i] = "C";
            gradePoint[i] = 2.0;
        } else if (score[i] >= 55) {
            grade[i] = "D+";
            gradePoint[i] = 1.5;
        } else if (score[i] >= 50) {
            grade[i] = "D";
            gradePoint[i] = 1.0;
        } else {
            grade[i] = "E";
            gradePoint[i] = 0;
        }
    }
}
void calculateGPA() {
    float totalGradePoints = 0;
    int totalCreditHours = 0;
    for (int i=0; i<8; i++) {
        totalGradePoints += gradePoint[i] * creditHours[i];
        totalCreditHours += creditHours[i];
    }
    gpa = totalGradePoints / totalCreditHours;
}
void calculateCGPA() {
    float totalGradePoints = 0;
    int totalCreditHours = 0;
    switch (numberOfSemesters) {
        case 1: {
            for (int i=0; i<8; i++) {
                totalGradePoints += gradePoint[i] * creditHours[i];
                totalCreditHours += creditHours[i];
            }
        }
        case 2: {
            for (int i=0; i<8; i++) {
                totalGradePoints += gradePoint[i] * creditHours[i];
                totalCreditHours += creditHours[i];
            }
            for (int i=0; i<8; i++) {
                totalGradePoints += gradePointSem2[i] * creditHoursSem2[i];
                totalCreditHours += creditHoursSem2[i];
            }
        }
        case 3: {
            for (int i=0; i<8; i++) {
                totalGradePoints += gradePoint[i] * creditHours[i];
                totalCreditHours += creditHours[i];
            }
            for (int i=0; i<8; i++) {
                totalGradePoints += gradePointSem2[i] * creditHoursSem2[i];
                totalCreditHours += creditHoursSem2[i];
            }
            for (int i=0; i<8; i++) {
                totalGradePoints += gradePointSem3[i] * creditHoursSem3[i];
                totalCreditHours += creditHoursSem3[i];
            }
        }
    }
    cgpa = totalGradePoints / totalCreditHours;
}
void displayResults() {
    cout <<"Below are your results:"<<endl;
    cout <<"------------------------------------------------------------"<<endl;
    cout <<setw(15)<<"COURSE      "<<left<<setw(12)<<"CREDIT HOURS\t"<<left<<setw(6)<<"SCORE\t"<<left<<setw(6)<<"GRADE\t"<<left<<setw(12)<<"GRADE POINT"<<endl;
    for (int i=0; i<8; i++) {
        cout <<left<<setw(15)<<course[i]<<left<<setw(5)<<"     "<<creditHours[i]<<setw(12)<<"  "<<score[i]<<setw(7)<<"  "<<grade[i]<<setw(7)<<"    "<<gradePoint[i]<<endl;
    }
    cout <<"------------------------------------------------------------"<<endl;
    determineGPAClass();
    determineCGPAClass();
    cout <<left<<setw(15)<<"GPA: "<<setw(3)<<"  "<<fixed<<setprecision(2)<<gpa<<endl;
    cout <<left<<setw(15)<<"Classification: "<<gpaClass<<endl;
}
void calculateSingleGPA() {
    readCourses(course);
    cout <<endl<<endl<<endl;
    readCreditHours(creditHours);
    cout <<endl<<endl<<endl;
    assignGradesGCTU();
    calculateGPA();
    cout <<endl<<endl<<endl;
    displayResults();
    return;
}
void displayFullResults() {
    cout <<"Below are your results:"<<endl;
    cout <<"------------------------------------------------------------"<<endl;
    cout <<setw(15)<<"COURSE      "<<left<<setw(12)<<"CREDIT HOURS\t"<<left<<setw(6)<<"SCORE\t"<<left<<setw(6)<<"GRADE\t"<<left<<setw(12)<<"GRADE POINT"<<endl;
    cout <<"------------------------------------------------------------"<<endl;
    switch (numberOfSemesters) {
        case 1: {
            for (int i=0; i<8; i++) {
                cout <<left<<setw(15)<<course[i]<<left<<setw(5)<<"     "<<creditHours[i]<<setw(12)<<"  "<<score[i]<<setw(7)<<"  "<<grade[i]<<setw(7)<<"    "<<gradePoint[i]<<endl;
            }
            break;
        }
        case 2: {
[7 Jul 2026 8:19 pm] Emmanuel Sarkodie: for (int i=0; i<8; i++) {
                cout <<left<<setw(15)<<course[i]<<left<<setw(5)<<"     "<<creditHours[i]<<setw(12)<<"  "<<score[i]<<setw(7)<<"  "<<grade[i]<<setw(7)<<"    "<<gradePoint[i]<<endl;
            }
            cout <<"------------------------------------------------------------"<<endl;
            cout <<left<<setw(15)<<"GPA: "<<setw(3)<<"  "<<fixed<<setprecision(2)<<gpa<<endl;
            determineGPAClass();
            cout <<left<<setw(15)<<"Classification: "<<gpaClass<<endl<<endl;
            cout <<"Semester 2 Results:"<<endl;
            cout <<"------------------------------------------------------------"<<endl;
            for (int i=0; i<8; i++) {
                cout <<left<<setw(15)<<courseSem2[i]<<left<<setw(5)<<"     "<<creditHoursSem2[i]<<setw(12)<<"  "<<scoreSem2[i]<<setw(7)<<"  "<<gradeSem2[i]<<setw(7)<<"    "<<gradePointSem2[i]<<endl;
            }
            break;
        }
        case 3: {
            for (int i=0; i<8; i++) {
                cout <<left<<setw(15)<<course[i]<<left<<setw(5)<<"     "<<creditHours[i]<<setw(12)<<"  "<<score[i]<<setw(7)<<"  "<<grade[i]<<setw(7)<<"    "<<gradePoint[i]<<endl;
            }
            cout <<"------------------------------------------------------------"<<endl;
            cout <<left<<setw(15)<<"GPA: "<<setw(3)<<"  "<<fixed<<setprecision(2)<<gpa<<endl;
            determineGPAClass();
            cout <<left<<setw(15)<<"Classification: "<<gpaClass<<endl<<endl;
            cout <<"Semester 2 Results:"<<endl;
            cout <<"------------------------------------------------------------"<<endl;
            for (int i=0; i<8; i++) {
                cout <<left<<setw(15)<<courseSem2[i]<<left<<setw(5)<<"     "<<creditHoursSem2[i]<<setw(12)<<"  "<<scoreSem2[i]<<setw(7)<<"  "<<gradeSem2[i]<<setw(7)<<"    "<<gradePointSem2[i]<<endl;
            }
            cout <<"------------------------------------------------------------"<<endl;
            cout <<left<<setw(15)<<"GPA: "<<setw(3)<<"  "<<fixed<<setprecision(2)<<gpa<<endl;
            determineGPAClass();
            cout <<left<<setw(15)<<"Classification: "<<gpaClass<<endl<<endl;
            cout <<"Semester 3 Results:"<<endl;
            cout <<"------------------------------------------------------------"<<endl;
            for (int i=0; i<8; i++) {
                cout <<left<<setw(15)<<courseSem3[i]<<left<<setw(5)<<"     "<<creditHoursSem3[i]<<setw(12)<<"  "<<scoreSem3[i]<<setw(7)<<"  "<<gradeSem3[i]<<setw(7)<<"    "<<gradePointSem3[i]<<endl;
            }
            break;
        }
    }
    cout <<"------------------------------------------------------------"<<endl;
    cout <<left<<setw(15)<<"CGPA: "<<setw(3)<<"  "<<fixed<<setprecision(2)<<cgpa<<endl;
    determineCGPAClass();
    cout <<left<<setw(15)<<"Classification: "<<cgpaClass<<endl<<endl;
}
void calculateMultipleGPAs() {
    cout <<"Kindly input the number of semesters you want to calculate the CGPA for:"<<endl;
    while (true) {
        validateInt(numberOfSemesters);
        if (numberOfSemesters < 1 || numberOfSemesters > 3) {
            int fails = 0;
            fails++;
            if (fails == 3) {
                cout <<"You don't seem to understand..."<<endl;
                cout <<"Try again later!"<<endl;
                return;
            }
            cout <<"Number of semesters must be between 1 and 3!"<<endl;
            cout <<"Try again:"<<endl;
        } else {
            break;
        }
    }
    switch (numberOfSemesters) {
        case 1: {
            calculateSingleGPA();
            break;
        }
        case 2: {
            readCourses(course);
            cout <<endl<<endl<<endl;
            readCreditHours(creditHours);
            cout <<endl<<endl<<endl;
            assignGradesGCTU();
[7 Jul 2026 8:19 pm] Emmanuel Sarkodie: cout <<endl<<endl<<endl;
            readCourses(courseSem2);
            cout <<endl<<endl<<endl;
            readCreditHours(creditHoursSem2);
            cout <<endl<<endl<<endl;
            assignGradesGCTU();
            calculateCGPA();
            cout <<endl<<endl<<endl;
            displayFullResults();
            break;
        }
        case 3: {
            readCourses(course);
            cout <<endl<<endl<<endl;
            readCreditHours(creditHours);
            cout <<endl<<endl<<endl;
            assignGradesGCTU();
            cout <<endl<<endl<<endl;
            readCourses(courseSem2);
            cout <<endl<<endl<<endl;
            readCreditHours(creditHoursSem2);
            cout <<endl<<endl<<endl;
            assignGradesGCTU();
            cout <<endl<<endl<<endl;
            readCourses(courseSem3);
            cout <<endl<<endl<<endl;
            readCreditHours(creditHoursSem3);
            cout <<endl<<endl<<endl;
            assignGradesGCTU();
            calculateCGPA();
            cout <<endl<<endl<<endl;
            displayFullResults();
            break;
        }
    return;
    }
}
int main(void) {
    int schoolChoice;
    int choiceCalculation;
    cout <<"Welcome!"<<endl;
    cout <<"I help you calculate your Grade Point Average and it's cumulative as well!"<<endl;
    cout <<"Please select your school from the list below:"<<endl;
    cout <<"1. Ghana Communications Technology University."<<endl;
    cout <<"2. University of Cape Coast."<<endl<<endl;
    cout <<"Input choice here(\"1\" or \"2\"):"<<endl;
    validateInt(schoolChoice);
    switch (schoolChoice) {
        case 1: {
            cout <<"---------GHANA COMMUNICATIONS TECHNOLOGY UNIVERSITY---------"<<endl;
            cout <<"What would you like to calculate?"<<endl;
            cout <<"Kindly choose an option from the list below:"<<endl;
            cout <<"1. GPA for a single semester."<<endl;
            cout <<"2. CGPA for a number of semesters."<<endl;
            validateInt(choiceCalculation);
            switch (choiceCalculation) {
                case 1: {
                    calculateSingleGPA();
                    break;
                }
                case 2: {
                    calculateMultipleGPAs();
                    break;
                }
                default : {
                    cout <<"Invalid input!"<<endl;
                    return 0;
                }
            }
            break;
        }
        case 2: {
            cout <<"------------------UNIVERSITY OF CAPE COAST------------------"<<endl;
            cout <<"What would you like to calculate?"<<endl;
            cout <<"Kindly choose an option from the list below:"<<endl;
            cout <<"1. GPA for a single semester."<<endl;
            cout <<"2. CGPA for a number of semesters."<<endl;
            validateInt(choiceCalculation);
            switch (choiceCalculation) {
                case 1: {
                    calculateSingleGPA();
                    break;
                }
                case 2: {
                    calculateMultipleGPAs();
                    break;
                }
                default : {
                    cout <<"Invalid input!"<<endl;
                    return 0;
                }
            }
            break;
        }
        case 3: {
            cout <<"Below are your results:"<<endl;
            cout <<"------------------------------------------------------------"<<endl;
            cout <<setw(15)<<"COURSE      "<<left<<setw(12)<<"CREDIT HOURS\t"<<left<<setw(6)<<"SCORE\t"<<left<<setw(6)<<"GRADE\t"<<left<<setw(12)<<"GRADE POINT"<<endl;
            cout <<"------------------------------------------------------------"<<endl;
            cout <<left<<setw(15)<<"MawudeKu"<<left<<setw(5)<<"     "<<"2"<<setw(12)<<"  "<<"87"<<setw(7)<<"  "<<"A+"<<setw(7)<<"    "<<"3.6"<<endl;
[7 Jul 2026 8:19 pm] Emmanuel Sarkodie: cout <<"------------------------------------------------------------"<<endl;
            cout <<left<<setw(15)<<"GPA: "<<setw(3)<<"  "<<fixed<<setprecision(2)<<gpa<<endl;
            cout <<left<<setw(15)<<"Classification: "<<endl;
            break;
        }
        default: {
            cout <<"Invalid input!"<<endl;
        }
    }
}
