//////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------GENERIC DATA STRUCTURE LIBRARY-----------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////
//
// Code of Singly Linear Linked List
//
////////////////////////////////////////////////////////////////////
template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
    private:
        struct nodeSL<T> * First;
        int iCount;

        int FactorsAddition(int No);
        bool CheckPerfect(int No);

    public:
        SinglyLL();     
        void Display();
        int Count();
        
        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        T Addition();
        int EvenCount();
        int OddCount();
        int FrequencyCount(T No);
        bool Search(T No);
        int SearchFirstOcc(T No);
        int SearchLastOcc(T No);
        void SumDigits();
        void SumFactors();
        void DisplayPerfect();
        T MiddleElement();
};

template <class T>
SinglyLL<T>::SinglyLL()    //constructor is defined with class name and scope resolution operator
{
    //cout<<"Inside Constructor"<<endl;
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> * temp = NULL;  
    temp = First;
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new struct nodeSL<T>;    //allocate dynamic memory

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)   //OR if(iCount == 0)
    {
        First = newn;
    }
    else 
    {
        newn->next = First;
        First = newn;
    }
    iCount++;               //iCount is For insert functions it is ++
                            // for delete functions it is --
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = NULL;

    newn = new struct nodeSL<T>;    //allocate dynamic memory

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)   //OR if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++; 
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    int iLength = 0;
    int i = 0;
    iLength = iCount;

    if(iPos < 1 || iPos > iLength+1)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iLength+1)
    {
        InsertLast(No);
    }
    else
    {
        struct nodeSL<T> * newn = NULL;
        struct nodeSL<T> * temp = NULL;

        newn = new struct nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        temp = First;
        for(i = 1; i<iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = NULL;
    if(First == NULL)
    {
        cout<<"Unable to delete as LinkedList is empty"<<endl;
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;
        First = temp->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = NULL;
    if(First == NULL)
    {
        cout<<"Unable to delete as LinkedList is empty"<<endl;
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;
        while(temp->next->next != NULL)
        {
            temp= temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    struct nodeSL<T> * temp1 = NULL;
    struct nodeSL<T> * temp2 = NULL;
    int iLength = 0;
    int i = 0;
    iLength = iCount;

    if(iPos < 1 || iPos > iLength)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iLength)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;
        temp2 = First;
        for(i = 1; i<iPos-1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        iCount--;           
    }
    
}

template <class T>
T SinglyLL<T>::Addition()
{
    struct nodeSL<T> * temp = NULL;  
    temp = First;
    T iSum = 0;

    while(temp != NULL)
    {
        iSum = iSum + temp->data;
        temp = temp->next;
    }
    return iSum;
}

template <class T>
int SinglyLL<T>::EvenCount()
{
    struct nodeSL<T> * temp = NULL;  
    temp = First;   
    int iCnt = 0;
    T iNo = 0;

    while(temp != NULL)
    {
        iNo = temp->data;
        if(iNo % 2 == 0)
        {
            iCnt++;
        }
        temp = temp->next;
    }
    return iCnt;
}

template <class T>
int SinglyLL<T>::OddCount()
{
    struct nodeSL<T> * temp = NULL;
    temp = First;
    int iCnt = 0;
    T iNo = 0;

    while(temp != NULL)
    {
        iNo = temp->data;
        if(iNo % 2 != 0)
        {
            iCnt++;
        }
        temp = temp->next;
    }
    return iCnt;
}

template <class T>
int SinglyLL<T>::FrequencyCount(T No)
{
    int iCnt = 0;
    struct nodeSL<T> * temp = NULL;
    temp = First;
    
    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iCnt++;
        }
        temp = temp->next;
    }
    return iCnt;
}

template <class T>
bool SinglyLL<T>::Search(T No)
{
    bool bFlag = false;
    struct nodeSL<T> * temp = NULL;
    temp = First;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            bFlag = true;
            break;
        }
        temp = temp->next;
    }
    return bFlag;
}

template <class T>
int SinglyLL<T>::SearchFirstOcc(T No)
{
    int iPos = -1;
    int iCnt = 1;
    struct nodeSL<T> * temp = NULL;
    temp = First;
    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iPos = iCnt;
            break;
        }
        iCnt++;
        temp = temp->next;
    }
    return iPos;
}

template <class T>
int SinglyLL<T>::SearchLastOcc(T No)
{
    int iPos = -1;
    int iCnt = 1;
    struct nodeSL<T> * temp = NULL;
    temp = First;
    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iPos = iCnt;
        }
        iCnt++;
        temp = temp->next;
    }
    return iPos;
}

template <class T>
void SinglyLL<T>::SumDigits()
{
    struct nodeSL<T> * temp = NULL;
    temp = First;
    int iDigit = 0, No = 0, iSum = 0;
    while(temp != NULL)
    {
        iSum = 0;
        No = temp->data;
        while(No != 0)
        {
            iDigit = No % 10;
            iSum = iSum + iDigit;
            No = No / 10;
        }
        cout<<iSum<<"\t";
        temp = temp->next;
    }   
    cout<<endl;
}

template <class T>
int SinglyLL<T>::FactorsAddition(int iNo)
{
    struct nodeSL<T> * temp = NULL;
    temp = First;
    int iSum = 0, i = 0;  
    for(i = 1; i<=iNo/2 ; i++)
    {            
        if(iNo % i == 0)
        {
            iSum = iSum + i;
        }            
    }
    return iSum;       
}

template <class T>
void SinglyLL<T>::SumFactors()
{
    struct nodeSL<T> * temp = NULL;
    temp = First;

    while(temp != NULL)
    {
        cout<<FactorsAddition(temp->data)<<"\t";
        temp = temp->next;
    }
    cout<<endl;
}

template <class T>
bool SinglyLL<T>::CheckPerfect(int No)
{
    int iSum = 0, i = 0;
    for(i = 1; i<=No/2; i++)
    {
        if(No % i == 0)
        {
            iSum = iSum + i;
        }
    }
    if(iSum == No)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void SinglyLL<T>::DisplayPerfect()
{
    struct nodeSL<T> * temp = NULL;
    temp = First;
    while(temp != NULL)
    {
        if(CheckPerfect(temp->data) == true)
        {
            cout<<temp->data<<" is perfect number"<<endl;
        }
        temp = temp->next;
    }
}

template <class T>
T SinglyLL<T>::MiddleElement()
{
    int iCnt = 0;
    struct nodeSL<T> * temp = First;
    int iPos = 0, i = 0;
    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }

    iPos = iCnt / 2;
    struct nodeSL<T> * temp1 = First;
    for(i = 1; i<=iPos; i++)
    {
        temp1 = temp1->next;
    }

    return temp1->data;
}


//////////////////////////////////////////////////////////
//
//Code of Singly Circular Linked List
//
///////////////////////////////////////////////////////////

template <class T>
struct nodeSC
{
    T data;
    struct nodeSC *next;
};

template <class T>
class singlyCL
{
    private:
        struct nodeSC<T> * First;
        struct nodeSC<T> * Last;
        int iCount;

        int FactorsAddition(T No);
        bool CheckPerfect(T No);

    public:
        singlyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
        
        T Addition();
        int EvenCount();
        int OddCount();
        int FrequencyCount(T No);
        bool Search(T No);
        int SearchFirstOcc(T No);
        int SearchLastOcc(T No);
        void SumDigits();
        void SumFactors();
        void DisplayPerfect();
        T MiddleElement();
};

template <class T>
singlyCL<T>::singlyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void singlyCL<T>::Display()
{
    if((First == NULL) && (Last == NULL))       //Filter
    {
        printf("LL is empty\n");
        return;
    }

    cout<<"->";
    do 
    {
        cout<<" | "<<First->data<<" |->";
        First = First->next;
    }while(First != Last->next);
    cout<<endl;
}

template <class T>
int singlyCL<T>::Count()
{
    return iCount;
}

template <class T>
void singlyCL<T>::InsertFirst(T No)
{
    struct nodeSC<T> * newn = NULL;

    newn = new struct nodeSC<T>;
    newn->data = No;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
        //(Last)->next = First;
    }
    else
    {
        newn->next = First;
        First = newn;
        //(Last)->next = First;
    }
    (Last)->next = First;
    iCount++;
}

template <class T>
void singlyCL<T>::InsertLast(T No)
{
    struct nodeSC<T> * newn = NULL;

    newn = new struct nodeSC<T>;
    newn->data = No;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
        //(Last)->next = First;
    }
    else
    {
        Last->next = newn;
        Last = newn;
        //(Last)->next = First;
    }   
    Last->next = First;
    iCount++;
}

template <class T>
void singlyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSC<T> * temp = NULL;
    int iLength = 0, i = 0;
    iLength = iCount;

    if(iPos < 1 || iPos > iLength+1)
    {
        cout<<"Invalid Position Entered"<<endl;
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iLength+1)
    {
        InsertLast(No);
    }
    else
    {
        struct nodeSC<T> * newn = NULL;
        newn = new struct nodeSC<T>;
        newn->data = No;
        newn->next = NULL;

        temp = First;
        for(i = 1; i<iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void singlyCL<T>::DeleteFirst()
{
    if((First == NULL) && (Last ==NULL))
    {
        cout<<"Unable to delete as LL is empty"<<endl;
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void singlyCL<T>::DeleteLast()
{
    if((First == NULL) && (Last ==NULL))
    {
        cout<<"Unable to delete as LL is empty"<<endl;
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        struct nodeSC<T> * temp = NULL;
        temp = First;
        while(temp->next != Last)
        {
            temp = temp->next;
        }
        delete temp->next;
        Last = temp;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void singlyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeSC<T> * temp1 = NULL;
    struct nodeSC<T> * temp2 = NULL;
    int iLength = 0, i = 0;
    iLength = iCount;

    if(iPos < 1 || iPos > iLength)
    {
        cout<<"Invalid Position Entered"<<endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iLength)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;
        temp2 = First;
        for(i = 1; i<iPos-1; i++)
        {
            temp1= temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        iCount--;
    }
}

template <class T>
T singlyCL<T>::Addition()
{
    T iSum = 0;

    do
    {
        iSum = iSum + First->data;
        First = First->next;
    }while(First != Last->next);

    return iSum;
}

template <class T>
int singlyCL<T>::EvenCount()
{
    int iCnt = 0;
    T iNo;

    do
    {
        iNo = First->data;
        if(iNo % 2 == 0)
        {
            iCnt++;
        }
        First = First->next;
    }while(First != Last->next);

    return iCnt;
}

template <class T>
int singlyCL<T>::OddCount()
{
    int iCnt = 0;
    T iNo;

    do
    {
        iNo = First->data;
        if(iNo % 2 != 0)
        {
            iCnt++;
        }
        First = First->next;
    }while(First != Last->next);

    return iCnt;
}

template <class T>
int singlyCL<T>::FrequencyCount(T No)
{
    int iCnt = 0;
        
    do
    {
        if(First->data == No)
        {
            iCnt++;
        }
        First = First->next;
    }while(First != Last->next);

    return iCnt;
}

template <class T>
bool singlyCL<T>::Search(T No)
{
    bool bFlag = false;

    struct nodeSC<T> * temp = First;
    
    do
    {
        if(temp->data == No)
        {
            bFlag = true;
            break;
        }
        temp = temp->next;
    }while(temp != Last->next);

    return bFlag;
}

template <class T>
int singlyCL<T>::SearchFirstOcc(T No)
{
    int iPos = -1;
    int iCnt = 1;

    if (First == NULL) 
    {
        return -1; // List is empty
    }

    struct nodeSC<T>* temp = First;

    do
    {
        if(temp->data == No)
        {
            iPos = iCnt;
            break;
        }
        iCnt++;
        temp = temp->next;
    }while(temp != First);

    return iPos;
}


template <class T>
int singlyCL<T>::SearchLastOcc(T No)
{
    int iPos = -1;
    int iCnt = 1;

    if (First == NULL) 
    {
        return -1; // List is empty
    }

    struct nodeSC<T>* temp = First;

    do
    {
        if (temp->data == No)
        {
            iPos = iCnt; // Update position to the latest occurrence
        }
        temp = temp->next;
        iCnt++;
    } while (temp != First); // Continue until we circle back to the head

    return iPos;
}

template <class T>
void singlyCL<T>::SumDigits()
{
    int iDigit = 0, No = 0, iSum = 0;
    
    do
    {
        iSum = 0;
        No = First->data;
        while(No != 0)
        {
            iDigit = No % 10;
            iSum = iSum + iDigit;
            No = No / 10;
        }
        cout<<iSum<<"\t";
        First = First->next;
    }while(First != Last->next);

    cout<<endl;
}

template <class T>
int singlyCL<T>::FactorsAddition(T iNo)
{
    int iSum = 0, i = 0;  
    for(i = 1; i<=iNo/2 ; i++)
    {            
        if(iNo % i == 0)
        {
            iSum = iSum + i;
        }            
    }

    return iSum;       
}

template <class T>
void singlyCL<T>::SumFactors()
{
    do
    {
        cout<<FactorsAddition(First->data)<<"\t";
        First = First->next;
    }while(First != Last->next);

    cout<<endl;
}

template <class T>
bool singlyCL<T>::CheckPerfect(T No)
{
    int iSum = 0, i = 0;
    for(i = 1; i<=No/2; i++)
    {
        if(No % i == 0)
        {
            iSum = iSum + i;
        }
    }
    if(iSum == No)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void singlyCL<T>::DisplayPerfect()
{
    do
    {
        if(CheckPerfect(First->data) == true)
        {
            cout<<First->data<<" is perfect number"<<endl;
        }
        First = First->next;
    }while(First != Last->next);
}

template <class T>
T singlyCL<T>::MiddleElement()
{
    int iCnt = 0;
    int iPos = 0, i = 0;
    struct nodeSC<T> * temp1 = First;

    do
    {
        iCnt++;
        First = First->next;
    }while(Last->next != First);

    iPos = iCnt / 2;
    
    for(i = 1; i<=iPos; i++)
    {
        temp1 = temp1->next;
    }

    return temp1->data;
}



////////////////////////////////////////////////////////////
//
//Code of Doubly Linear Linked List
//
///////////////////////////////////////////////////////////

template <class T>
struct nodeDL
{
    T data;
    struct nodeDL *next;
    struct nodeDL *prev;
};

template <class T>
class DoublyLL
{
    public:
        struct nodeDL<T> * First;
        int iCount;

        int FactorsAddition(T No);
        bool CheckPerfect(T No);

    public:
        
        DoublyLL();

        void Display();
        int Count();
        
        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        T Addition();
        int EvenCount();
        int OddCount();
        int FrequencyCount(T No);
        bool Search(T No);
        int SearchFirstOcc(T No);
        int SearchLastOcc(T No);
        void SumDigits();
        void SumFactors();
        void DisplayPerfect();
        T MiddleElement();
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
    struct nodeDL<T> * temp = NULL;
    temp = First;
    cout<<"NULL <=> ";
    while(temp != NULL)
    {
        cout<<" "<<temp->data<<" <=>";
        temp = temp->next;
    }
    cout<<" NULL"<<endl;
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct nodeDL<T> * newn = NULL;

    newn = new struct nodeDL<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct nodeDL<T> * newn = NULL;
    struct nodeDL<T> * temp = NULL;

    newn = new struct nodeDL<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDL<T> * temp = NULL;
    int iLength = 0;
    int i = 0;

    iLength = iCount;

    if(iPos < 1 || iPos > iLength+1)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iLength+1)
    {
        InsertLast(No);
    }
    else
    {
        struct nodeDL<T> * newn = NULL;
        newn = new struct nodeDL<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;
        for(i= 1; i<iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    struct nodeDL<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to delete as LL is Empty"<<endl;
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else 
    {
        temp = First;
        First = First->next;
        temp->next->prev = NULL;
        delete temp;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    struct nodeDL<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to delete as LL is Empty"<<endl;
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else 
    {
        temp = First;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    struct nodeDL<T> * temp = NULL;
    int iLength = 0;
    int i = 0;

    iLength = iCount;

    if(iPos < 1 || iPos > iLength)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iLength)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for(i = 1; i<iPos-1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        iCount--;
    }
}

template <class T>
T DoublyLL<T>::Addition()
{
    T iSum = 0;

    struct nodeDL<T> * temp = First;

    while(temp != NULL)
    {
        iSum = iSum + temp->data;
        temp = temp->next;
    }

    return iSum;
}

template <class T>
int DoublyLL<T>::EvenCount()
{
    int iCnt = 0;
    T iNo;

    struct nodeDL<T> * temp = First;
    while(temp != NULL)
    {
        iNo = temp->data;
        if((temp->data) % 2 == 0)
        {
            iCnt++;
        }
        temp = temp->next;
    }

    return iCnt;
}

template <class T>
int DoublyLL<T>::OddCount()
{
    int iCnt = 0;
    T iNo;

    struct nodeDL<T> * temp = First;

    while(temp != NULL)
    {
        iNo = temp->data;
        if(iNo % 2 != 0)
        {
            iCnt++;
        }
        temp = temp->next;
    }

    return iCnt;
}

template <class T>
int DoublyLL<T>::FrequencyCount(T No)
{
    int iCnt = 0;
    
    struct nodeDL<T> * temp = First;
        
    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iCnt++;
        }
        temp = temp->next;
    }

    return iCnt;
}

template <class T>
bool DoublyLL<T>::Search(T No)
{
    bool bFlag = false;

    struct nodeDL<T> * temp = First;
    
    while(temp != NULL)
    {
        if(temp->data == No)
        {
            bFlag = true;
            break;
        }
        temp = temp->next;
    }

    return bFlag;
}

template <class T>
int DoublyLL<T>::SearchFirstOcc(T No)
{
    int iPos = -1;
    int iCnt = 1;

    if (First == NULL) 
    {
        return -1; // List is empty
    }

    struct nodeDL<T>* temp = First;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iPos = iCnt;
            break;
        }
        iCnt++;
        temp = temp->next;
    }

    return iPos;
}


template <class T>
int DoublyLL<T>::SearchLastOcc(T No)
{
    int iPos = -1;
    int iCnt = 1;

    if (First == NULL) 
    {
        return -1; // List is empty
    }

    struct nodeDL<T>* temp = First;

    while(temp != NULL)
    {
        if (temp->data == No)
        {
            iPos = iCnt; // Update position to the latest occurrence
        }
        temp = temp->next;
        iCnt++;
    } 

    return iPos;
}

template <class T>
void DoublyLL<T>::SumDigits()
{
    int iDigit = 0, No = 0, iSum = 0;

    struct nodeDL<T> * temp = First;
    
    while(temp != NULL)
    {
        iSum = 0;
        No = temp->data;
        while(No != 0)
        {
            iDigit = No % 10;
            iSum = iSum + iDigit;
            No = No / 10;
        }
        cout<<iSum<<"\t";
        temp = temp->next;
    }

    cout<<endl;
}

template <class T>
int DoublyLL<T>::FactorsAddition(T iNo)
{
    int iSum = 0, i = 0;  
    for(i = 1; i<=iNo/2 ; i++)
    {            
        if(iNo % i == 0)
        {
            iSum = iSum + i;
        }            
    }

    return iSum;       
}

template <class T>
void DoublyLL<T>::SumFactors()
{
    struct nodeDL<T> * temp = First;

    while(temp != NULL)
    {
        cout<<FactorsAddition(temp->data)<<"\t";
        temp = temp->next;
    }

    cout<<endl;
}

template <class T>
bool DoublyLL<T>::CheckPerfect(T No)
{
    int iSum = 0, i = 0;
    for(i = 1; i<=No/2; i++)
    {
        if(No % i == 0)
        {
            iSum = iSum + i;
        }
    }
    if(iSum == No)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void DoublyLL<T>::DisplayPerfect()
{
    struct nodeDL<T> * temp = First;

    while(temp != NULL)
    {
        if(CheckPerfect(temp->data) == true)
        {
            cout<<temp->data<<" is perfect number"<<endl;
        }
        temp = temp->next;
    }
}

template <class T>
T DoublyLL<T>::MiddleElement()
{
    int iCnt = 0;
    int iPos = 0, i = 0;
    struct nodeDL<T> * temp = First;
    struct nodeDL<T> * temp1 = First;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }

    iPos = iCnt / 2;
    
    for(i = 1; i<=iPos; i++)
    {
        temp1 = temp1->next;
    }

    return temp1->data;
}

/////////////////////////////////////////////////////////////////
//
//Code of Doubly Circular Linked List
//
//////////////////////////////////////////////////////////////////
template <class T>
struct nodeDC 
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template <class T>
class DoublyCL
{
    private:
        struct nodeDC<T> * First;
        struct nodeDC<T> * Last;
        int iCount;

        int FactorsAddition(T No);
        bool CheckPerfect(T No);

    public:

        DoublyCL();         //Constructor

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        T Addition();
        int EvenCount();
        int OddCount();
        int FrequencyCount(T No);
        bool Search(T No);
        int SearchFirstOcc(T No);
        int SearchLastOcc(T No);
        void SumDigits();
        void SumFactors();
        void DisplayPerfect();
        T MiddleElement();
};

template <class T>
DoublyCL<T>::DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked List is Empty"<<endl;
        return;
    }

    cout<<" <=> ";
    do 
    {
        cout<<"| "<<First->data<<" | <=> ";
        First = First->next;
    }while(Last->next != First);
    cout<<endl;
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new struct nodeDC<T>; // OR newn = new node;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
        // Last->next = First;
        // First->prev = Last;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
        // First->prev = Last;
        // Last->next = First;
    }
    Last->next = First;
    First->prev = Last;
    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new struct nodeDC<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
        // Last->next = First;
        // First->prev = Last;
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;
        // Last->next = First;
        // First->prev = Last;
    }
    Last->next = First;
    First->prev = Last;
    iCount++;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    int i = 0;
    int iLength = 0;
    iLength = iCount;

    if(iPos < 1 || iPos > iLength+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iLength+1)
    {
        InsertLast(No);
    }
    else
    {
        struct nodeDC<T> * newn = NULL;

        newn = new struct nodeDC<T>;
        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        struct nodeDC<T> * temp = NULL;
        temp = First;
        for(i = 1; i<iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if((First == NULL) && (Last == NULL))   // Empty LL
    {
        printf("Unable to delete as LL is empty\n");
        return;
    }
    else if(First == Last)      //Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else        //More than one node
    {
        First = First->next;
        delete Last->next;
        First->prev = Last;
        Last->next = First;   
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if((First == NULL) && (Last == NULL))   // Empty LL
    {
        printf("Unable to delete as LL is empty\n");
        return;
    }
    else if(First == Last)      //Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else        //More than one node
    {
        Last = Last->prev;
        delete First->prev;
        Last->next = First;
        First->prev = Last;

    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    int iLength = 0;
    iLength = iCount;

    if(iPos < 1 || iPos > iLength)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iLength)
    {
        DeleteLast();
    }
    else
    {
        struct nodeDC<T> * temp = NULL;
        temp = First;
        for(i = 1; i<iPos-1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;        

        iCount--;
    }
}

template <class T>
T DoublyCL<T>::Addition()
{
    T iSum = 0;

    do
    {
        iSum = iSum + First->data;
        First = First->next;
    }while(Last->next != First);

    return iSum;
}

template <class T>
int DoublyCL<T>::EvenCount()
{
    int iCnt = 0;
    T iNo;

    do
    {
        iNo = First->data;
        if(iNo % 2 == 0)
        {
            iCnt++;
        }
        First = First->next;
    }while(Last->next != First);

    return iCnt;
}

template <class T>
int DoublyCL<T>::OddCount()
{
    int iCnt = 0;
    T iNo;

    do
    {
        iNo = First->data;
        if(iNo % 2 != 0)
        {
            iCnt++;
        }
        First = First->next;
    }while(Last->next != First);

    return iCnt;
}

template <class T>
int DoublyCL<T>::FrequencyCount(T No)
{
    int iCnt = 0;
        
    do
    {
        if(First->data == No)
        {
            iCnt++;
        }
        First = First->next;
    }while(Last->next != First);

    return iCnt;
}

template <class T>
bool DoublyCL<T>::Search(T No)
{
    bool bFlag = false;

    struct nodeDC<T> * temp = First;
    
    do
    {
        if(temp->data == No)
        {
            bFlag = true;
            break;
        }
        temp = temp->next;
    }while(Last->next != temp);

    return bFlag;
}

template <class T>
int DoublyCL<T>::SearchFirstOcc(T No)
{
    int iPos = -1;
    int iCnt = 1;

    if (First == NULL) 
    {
        return -1; // List is empty
    }

    struct nodeDC<T>* temp = First;

    do
    {
        if(temp->data == No)
        {
            iPos = iCnt;
            break;
        }
        iCnt++;
        temp = temp->next;
    }while(temp != First);

    return iPos;
}


template <class T>
int DoublyCL<T>::SearchLastOcc(T No)
{
    int iPos = -1;
    int iCnt = 1;

    if (First == NULL) 
    {
        return -1; // List is empty
    }

    struct nodeDC<T>* temp = First;

    do
    {
        if (temp->data == No)
        {
            iPos = iCnt; // Update position to the latest occurrence
        }
        temp = temp->next;
        iCnt++;
    } while (temp != First); // Continue until we circle back to the head

    return iPos;
}

template <class T>
void DoublyCL<T>::SumDigits()
{
    int iDigit = 0, No = 0, iSum = 0;
    
    do
    {
        iSum = 0;
        No = First->data;
        while(No != 0)
        {
            iDigit = No % 10;
            iSum = iSum + iDigit;
            No = No / 10;
        }
        cout<<iSum<<"\t";
        First = First->next;
    }while(Last->next != First);

    cout<<endl;
}

template <class T>
int DoublyCL<T>::FactorsAddition(T iNo)
{
    int iSum = 0, i = 0;  
    for(i = 1; i<=iNo/2 ; i++)
    {            
        if(iNo % i == 0)
        {
            iSum = iSum + i;
        }            
    }

    return iSum;       
}

template <class T>
void DoublyCL<T>::SumFactors()
{
    do
    {
        cout<<FactorsAddition(First->data)<<"\t";
        First = First->next;
    }while(Last->next != First);

    cout<<endl;
}

template <class T>
bool DoublyCL<T>::CheckPerfect(T No)
{
    int iSum = 0, i = 0;
    for(i = 1; i<=No/2; i++)
    {
        if(No % i == 0)
        {
            iSum = iSum + i;
        }
    }
    if(iSum == No)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void DoublyCL<T>::DisplayPerfect()
{
    do
    {
        if(CheckPerfect(First->data) == true)
        {
            cout<<First->data<<" is perfect number"<<endl;
        }
        First = First->next;
    }while(Last->next != First);
}

template <class T>
T DoublyCL<T>::MiddleElement()
{
    int iCnt = 0;
    int iPos = 0, i = 0;
    struct nodeDC<T> * temp1 = First;

    do
    {
        iCnt++;
        First = First->next;
    }while(Last->next != First);

    iPos = iCnt / 2;
    
    for(i = 1; i<=iPos; i++)
    {
        temp1 = temp1->next;
    }

    return temp1->data;
}



///////////////////////////////////////////////////////////
//
//Code of Stack
//
///////////////////////////////////////////////////////////


template <class T>
struct nodeSCK
{
    T data;
    struct nodeSCK *next;
};


template <class T>
class Stack
{
    private:
        struct nodeSCK<T> * First;
        int iCount;

    public:
         
        Stack();
        void Display();
        int Count();
        void Push(T No);  
        T Pop();          
};

template <class T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Stack<T>::Display()
{
    cout<<"Elements of stack are: "<<endl;
    struct nodeSCK<T> * temp = NULL;
    temp = First;
    while(temp != NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    cout<<endl;
}

template <class T>
int Stack<T>::Count()
{
    return iCount;
}

template <class T>
void Stack<T>::Push(T No)
{
    struct nodeSCK<T> * newn = NULL;
    
    newn = new struct nodeSCK<T>;
    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next =  First;
        First = newn;
    }
    iCount++;
}

template <class T>
T Stack<T>::Pop()
{
    T iValue = 0;
    struct nodeSCK<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to pop the element as Stack is empty"<<endl;
        return -1;
    }
    else
    {
        temp = First;

        iValue = First->data;
        First = First->next;
        delete temp;

        iCount--;
    }
    return iValue;
}


//////////////////////////////////////////////////////////
//
//Code of Queue
//
////////////////////////////////////////////////////////////


template <class T>
struct nodeQ
{
    int data;
    struct nodeQ *next;
};

template <class T>
class Queue
{
    private:
        struct nodeQ<T> * First;
        int iCount;

    public:
         
        Queue();
        void Display();
        int Count();
        void EnQueue(T No);  
        T DeQueue();          
};

template <class T>
Queue<T>::Queue()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Queue<T>::Display()
{
    cout<<"Elements of Queue are: "<<endl;
    struct nodeQ<T> * temp = NULL;
    
    temp = First;
    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
    cout<<endl;
}

template <class T>
int Queue<T>::Count()
{
    return iCount;
}

template <class T>
void Queue<T>::EnQueue(T No)
{
    struct nodeQ<T> * newn = NULL;
    struct nodeQ<T> * temp = NULL;
    
    newn = new struct nodeQ<T>;
    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
T Queue<T>::DeQueue()
{
    T iValue;
    struct nodeQ<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to remove the element as Queue is empty"<<endl;
        return -1;
    }
    else
    {
        temp = First;

        iValue = First->data;
        First = First->next;
        delete temp;

        iCount--;
    }
    return iValue;
}

//////////////////////////////////////////////////////////
//
//Code of Searching and Sorting Algorithms
//
////////////////////////////////////////////////////////////

template <class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

        ArrayX(int Value); 
        ~ArrayX(); 

        void Accept();
        void Display();
        
        bool LinearSearch(T Value);   
        bool BiDirectionalSearch(T Value);  
        bool BinarySearch(T Value); 

        void BubbleSort();
        void BubbleSortEfficient();
        void SelectionSort();
        void InsertionSort();
};

template <class T>
ArrayX<T>::ArrayX(int Value)
{
    this->iSize = Value;
    this->Arr = new T[iSize];
}

template <class T>
void ArrayX<T>::Accept()
{
    int i = 0;
    cout<<"Enter the elements: "<<endl;
    for(i = 0; i<iSize; i++)
    {
        cin>>Arr[i];
    }
}

template <class T>
void ArrayX<T>::Display()
{
    int i = 0;
    cout<<"Entered elements are: "<<endl;
    for(i = 0; i<iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }
}

template <class T>
ArrayX<T>::~ArrayX()
{
    delete []Arr;
}

///////////////////////////////////////////////////////////////////////
// Linear Search
///////////////////////////////////////////////////////////////////////

template <class T>
bool ArrayX<T>::LinearSearch(T Value)
{
    int i = 0;
    bool bFlag = false;
    for(i = 0; i< iSize; i++)
    {
        if(Arr[i] == Value)
        {
            bFlag = true;
            break;
        }
    }
    return bFlag;
}

///////////////////////////////////////////////////////////////////////
// BiDirectional Search
///////////////////////////////////////////////////////////////////////

template <class T>
bool ArrayX<T>::BiDirectionalSearch(T Value)
{
    bool bFlag = false;
    int iStart = 0, iEnd = iSize-1;
    int i = 0, j = 0;
    
    for(i = iStart, j = iEnd; iStart<=iEnd; i++, j--)
    {
        if((Arr[i] == Value) || (Arr[j] == Value))
        {
            bFlag = true;
            break;
        }
    }
    return bFlag;
}

///////////////////////////////////////////////////////////////////////
// Binary Search
///////////////////////////////////////////////////////////////////////


template <class T>
bool ArrayX<T>::BinarySearch(T Value)
{
    int iStart= 0, iEnd = 0, iMid = 0;
    bool flag = false;

    iStart = 0;
    iEnd = iSize-1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) /2);

        if((Arr[iMid] == Value) || (Arr[iStart] == Value) || (Arr[iEnd] ==Value))
        {
            flag = true;
            break;
        }
        else if(Value < Arr[iMid])
        {
            iStart = iMid + 1;
        }
        else if(Value > Arr[iMid])
        {
            iEnd = iMid - 1;
        }
    }
    return flag;
}  

///////////////////////////////////////////////////////////////////////
// Bubble Sort
///////////////////////////////////////////////////////////////////////


template <class T>
void ArrayX<T>::BubbleSort()
{
    T temp;
    int i = 0, j = 0;

    for(i = 0; i<iSize-1; i++)
    {
        for(j = 0; j<iSize- 1-i; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
        cout<<"\nArray After pass: "<<i+1<<endl;
        Display();
    }
}

///////////////////////////////////////////////////////////////////////
// Bubble Sort Efficient
///////////////////////////////////////////////////////////////////////


template <class T>
void ArrayX<T>::BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = false;

    for(i = 0; i<iSize-1; i++)
    {
        flag = false;
        for(j = 0; j<iSize- 1-i; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
        if(flag == false)
        {
            break;
        }
        cout<<"\nArray After pass: "<<i+1<<endl;
        Display();
    }
}

///////////////////////////////////////////////////////////////////////
// Selection Sort
///////////////////////////////////////////////////////////////////////


template <class T>
void ArrayX<T>::SelectionSort()
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    for(i = 0; i< iSize-1; i++)
    {
        min_index = i;

        for(j = i+1; j< iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}

///////////////////////////////////////////////////////////////////////
// Insertion Sort
///////////////////////////////////////////////////////////////////////

template <class T>
void ArrayX<T>::InsertionSort()
{
    int i = 0, j = 0;
    T selected;

    for(i = 1; i< iSize; i++)
    {
        for(j = i-1, selected = Arr[i]; (j>=0) && (Arr[j] > selected); j--)
        {
            Arr[j+1]= Arr[j];
        }
        Arr[j+1] = selected;
    }    
}


//////////////////////////////////////////////////////////
//
//Code of Binary Search Tree
//
////////////////////////////////////////////////////////////

template <class T>
struct Node 
{
    T data;
    struct Node* lchild;
    struct Node* rchild;

    Node(T value) 
    {
        data = value;
        lchild = NULL;
        rchild = NULL;
    }
};

template <class T>
class BStree 
{
    private:
        struct Node<T>* Root;

        // Helper functions
        void insert(struct Node<T>** root, T value);
        void inorderTraversal(struct Node<T>* root);
        void preorderTraversal(struct Node<T>* root);
        void postorderTraversal(struct Node<T>* root);
        int countLeafNodes(struct Node<T>* root);
        int countParentNodes(struct Node<T>* root);
        int countAllNodes(struct Node<T>* root);

    public:
        BStree();

        void Insert(T value);
        void Inorder();
        void Preorder();
        void Postorder();
        bool Search(T value);
        int CountLeaf();
        int CountParent();
        int CountAllNodes();
};

template <class T>
BStree<T>::BStree()
{
    Root = NULL;
}

template <class T>
void BStree<T>::insert(struct Node<T>** root, T value) 
{
    if (*root == NULL) 
    {
        *root = new struct Node<T>(value);
    } 
    else if (value < (*root)->data) 
    {
        insert(&((*root)->lchild), value);
    } 
    else if (value > (*root)->data) 
    {
        insert(&((*root)->rchild), value);
    } 
    else 
    {
        cout << "Element already present\n";
    }
}

template <class T>
void BStree<T>::Insert(T value) 
{
    insert(&Root, value);
}

template <class T>
void BStree<T>::inorderTraversal(struct Node<T>* root) 
{
    if (root != NULL) {
        inorderTraversal(root->lchild);
        cout << root->data << " ";
        inorderTraversal(root->rchild);
    }
}

template <class T>
void BStree<T>::Inorder() 
{
    cout << "Inorder Traversal: ";
    inorderTraversal(Root);
    cout << endl;
}

template <class T>
void BStree<T>::preorderTraversal(struct Node<T>* root) 
{
    if (root != NULL) {
        cout << root->data << " ";
        preorderTraversal(root->lchild);
        preorderTraversal(root->rchild);
    }
}

template <class T>
void BStree<T>::Preorder() 
{
    cout << "Preorder Traversal: ";
    preorderTraversal(Root);
    cout << endl;
}

template <class T>
void BStree<T>::postorderTraversal(struct Node<T>* root) 
{
    if (root != NULL) {
        postorderTraversal(root->lchild);
        postorderTraversal(root->rchild);
        cout << root->data << " ";
    }
}

template <class T>
void BStree<T>::Postorder() 
{
    cout << "Postorder Traversal: ";
    postorderTraversal(Root);
    cout << endl;
}

template <class T>
bool BStree<T>::Search(T value) 
{
    struct Node<T>* temp = Root;
    bool flag = false;
    while (temp != NULL)
    {
        if (value == temp->data) 
        {
            flag = true;
            break;
        } 
        else if (value < temp->data) 
        {
            temp = temp->lchild;
        } 
        else 
        {
            temp = temp->rchild;
        }
    }
    return flag;
}

template <class T>
int BStree<T>::countLeafNodes(struct Node<T>* root) 
{
    if (root == NULL) 
    {
        return 0;
    }
    if (root->lchild == NULL && root->rchild == NULL)
    {
        return 1;
    }
    else
    {
        return countLeafNodes(root->lchild) + countLeafNodes(root->rchild);
    }
}

template <class T>
int BStree<T>::CountLeaf() 
{
    return countLeafNodes(Root);
}

template <class T>
int BStree<T>::countParentNodes(struct Node<T>* root) 
{
    int count = 0;
    if (root == NULL) 
    {
        return 0;
    }    
    if (root->lchild != NULL || root->rchild != NULL) 
    {
        count++;
    }

    return count + countParentNodes(root->lchild) + countParentNodes(root->rchild);
}

template <class T>
int BStree<T>::CountParent() 
{
    return countParentNodes(Root);
}

template <class T>
int BStree<T>::countAllNodes(struct Node<T>* root) 
{
    if (root == NULL) 
    {
        return 0;
    }
    else
    {
        return 1 + countAllNodes(root->lchild) + countAllNodes(root->rchild);
    }
}

template <class T>
int BStree<T>::CountAllNodes() 
{
    return countAllNodes(Root);
}


int main()
{
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"-----------------------Singly Linear Linked List------------------------------"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    //LL of Integer
    cout<<"-------------------------LL of integers-----------------------"<<endl;

    SinglyLL<int> *iSLobj = new SinglyLL<int>();
    
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"-----------------------Singly Circular Linked List------------------------------"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    //Linked List of Integers
    cout<<"-------------------------LL of integers-----------------------"<<endl;

    singlyCL<int> *iSCobj = new singlyCL<int>();

    

    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"-----------------------Doubly Linear Linked List------------------------------"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    //Linked List of Integers
    cout<<"-------------------------LL of integers-----------------------"<<endl;


    DoublyLL<int> *iDLobj = new DoublyLL<int>();

    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"-----------------------Doubly Circular Linked List------------------------------"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    //Doubly Circular LL
    cout<<"-------------------------LL of integers-----------------------"<<endl;
    
    DoublyCL<int> *iDCobj = new DoublyCL<int>();
 

    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"-----------------------Implementation of Stack----------------------------------"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    //Stack
    cout<<"-------------------------Stack of integers--------------------------------------"<<endl;

    Stack<int> *iSCKobj = new Stack<int>();
  

    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"-----------------------Implementation of Queue----------------------------------"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    //Queue
    cout<<"-------------------------Queue of integers--------------------------------------"<<endl;

    Queue<int> *iQobj = new Queue<int>();

    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"-----------------------Searching and Sorting Algorithms------------------------"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"------------------Searching and Sorting of Intergers----------------------------"<<endl;

    int iLength = 0, No = 0;
    bool bRet = false;

    // cout<<"Enter the number of elements: "<<endl;
    // cin>>iLength;

    ArrayX<int> *aobj = new ArrayX<int>(iLength);


    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"------------------------------Binary Search Tree--------------------------------"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"---------------------Binary Search Tree of Intergers----------------------------"<<endl;

    BStree<int> *bstobj = new BStree<int>();
    
    return 0;

    
}