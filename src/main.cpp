//***************************************************************************
// File name:   main.cpp
// Author:      
// Date:        
// Class:       
// Assignment:  
// Purpose:     
//***************************************************************************

#include <iostream>
#include <vector> 
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>  

typedef struct TeamDef { 
	size_t mCount;
	std::vector<std::string> mLabels;
} TeamDef;

typedef struct Person {
	std::string mFname;
	std::string mLname;
} Person;


//***************************************************************************
// Function:    sortFName
//
// Description: determine if LHS first name  < RHS first name
//
// Parameters:  sLHS - Left hand side Person 
//							sRHS - Right hand side Person
//										
// Returned:    LHS < RHS
//***************************************************************************
bool sortFName (Person sLHS, Person sRHS) {
	return ( sLHS.mFname < sRHS.mFname); 
}

//***************************************************************************
// Function:    sortFNameRef
//
// Description: determine if ! (LHS first name  < RHS first name)
//
// Parameters:  sLHS - Left hand side Person 
//							sRHS - Right hand side Person
//										
// Returned:    !(LHS < RHS)
//***************************************************************************
bool sortFNameRev(Person sLHS, Person sRHS) {
	return !(sortFName(sLHS, sRHS));
}


//***************************************************************************
// Function:    main
//
// Description: Driver to build teams!
//
// Parameters:  argc - count of command line args
//							argv - command line args!
//											teamDef people randomnes output
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main(int argc, char *argv[])
{
	std::string cTeamDefFilename;
	std::string cPeopleFilename;
	std::string cRandom;
	std::string cOutFilename;
	std::vector <Person> cPeople;
	
	std::ifstream cPeopleFile;
	std::ifstream cTeamDefFile;
	std::ofstream cOutFile;
	std::string cLine;
	TeamDef sTeamDef;
	Person sPerson;

	if (argc != 5) {
		std::cerr << "\nUSAGE: " << argv[0] << " teamDef people randomnes output\n\n";
		return EXIT_FAILURE;
	}

	cTeamDefFilename = argv[1];
	cPeopleFilename = argv[2];
	cRandom = argv[3];
	cOutFilename = argv[4];
	


	cTeamDefFile.open (cTeamDefFilename);

	if (cTeamDefFilename.ends_with(".csv")) {
		while ( getline(cTeamDefFile, cLine) )
		{
			std::stringstream cStrStream (cLine);
			std::string cTmp;

			// get int
			getline(cStrStream, cTmp, ',');
			sTeamDef.mCount = std::stoi(cTmp);
			while (getline(cStrStream, cTmp, ',')) {
				sTeamDef.mLabels.push_back(cTmp);
			}

		}
	} else {
		// .txt
		// get int
		getline(cTeamDefFile, cLine);
		sTeamDef.mCount = std::stoi(cLine);

		while ( getline(cTeamDefFile, cLine) )
		{
			sTeamDef.mLabels.push_back(cLine);
		}
	}

	cPeopleFile.open (cPeopleFilename);

	if (cPeopleFilename.ends_with(".csv")) {
		while ( getline(cPeopleFile, cLine) )
		{
			std::stringstream cStrStream (cLine);
			std::string cTmp;

			while (getline(cStrStream, cTmp, ',')) {
				sPerson.mFname = cTmp;
				getline(cStrStream, cTmp, ',');
				sPerson.mLname = cTmp;
				cPeople.push_back(sPerson);
			}
		}
	} else {
		// .txt
		while ( getline(cPeopleFile, cLine) )
		{
			sPerson.mFname = cLine;
			getline(cPeopleFile, cLine);
			sPerson.mLname = cLine;
			cPeople.push_back(sPerson);
		}
	}


	std::cout << sTeamDef.mCount << std::endl; 
	for (auto data : sTeamDef.mLabels) {
		std::cout << data << std::endl;
	}

	std::sort (cPeople.begin(), cPeople.end(), sortFName);
	std::cout << "--------------------\n";
	for (auto data : cPeople) {
		std::cout << data.mFname << " " << data.mLname << std::endl;
	}

	std::sort (cPeople.begin(), cPeople.end(), sortFNameRev);
	std::cout << "--------------------\n";

	for (auto data : cPeople) {
		std::cout << data.mFname << " " << data.mLname << std::endl;
	}

	cPeopleFile.close();
	cTeamDefFile.close();

	std::sort (cPeople.begin(), cPeople.end(), sortFName);

  return EXIT_SUCCESS;
}
