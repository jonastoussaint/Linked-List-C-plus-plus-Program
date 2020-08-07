//+-------------------------------------------
//+ Author: Jonas Toussaint                  + 
//+ Class: COP3530                           + 
//+ Assignment: Project1-linklist            +
//+ Due Date: 1/17/18                        +
//+ This batch programming reads in a file of+ 
//+ of words and characters and removes all  +
//+ numbers and special characters and puts  +
//+ them into a linked list word by word in  +
//+ a sorted linked list. It then prints     +
//+ the output to the user                   +
//+------------------------------------------+
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

//Node structure
struct node
{
    string val;
    int count;
    node* next;
    node() 
    {
        count=1;
    }
};

//Insert function for linked list.
void insertNode(node* &head, string num);

// Print function for linked list.
void printList(node* list);




int main()
{
  
   node* list = NULL;                                    // Create node called list pointer and set = NULL.
   
   ifstream inF;                                         // File object 
   inF.open("file3.txt");                                // Open the file 
    
    //Declaration of variables 
    string s;
    string word;
    int max;
    
    while(!inF.eof())                                   // A while loop to read throught the whole file.
    {
       getline(inF,s);                                  //   read the file.
        max=80;
        
        if(s.length() < max)
            max = s.length();
        
        for(int i=0; i < max;i++)
        {        
            if(((s[i] == ' ') && (word !="")))          // Checks for blanked space and non word characters
            {              
                for(int j=0, len = word.size(); j<len; j++)
                {
                     if(ispunct(s[j]))                  // if statements removes all punctuations 
                     { 
                          s.erase(j--, 1);              // erased the punctuations.s
                          len = s.size();   
                     }                                           
                }
                    for(int n=0; n < word.size(); n++)
                    {
                        word[n] = tolower(word[n]);     // Changes the characters to lowers case.
                    }
                        insertNode(list, word);         // Word to push in insert function

                        word = "";               
            }
            
                if(s[i]!=' ')
                {
                    word+=s[i];
                }
                
                if(i == max - 1 && word != "")
                {
                 
                    word = " ";
                }
        }
       
    }
        
                printList(list);   // Call the print functions.
    return 0;

}

void insertNode(node* &head, string sen)
{
    node* temp = head;            // create a node temp.
    if(head == NULL)              // if the head of the linked list is empty. 
    {
        head = new node;          // create a new node.
        head-> val=sen;           // passed the sen to head.
        return;
    }
    
    if(sen < head -> val)         // if sen is less than the head that points to val.
    {
        if(sen == head -> val)    // if sen appears multiple times increase the counter.
        {
            head -> count++;      // Increase the counter in the head.
            return;
        }
     node* new_node = new node;   // Create a new node called new_node.
     new_node -> val = sen;       // Set sen to the new node.
     new_node -> next = head;     // Move the next pointer.  
     head = new_node;             // Set head to the new node.
        return;
    }
    
     while(temp -> next != NULL)  // A while loop that will create a new node if the
     {                            // next node is NULL.
         if(sen == temp -> val)   // if sen is temp then increase the counter.
         {
            temp -> count++;      // Increase the temp counter.
            return;
         }
        
         if(sen < temp -> next -> val)            // if sen is less the next pointer that points to val
         {           
             node* new_node = new node;           // Create a new node pointer calles new_node.
             new_node -> val = sen;               // Set sen = the new_node pointer that points to val.
             new_node -> next = temp -> next;     // the temp pointer that points to next = new_node that points
             temp -> next = new_node;             // Set new_node = to temp pointer that points to next.
             return;
         }
         
         temp = temp -> next;                     // Set temp pointer that points to next to temp.
     }
    
    if(sen > temp -> val)                         // Is sen is greater the temp that points to val.
    {       
         if(sen == temp -> val)                   //  if sen is temp that points to val.
         {
            temp -> count++;                      //  Then increase the temp that points to the counter.
            return;
         }
        
        node* new_node = new node;               // Create a new node pointer called new_node. 
        new_node -> val = sen;                   // Set sen = to new_node that points to next.
        temp -> next = new_node;                 // Set new_node = temp that points to next.
        return;
    }
    
}

void printList(node* list)
{
   while(list!= NULL)
   {
    cout << list -> val << " " << list-> count << endl;
    list = list -> next;
   }
}
