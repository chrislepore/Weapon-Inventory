#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

///structs
typedef struct weapon{
    string name;
    string type;
    int power_level;
    int durability;
    int level;
}W;


///prototypes
//fills selected slot with what you input
void inputFunction(vector<W> &object, int n);

//prints out information from selected slot
void printinventory(vector<W> &object, int n);

//searches for slot
void searhFunction(vector<W> &object, string checker);


///global variable for inputs
int n = 0;

int main()
{
    //declares inventory as vector and a string operationChecker to check what operation to do
    vector <W> arsenal (1);
    string operationChecker = "";

    do{
    cout << "----------------Menu----------------------" <<endl;
    cout << "To input another weapon, type -- input" <<endl;
    cout << "To search existing weapon, type -- search" <<endl;
    cout << "To stop, type -- stop" <<endl;
    cout << "------------------------------------------" <<endl;

    //asks user what operation to do and makes it lower case
    cout << "what do you wish to do?? --  ";
    cin >> operationChecker;
    for(int i=0;i<operationChecker.length();i++)
    {
        operationChecker[i]=tolower(operationChecker[i]);
    }

    //checks if input was entered as operation and fills the next inventory slot
    if(operationChecker == "input")
    {
        inputFunction(arsenal, n);
        arsenal.emplace_back();
        n++;
    }

    //checks if search was entered and if it was it preforms the search function
    searhFunction(arsenal, operationChecker);

    //if the operation entered is stop the program with break out of loop
    if(operationChecker == "stop")
    {
        break;
    }

    }while(true);

    return 0;
}

void inputFunction(vector<W> &object, int n){
    //asks for name and makes sure the string name is filled then makes it all lowercase
    cout << "name --";
    cin.ignore();
    getline(cin, object[n].name);
    for (int i=0;i<object[n].name.length();i++)
    {
         object[n].name[i]=tolower(object[n].name[i]);
    }

    //asks for type and makes sure the string type is filled then makes it all lowercase
    cout << "type --";
    getline(cin, object[n].type);
    for (int i=0;i<object[n].type.length();i++)
    {
         object[n].type[i]=tolower(object[n].type[i]);
    }

    //asks for the power level and makes sure it's a number
    cout << "power level --";
    while(!(cin >> object[n].power_level))
    {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
    }

    //asks for the durability and makes sure it's a number
    cout << "durability --";
    while(!(cin >> object[n].durability))
    {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
    }

    //asks for the level and makes sure it's a number
    cout << "level --";
    while(!(cin >> object[n].level))
    {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
    }
}

void printinventory(vector <W> &object, int n){
    //prints out all the structs of a selected slot of the vector arsenal
    cout << " --------------------------- " <<endl;
    cout << "slot "<<n + 1<<" is filled with" <<endl;
    cout << "name: " <<object[n].name << endl;
    cout << "type: " <<object[n].type << endl;
    cout << "power level: " <<object[n].power_level << endl;
    cout << "durability: " <<object[n].durability << "%"<< endl;
    cout << "level: " <<object[n].level << endl;
    cout << " --------------------------- " <<endl;
}

void searhFunction(vector<W> &object, string checker)
{
    //declares all variables for searchFunction
    string search_it;
    string category;
    int t = 0;
    int r;
    int low;
    int high;

    //checks if search was entered as a operation and that at least 1 item has been entered before hand
    if(checker == "search")
    {
        if(object.size() > 1)
        {
            //asks for what search category to search and makes it lowercase. if the input does not equal any of the categories then
            //"-----sorry not a category-------" is outputted
            cout << "pick a category to search by --- name, type, power level, durability, level: "<<endl;
            cin.ignore();
            getline(cin, search_it);
            for(int i=0;i<search_it.length();i++)
            {
                search_it[i]=tolower(search_it[i]);
            }

            //if name is entered it will ask for the name and search through the vector to find a name that matches.
            //if name/names is found it will print it out with print inventory, if none are found then "sorry no result" is outputted
            if(search_it == "name")
            {
                cout << "what name: ";
                getline(cin, category);
                for(int i=0;i<category.length();i++)
                {
                    category[i]=tolower(category[i]);
                }
                for(int i = 0; i < object.size(); i++)
                {
                    if(object[i].name == category)
                    {
                        printinventory(object, i);
                        t++;
                    }
                }
                if(t == 0){
                    cout << "-------sorry no result-------" <<endl;
                }

            //if type is entered it will ask for the type and search through the vector to find a type that matches.
            //if type/types is found it will print it out with print inventory, if none are found then "sorry no result" is outputted
            }else if(search_it == "type")
            {
                cout << "what type: ";
                getline(cin, category);
                for(int i=0;i<category.length();i++)
                {
                    category[i]=tolower(category[i]);
                }
                for(int i = 0; i < object.size(); i++)
                {
                    if(object[i].type == category)
                    {
                        printinventory(object, i);
                        t++;
                    }
                }
                if(t == 0)
                {
                    cout << "-------sorry no result-------" <<endl;
                }

            //if power level is entered it will ask for and low number and a high number and then searches through the vector to find a power level
            //that fits between the low and high value and is outputted. if none are found "sorry no result" is outputted
            }else if(search_it == "power level")
            {
                cout << "low power level: ";
                while(!(cin >> low))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input.  Try again: ";
                }
                cout << "high power level: ";
                while(!(cin >> high))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input.  Try again: ";
                }
                for(int i = 0; i < object.size()-1; i++)
                {
                    if(object[i].power_level >= low && object[i].power_level <= high)
                    {
                        printinventory(object, i);
                        t++;
                    }
                }
                if(t == 0)
                {
                    cout << "-------sorry no result-------" <<endl;
                }

            //if durability is entered it will ask for and low number and a high number and then searches through the vector to find a durability
            //that fits between the low and high value and is outputted. if none are found "sorry no result" is outputted
            }else if(search_it == "durability")
            {
                cout << "low durability: ";
                while(!(cin >> low))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input.  Try again: ";
                }
                cout << "high durability: ";
                while(!(cin >> high))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input.  Try again: ";
                }
                for(int i = 0; i < object.size()-1; i++)
                {
                    if(object[i].durability >= low && object[i].durability <= high)
                    {
                        printinventory(object, i);
                        t++;
                    }
                }
                if(t == 0)
                {
                    cout << "-------sorry no result-------" <<endl;
                }

            //if level is entered it will ask for the number of level and search through the vector to find a level that matches.
            //if level/levels is found it will print it out with print inventory, if none are found then "sorry no result" is outputted
            }else if(search_it == "level")
            {
                cout << "level: ";
                while(!(cin >> r))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input.  Try again: ";
                }
                for(int i = 0; i < object.size(); i++)
                {
                    if(object[i].level == r)
                    {
                        printinventory(object, i);
                        t++;
                    }
                }
                if(t == 0)
                {
                    cout << "-------sorry no result-------" <<endl;
                }

            }else
            {
                cout << "-----sorry not a category-------" <<endl;
            }
        }else
        {
            cout << "------ sorry nothing has been inputed to search -------" <<endl;
        }
    }
}

