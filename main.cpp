/* 
 * File:   main.cpp
 * Author: Chandler A. McBride
 * Created on February 9, 2019, 1:20 PM
 * Purpose:  Game of war V2, File I/O
 */


//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Set function for Random Number Generator
#include <ctime>     //Time Library
#include <fstream>   //File stream Library
#include <iomanip>
#include <string>
using namespace std;
void shuffle(int cards[], int size, char face); //Function prototype for shuffling the cards

  



//Execution Begins Here!
int main(int argc, char** argv) {
    
    
    ofstream dealp, dealc; //Output file stream variables
    ifstream playp, playc; //Input file stream variables
     
    dealp.open("players_cards.dat"); //Opening the output file
    dealc.open("computer_cards.dat");//Opening the output file
    playp.open("p_card.dat");        //Opening the input file
    playc.open("c_card.dat");        //Opening the input file
    
    //Variables
    char select;
    int asize=9;
    char choice;
    
    //Static variables for the suits of the cards 
    static char facec='c';
    static char faces='s';
    static char faced='d';
    static char faceh='h';
    
    //One-dimensional arrays for the number cards of each suit
    int clubs[]={2,3,4,5,6,7,8,9,10};
    int spades[]={2,3,4,5,6,7,8,9,10};
    int diamnds[]={2,3,4,5,6,7,8,9,10};
    int hearts[]={2,3,4,5,6,7,8,9,10};

    //Multi-dimensional array for the face cards of each suit
    char facecds[5][4]={{'s', 'd', 'h', 'c'},
                        {'a', 'a', 'a', 'a'},
                        {'j', 'j', 'j', 'j'},
                        {'q', 'q', 'q', 'q'},
                        {'k', 'k', 'k', 'k'}};
   
    //The greeting and game rules
    cout<<"Welcome to the game of war. The rules are:\n"
            "Your opponent is the computer. \n"
            "You and your opponent are dealt 26 cards each.\n"
            "You will each play one card. Those cards \n"
            "will be compared, and the one that is highest\n"
            "wins the round. If the cards are equal,\n"
            "then you will both lose the cards from \n"
            "that round. The winner will have the most \n"
            "cards after all cards have been played.\n"
            "Would you like to play?           y/n"<<endl;
    cin>>choice; //Variable for the the users choice to enter the game
    
    //Checking if the user chose yes or no
    if (choice!='y')
    {cout<<"Okay, have a great day."<<endl;
    return 0;}
    
 
   
    //Deals the spades face cards to both players
    for (int c=1; c<5; c++)  
    {    
    dealp<<facecds[0][0]<<facecds[c][0]<<endl;
    
    c++;
    dealc<<facecds[0][0]<<facecds[c][0]<<endl;
    
    }
    
    //Deals the clubs face cards to each player
    for (int a=1; a<5; a++)  
    {    
    dealc<<facecds[0][1]<<facecds[a][0]<<endl;
    a++;
    dealp<<facecds[0][1]<<facecds[a][0]<<endl;
    }
    
    //Deals the hearts face cards to each player
    for (int b=1; b<5; b++)  
    {    
    dealp<<facecds[0][2]<<facecds[b][0]<<endl;
    b++;
    dealc<<facecds[0][2]<<facecds[b][0]<<endl;
    }
    
    //Deals the diamonds face cards to each player
    for (int d=1; d<5; d++)  
    {    
    dealp<<facecds[0][3]<<facecds[d][0]<<endl;
    d++;
    dealp<<facecds[0][3]<<facecds[d][0]<<endl;
    }
    
    
    
    
    int swap;
    //Deals the clubs number cards 
    for (int i=0; i<9; i++) 
    {
        
        int lgindex;    
       
        //Generates a random number to shuffle the cards at random
        srand(time(0));
        int num=(rand()%10)-1;

        if (clubs[num]> clubs[i])
            lgindex=num;
        
        //This puts the cards into their location within the array
        swap=clubs[lgindex];
        clubs[lgindex]=clubs[i];
        clubs[i]=swap;
                 
    }
 
    for (int a=0; a<9; a++)
    {
        if (a%2!=0){
        
        dealp<<facec<<clubs[a]<<endl;
        if(a!=8)
        {a++;}}

        dealc<<facec<<clubs[a]<<endl;
    }
    
    
    
    
        //Deals the spades number cards 
    for (int i=0; i<9; i++) 
    {
        
        int lgindex;
        
       //Generates a random number to shuffle the cards at random
        srand(time(0));
        int num=(rand()%10)-1;

        if (spades[num]> spades[i])
            lgindex=num;
        
        //This puts the cards into their location within the array
        swap=spades[lgindex];
        spades[lgindex]=spades[i];
        spades[i]=swap;
                 
    }
 
    for (int a=0; a<9; a++)
    {
        if (a%2!=0){
        
        dealp<<faces<<spades[a]<<endl;
        if(a!=8)
        {a++;}}

        dealc<<faces<<spades[a]<<endl;
    }
    
    
    
    
        //Deals the diamonds number cards
    for (int i=0; i<9; i++) 
    {
        
        int lgindex;    
       
        //Generates a random number to shuffle the cards at random
        srand(time(0));
        int num=(rand()%10)-1;

        if (diamnds[num]> diamnds[i])
            lgindex=num;
        
        //This puts the cards into their location within the array
        swap=diamnds[lgindex];
        diamnds[lgindex]=diamnds[i];
        diamnds[i]=swap;
                 
    }
 
    for (int a=0; a<9; a++)
    {
        if (a%2!=0){
        
        dealp<<faced<<diamnds[a]<<endl;
        if(a!=8)
        {a++;}}

        dealc<<faced<<diamnds[a]<<endl;
    }
    
    
    
    
     //Deals the hearts number cards
    for (int i=0; i<9; i++) 
    {
        
        int lgindex;    
       
        //Generates a random number to shuffle the cards at random
        srand(time(0));
        int num=(rand()%10)-1;

        if (hearts[num]> hearts[i])
            lgindex=num;
        
        //This puts the cards into their location within the array
        swap=hearts[lgindex];
        hearts[lgindex]=hearts[i];
        hearts[i]=swap;
                 
    }
 
    for (int a=0; a<9; a++)
    {
        if (a%2!=0){
        
        dealp<<faceh<<hearts[a]<<endl;
        if(a!=8)
        {a++;}}

        dealc<<faceh<<hearts[a]<<endl;
    }
    
     
    //Variables for the comparing the cards
     int pnum=26;
     int cnum=26;   
     char play;
     string plcard, cocard;
     int pvcard, cvcard;
    
     for(int i=1; i<27; i++) //Loop for 26 rounds to the game
       
   {
        
       
       cout<<"ROUND "<<i<<endl; //Outputs the round 
       cout<<"Type the letter 'p' to play a card: "<<endl;//Lets the user type p to play
       cin>>play;
       cout<<endl;
       
       playp>>plcard; //Inputs the players card from the input file
       playc>>cocard; //Inputs the computers card from the input file
       
      
       //Give value to players cards
       if(plcard[1]=='a')
       {pvcard=14;}
       else if(plcard[1]=='k')
       {pvcard=13;}
       else if(plcard[1]=='q')
       {pvcard=12;}
       else if(plcard[1]=='j')
       {pvcard=11;}
       else if(plcard[1]=='2')
       {pvcard=2;}
       else if(plcard[1]=='3')
       {pvcard=3;}
       else if(plcard[1]=='4')
       {pvcard=4;}
       else if(plcard[1]=='5')
       {pvcard=5;}
       else if(plcard[1]=='6')
       {pvcard=6;}
       else if(plcard[1]=='7')
       {pvcard=7;}
        else if(plcard[1]=='8')
       {pvcard=8;}
       else if(plcard[1]=='9')
       {pvcard=9;}
       else if(plcard[1]=='1')
       {pvcard=10;}
       else
       {pvcard=0;}
       
       //Give value to computers cards
       if(cocard[1]=='a')
       {cvcard=14;}
       else if(cocard[1]=='k')
       {cvcard=13;}
       else if(cocard[1]=='q')
       {cvcard=12;}
       else if(cocard[1]=='j')
       {cvcard=11;}
       else if(cocard[1]=='2')
       {cvcard=2;}
       else if(cocard[1]=='3')
       {cvcard=3;}
       else if(cocard[1]=='4')
       {cvcard=4;}
       else if(cocard[1]=='5')
       {cvcard=5;}
       else if(cocard[1]=='6')
       {cvcard=6;}
       else if(cocard[1]=='7')
       {cvcard=7;}
        else if(cocard[1]=='8')
       {cvcard=8;}
       else if(cocard[1]=='9')
       {cvcard=9;}
       else if(cocard[1]=='1')
       {cvcard=10;}
       else
       {cvcard=0;}
       
       cout<<"Your card is: "<<plcard<<endl; //Outputs the players card
       cout<<"The computers card is: "<<cocard<<endl; //Outputs the computers card
      
       
       
       //Determine winner of round 337-358
       if(pvcard>cvcard)
       {
          
           cout<<"You win this round! "<<endl<<endl;
           pnum+=1;
           cnum-=1;
       }
       else if(pvcard<cvcard)
       {
           
           cout<<"You lost this round! "<<endl<<endl;
           pnum-=1;
           cnum+=1;
       }
       else if(pvcard==cvcard)
       {
           
           cout<<"WAR!! You both lose your cards. "<<endl<<endl;
           pnum-=1;
           cnum-=1;
       }
       
        cout<<"You have "<<pnum<<" cards."<<endl; //Outputs the number of cards the player has
        cout<<"The computer has "<<cnum<<" cards."<<endl<<endl<<endl<<endl; //Outputs the number of cards the computer has
        
   }
    
     //Announces the winner based on who has the most cards 365-371
     if(pnum>cnum)
     {cout<<"YOU WIN! CONGRATULATIONS! "<<endl<<endl<<endl;}
     else if(cnum>pnum)
     {cout<<"YOU LOSE! "<<endl<<endl<<endl;}
     else
     {cout<<"TIE! NO ONE WINS"<<endl<<endl<<endl;}
    
   //Closes the input/output files
    dealp.close();
    dealc.close();
    playp.close();
    playc.close();
    
    //Function call (passing arrays through a function) to shuffle the number cards
    shuffle(clubs, asize, facec);
    shuffle(spades, asize, faces);
    shuffle(diamnds, asize, faced);
    shuffle(hearts, asize, faceh);


return 0; //End the program
}

//Function that shuffles the number cards  
void shuffle(int cards[], int size, char face)
{  
    int swap;
       
    for (int i=0; i<9; i++) 
    {
        
        int lgindex;    
       
        srand(time(0));
        int num=(rand()%10)-1;
        

        if (cards[num]> cards[i])
            lgindex=num;
        
        swap=cards[lgindex];
        cards[lgindex]=cards[i];
        cards[i]=swap;
      
           
    }

    for (int a=0; a<9; a++)
    {
        if (a%2!=0){
        cout<<face<<cards[a]<<" ";
        
        if(a!=8)
        {a++;}}
        
        cout<<face<<cards[a]<<" ";
       
    }
    cout<< endl;
  
} 

