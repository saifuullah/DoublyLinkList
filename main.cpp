#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
using namespace std;

                                    /**    THIS IS FIRST CLASS
                                    *
                                    *      CONTAIN SOME SETTERS,GATTERS
                                    *      AND SOME VARIABLES
                                    **/
class Node
{
private:
    Node *next;
    Node *prevv;
    int data;
public:
    void setNextNode(Node *n)
    {   next=n;
    }
void setPrev(Node *n)
{
    prevv=n;
}
    void setData(int d)
    {   data=d;
    }

    int getData()
    {
         return data;
    }

    Node *getNextNode()
    {   return next;
    }
Node *getPrev()
{
    return prevv;
}
    Node(int d)
    {   next=NULL;
        data=d;
        prevv=NULL;
    }

    Node()
    {
         next=NULL;
         prevv=NULL;
    }

};/// CLASS END PARENTHESIS

/**       **********    First Class End      *************
*         *******       Second Class            **********
*         ****         D-Linked_List Class         *******
*
**/

class Linked_List
{
private:
    Node *first;
    Node *NONE;
public:

Linked_List()
{
    first=NULL;
    NONE =NULL;
}
    void add_at_start(int dat)       ///THIS IS ADD AT START FUNCTION
    {   Node *temp=new Node(dat);
        Node *temp2=first;
        if(first==NULL)
            first=temp;
        else
        {   temp->setNextNode(temp2);
             temp2->setPrev(temp);
             first=temp;
        }
    }//End

  void add_at_end(int dat)      ///THIS FUNCTION WILL ADD AT END OF THE LIST
  {
      Node *temp=new Node(dat);
      Node *temp2=first;
      if(first==NULL)
        add_at_start(dat);
      else
      {
      while(temp2->getNextNode()!=NULL)
      {
          temp2=temp2->getNextNode();
      }
      temp2->setNextNode(temp);
      temp->setPrev(temp2);
      }
  }//END


    void display_all()             ///This Will display list
    {   Node *temp=first;
    if(first==NULL)
        cout<<"Sorry, List is Empty :)  "<<endl;
    else{
        while(temp !=NULL)
        {   cout<<temp->getData()<<endl;
            temp=temp->getNextNode();
        }
    }
    }//End

    void remove_first()          ///THIS WILL REMOVE THE FIRST VALUE
    {
        if(first==NULL)
            cout<<"Sorry, List is Empty Nothing to Delete :) "<<endl;

    else if(first->getNextNode()==NULL)
        first=NULL;
    else
        first=first->getNextNode();
        first->setPrev(NONE);
    }//END


    void remove_last()            ///THIS WILL REMOVE THE LAST VALUE
    {

        Node *temp=first;
        if(first==NULL)
            cout<<"Sorry, List is Empty :) "<<endl;
        else if(first->getNextNode()==NULL)
            first=NULL;
        else
        {
            while(temp->getNextNode()->getNextNode()!=NULL)
            {
                temp=temp->getNextNode();
            }
        temp->setNextNode(NONE);
        }
    }//End

    void remove_wanted(int dat)      ///THIS WILL REMOVE THE USER GIVEN VALUE FROM LIST
    {
        Node *temp=first;
        int co=0;
        if(first==NULL)
            cout<<"Sorry, Data List is Empty "<<endl;
            else
                if(first->getData()==dat)
            { first=first->getNextNode();
                first->setPrev(NONE);
            }
        else
        {
            Node *t=first;
            while(t->getNextNode()!=NULL)
            {
                if(t->getData()==dat)
                    co++;
            t=t->getNextNode();
            }
            if(co==0)
                cout<<"Sorry, Given Data is not found "<<endl;
            else
            {
               temp=first;
                while(temp->getNextNode()->getData()!=dat)
            {
                temp=temp->getNextNode();
            }
            temp->setNextNode(temp->getNextNode()->getNextNode());
            temp->getNextNode()->setPrev(temp);
            }
 }
 }//END OF FUNCTION

int getSize()         ///THIS FUNCTION WILL GIVE THE SIZE
{
    int countr=0;
    Node *temp=first;
    if(temp==NULL)
        cout <<"Sorry, List is Empty >> "<<endl;
    else
    {
    while(temp!=NULL)
    {
        temp=temp->getNextNode();
        countr++;
    }
    }
    return countr;
}//END  OF FUNCTION

void remove_index(int ind)     ///THIS FUNCTION WILL REMOVE THE VALUE , WHICH INDEX IS GIVEN BY USER
{
    if(first == NULL)
        cout <<"Sorry, List is Empty "<<endl;
    else {
    Node *temp=first;
    int i=0;
    if(ind < 0)
        cout <<"Sorry, Wrong Index/Location is given : "<<endl;

    else
        if(ind > getSize())
        cout <<" Sorry, given Index Exceeds the Size of List "<<endl;

    else
        if(ind == 0)
      { first = first->getNextNode();
        first ->setPrev(NONE); }
    else
        if (ind==1)
        { first ->setNextNode(first->getNextNode()->getNextNode());
        first->getNextNode()->setPrev(first); }
    else
    {

        for(i=1; i<ind ; i++)
          {
              temp=temp->getNextNode();
    }
    temp->setNextNode(temp->getNextNode()->getNextNode());
    temp->getNextNode()->setPrev(temp);
    }
    }
}//END OF FUNCTION


void add_at_user_p(int dat, int indx)       ///THIS WILL ADD A NEW NODE AT USER GIVEN POSITION
{
    Node *temp2=new Node(dat);
    Node *temp=first;
    if(indx<0)
        add_at_start(dat);
    else if(indx>getSize())
        add_at_end(dat);
    else if(indx+1==getSize())
        add_at_end(dat);
    else
        {
        for (int i=1; i<indx; i++)
        {
            temp=temp->getNextNode();
        }
        temp2->setNextNode(temp->getNextNode());
        temp->setNextNode(temp2);
        temp2->getNextNode()->setPrev(temp2);
        temp2->setPrev(temp);
    }
}//END OF FUNCTION

void search_data(int dat)        ///THIS IS FOR SEARCHING DATA ON THE BASE OF
{                                ///      GIVEN DATA
    Node *temp=first;
    int co=0,x=0;
    while(temp!=NULL)
    {
        if(temp->getData()==dat)
            co++;
     temp=temp->getNextNode();
    }
    if(co==0)
        cout <<"Sorry, The Given Data is Not Found inThe List "<<endl;
    else
    {
        temp=first;
        while(temp->getData()!= dat)
        {
              temp=temp->getNextNode();
        x++;
         }
        cout <<"The Position Of Given Data is  "<<x<<endl;
    }
}//END OF FUNCTION

void show_data(int indxx)        ///THIS WILL SEARCH ON THE BASE OF INDEX
{
    Node *temp=first;
    if(indxx>getSize())
        cout <<"Sorry, the Given index Exceeds the Size of the List "<<endl;
    else if(indxx<0)
        cout <<"Sorry, Given Position is not correct "<<endl;
    else
    {
      for(int i=0; i<indxx; i++)
      {
          temp=temp->getNextNode();
      }
      cout <<"The Data At Given Location is "<<temp->getData()<<endl;
    }

}//END OF FUNCTION

void readFile()              ///THIS FUNCTION WILL READ INSTRUCTION FROM FILE
{
 ifstream file;
 file.open("read.txt",ios::in); ///Opening file in only reading mode
 string ch;
 if(!file.fail())    ///if fails to the File is Will show error message
 {
 while(file.eof()==0)
 {
     file>>ch;
     if(ch=="A")
     {
         int x;
         file>>x;
         add_at_end(x);
     }
   else if(ch=="AAS")
     {
         int y;
         file >>y;
         add_at_start(y);
     }
     else if(ch=="AT")
     {
         int z,xx;
         file >>ch;
         file >>ch;
        add_at_user_p(xx,z);
     }
    else if(ch=="D")
     {
         display_all();
     }
    else if(ch=="RFS")
     {
         remove_first();
     }
    else  if(ch=="RA")
     {
         int nn;
         file>>nn;
         remove_index(nn);
     }
    else if(ch=="R")
     {
         int bb;
         file >>bb;
         remove_wanted(bb);
     }
    else  if(ch=="RFE")
     {
         remove_last();
     }
     else
        cout <<"Wrong Instruction read from file "<<endl;
 }//while end
file.close();
}
else
    cout<<endl<<"Sorry, File Cannot Be Opened"<<endl;
    cout<<"May be File Does't Exist "<<endl;
    cout<<"Or File is open in another program "<<endl<<endl;
}//END OF FUNCTION


};//class End

                /**            /// Hello this main function
                *
                *             ///  MAIN FUNCTION START FROM HERE
                *
                **/

int main()
{   Linked_List myList;
    char ch;
    int choice,dat;

    do           //do while loop start
    {

    system("CLS");
        cout<<"********************************************"<<endl;
        cout<<"1 For Add data at start                  ***"<<endl;
        cout<<"2 For Add data at end                    ***"<<endl;
        cout<<"3 For Remove Data From start             ***"<<endl;
        cout<<"4 For Remove data From Last              ***"<<endl;
        cout<<"5 For Remove Specific Data From list     ***"<<endl;
        cout<<"6 For Remove Data from Specific index    ***"<<endl;
        cout<<"7 For Add Data at Specific Location      ***"<<endl;
        cout<<"8 To SEARCH for Data                     ***"<<endl;
        cout<<"9 To Search data on Desired location     ***"<<endl;
        cout<<"10 For Get the Size of the List          ***"<<endl;
        cout<<"11 For Display whole List                ***"<<endl;
        cout<<"12 To read Instruction From File         ***"<<endl;

        cout<<"********************************************"<<endl;
       cout <<"Enter Your Choice : ";
        cin>>choice;

        switch(choice)
        {   case 1:
                cout<<"Enter Value to be add at start "<<endl;
                cin>>dat;
                myList.add_at_start(dat);
                break;

            case 2:
                cout<<"Enter Data to Add at end "<<endl;
                cin>>dat;
                myList.add_at_end(dat);
                break;
            case 3:
                myList.remove_first();
                break;
            case 4:
                myList.remove_last();
                break;
            case 5:
                cout<<endl<<"Enter the Data you want to delete from List "<<endl;
                cin>>dat;
                myList.remove_wanted(dat);
                break;
            case 6:
                cout<<endl<<"Enter the index you want Delete it's Data "<<endl;
                cin>>dat;
                myList.remove_index(dat);
                break;
            case 7:
                cout <<"Enter the Location of New Data "<<endl;
                cin >>choice;
                cout <<"Enter the Data "<<endl;
                cin >>dat;
                myList.add_at_user_p(dat, choice);
                break;
            case 8:
                cout <<"Enter the Data "<<endl;
                cin >>dat;
                myList.search_data(dat);
                break;
            case 9:
                cout <<"Enter the Location To Show It's Data "<<endl;
                cin>>dat;
                myList.show_data(dat);
                break;
            case 10 :
                dat= myList.getSize();
                if(dat!=0)
                cout <<endl<<"The Size of the List is  >> "<<dat<<endl;
                break;
            case 11:
                myList.display_all();
                break;
            case 12:
                myList.readFile();
                break;
            default:
                cout<<"Wrong Choice "<<endl;

        }  //switch End
        cout<<"Do You Want To Continue : (y/n) : ";
        cin>>ch;
        cout <<endl<<endl;
    }
    while(ch!='n');

    return 0;
}
