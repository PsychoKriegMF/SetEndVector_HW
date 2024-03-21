#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
//#include <cctype>

int main() {
	setlocale(LC_ALL, "ru");
	std::set<std::string> dictionary_set;
	std::vector<std::string> dictionary_vec;
	double start_time;
	double stop_time;
	
	std::cout << "Сначала результат работы через set.\n";

	start_time = clock();
	std::ifstream file("Harry.txt");
	if (!file.is_open())
	{
		std::cerr << "Error\n";
		return -1;
	}
	
	std::string word;
	while (file >> word)
	{
		for (char& c : word)
		{
			c = std::tolower(c);
		}
		word.erase(std::remove_if(word.begin(),
									word.end(),
									[](char c) {return std::ispunct(c); }),
									word.end());
		dictionary_set.insert(word);		
	}

	file.close();
	stop_time = clock();
	std::cout << "Кол-во уникальных слов: " << dictionary_set.size() << std::endl;
	std::cout << "Времени затрачено: " << (stop_time - start_time) / 1000 << " sec" << std::endl;
	
	std::cout << "\nТеперь результат работы через vector.\n";

	start_time = clock(); 
	std::ifstream file2("Harry.txt"); 
	if (!file2.is_open())
	{
		std::cerr << "Error\n";
		return -1;
	}
	while (file2 >> word)
	{
		std::transform(word.begin(),
			           word.end(),
			           word.begin(),
			           [](unsigned char c) {return std::tolower(c); });
		word.erase(std::remove_if(word.begin(),
								  word.end(),
								  [](unsigned char c) {return std::ispunct(c); }),
								  word.end());
		if (std::find(dictionary_vec.begin(), dictionary_vec.end(), word) == dictionary_vec.end())
		{
			dictionary_vec.push_back(word);
		}			
	}
	file2.close();
	stop_time = clock();
	std::cout << "Кол-во уникальных слов: " << dictionary_vec.size() << std::endl;
	std::cout << "Времени затрачено: " << (stop_time - start_time) / 1000 << " sec" << std::endl;



	return 0;
}