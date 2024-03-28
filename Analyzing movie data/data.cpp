#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::string lower(std::string str) {
	for (int i = 0; i < str.size(); i++)
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	return str;
}

class Film {
public:
	Film() {}
	Film(std::map<std::string, std::string> _actors, std::string _name) : name(_name) {
		actors = _actors;
	}
	Film(std::string _name) : name(_name) {};
	Film(Film& other) {
		actors = other.actors;
		name = other.name;
	}
	Film& operator=(Film& other) {
		actors = other.actors;
		name = other.name;
		return *this;
	}
	void add(std::string actor, std::string role) {
		actors.insert(std::make_pair(actor, role));
	}
	std::string getName() {
		return name;
	}
	std::map<std::string, std::string> getActors() {
		return actors;
	}
private:
	std::map<std::string, std::string> actors;
	std::string name;
};

int main() {
	std::ifstream file("portal.json");
	//nlohmann::json dict;
	json dict = json::parse(file);
	//file >> dict;
	std::cout << "Input the actor's name or family:" << std::endl;
	std::string str;
	std::cin >> str;
	Film filmFound;

	for (auto portal : dict) {
		for (auto& films : portal.items()) {
			for (auto filmdata : films.value()) {
				if (filmdata.is_object()) {
					for (auto it = filmdata.begin(); it != filmdata.end(); ++it) {
						std::string strKey = it.key();
						if (strKey.find(str) != std::string::npos)
							filmFound = Film({ {strKey, it.value()} }, films.key());
					}
				}
				auto findActor = filmdata.find(str);
				if (findActor != filmdata.end())
					std::cout << "Found: " << *findActor << "\n\n";
			}
		}
	}
	std::cout << "Film name: " << filmFound.getName() << '\n';
	std::cout << "Actors:\n";
	for (const auto& actor : filmFound.getActors())
		std::cout << actor.first << " : " << actor.second << ";\n";
	system("pause");
	return 0;
}
