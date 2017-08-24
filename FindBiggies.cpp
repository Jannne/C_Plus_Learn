#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void elimDups(vector<string> &words);
void biggies(vector<string> &words, vector<string>::size_type sz);

int main()
{
	vector<string> vec{ "I", "have", "a", "job", "that", "is", "in", "abc", "in", "shanghai", "i", "am", "glad", "here" };
	biggies(vec, 4);
    return 0;
}

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
	auto wc = find_if(words.cbegin(), words.cend(), [sz](const string &a) { return a.size() >= sz; });
	auto count = words.end() - wc;
	cout << count << " " << "words length is bigger than " << sz << endl;

	for_each(wc, words.cend(), [](const string &a) { cout << a << " "; });

	cout << endl;
}
