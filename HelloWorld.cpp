#include <iostream>
using namespace std;

int main(int argc, const char* argv[])
{
    auto msg = "Hello from master ---";
    cout << msg << endl;

    if (argc > 1) 
    {
        cout << " --- With param: " << argv[1] << endl;
    }

	return 0;
}
