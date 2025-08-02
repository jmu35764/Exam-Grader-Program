// Exam Grader Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

const double MAX_SIZE = 20;

int getAnswers(string filename1, string filename2, char correctarr[],  char studentarr[], int x)
{
    // Finds the names of the files to open
    std::ifstream File1(filename1);
    std::ifstream File2(filename2);

    // Makes sure files can be opened
    if (!File1 && !File2)
    {
        std::cerr << "Error Opening File!" << std::endl;
        return 0;
    }

    //Sets each value from the value into a spot in the array
    while (File1 >> correctarr[x])
    {
        x++;
    }

    x = 0;

    while (File2 >> studentarr[x])
    {
        x++;
    }

    x = 0;
}

void gradeExam(char correctarr[], char studentarr[], int numarr[], char comparearr[][2], double& wrngAnsw, int x)
{
    for (x = 0; x <= (MAX_SIZE - 1); x++)
    {
        if (correctarr[x] != studentarr[x])
        {
            //Store the number of the question that is marked wrong
            numarr[x] = x + 1;

            //Sets the value of the first column of correct array to match 
            // the correlated value of the correct answer
            comparearr[x][0] = correctarr[x];

            //Sets the value of the second column of correct array to match 
            // the correlated value of the wrong answer
            comparearr[x][1] = studentarr[x];

            // Tracks total number of wrong answers
            wrngAnsw++;
        }

        else
        {
            numarr[x] = 0;
            comparearr[x][0] = 0;
            comparearr[x][1] = 0;
        }

    }
}


void writeReport(int numarr[], char comparearr[][2], double missed, int x)
{
    double score = ((MAX_SIZE-missed) / MAX_SIZE)*100;
    
    // Displays the header
    cout << "Exam Report Details" << endl;
    cout << "Number of questions missed: " << missed << endl;
    cout << "Missed questions and correct answers:" << endl;
    cout << setw(11) << left << "Question" << setw(17) << left << "Correct Answer" << setw(14) << left << "Your Answer" << endl;
    
    //Displays the array values
    for (x = 0; x <= (MAX_SIZE - 1); x++)
    {
        if (numarr[x] != 0 && comparearr[x][0] != 0 && comparearr[x][1] != 0)
        {
            cout << setw(4) << right << numarr[x];
            cout << setw(14) << right << comparearr[x][0];
            cout << setw(18) << right << comparearr[x][1] << endl;
        }
    }

    cout << "Test Score:  " << score << "%" << endl;


    if (score > 70)
    {
        cout << "You passed the exam." << endl;
    }
    else
    {
        cout << "You failed the exam." << endl;
    }
}

int main()
{
    char correct[20];
    char student[20];
    char compare[20][2];
    //const int MAX_SIZE = 20;
    int number[20];
    double wrongAnswers = 0;
    int x = 0;
    int y = 0;

    string filename1 = "CorrectAnswers.txt";
    string filename2 = "StudentAnswers.txt";
    
    
    //First Function
    getAnswers(filename1, filename2, correct, student, x);
    gradeExam(correct, student, number, compare, wrongAnswers, x);

    //cout << wrongAnswers << endl;

    writeReport(number, compare, wrongAnswers, x);
}

