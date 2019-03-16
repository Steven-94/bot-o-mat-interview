#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int SetTask(int task_ID);
int TypeBonus(string R_type, int total_score, int task_ID);
bool CanCompleteTask(int task_ID, string R_type);
void ScoreThisRun(string R_name[], int R_score[], int R_count);
//void DisplayLeaderboard();
//void SaveLeaderboard(ifstream OldLeaderboard, ofstream Newleaderboard, string Name[], int Score[]);


int main()
{
    int R_count, task_ID;
    
    cout << "Welcome to Bot-o-mat!" << endl;
    cout << "How many bots will you create today?" << endl;
    cin >> R_count;
    
    if(R_count == 0)
    {return 0;}
    
    
    string * R_name = new string[R_count];  // Name of all robot
    string * R_type = new string[R_count];  // Type of all robots
    int * R_score = new int[R_count];       // the total time for completing the given task
    
    cout << endl<<endl;
    cout << "Please name the robot(s) and their type" << endl;
    cout << "Unipedal, Bipedal, Quadrupedal, Arachnid, Radial, Aerotonautical" << endl;
    
    for (int i =0; i<R_count; i++)
    {
        cout<< "Name: ";
        cin>> R_name[i];
        
        cout << "Type: ";
        cin>> R_type[i];
        cout << endl;
    }
    
    cout << endl<<endl;
    cout << "               Assign task to the robot(s)" << endl;
    cout << "             Type 0 (zero) when you are done" << endl << endl;
    cout << "Do the dishes          (ID = 1)" << " Mow the lawn        (ID = 6)" <<endl;
    cout << "Sweep the house        (ID = 2)" << " Rake the leaves     (ID = 7)" <<  endl;
    cout << "Do the laundry         (ID = 3)" << " Give the dog a bath (ID = 8)" << endl;
    cout << "Take out the recycling (ID = 4)" << " Bake some cookies   (ID = 9)" << endl;
    cout << "Make a sammich         (ID = 5)" << " Wash the car        (ID = 10)" << endl;
    
    for(int j =0; j<R_count; j++)
    {
        cout << "Assigning task to robot: " << R_name[j] << endl;
        
        do{
            cin >> task_ID;
            
            if(CanCompleteTask(task_ID, R_type[j]))
            {
                R_score[j] += TypeBonus(R_type[j], SetTask(task_ID), task_ID);
            }
            else {cout << "This robot can't complete that task" << endl;}
        }while(task_ID !=0);
        
        cout << "Completed assigning task for robot: " << R_name[j] << endl << endl;
    }
    
    ScoreThisRun(R_name, R_score, R_count);
    return 0;
}

int SetTask(int task_ID)
{
    int total_score =0;
    
    if(task_ID =1)
    {total_score = 1000;} // do the dishes
    
    if(task_ID =2)
    {total_score = 3000;} // sweep the house
    
    if(task_ID =3)
    {total_score = 10000;} // do the laundry
    
    if(task_ID =4)
    {total_score = 4000;} // take out the recycling
    
    if(task_ID =5)
    {total_score = 7000;} // make a sammich
    
    if(task_ID =6)
    {total_score = 20000;} // mow the lawn
    
    if(task_ID =7)
    {total_score = 18000;} // rake the leaves
    
    if(task_ID =8)
    {total_score = 14500;} // give the dog a bath
    
    if(task_ID =9)
    {total_score = 8000;} // bake some cookies
    
    if(task_ID =10)
    {total_score = 20000;} // wash the car

}

int TypeBonus(string R_type, int total_score, int task_ID) 
{
    
    string type;

    for(int i = 0; i<R_type.length(); i++)
        type += toupper(R_type[i]);

    if (type == "BIPEDAL")
    {
        if (task_ID == 4 || task_ID == 6 )
        {total_score = total_score/2;}
    }
    if (type == "QUADRUPEDAL")
    {
        if (task_ID ==  2|| task_ID == 6)
        {total_score = total_score/2;}
    }
    if (type == "ARACHNID")
    {
        if (task_ID == 10 || task_ID == 7)
        {total_score = total_score/4;}
    }
    
    if (type == "RADIAL")
    {
        if (task_ID == 1)
        {total_score = total_score/2;}
    }
    
    if (type == "AERONAUTICAL")
    {
        if (task_ID == 2 || task_ID == 10)
        {total_score = total_score/3;}
    }
}

bool CanCompleteTask(int task_ID, string R_type)
{

    string type;

    for(int i = 0; i<R_type.length(); i++)
        type += toupper(R_type[i]);

    if (type == "QUADRUPEDAL")// can't do dishes, laundry, sammich, wash the dog
    {
        if (task_ID ==  1 || task_ID == 3 || task_ID == 5 || task_ID == 8)
        {return false;}
    }
    if (type == "ARACHNID") // can't do sandwiches
    {
        if (task_ID == 5 || task_ID == 7)
        {return false;}
    }
    
    if (type == "RADIAL") // can only wash dishes
    {
        if (task_ID != 1)
        { return true;}
    }
    
    if (type == "AERONAUTICAL") //cant do dishes, laundry, sammich, cookies
    {
        if (task_ID == 2 || task_ID == 10)
        {return false;}
    }

    return true;
}

void ScoreThisRun(string R_name[], int R_score[], int R_count) // if score == 0 no task completed
{

    int *Top10Score = new int[R_count];
    string *Top10Names = new string[R_count];

    cout << "Presenting the top robots for this run" <<endl;
    cout << "--------------------------------------" <<endl;

    for(int i=0; i<R_count; i++)
    {
        for(int j=0; j<i; j++)
        {
            if (R_score[i] > R_score[j])
            {
                 Top10Names[i] = R_name[i];
                 Top10Score[i] = R_score[i];
            }
        }
    }

    for (int p = 0; p < R_count; p++)
    {
        cout << p+1 << ") Name: " << Top10Names[p];
        cout << " Score: " << Top10Score << endl;
    }
}

//unimplemented code for displaying a leaderboard, Name & Score
void DisplayLeaderboard()
{
    ifstream inTopScores;

    inTopScores.open("leaderboard.txt");

    if (inTopScores.fail())
    {
        cout << "No leaderboard available..." << endl;
    }

    else
    {
        cout << " Displaying Top 10 leaderboard " << endl;
        int count =0;
        string Name, Score;
        while(!inTopScores.eof() || count <10)
        {
            inTopScores >> Name;
            inTopScores >> Score;

            cout << count+1 <<") Name: " << " Score: " << Score << endl;
        }
    }

    inTopScores.close();
}


//unimplemented code for a persistent leaderboard, Name & Score
void SaveLeaderboard(ifstream OldLeaderboard, ofstream Newleaderboard, string Name[], int Score[])
{
    OldLeaderboard.open("leaderboard.txt");
    if (OldLeaderboard.fail())
    {
        OldLeaderboard.close();
        Newleaderboard.open("leaderboard.txt");

        for (int i = 0; i < 10; i++) //apend?
        {
            Newleaderboard << Name[i];
            Newleaderboard << Score[i];
        }
        Newleaderboard.close();
        return;
    }

    else
    {
        
    }
}
