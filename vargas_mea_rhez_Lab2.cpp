#include <iostream>
#include <string>

using namespace std;

typedef struct Node {
  string songName;
  Node *link;
} Node;


Node *createNode(string data) {
  Node *newNode = new Node;
  newNode->songName = data; 
  newNode->link = NULL;     

  return newNode;
}


void traverse(Node *head) {
  Node *temp = new Node; 
  temp = head;           

  cout << "My Playlist" << endl;
  while (temp != NULL) { 
    cout << temp->songName << "->" << endl; 
    if (temp->link == NULL) {            
      cout << "NULL" << endl; 
    }

    temp = temp->link;
  }
}


Node *insertAtEnd(string data, Node *head) {
  if (head == NULL) { 
    Node *newNode = createNode(data); 
    head = newNode;                   
    cout << "A new node has been inserted at the end" << endl;
    
    return head;
  }

  Node *temp = new Node; 
  temp = head;            

  while (temp->link != NULL) { 
    temp = temp->link;
  }

  Node *newNode = createNode(data); 
  temp->link = newNode;       
                        

  cout << "A new node has been inserted at the end" << endl;
  return head;
}


Node *insertAtBeginning(string data, Node *head) {
  Node *newNode = createNode(data); 
  newNode->link = head;             
  head = newNode;                 
  cout << "A new node has been inserted at the beginning" << endl;
                                        
  return head;
}
string insertAfter(string after, string data, Node *head) {
  Node *temp = new Node; 
  temp = head;           

  while (temp->songName.compare(after) != 0) {
    if (temp == NULL) {                   
                            
                                            
      return "No such song exist, please try again later.";
    }

    temp = temp->link;
  }

  Node *newNode = createNode(data); 
  newNode->link = temp->link;      
                
  temp->link = newNode;         
    return "An new node has been added after " + after + "\n"; 
                                                        
  }
                                    


Node* deleteAtEnd(Node *head) {
  if (head == NULL) { 
    cout << "The linkedlist is empty\n";
    return head;
  }

  if (head->link == NULL) {
    cout << "The head has been deleted\n";
    return NULL;
    return NULL;
  }

  Node *temp = new Node;

  while (temp->link->link != NULL) { 
                                    
    temp = temp->link;
  }

  cout << "A node has been deleted at the end \n";
  return head;

  temp->link = NULL;
  return head;
}


Node *deleteFromBeginning(Node *head) {
  if (head == NULL) {
    cout << "The linked list is empty \n" << endl;
    return NULL;
  }

  if (head->link == NULL) {
    delete head;
  }

  head = head->link;

  cout << "A node has been delete from the beginning \n" << endl;

  return head;
}


Node *deleteFromGivenNode(string givenNode, Node *head) {
  if (head == NULL) { 
    cout << "The linked list is empty.\n" << endl;
    return NULL;
  }

  if (head->songName.compare(givenNode) == 0) {  
                    
    head = deleteFromBeginning(head);
    cout << "The Node " + givenNode + " has been deleted.\n" << endl;
    return head;
  }

  Node *temp = new Node;
  Node *next = new Node; 
        
  temp = head;          
  next = temp->link;      
                        

  while (next->songName.compare(givenNode) != 0) {
                                
    if (temp == NULL) { 
                        
      cout << "No such node exist.\n" << endl;
      return head;
    }

    temp = temp->link;
    next = next->link;
  }

  temp->link = next->link;
  cout << "The Node " + givenNode + " has been deleted.\n" << endl;
  return head;
}

int main() {
  Node *head = createNode("Sanctuary by Joji");


  head = insertAtEnd("Sunday Morning by Maroon 5", head);
  head = insertAtEnd("Blinding Lights by The Weeknd", head);
  head = insertAtEnd("Shape of You by Ed Sheeran", head);

  
  head = insertAtBeginning("Bad Habits by Ed Sheeran", head);
  head = insertAtBeginning("Levitating by Dua Lipa", head);
  head = insertAtBeginning("Peaches by Justin Bieber", head);
  head = insertAtBeginning("Stay by The Kid LAROI", head);

  insertAfter("Stay by The Kid LAROI", "Tala by  Mowdaw", head);
  insertAfter("Stay by The Kid LAROI", "Buwan by  Juan Karlos", head);
  insertAfter("Stay by The Kid LAROI", "Pare Ko by  KZ Tandingan", head);

  
  traverse(head);

  head = deleteAtEnd(head);
  head = deleteFromBeginning(head);
  head = deleteFromGivenNode("Shape of You by Ed Sheeran", head);
  traverse(head);

  return 0;
}

 



