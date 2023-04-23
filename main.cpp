#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

// Using the standard namespace to make things easier.
using namespace std;

// My function for comparing the ranks of crew members on the Enterprise
bool compareCrewRanks(const unique_ptr<string>& a, const unique_ptr<string>& b) {
    return *a < *b;
}

// My function that demonstrates use of smart pointers
void pointersTest() {
    // unique pointers
    auto captain = make_unique<string>("Captain Jean-Luc Picard");
    auto numberOne = make_unique<string>("Commander Will Riker");
    auto chiefEngineer = make_unique<string>("Lt. Commander Geordi La Forge");

    // This will output values of my unique_ptrs
    cout << "Captain: " << *captain << endl;
    cout << "First Officer: " << *numberOne << endl;
    cout << "Chief Engineer: " << *chiefEngineer << endl;
}

// My function for a search and sort with smart pointers test from the book
void searchingAndSortingTest() {
    // This will create the vector
    vector<unique_ptr<string>> crewMembers;

    // This will add elements from push_back() and make_unique()
    crewMembers.push_back(make_unique<string>("Counselor Deanna Troi"));
    crewMembers.push_back(make_unique<string>("Dr. Beverly Crusher"));
    crewMembers.push_back(make_unique<string>("Ensign 'Shut-up' Wesley Crusher"));

    // Sort the vector using the compareRanks() function i made
    sort(crewMembers.begin(), crewMembers.end(), compareCrewRanks);

    // Outputs the sorted vector
    cout << "All crew members sorted by their rank (Highest to Lowest): " << endl;
    for (const auto& member : crewMembers) {
        cout << *member << endl;
    }
}

// a function that demonstrates string stream processing
void stringStreamProcessingTest() {
    // initialize the string and istringstream object - quote is from Picard from TNG
    string input = "It is possible to commit no mistakes and still lose. That is not weakness, that is life.";
    istringstream iss(input);

    // create a vector of strings and store the words
    vector<string> words;

    // now extract words from the input string and send to a vector using push_back()
    string word;
    while (iss >> word) {
        words.push_back(word);
    }

    // display the words
    cout << "Words that were extracted from my input: " << endl;
    for (const auto& word : words) {
        cout << word << endl;
    }
}

int main() {
    // Prints welcome message to the screen, used https://patorjk.com/ ASCII Art Generator
    cout << R"(
 __          __       _      ____    _____           _           _   
 \ \        / /      | |    |___ \  |  __ \         (_)         | |  
  \ \  /\  / /__  ___| | __   __) | | |__) | __ ___  _  ___  ___| |_ 
   \ \/  \/ / _ \/ _ \ |/ /  |__ <  |  ___/ '__/ _ \| |/ _ \/ __| __|
    \  /\  /  __/  __/   <   ___) | | |   | | | (_) | |  __/ (__| |_ 
     \/  \/ \___|\___|_|\_\ |____/  |_|   |_|  \___/| |\___|\___|\__|
                                                   _/ |              
                                                  |__/               
)" << endl;
    cout << "Smart Pointers Test Program. Sorry, for the Star Trek TNG theme. :D" << endl;

    system("pause"); // pause until user presses a key to continue

    pointersTest();
    cout << " " << endl; // making blank line
    system("pause"); // pause until user presses a key to continue
    searchingAndSortingTest();
    cout << " " << endl; // making blank line
    system("pause"); // pause until user presses a key to continue
    stringStreamProcessingTest();
    cout << " " << endl; // making blank line
    system("pause"); // pause until user presses a key to continue

    // Output completion message
    cout << "Week 3 Pointer Test is now Complete." << endl;

    return 0;
}