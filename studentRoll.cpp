#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {//the parameter is a pointer to a Student object; 
	auto n = new Node;

	n->s = new Student(s);

	if (head == nullptr)
		head = n;

	if (tail != nullptr)
		tail->next = n;

	tail = n;
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
	for (auto current = head; current != nullptr;) {
		const auto next = current->next;
		delete current;
		current = next;
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
  this-> ~StudentRoll(); // release old resources 
  new(this) StudentRoll(right); // storage reuse -- copy from rhs  
  
  


  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}






