#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<ctime>
#define nl cout<<endl
using namespace std;

void victory(){
    Sleep(500);
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


bool numcheck(int a, int trash[9]){
    if(a>8 || a<0)return 1;
    for(int i=0; i<9; i++){
        if(trash[a]==1)return 1;
    }
    return 0;
}

void make(char arr[9]){
    cout<<"+-----+";nl;
    cout<<"|"<<arr[0]<<"|"<<arr[1]<<"|"<<arr[2]<<"|";nl;
    cout<<"|"<<arr[3]<<"|"<<arr[4]<<"|"<<arr[5]<<"|";nl;
    cout<<"|"<<arr[6]<<"|"<<arr[7]<<"|"<<arr[8]<<"|";nl;
    cout<<"+-----+";nl;
}

bool checkX(char arr[9]){
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
bool checkO(char arr[9]){
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

int main(){
    srand((unsigned) time(0));

    char arr[9];
    for(int i=0; i<9; i++){
        arr[i]=' ';
    }

    int trash[9];
    for(int i=0; i<9; i++){
        trash[i]=-1;
    }

    nl;nl;nl;cout<<"Hello There!";Sleep(400);
    nl; nl;
    cout<<"I would like to play a game with you!";Sleep(200);
    nl; nl;
    cout<<"I'm giving you offer to make the first move...so here's your game matrix...";Sleep(700);
    nl; nl;
    make(arr);
    nl;Sleep(300);
    cout<<"So, let me tell how will you make moves";nl;Sleep(300);
    cout<<"To write in any block, you'll only have to enter the index of that block";nl;
    cout<<"which are 1, 2, 3, 4, 5, 6, 7, 8, 9";nl;
    cout<<"So, here we are...";nl;nl;

    cout<<"<------------GAME ARENA------------>";nl;nl;
    int turns=5;
    int chance;
    while(turns--){
        cin>>chance;
        chance--;
        while(numcheck(chance, trash)){
            cout<<"You put an incorrect entry...Pls try again...";nl;
            cin>>chance;
            chance--;
        }
        trash[chance]=1;
        arr[chance]='X';
        make(arr);nl;
        if(checkX(arr)==1){Sleep(100);cout<<"YOU WON";nl;victory();return 0;}


        if(turns==0){cout<<"It's draw...Better luck next time...";return 0;}

        cout<<"Now its my turn";nl;
        cout<<"LET ME THINK";
        Sleep(50);cout<<".";Sleep(50);cout<<".";
        Sleep(50);cout<<".";Sleep(50);cout<<".";
        Sleep(50);cout<<".";Sleep(50);cout<<".";
        Sleep(50);cout<<".";Sleep(50);cout<<".";
       nl;

        chance = rand()%9;
        while(numcheck(chance, trash)==1){
        chance = rand()%9;        
        }
        trash[chance]=1;
        arr[chance]='O';
        make(arr);nl;
        if(checkO(arr)==1){Sleep(100);cout<<"I WON";nl;victory();return 0;}

        cout<<"<------------------------------->";nl;
    }
}