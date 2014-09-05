/*
8.2 Imagine you have a call center with three levels of employees: respondent,
   manager, and director. An incoming telephone call must be first allocated to a
  respondent who is free. If the respondent can't handle the call, he or she must
 escalate the call to a manager. If the manager is not free or not able to handle it,
then the call should be escalated to a director. Design the classes and data struc-
tures for this problem. Implement a method dispatchCall() which assigns a
call to the first available employee.
*/

#include <iostream>

class call {
private:
	int emergency_level;
public:
	int get_level() { return emergency_level; }
	void set_level(int level) { emergency_level = level; }
};

class employee {
protected:
	bool free;
public:
	bool isfree() { return free; }
	void setfree(bool status) { free = status; }
	virtual bool can_handle(call &c) = 0;	
};

class respondent: public employee {
public:
	bool can_handle(call &c) {
		if (c.get_level() <= 0)
			return true;
		return false;
	}	
};

class manager: public employee {
public:
	bool can_handle(call &c) {
		if (c.get_level() <= 1)
			return true;
		return false;
	}
};

class director: public employee {
public:
	bool can_handle(call &c) {
		if (c.get_level() <= 2)
			return true;
		std::cout << "error in level" << endl;
		return false;
	}
};

employee* dispatchCall(call &c, vector<respondent*> respondents, vector<manager*> managers, vector<director*> directors) {
	for (int i = 0; i < respondents.size(); i++) {
		if (respondents[i]->get_status()) {
			if (respondents[i]->can_handle(c))
				return respondents[i];
			for (int j=0; j<managers.size(); j++) {
				if (managers[j]->get_status()) {
					if (managers[j]->can_handle())
						return manager[j];
					for (int k = 0; k<directors.size(); k++) {
						if (directors[i]->get_status())
							return directors[k];
					}
				}
			}
		}
	}
}
