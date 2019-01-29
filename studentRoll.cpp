#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {//the parameter is a pointer to a Student object; 
	Node* n = new Node;

	n->s = new Student(s);//
        n->next = NULL; //**

	if (head == NULL){
		head = n;
		tail = n; 
	}

	else{   //do not write:  if(tail != NULL), because tail exists and this does nothing; 
		tail->next = n;
		//n->next=NULL;
		tail = n; 
        }
	 
	
}

std::string StudentRoll::toString() const {
	std::string str = "[";

	for (Node* p = head; p != NULL; p = p->next) {
		str += p->s->toString();
	//	if (p != tail)
		if(p->next != NULL)
			str += ",";
	}

	str += "]";
	return str;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
    head = tail = NULL;

    for (Node* n = orig.head; n != NULL; n = n->next)
        insertAtTail(*(n->s));
          
}

StudentRoll::~StudentRoll() {
	Node *cur = head;
	Node *next;
	while(cur){
	  next = cur->next;
          delete cur->s; 
	  delete cur;
	  cur = next; 
	}
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
 // this-> ~StudentRoll(); 
 // new(this) StudentRoll(right);
  Node* curr = head;
  Node* next = NULL;
  while(curr){
      next = curr->next;
      delete curr->s;
      delete curr; 
      curr= next; 
  }
  
  head = tail = NULL; 
  for(Node* n = right.head; n != nullptr; n = n->next){
	insertAtTail(*(n->s)); 
  }

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}






