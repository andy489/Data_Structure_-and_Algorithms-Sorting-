#include<iostream>
#include<map>
using namespace std;

int main() 
{
    map<int, string> numberNames { {2, "two"} };

    for (int i = 0; i < numberNames.size(); i++) 
	{
        cout << numberNames[i] << ",";
    }

    return 0;
}

// a) zero, onem two,
// b) ,,two,
// c) two,
// d) There will be a runtime error
