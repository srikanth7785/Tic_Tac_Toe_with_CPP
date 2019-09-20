#include<iostream>
#include<cstdlib>
#include<sys/time.h>
using namespace std;
char a[3][3];
char p;
void display()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}

int check()
{
    int i,j;
    if(a[0][0]==a[1][1]&&a[1][1]==a[2][2])
    {
        p=a[0][0];
        if(p!='_')
        {
            return 1;
        }
    }
    if(a[0][2]==a[1][1]&&a[1][1]==a[2][0])
    {
        p=a[0][2];
        if(p!='_')
        {
            return 1;
        }
    }
    for(i=0;i<3;i++)
    {
        if(a[i][0]==a[i][1]&&a[i][1]==a[i][2])
        {
            p=a[i][0];
            if(p!='_')
            {
             return 1;
            }
        }
        if(a[0][i]==a[1][i]&&a[1][i]==a[2][i])
        {
            p=a[0][i];
            if(p!='_')
            {
                return 1;
            }
        }
    }
    return 0;
}
void multi_player()
{
   cout<<"player 1: x and player 2: o"<<endl;
      int x,y,i,j;
      for(i=0;i<3;i++)
      {
          for(j=0;j<3;j++)
          {
              a[i][j]='_';
          }
      }
      display();
      for(int c=1;c<=9;c++)
      {
          (c%2==1)?cout<<"player 1 :":cout<<"player 2 :";
          cout<<"enter the row and column : "<<"\t";
          cin>>x>>y;
          if(a[x-1][y-1]=='_')
          {
              a[x-1][y-1]=(c%2==1)?'x':'o';
          }
          else 
          {
              cout<<"you are over writing the other player"<<endl;
              c--;
          }
          display();
          if(c>4)
          {
              if(check()==1)
              {
                  (p=='x')?cout<<"player 1 is winner":cout<<"player 2 is winner";
                  return;
              }
          }
      }
      cout<<"draw match";
}
int computer_entry()
{
  srand(time(0));
  int x=(rand()%3)+1;
  return x;
}
void play_with_computer()
{
   cout<<"computer : x and player : o"<<endl;
      int x,y,i,j;
      for(i=0;i<3;i++)
      {
          for(j=0;j<3;j++)
          {
              a[i][j]='_';
          }
      }
      display();
      for(int c=1;c<=9;c++)
      {
          if(c%2==1)
          {
            cout<<"computer turn :"<<endl;
            here:x=computer_entry();
            y=computer_entry();
            if(a[x-1][y-1]!='_')
            goto here;
          }
          else 
          {
              cout<<" player turn :"<<endl;
              cout<<"enter the row and column : "<<"\t";
              cin>>x>>y;
          }

          if(a[x-1][y-1]=='_')
          {
              a[x-1][y-1]=(c%2==1)?'x':'o';
          }
          else 
          {
              (c%2==1)?cout<<"computer " : cout<<"player "; 
              cout << "is over writing the other player"<<endl;
              c--;
          }
          display();
          if(c>4)
          {
              if(check()==1)
              {
                  (p=='x')?cout<<"computer is winner":cout<<"player is winner";
                  return;
              }
          }
      }
      cout<<"draw match";
}
int main()
{ int d;
  cout<<"multiplayer or play with computer:"<<endl;
  cout<<"enter 1 for multiplayer...2 to play with computer: "<<endl<<"your choice: "<<endl;
  cin>>d;
  cout << endl;
  if(d==1)
  {
    multi_player(); 
  }
  
  else if (d==2)
  {
    play_with_computer();
  }
    return 0;
}