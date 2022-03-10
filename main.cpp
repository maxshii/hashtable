/*
 *
 *
 *
 */

#include <iostream>
#include <cstring>
#include <iomanip>

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

void random(Student* table[]);
int hashFun(Student* s, int arraySize);
void add(Student* s, node* table[], int arraySize);
void print(node* table[], int arraySize);
void del(Student* s);

int main() {

 /* while(true) {
      char input[80];
      cin.getline(input, 80, '\n');
      if (strcmp(input, "ADD")==0)
      {
      }
      else if (strcmp(input, "PRINT")==0)
      {
      }
      else if (strcmp(input, "DELETE")==0)
      {
          int id = 0;
          cout << "Enter ID: ";
          cin >> id;
      }
      else if (strcmp(input, "QUIT")==0)
      {
          break;   
      }
  }*/

  Student* a = new Student();
  strcpy(a->first, "Max");
  strcpy(a->last, "Shi");
  a->id = 1;
  a->gpa = 6.9;

  Student* b = new Student();
  strcpy(b->first, "Bob");
  strcpy(b->last, "Shi");
  b->id = 1;
  b->gpa = 6.9;

  Student* c = new Student();
  strcpy(c->first, "Zob");
  strcpy(c->last, "Shi");
  c->id = 1;
  c->gpa = 6.9;

  node* table[100] = {NULL};

  int arraySize = *(&table+1) - table;
  cout << hashFun(a, arraySize);

  add(a, table, arraySize);
  add(b, table, arraySize);
  add(c, table, arraySize);


  print(table, 100);
  
      
  return 0;
}

void random(Student* table[])
{
  
}

int hashFun(Student* s, int arraySize)
{
  return (s->id)%arraySize;
  
}

void add(Student* s, node* table[], int arraySize)
{
  int index = hashFun(s, arraySize);
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
        cout << count;
      }
    current->next = n;
  }

  if(count >= 3)
  {
    //double hashtable
  }
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