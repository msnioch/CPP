/*Quiz game v4 - it's a game that read the questions from a text file. The application'll try to open the text file in application folder.
 * If opening the text file fails, you will be asked for the file path.*/

#include <iostream>
#include <memory>                                                       //Library for unique_ptr and make_unique.
#include <fstream>                                                      //Library for input data from file output to file
#include <string>                                                       //Library for getline()
#include <algorithm>                                                    //Library for transform()
#include <Windows.h>                                                    //Library for Sleep().
#include <cstdlib>                                                      //Library for getchar() and system("CLS").

using namespace std;

int points_Sum = 0;                                                     //Declarate global integer of sum points.

string file_Patch = "Quiz.txt";                                         //Declarate global string of question file patch.

fstream file;                                                           //Declarate file stream variable file.

class Quiz
{
    int number;                                                         //Declarate integer of question number.
    
    string content;                                                     //Declarate string of content.

    string answer_A, answer_B, answer_C, answer_D;                      //Declarate string of answer from a to d.

    string user_Answer, correct_Answer;                                 //Declarate string of user and correct answer.

    fstream question_File;                                              //Declarate file stream variable question_File.

public:
    void Load (int num)                                                 //Method Load() with input num of question number.
    {
        number = num;                                                   //Assign variable question number.

        string temporary_Line;                                          //Declarate temporary_Line.

        int current_Line = 0;                                           //Declarate counter of current line.

        int first_Line = (number - 1) * 6;                              //Compute the first line number for current question.

        question_File.open (file_Patch, ios::in);                       //Open question_File with file_Patch to read.

        while (getline (question_File, temporary_Line))                 //Assign question_File lines to temporary_Line.
        {
            if (current_Line == first_Line)
            {
                content = temporary_Line;                               //Assign temporary_Line 0, 6, 12 ... to variable content.
            }

            else if (current_Line == first_Line + 1)
            {
                answer_A = temporary_Line;                              //Assign temporary_Line 1, 7, 13 ... to variable answer_A.
            }

            else if (current_Line == first_Line + 2)
            {
                answer_B = temporary_Line;                              //Assign temporary_Line 2, 8, 14 ... to variable answer_B.
            }

            else if (current_Line == first_Line + 3)
            {
                answer_C = temporary_Line;                              //Assign temporary_Line 3, 9, 15 ... to variable answer_C.
            }

            else if (current_Line == first_Line + 4)
            {
                answer_D = temporary_Line;                              //Assign temporary_Line 4, 10, 16 ... to variable answer_D.
            }

            else if (current_Line == first_Line + 5)
            {
                correct_Answer = temporary_Line;                        //Assign temporary_Line 5, 11, 17 ... to variable correct_Answer.
            }

            current_Line++;                                             //Increment current line number.
        }

        question_File.close();                                          //Close question_File.

        Show();
    }

    void Show()
    {
        cout << number << ". " << content << endl;                      //Show the question content.

        cout << "a) " << answer_A << endl;                              //Show the answer a.

        cout << "b) " << answer_B << endl;                              //Show the answer b.

        cout << "c) " << answer_C << endl;                              //Show the answer c.

        cout << "d) " << answer_D << endl;                              //Show the answer d.

        cout << "\nWrite correct answer a, b, c or d and press ENTER: ";    //Show the user answers.

        CheckAnswer();
    }

    void CheckAnswer()
    {
        cin >> user_Answer;                                             //Read user answer and assign it to variable.

        transform (user_Answer.begin(), user_Answer.end(), user_Answer.begin(), ::tolower);     //Convert user answer to small letters.

        if (user_Answer == correct_Answer)
        {
            Sleep(250);                                                 //Stop the console for 0.25 second.

            cout << "\nGood! You get a point!" << endl;

            points_Sum++;                                               //If user answer is true then add 1 point.

            Sleep(2000);                                                //Stop the console for 2 seconds.
        }

        else
        {
            Sleep(250);                                                 //Stop the console for 0.25 second.

            cout << "\nThis is not the correct answer! You don't get a point!" << endl;

            cout << "The correct answer is " << correct_Answer << "!" << endl;

            Sleep(6000);                                                //Stop the console for 2 seconds.
        }
    }
};

bool File_Exists (string &patch)                                        //Function test if the file exists with input of file patch (by reference).
{
    file.open (patch, ios::in);                                         //Open file with patch to read.

    if (! file.good())                                                  //Negation if the patch is correct.
    {
        cout << "\nThe question file doesn't exists!\nPlease write the quesion file patch or write END then press ENTER to exit application: ";
        
        cin >> patch;                                                   //Change file patch or exit application with command END.
        
        if (patch == "END")
        {
            exit(0);                                                    //Exit application.
        }

        return false;                                                   //If the quesion file not exists return true.
    }

    else
    {
        file.close();                                                   //Close file.

        return true;                                                    //If the quesion file exists return true.
    }
}

int how_Many_Lines()                                                    //Function return number of lines in file.
{
    int line_Counter = 0;                                               //Declaration of line_Counter.

    string line;                                                        //Declaration of temporary line.

    file.open(file_Patch, ios::in);                                     //Open file with patch to read.

    while (getline (file, line))                                        //Assign file lines to line.
    {
        line_Counter++;                                                 //Increment the number of line_Counter.
    }

    file.close();                                                       //Close file.

    return line_Counter;
}

int main()
{
    cout << "*************** C++ Quiz ***************" << endl;

    cout << "Press ENTER to start the Quiz. Good Luck!";

    getchar();                                                          //Stop console.

    while (! File_Exists (file_Patch));                                 //If the file not exsist, the condition is true.

    int how_Many_Questions = how_Many_Lines() / 6;                      //Compute number of questions in file. One question has 6 lines.
    
    unique_ptr<Quiz[]> Question = make_unique<Quiz[]> (how_Many_Questions);     //Declarate dynamic allocated array of class Quiz with smart pointer.

    //Quiz* Question = new Quiz [how_Many_Questions];                   //Dynamic allocated array with raw pointer (possible instead smart pointer).

    for (int question_Number = 0; question_Number < how_Many_Questions; question_Number++)  //Loop controls question number.
    {
        system("CLS");                                                  //The method clear console.

        Question[question_Number].Load (question_Number + 1);           //Create new object of class Quiz.
    }

    //delete[] Question;                                                //Delete dynamic allocated array (only in case raw pointer).

    system("CLS");                                                      //The method clear console.

    if (points_Sum == how_Many_Questions)
    {
        cout << "Excellent! You got all " << points_Sum << " points!" << endl;
    }

    else if (points_Sum >= (how_Many_Questions * 0.67))
    {
        cout << "Very Good! You got " << points_Sum << " points!" << endl;
    }

    else
    {
        cout << "You got " << points_Sum << " points!" << endl;
    }

    cout << "\n*************** End Quiz ***************" << endl;

    cout << "Press ENTER to exit.";

    getchar();  getchar();                                              //Stop console.

    return 0;
}