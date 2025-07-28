// Exam Grader Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

int main()
{
    std::ifstream File1("CorrectAnswers.txt");
    std::ifstream File2("StudentAnswers.txt");
            
    if (!File1 && !File2)
    {
        std::cerr << "Error Opening File!" << std::endl;
        return 1;
    }

    char correct[20];
    char student[20];
    int x = 0;
    int y = 0;

    while (File1 >> correct[x])
    {
        std::cout << correct[x] << std::endl;
        x++;
    }

    while (File2 >> student[y])
    {
        std::cout << student[y] << std::endl;
        y++;
    }
    
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
