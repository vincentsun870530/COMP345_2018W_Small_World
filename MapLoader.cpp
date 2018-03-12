#include "MapLoader.h"
#include <iostream>
#include <string>


MapLoader::~MapLoader()
{
}

Map* MapLoader::loadMap(bool interactive = false)
{
		Map* map = new Map();

		if (interactive) {
			string tempString;
			bool set = true;

			while (set) {
				try
				{
					cout << "Please input the name of your map: " << endl;
					cin >> tempString;

					const char *constTempChar = &(tempString.at(3));
					if (atoi(constTempChar) != numOfPlayers) throw runtime_error("The number of players does not match the input map! and ");

					std::ifstream ifs(tempString);
					boost::archive::text_iarchive ia(ifs);
					ia >> *map;
					ifs.close();
					set = false;

					
				}
				catch (const boost::archive::archive_exception&)
				{
					cout << "Your file includes error information or the file you input does not exit, please try another file: " << endl;
					set = true;
					
				}
				catch (std::exception err)
				{
					cout << err.what() << endl;
					cout << "Your file includes error information or the file you input does not exit, please try another file: " << endl;
					set = true;
					
				}
			}
			return map;
		}

		if (numOfPlayers == 2) {
		std::ifstream ifs("Map2.txt");
		boost::archive::text_iarchive ia(ifs);
		ia >> *map;
		ifs.close();
		return map;
		
	}
	else if (numOfPlayers == 3) {
		Map* map = new Map();
		std::ifstream ifs("Map3.txt");
		boost::archive::text_iarchive ia(ifs);
		ia >> *map;
		ifs.close();
		return map;
	}
	else if (numOfPlayers == 4) {
		Map* map = new Map();
		std::ifstream ifs("Map4.txt");
		boost::archive::text_iarchive ia(ifs);
		ia >> *map;
		ifs.close();
		return map;
	}
	else {
		Map* map = new Map();
		std::ifstream ifs("Map5.txt");
		boost::archive::text_iarchive ia(ifs);
		ia >> *map;
		ifs.close();
		return map;
	}
};