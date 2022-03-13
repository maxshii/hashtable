/*
 *
 *
 *
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
  fstream first;
  first.open("first.txt");
  char firstArr[50][30];
  char name[80];
  for(int i = 0; i < 50; i++)
    {
      first.getline(name, 30, '\n');
      strcpy(firstArr[i], name);
    }

  fstream last;
  last.open("last.txt");
  char lastArr[100][30];
  for(int i = 0; i < 100; i++)
    {
      last.getline(name, 30, '\n');
      strcpy(lastArr[i], name);
    }
  
  
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
      arraySize = arraySize * 2;
      node* *temp = new node*[arraySize];
      copy(temp, tablePtr, arraySize);
      delete tablePtr;
      tablePtr = temp;    
    }
    else if (strcmp(input, "QUIT") == 0)
    {
        break;   
    }
  }
  return 0;
}

bool random(node* table[], int arraySize, char firstNames[][30], char lastNames[][30], int &id)
{
  bool rehash = false;
  int number = 0;
  cout << "Enter number of students to generate: ";
  cin >> number;
  cin.ignore(100, '\n');

  for (int i = 0; i < number; i++)
    {
      Student* s = new Student();
      strcpy(s->first, firstNames[rand() % 50]);
      strcpy(s->last, lastNames[rand() % 50]);
      s->id = ++id;
      float newGpa = (rand() % 50)/10.0;
      s->gpa = newGpa;
      rehash = add(s, table, arraySize);
    }
  return rehash;
}

int hashFun(int id, int arraySize)
{
  return (id)%arraySize;
  
}

bool add(Student* s, node* table[], int arraySize)
{
  int index = hashFun(s->id, arraySize);
  node* n = new node();
  n->s = s;
  n->next = NULL;

  int count = 1;
  if(table[index] == NULL)
  { 
    table[index] = n;
  }
  else
  {
    node* current = table[index];
    while(current->next != NULL)
      {
        current = current->next;
        count++;
      }
    current->next = n;
  }

  if(count >= 3)
  {
    return true;
  }
  return false;
}

void print(node* table[], int arraySize)
{
  for(int i = 0; i < arraySize; i++)
    {
      if(table[i] != NULL)
      {
        cout << table[i]->s->first  << " " << table[i]->s->last << ", ID: " << table[i]->s->id << ", GPA: " << setprecision(2) << table[i]->s->gpa << endl;

        node* current = table[i]->next;
        while(current != NULL)
        {
          cout << current->s->first << " " << current->s->last << ", ID: " << current->s->id << ", GPA: " << setprecision(2) << current->s->gpa << endl;
          current = current->next;
        }
      }
    }
}

void del(node* table[], int arraySize, int id)
{
  int index = hashFun(id, arraySize);
  deleteNode(table[index], table[index], table[index], id);
      
}

void deleteNode(node* &head, node* previous, node* current, int id)
{
  if(head == NULL){
    
  }
  else if(head->s->id == id)
  {
    node* temp = head;
    head = head->next;
    delete temp;
    deleteNode(head, head, head, id);
  }
  else if(current == NULL)
  {

  }
  else if(current->s->id == id)
  {
    previous->next = current->next;
    delete current;
    deleteNode(head, previous, previous->next, id);
  }
  else if(current->s->id != id)
  {
    deleteNode(head, current, current->next, id);
  }
}

bool copy(node* newTable[], node* oldTable[], int newSize)
{
  bool rehash = false;
  int collisionsGreaterThan3 = 0;
  for(int i = 0; i < newSize/2; i++)
    {
      if(oldTable[i] != NULL)
      {
        rehash = add(oldTable[i]->s, newTable, newSize);
        if (rehash == true)
        {
          collisionsGreaterThan3++;
        }
        
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