/*
Design a parking lot using object-oriented principles.
*/

#include <iostream>

class car {
private:
	int car_id;
	int slot_id;
public:
	int get_carid() { return car_id; }
	int get_slotid() { return slot_id; }		
};

class parking_lot {
private:
	int capacity;
	int map[capacity];
	int used_slots;
public:
	int get_capacity() { return capacity; }
	void set_capacity(int cap) { capacity = cap; }
	bool is_full() { return used_slots == capacity; }
	int remain_slots { return capacity - used_slots; }
	void assign_to_car(car &c) { 
		if (is_full()) {
			std::cout << "no slot" << std::endl;
			return;
		}

		std::cout << "a new car comes" << endl;
		for (int i = 0; i<capacity; i++)
			if (0 == map[i]) map[i] = 1;
		used_slots++;
		c.slot_id = i;
	}

	void car_leave(car &c) {
		if (0 == used_slots) {
			std::cout << "no car takes place right now" << std::endl;
			return;
		}

		map[c.slot_id] = 0;
		used_slot--;
	}
};
