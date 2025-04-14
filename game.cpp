#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
const int size = 9;

class player {
protected:

    string username;
    int points = 0;
    int rounds;
    int N = 1;
    vector<int> positions;
    vector<char> UserInput;
    vector<char> results;
    vector<int> scores;

public:
    player() {}
    player(string username) {
        this->username = username;
    }

    int getpoints() {
        return points;
    }

    void resetpoints() {
        points = 0;
    }

    void display() {
        cout << "Insert number of rounds: ";
        cin >> rounds;
        rounds += 1; // Increment rounds by 1
        cout << "Insert N: ";
        cin >> N;
    }

    void setName(string a_name) {
        username = a_name;
    }

    int getN() { return N; }

    int getPositions() {
        for (int i = 0; i < (int)positions.size(); i++) {
            cout << positions[i] << endl;
        }
        return positions.size();
    }

    void resetPosition() {
        positions.clear();
    }

    int getRounds() {
        return rounds;
    } 

    int addResult(char result) {
        results.push_back(result);
        return results.size();
    }
    
    int addInput(char input) {
        UserInput.push_back(input);
        return UserInput.size();
    }
    void ResetInput() {
        UserInput.clear();
    }
   
    void resetResults() {
        results.clear();
    }

    void addScore(int score) {
        scores.push_back(score); 
    }

    void resetScores() {
        scores.clear();
    }
    
    void summary() {
        cout << "***************************** Summary *****************************" << endl;
        cout << "N = " << N << endl;
        cout << "\nRounds =       ";

        for (int i = 1; i < rounds; i++) {
            cout << i << "    ";
        }
        cout << endl;

        cout << "\nResponses =    ";
        for (int i = 0; i < (int)UserInput.size(); i++) {
            if (UserInput[i] == 'y' || UserInput[i] == 'n') {
                cout << UserInput[i] << "    ";  
            }
        }
        cout << endl << endl;

        cout << "Score =        ";
        for (int i = 0; i < (int)scores.size(); i++) {
            cout << scores[i] << "    ";
        }
        cout << endl << endl;

        cout << "Status =       ";
        for (int i = 0; i < (int)results.size(); i++) {
            cout << results[i] << "    ";
        } 
        cout << endl << endl;
         cout << "******************************************************************" << endl;
    }
};

class board_output {
public:
    void draw() {
        cout << "     |     |      \n";
        cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
        cout << "_____|_____|_____ \n";
        cout << "     |     |      \n";
        cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
        cout << "_____|_____|_____ \n";
        cout << "     |     |      \n";
        cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
        cout << "     |     |      \n";
        cout << "\n";
    }
    void drawTown(){
        cout << "~         ~~          __"<<endl;
        cout<<"       _T      .,,.    ~--~ ^^" <<endl;
        cout<<" ^^   // \\                    ~"<<endl;
        cout << "      ][O]    ^^      ,-~ ~"<<endl;
        cout <<"   /''-I_I         _II____"<<endl;
        cout <<"__/_  /   \\ ______/ ''   /'\\_,__"<<endl;
        cout <<"  | II--'''' \\,--:--..,_/,.-{ },"<<endl;
        cout <<"; '/__\\,,.--';|   |[] .-.| O{ _ }"<<endl;
        cout << ":' |  | []  -|   ''--:.;[,.'\\,/"<<endl;
        cout <<"'  |[]|,.--'' '',   ''-,.    |"  <<endl;
        cout <<"..    ..-''    ;       ''. '"<<endl;

        cout <<"To leave this town you must complete all the challenges that come your way..."<<endl;
        cout << "Be careful on your journey." <<endl;

    }
    void drawCastle(){
        cout << "Congratulations!" << " You've reached the end of this perilous journey! "<< endl;
        cout <<"Head to the castle and enjoy the feast that awaits you. "<< endl;
        cout << "                P"<<endl;
        cout << "             P /\\  P"<<endl;
        cout << "            /\\|  |/\\"<<endl;
        cout << "         [] ||_/\\_|| []"<<endl;
        cout << "         ||_||____||_||"<<endl;
        cout <<"         ||____[]____||"<<endl;
        cout << "        {::     \\__    }"<<endl;
        cout << "    ___  \\v:    .'""  _V ___"<<endl;
        cout << "   (      \\_      __/  --  )_"<<endl;
        cout << "  (__---    |::\\ :/  ---     )"<<endl;
        cout <<"     (       \\::\\/  ----- ___)"<<endl;
        cout << "      (______  \\/     _____)"<<endl;
        
    }

    void drawNowhere(){
        cout <<"                 ,-_                  (`  )." <<endl;
        cout <<"                 |-_'-,              (     )." <<endl;
        cout <<"                 |-_'-'           _(        '`." <<endl;
        cout <<"        _        |-_'/        .=(`(      .     )" <<endl;
        cout <<"       /;-,_     |-_'        (     (.__.:-`-_.'" <<endl;
        cout <<"      /-.-;,-,___|'          `(       ) )" <<endl;
        cout <<"     /;-;-;-;_;_/|\\_ _ _ _ _   ` __.:'   )" <<endl;
        cout <<"        x_( __`|_P_|`-;-;-;,|        `--'" <<endl;
        cout <<"        |\\ \\    _||   `-;-;-'" <<endl;
        cout <<"        | \\`   -_|.      '-'" <<endl;
        cout <<"        | /   /-_| `" <<endl;
        cout <<"        |/   ,'-_|  \\" <<endl;
        cout <<"        /____|'-_|___\\" <<endl;
        cout <<" _..,____]__|_\\-_'|_[___,.._" <<endl;
        cout <<"'                          ``'--,..,.      "<<endl;

        cout << "Oh no, it seems you didn't win enough challenges to reach the castle. "<<endl;
        cout << "Let's try again, shall we?"<<endl;
    }


};

class Managing_Seq : public player {
    int index;

public:
    char compare;

    void Random_num() {
        srand(time(NULL));
        index = rand() % size;
        board[index] = "X";
        positions.push_back(index);
    }

    void clearboard() {
        board[index] = " ";
    }

    void getinput() {
        cout << "Did the X appear " << N << " times ago" << endl;
    }

    int checkResult() {
        if ((int)positions.size() < N) {
            return points;
        }

        int place = (int)positions.size() - 1;
        cout << "Is there a match? (y) or (n)? ";
        cin >> compare;

        while (compare != 'y' && compare != 'n') {
            cout << "Invalid input, please enter (y) or (n): ";
            cin >> compare;
        }

        bool match = (positions[place] == positions[place - N]);
        if ((match && compare == 'y') || (!match && compare == 'n')) {
            points++;
        }
        if ((match && compare == 'y') || (!match && compare == 'n')) {
            addResult('c'); // Correct
        } else {
            addResult('w'); // Wrong
        }

        addInput(compare);
        return points;
    }
};

int main() {
    string name;
    player p1;
    board_output b1;
    Managing_Seq M1;
    char yes_no;
    string ready;
    float percentage;

    
    int exit = 2;
    cout << "Game loading..."<<endl;
    cout << "Enter username: ";
    cin >> name;
    M1.setName(name);
    cout << "Welcome to Dual-N-Back!!" << endl;
    b1.drawTown();
     

    while (exit != 1) {
        M1.display();
        
        int no_rounds = M1.getRounds();
        M1.resetpoints();
        M1.resetPosition();
        M1.resetResults();
        M1.resetScores();
        M1.ResetInput();

        for (int i = 0; i < M1.getN(); i++) {
            M1.Random_num();
            b1.draw();
            M1.clearboard();
        }
        cout << "Are you ready to start? ";
        cin >> ready;
        system("cls");
        for (int i = 0; i < no_rounds - 1; i++) { 
            M1.Random_num();
            b1.draw();
            int points = M1.checkResult();
            M1.addScore(points); // Add score to player's scores
            M1.clearboard();
             system("cls");
        }

        
        int total_points = M1.getpoints();
        cout << "You got " << total_points << " out of " << M1.getRounds() - 1 << " correct!" << endl;
          
        M1.summary();
        percentage = total_points/(no_rounds-1);
        if(percentage >= 0.5){
            b1.drawCastle();
        }
        else if(percentage < 0.5){
            b1.drawNowhere();
        }
      
        cout << "Press 1 to exit the game. Press 0 to continue: ";
        cin >> exit;
        while( exit!=0 && exit != 1) {
            cout << "Invalid input, please enter 1 or 0: ";
            cin >> exit;
        }
    }
    
    cout << "Program shutting down. See you again soon :)" << endl;

    return 0;

}
