/*
 * Program to implement hash table using an array of linked list nodes. Is able to rehash when there are more than 3 collisions.
 * By: Max Shi
 * 3/12/2022
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace::std;

struct Student {
  char first[80];
  char last[80];
  int id;
  float gpa;
};

struct node
{
  Student* s;
  node* next;
};

bool random(node* table[], int arraySize, char firstNames[][30], char lastNames[][30], int &id);
int hashFun(Student* s, int arraySize);
bool add(Student* s, node* table[], int arraySize);
void print(node* table[], int arraySize);
void del(node* table[], int arraySize, int id);
void deleteNode(node* &head, node* previous, node* current, int id);
bool copy(node* newTable[], node* oldTable[], int newSize);

int main() {
  srand(time(NULL));
<<<<<<< HEAD

  //creates array of first names from a text file
=======
>>>>>>> origin/main
  fstream first;
  first.open("first.txt");
  char firstArr[50][30];
  char name[80];
  for(int i = 0; i < 50; i++)
    {
      first.getline(name, 30, '\n'); //each name is on a new line
      strcpy(firstArr[i], name);
    }

  //creates array of last names from text file
  fstream last;
  last.open("last.txt");
  char lastArr[100][30];
  for(int i = 0; i < 100; i++)
    {
      last.getline(name, 30, '\n');
      strcpy(lastArr[i], name);
    }
<<<<<<< HEAD

  int arraySize = 100; //initial size of array
  int id = 0; //starting id for student generator

  //pointer to array of node pointers
  node* *tablePtr = new node*[100];
  for(int i = 0; i< 100; i++)
  {
    tablePtr[i] = NULL; //sets each position of array to NULL
  }
=======
  
  
  Student* a = new Student();
  strcpy(a->first, "Max");
  strcpy(a->last, "Shi");
  a->id = 1;
  a->gpa = 6.9;

  Student* b = new Student();
  strcpy(b->first, "Bob");
  strcpy(b->last, "Shi");
  b->id = 0;
  b->gpa = 6.9;

  Student* c = new Student();
  strcpy(c->first, "Zob");
  strcpy(c->last, "Shi");
  c->id = 100;
  c->gpa = 6.9;
 


  node* *tablePtr = new node*[100];
  for(int i = 0; i< 100; i++)
    {
      tablePtr[i] = NULL;
    }

 
 
  int arraySize = 100;

  
  add(a, tablePtr, arraySize);
  add(b, tablePtr, arraySize);
  add(c, tablePtr, arraySize);
  

  int id = 0;
  
  print(tablePtr, arraySize);
>>>>>>> origin/main

  while(true) {
    char input[80];
    cout << "ADD, PRINT, DELETE, GENERATE, QUIT\n";
    cin.getline(input, 80);
    bool rehash = false;
    if (strcmp(input, "ADD")==0)
    {
      char first[80];
      char last[80];
      int id;
      float gpa;
      cout << "Enter first name: ";
      cin.getline(first, 80);
      cout << "Enter last name: ";
      cin.getline(last, 80);
      cout << "Enter id: ";
      cin >> id;
      cin.ignore();
      cout << "Enter gpa: ";
      cin >> gpa;
      cin.ignore();

      Student* s = new Student();
      strcpy(s->first, first);
      strcpy(s->last, last);
      s->id = id;
      s->gpa = gpa;
      
      rehash = add(s, tablePtr, arraySize);
    }
    else if (strcmp(input, "PRINT") == 0)
    {
      print(tablePtr, arraySize);
    }
    else if (strcmp(input, "DELETE") == 0)
    {
      int id = 0;
      cout << "Enter ID: ";
      cin >> id;
      cin.ignore();
      del(tablePtr, arraySize, id);
    }
    else if(strcmp(input, "GENERATE") == 0)
    {
<<<<<<< HEAD
      rehash = random(tablePtr, arraySize, firstArr, lastArr, id);
=======
      arraySize = arraySize * 2;
      node* *temp = new node*[arraySize];
      copy(temp, tablePtr, arraySize);
      delete tablePtr;
      tablePtr = temp;    
>>>>>>> origin/main
    }
    else if (strcmp(input, "QUIT") == 0)
    {
        break;   
    }
<<<<<<< HEAD

    //puts the nodes from the original table into a table that is twice as large
    while (rehash == true)
    {
      arraySize = arraySize * 2;
      node* *temp = new node*[arraySize];
      rehash = copy(temp, tablePtr, arraySize);
      delete tablePtr; //delete old table
      tablePtr = temp; //sets the pointer to the new table
      cout << "Table rehashed. Size: " << arraySize << endl;
    }
=======
>>>>>>> origin/main
  }
  return 0;
}

//randomly generate students and add them to hash table
bool random(node* table[], int arraySize, char firstNames[][30], char lastNames[][30], int &id)
{
  bool rehash = false;
  int number = 0;
  cout << "Enter number of students to generate: ";
  cin >> number;
  cin.ignore(100, '\n');

  //generates for the number of students
  for (int i = 0; i < number; i++)
    {
      Student* s = new Student();
      strcpy(s->first, firstNames[rand() % 50]); //gets random name
      strcpy(s->last, lastNames[rand() % 50]);
      s->id = ++id;
      float newGpa = (rand() % 50)/10.0;
      s->gpa = newGpa;
      rehash = add(s, table, arraySize);
    }
  return rehash;
}

<<<<<<< HEAD
//returns an integer based on id and array size 
int hashFun(int id, int arraySize)
{
  return (id)%arraySize;
=======
int hashFun(int id, int arraySize)
{
  return (id)%arraySize;
  
>>>>>>> origin/main
}

//adds a student to a hash table
bool add(Student* s, node* table[], int arraySize)
{
  int index = hashFun(s->id, arraySize);
<<<<<<< HEAD

  //create new node
=======
>>>>>>> origin/main
  node* n = new node();
  n->s = s;
  n->next = NULL;

  int count = 1; //count how many collisions

  //if nothing in array at index, insert node
  if(table[index] == NULL)
  { 
    table[index] = n;
  }
  //else add node to end of linked list
  else
  {

    //goes to end of linked list
    node* current = table[index];
    while(current->next != NULL)
      {
        current = current->next;
        count++;
      }
    //adds the new node to the next of the last node
    current->next = n;
  }

  if(count > 3)
  {
    return true; //must rehash
  }
  return false; //no need for rehash
}

//print hash table
void print(node* table[], int arraySize)
{
  for(int i = 0; i < arraySize; i++)
    {
      if(table[i] != NULL)
      {
        //print first node, prob can just use the while loop only but im too lazy to change
        cout << "Position in array: " << i << ": " << table[i]->s->first  << " " << table[i]->s->last << ", ID: " << table[i]->s->id << ", GPA: " << setprecision(2) << table[i]->s->gpa << endl;

        //print rest of nodes
        node* current = table[i]->next;
        while(current != NULL)
        {
          cout << "Position in array: " << i << ": " << current->s->first << " " << current->s->last << ", ID: " << current->s->id << ", GPA: " << setprecision(2) << current->s->gpa << endl;
          current = current->next;
        }
      }
    }
}

<<<<<<< HEAD
//deletes all students with specified id
void del(node* table[], int arraySize, int id)
{
  int index = hashFun(id, arraySize); //finds where the student will be
  deleteNode(table[index], table[index], table[index], id);
}


void deleteNode(node* &head, node* previous, node* current, int id)
{
  if(head == NULL){
    //do nothing
=======
void del(node* table[], int arraySize, int id)
{
  int index = hashFun(id, arraySize);
  deleteNode(table[index], table[index], table[index], id);
      
}

void deleteNode(node* &head, node* previous, node* current, int id)
{
  if(head == NULL){
    
>>>>>>> origin/main
  }
  else if(head->s->id == id)
  {
    node* temp = head;
<<<<<<< HEAD
    head = head->next; //move head to next
    delete temp; //delete old head
=======
    head = head->next;
    delete temp;
>>>>>>> origin/main
    deleteNode(head, head, head, id);
  }
  else if(current == NULL)
  {
<<<<<<< HEAD
    //do nothing
  }
  else if(current->s->id == id)
  {
    previous->next = current->next; //previous connects to what is after current
=======

  }
  else if(current->s->id == id)
  {
    previous->next = current->next;
>>>>>>> origin/main
    delete current;
    deleteNode(head, previous, previous->next, id);
  }
  else if(current->s->id != id)
  {
<<<<<<< HEAD
    deleteNode(head, current, current->next, id); //go next
  }
}

//copies from old table into new table using a hash function with the new size
bool copy(node* newTable[], node* oldTable[], int newSize)
{
  bool rehash = false;
  int collisionsGreaterThan3 = 0; //counts how many times there are more than 3 collisions
=======
    deleteNode(head, current, current->next, id);
  }
}

bool copy(node* newTable[], node* oldTable[], int newSize)
{
  bool rehash = false;
  int collisionsGreaterThan3 = 0;
>>>>>>> origin/main
  for(int i = 0; i < newSize/2; i++)
    {
      if(oldTable[i] != NULL)
      {
<<<<<<< HEAD
        // adds from old table
=======
>>>>>>> origin/main
        rehash = add(oldTable[i]->s, newTable, newSize);
        if (rehash == true)
        {
          collisionsGreaterThan3++;
        }
<<<<<<< HEAD

        //adds the rest of nodes
=======
        
>>>>>>> origin/main
        node* current = oldTable[i]->next;
        while(current != NULL)
        {
          rehash = add(current->s, newTable, newSize);
          if (rehash == true)
          {
            collisionsGreaterThan3++;
          }
          current = current->next;
        }
      }
      
    }
  if(collisionsGreaterThan3 > 0)
  {
    return true;
  }
  return false;
}