// Exam Grader Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

const double MAX_SIZE = 20;

void getAnswers(string filename1, string filename2, char correctarr[],  char studentarr[], int x)
{
    std::ifstream File1(filename1);
    std::ifstream File2(filename2);

    if (!File1 && !File2)
    {
        std::cerr << "Error Opening File!" << std::endl;
        //return 1;
    }


    while (File1 >> correctarr[x])
    {
        //std::cout << std::setw(3) << correct[x] << std::endl;
        x++;
    }

    x = 0;

    while (File2 >> studentarr[x])
    {
        //std::cout << std::setw(3) << correctarr[x] << std::setw(3) << studentarr[x] << std::endl;
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
            numarr[x] = x + 1;
            comparearr[x][0] = correctarr[x];
            comparearr[x][1] = studentarr[x];
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
    
    cout << "Exam Report Details" << endl;
    cout << "Number of questions missed: " << missed << endl;
    cout << "Missed questions and correct answers:" << endl;
    cout << setw(11) << left << "Question" << setw(17) << left << "Correct Answer" << setw(14) << left << "Your Answer" << endl;
    
    
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


    /*for (x = 0; x <= (MAX_SIZE - 1); x++)
    {
        if (number[x] != 0 && compare[x][0] != 0 && compare[x][1] != 0)
        {
            std::cout << std::setw(5) << number[x] << std::setw(5) << compare[x][0] << std::setw(5) << compare[x][1] << std::endl;
        }
    }*/
    //cout << student[5] << endl;

    /*for (x = 0; x <= (MAX_SIZE - 1); x++)
    {
        if (correct[x] != student[x])
        {
            number[x] = x+1;
            compare[x][0] = correct[x];
            compare[x][1] = student[x];
            wrongAnswers++;
        }

        else
        {
            number[x] = 0;
            compare[x][0] = 0;
            compare[x][1] = 0;
        }

        if (number[x] != 0 && compare[x][0] != 0 && compare[x][1] != 0)
        {
            std::cout << std::setw(5) << number[x] <<std::setw(5) << compare[x][0] << std::setw(5) << compare[x][1] << std::endl;
        }


    }*/

    //std::cout << std::endl << currentSize << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
