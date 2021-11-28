////SkyWalker///
#include<bits/stdc++.h>
#include<windows.h>
#include<ctime>
#define ll long long
#define ld long double
#define fir(i, a, b) for(int i=a;i<b;i++)
#define rfir(i, a, b) for(int i=a;i>=b;i--)
#define vi vector<int>
#define pii pair<int, int>
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define mod 1000000007
#define nl cout<<endl
#define fast                  \
ios_base::sync_with_stdio(0); \
cin.tie(0);                   \
cout.tie(0);
#define tests                 \
int tt;                       \
cin>>tt; while(tt--)
using namespace std;
/****************************/


void victory(){
    cout<<" .\"\".    .\"\", ";nl;
    cout<<" |  |   /  /      ";nl;
    cout<<" |  |  /  /       ";nl;
    cout<<" |  | /  /        ";nl;
    cout<<" |  |/  ;-._      ";nl;
    cout<<" }  ` _/  / ;     ";nl;
    cout<<" |  /` ) /  /     ";nl;
    cout<<" | /  /_/\\_/\\     ";nl;
    cout<<" |/  /      |     ";nl;
    cout<<" (  ' \\ '-  |     ";nl;
    cout<<"  \\    `.  /      ";nl;
    cout<<"   |      |       ";nl;
    cout<<"   |      |       ";nl;
}


class Game{
    //Minimax algorithm
    int minimax(bool isMaxim){
        if(checkX())return 1;
        if(checkO())return -1;
        if(checkDraw())return 0;

        if(isMaxim){
            int bestScore = INT_MIN;
            fir(i, 0, 9){
                if(arr[i]==' '){
                    arr[i]='X';
                    int score = minimax(false);
                    arr[i]=' ';
                    bestScore = max(bestScore, score);
                }
            }
            return bestScore;
        }
        else {
            int bestScore = INT_MAX;
            fir(i, 0, 9){
                if(arr[i]==' '){
                    arr[i]='O';
                    int score = minimax(true);
                    arr[i]=' ';
                    bestScore = min(bestScore, score);
                }
            }
            return bestScore;
        }
    }

public:
    char arr[9];
    int trash[9];

    Game(){
        fir(i, 0, 9)trash[i]=-1;
        fir(i, 0, 9)arr[i]=' ';
    }

    void makeGrid(){
        cout<<"+-----+-----+-----+";nl;
        cout<<"|"<<"     "<<"|"<<"     "<<"|"<<"     "<<"|";nl;
        cout<<"|"<<"  "<<arr[0]<<"  "<<"|"<<"  "<<arr[1]<<"  "<<"|"<<"  "<<arr[2]<<"  "<<"|";nl;
        cout<<"|"<<"     "<<"|"<<"     "<<"|"<<"     "<<"|";nl;
        cout<<"+-----+-----+-----+";nl;
        cout<<"|"<<"     "<<"|"<<"     "<<"|"<<"     "<<"|";nl;
        cout<<"|"<<"  "<<arr[3]<<"  "<<"|"<<"  "<<arr[4]<<"  "<<"|"<<"  "<<arr[5]<<"  "<<"|";nl;
        cout<<"|"<<"     "<<"|"<<"     "<<"|"<<"     "<<"|";nl;
        cout<<"+-----+-----+-----+";nl;
        cout<<"|"<<"     "<<"|"<<"     "<<"|"<<"     "<<"|";nl;
        cout<<"|"<<"  "<<arr[6]<<"  "<<"|"<<"  "<<arr[7]<<"  "<<"|"<<"  "<<arr[8]<<"  "<<"|";nl;
        cout<<"|"<<"     "<<"|"<<"     "<<"|"<<"     "<<"|";nl;
        cout<<"+-----+-----+-----+";nl;
    }


    //if index is invalid, returns true
    bool numcheck(int a){
        if(a>8 || a<0)return 1;
        for(int i=0; i<9; i++){
            if(trash[a]==1)return 1;
        }
        return 0;
    }

    bool checkX(){
        bool f=0;
        // for x
            if(arr[0]=='X' && arr[1]=='X' && arr[2]=='X')f=1;
        else if(arr[3]=='X' && arr[4]=='X' && arr[5]=='X')f=1;
        else if(arr[6]=='X' && arr[7]=='X' && arr[8]=='X')f=1;
        else if(arr[0]=='X' && arr[4]=='X' && arr[8]=='X')f=1;
        else if(arr[2]=='X' && arr[4]=='X' && arr[6]=='X')f=1;
        else if(arr[0]=='X' && arr[3]=='X' && arr[6]=='X')f=1;
        else if(arr[1]=='X' && arr[4]=='X' && arr[7]=='X')f=1;
        else if(arr[2]=='X' && arr[5]=='X' && arr[8]=='X')f=1;
        if(f==1)return 1;
        else return 0;
    }

    bool checkO(){
        bool f=0;
        // for O
            if(arr[3]=='O' && arr[4]=='O' && arr[5]=='O')f=1;
        else if(arr[6]=='O' && arr[7]=='O' && arr[8]=='O')f=1;
        else if(arr[0]=='O' && arr[1]=='O' && arr[2]=='O')f=1;
        else if(arr[0]=='O' && arr[4]=='O' && arr[8]=='O')f=1;
        else if(arr[2]=='O' && arr[4]=='O' && arr[6]=='O')f=1;
        else if(arr[0]=='O' && arr[3]=='O' && arr[6]=='O')f=1;
        else if(arr[1]=='O' && arr[4]=='O' && arr[7]=='O')f=1;
        else if(arr[2]=='O' && arr[5]=='O' && arr[8]=='O')f=1;
        if(f==1)return 1;
        return 0;
    }
    
    bool checkDraw(){
        if(!checkX() && !checkO()){
            fir(i, 0, 9){
                if(arr[i]==' ')return 0;
            }
            return 1;
        }
        else return 0;
    }



    
    void bestMove(){
        int bestScore = INT_MAX;
        int move;
        fir(i, 0, 9){
            if(arr[i]==' '){
                arr[i]='O';
                int score = minimax(true);
                arr[i]=' ';
                if (score < bestScore) {
                    bestScore = score;
                    move = i;
                }
            }
        }

        arr[move]='O';
        trash[move]=1;
    }

};




int main()
{   
    Game one;

    nl;nl;nl;cout<<"Hello There!";Sleep(400);
    nl; nl;
    cout<<"I would like to play a game with you!";Sleep(200);
    nl; nl;
    cout<<"I'm giving you offer to make the first move...so here's your game matrix...";Sleep(700);
    nl; nl;
    one.makeGrid();
    nl;Sleep(300);
    cout<<"So, let me tell how will you make moves";nl;Sleep(300);
    cout<<"To write in any block, you'll only have to enter the index of that block";nl;
    cout<<"which are 1, 2, 3, 4, 5, 6, 7, 8, 9";nl;
    cout<<"So, here we are...";nl;nl;

    cout<<"<------------GAME ARENA------------>";nl;nl;


    int chance;
    while(true){

        /*
        ========================================
                Taking the input
        ========================================
        */
        cin>>chance;
        chance--;
        while(one.numcheck(chance)){
            cout<<"You put an incorrect entry...Pls try again...";nl;
            cin>>chance;
            chance--;
        }


        /*
        ========================================
                Updating the grid
        ========================================
        */
        one.trash[chance]=1;
        one.arr[chance]='X';
        one.makeGrid();nl;
        if(one.checkX()){Sleep(100);cout<<"YOU WON";nl;victory();return 0;}
        if(one.checkDraw()){cout<<"It's draw...Better luck next time...";return 0;}


        /*
        ========================================
                    Thinking design
        ========================================
        */
        cout<<"Now its my turn";nl;
        cout<<"LET ME THINK...";
        Sleep(50);cout<<".";Sleep(50);cout<<".";
        Sleep(50);cout<<".";Sleep(50);cout<<".";
        Sleep(50);cout<<".";Sleep(50);cout<<".";
        Sleep(50);cout<<".";Sleep(50);cout<<".";
        nl;


        /*
        ========================================
                Processing the computer move
        ========================================
        */
        one.bestMove();
        one.makeGrid();nl;
        if(one.checkX()){Sleep(100);cout<<"YOU WON";nl;victory();return 0;}
        if(one.checkDraw()){cout<<"It's draw...Better luck next time...";return 0;}
    }
return 0;
}