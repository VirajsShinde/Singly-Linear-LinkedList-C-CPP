#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////
//Linear Data Structure  //github.com/VirajsShinde

//Linked List --> Singly->Linear.cpp (C++)  

////////////////////////////////////////////////////////////////////////////////////////
#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyLL
{
    public:
            PNODE first;
            int iCount;

    SinglyLL();

    void InsertFirst(int iNo);
    void InsertLast(int iNo);
    void InsertAtPosition(int iNo,int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPosition(int iPos);

    void Display();
    void Options();
};

/////////////////////////////////////////////////////////////////////////////////////

SinglyLL :: SinglyLL()
{
    first = NULL;
    iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////

void SinglyLL :: InsertFirst(int iNo)
{
    PNODE newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if(first == NULL)   //if(iCount == 0)
    {
        first = newn;
        iCount++;
    }
    else
    {
        newn->next = first;
        first = newn;
        iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////////////

void SinglyLL :: InsertLast(int iNo)
{
    PNODE newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if(first == NULL)   
    {
        first = newn;
        iCount++;
    }
    else
    {
        PNODE temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////////////

void SinglyLL :: InsertAtPosition(int iNo,int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }

    else if(iPos == iCount+1)
    {
        InsertLast(iNo);
    }
    else
    {
    PNODE newn = new NODE;

        newn->data = iNo;
        newn->next = NULL;

        PNODE temp = first;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////////////

void SinglyLL :: DeleteFirst()
{
    PNODE temp = first;

    if(first == NULL)
    {
        cout<<"Linked list is Empty"<<"\n";
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
        iCount--;
    }
    else
    {
        first = first->next;
        delete temp;
        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////

void SinglyLL :: DeleteLast()
{
    PNODE temp = first;

    if(first == NULL)
    {
        cout<<"Linked list is Empty"<<"\n";
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
        iCount--;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////

void SinglyLL :: DeleteAtPosition(int iPos)
{
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }

    else if(iPos == iCount)
    {
        DeleteLast(); 
    }
    else
    {
        temp1 = first;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp1->next->next;
        delete temp2;

        iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////////////////

void SinglyLL :: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";

    PNODE temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"| NULL |"<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////

void SinglyLL :: Options()
{
    cout<<"-------------------------------------------------------------------"<<"\n";

        cout<<"Please Select Desire Option : "<<"\n";
        cout<<"1 : Insert First"<<"\n";
        cout<<"2 : Insert Last"<<"\n";
        cout<<"3 : Insert At given Position"<<"\n";
        cout<<"4 : Delete First"<<"\n";
        cout<<"5 : Delete Last"<<"\n";
        cout<<"6 : Delete At given Position"<<"\n";
        cout<<"7 : Display the contents of Linked List"<<"\n";
        cout<<"8 : Count Number of Nodes from Linked List"<<"\n";
        cout<<"9 : Options"<<"\n";
        cout<<"10 : EXIT"<<"\n";
        cout<<"-------------------------------------------------------------------"<<"\n";

};
////////////////////////////////////////////////////////////////////////////////////

int main()
{
    SinglyLL sObj1;
    
    int iChioce = 0, iPos = 0, iRet = 0, iNo = 0;

    cout<<"\n Welcome --DS--> Singly->Linear.cpp"<<"\n";

    sObj1.Options();

    while(1)
    {
        cout<<"Enter Option :"<<"\n";
        cin>>iChioce;

        switch(iChioce) 
        {
            case 1:
                cout<<"Enter the data that you want to insert First"<<"\n";
                cin>>iNo;

                sObj1.InsertFirst(iNo);
                sObj1.Display();
                break;

            case 2:
                cout<<"Enter the data that you want to insert Last"<<"\n";
                cin>>iNo;

                sObj1.InsertLast(iNo);
                sObj1.Display();
                break;

            case 3:
                cout<<"Enter the data that you want to insert first"<<"\n";
                cin>>iNo;

                cout<<"Enter the Position : "<<"\n";
                cin>>iPos;

                sObj1.InsertAtPosition(iNo,iPos);
                sObj1.Display();
                break;

            case 4:
                sObj1.DeleteFirst();
                sObj1.Display();
                break;

            case 5:
                sObj1.DeleteLast();
                sObj1.Display();
                break;

            case 6:
                cout<<"Enter the Position"<<"\n";
                cin>>iPos;

                sObj1.DeleteAtPosition(iPos);
                sObj1.Display();
                break;

            case 7:
                sObj1.Display();
                break;

            case 8:
                cout<<"Number of Nodes are : "<<sObj1.iCount<<"\n\n";
                sObj1.Display();
                break;
            
            case 9:
                sObj1.Options();
                break;
                
            case 10:
                cout<<"Thank you for using this application"<<"\n";
                cout<<"-------------------------------------------------------------------"<<"\n";
                return 0;

            default:
                cout<<"Invalid Position"<<"\n";
                break;
        }
        cout<<"----------------------------------------------------------------------"<<"\n";
    }
    return 0;
}