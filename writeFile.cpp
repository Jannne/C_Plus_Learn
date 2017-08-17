#include <fstream>
using namespace std;
int main()
{
	ofstream of("result.txt", ofstream::out | ofstream::app);

	if (of) {
		of << "This is writed by c++" << endl;

		if(of.is_open()) {
			of.close();
		}
	}	
	return 0;
}
