#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {//the parameter is a pointer to a Student object; 
	auto n = new Node;

	n->s = new Student(s);
        n->next = NULL; //**

	if (head == nullptr){
		head = n;
		tail = n; 
	}

	if (tail != nullptr){
		tail->next = n;
		tail = n; 
        }
	
}

std::string StudentRoll::toString() const {
	std::string str = "[";

	for (auto p = head; p != nullptr; p = p->next) {
		str += p->s->toString();
		if (p != tail)
			str += ",";
	}

	str += "]";
	return str;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
    head = tail = nullptr;

    for (auto n = orig.head; n != nullptr; n = n->next) //I copied this from online
        insertAtTail(*(n->s));
          
}

StudentRoll::~StudentRoll() {
	Node *cur = head;
	Node *next;
	while(cur){
	  next = cur->next;
	  delete(cur);
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
  this-> ~StudentRoll(); 
  new(this) StudentRoll(right);
  

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}






