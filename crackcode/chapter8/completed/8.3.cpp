/*8.3 Design a musical jukebox using object-oriented principles.*/
#include <iostream>

class singer {
private:
	vector<music> music;
	string name;
	bool ismale;
	int age;
	int popular;
public:
	bool get_male() { return ismale; }
	int get_age() { return age; }	
	string get_name() { return name; }	
	int get_popular() { return popular; }
};

class music {
private:
	string name;
	int type;
	vector<singer> singers;
public:
	string get_name() { return name; }
	int get_type(void) { return type; }
	vector<singers> get_singers(void) { return singers; }
};

bool music_compare(music ma, music mb) {
	return ma.get_name() < mb.get_name();
}

bool singlers_compare(singer sa, singer sb) {
	return sa.get_name() < sb.get_name();	
}

bool popular_compare(music ma, music mb) {
	return ma.get_popular() < mb.get_popular();
}

class jukebox {
private:
	vector<music> music;
	vector<singer> singers;
public:
	/* play a music */	
	void play(music m) {
	}
	
	/* list all music */
	void list_all_music(void) {
		sort(music.begin(), music.end(), music_compare);
		for (int i = 0; i < music.size(); i++) 
			std::cout << music[i].get_name() << std::endl;
	}	

	/* list by singers */
	list_by_singers(void) {
		sort(singers.begin(), singers.end(), singers_compare);
		for (int i = 0; i < singers.size(); i++) {
			std::cout << singers[i].get_name() << std::endl;
			for (int j = 0; j < singers[i].music.size(); j++)
				std::cout << singers[i].music[j].get_name() << std::endl;
		}
	}

	/* list by popularity */
	vector<music> list_by_popularity(void) {
		sort(music.begin(), music.end(), popular_compare);
                for (int i = 0; i < music.size(); i++)
                        std::cout << music[i].get_name() << std::endl;	
	}
};
