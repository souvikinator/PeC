#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <ctype.h>
using namespace std;

class A{
public:
  char code[300];
}ob[300];

void intro(){
   cout<<"\u001b[36;1m ___          ____\n";
   cout<<"\u001b[36;1m| _ |  ___   / ___)\n";
   cout<<"\u001b[36;1m|  _/ / -_) | (___\n";
   cout<<"\u001b[36;1m|_|   |___| |_____)\n\n";
  cout<<"\u001b[0m\u001b[32;1mGuide:\n1)use arrow keys to navigate cursor";
  cout<<"\n2)ctrl+E to save and exit\n3)ctrl+Z to exit without saving\n4)to open file in specific location just enter the path along with file name\nexample:\u001b[0m/home/projects/a.txt";
}

void menu(char fl[]){
  cout<<"\u001b[34;1m >PeC.      \t\t\t\t\t \u001b[31;1m[^E]:save & exit  [^Z]:exit \n\u001b[33;1m file: \u001b[0m ["<<fl<<"] ";
  //cout<<"\u001b[0m\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
    cout<<"\u001b[30;1m\n______________________________________::::_____________________________________\u001b[0m\n\n";
  //cout<<"\u001b[0m";
}

int main(){

  int i=0,c=0,x=0,n=0,z=0,m=0;char ch,fl_name[30],synt[20];
  string code;

system("clear");
intro();
cout<<"\n\n\u001b[32;1menter file name:\u001b[0m";cin>>fl_name;
system("clear");

menu(fl_name);

fstream f(fl_name,ios::in|ios::out|ios::app);

while(getline(f,code)){
  cout<<code<<endl;
  strcpy(ob[i].code,code.data());
  i+=1;
}
f.close();

system("stty cbreak");
while(1){x=0;
  system("stty -echo");
  while((ch=getchar())!='\n'){
    c=ch;
     if(c==127){//backspace
        cout<<"\u001b[1D\u001b[0K";
        //cout<<"\u001b[1D";
        ob[i].code[n-1]='\0';
        n=n-2;
     }else if(c==5){//ctrl+E
       x=1;break;
     }else if(c==27){//arrow key detection
        //cout<<"arrow";
        c=getchar();
        //cout<<c;
        if(c==91){
          c=getchar();
          //cout<<c;
          switch(c){
            case 65:
            //cout<<"\u001b[4D\u001b[0K";//up
            cout<<"\u001b[1F";i-=1;n=-1;
            break;
            case 66:
            //cout<<"\u001b[4D\u001b[0K";//down
            cout<<"\u001b[1E";i+=1;n=-1;
            break;
            case 67:
            //cout<<"\u001b[4C\u001b[0K";//right
            cout<<"\u001b[1C";
            break;
            case 68:
            //cout<<"\u001b[4C\u001b[0K";//left
            cout<<"\u001b[1D";n=n-2;
            break;
          }
        }

     }else{
       //system("stty echo");
       system("lolcat -a");
       cout<<ch;
       ob[i].code[n]=ch;//storing user inputs
     }
     n+=1;
  }
  ob[i].code[n+1]='\0';
  cout<<"\n";
  i+=1;n=0;
  if(x==1){strcpy(ob[i+1].code,"!");i=0; break;}
}

system("stty echo");
system("stty -cbreak");
f.open(fl_name,ios::out);
while(strcmp(ob[i].code,"!")!=0){
  f<<ob[i].code<<endl;
  i+=1;
}
f.close();
system("clear");
  return 0;
}
