#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <set>

using namespace std;

typedef vector<string>::size_type line_no; //vector<string>保存读入的文件

map<string, set<line_no>> mss;

vector<string> file;

void input_file(ifstream &in)
{
	string line;

	while(getline(in, line)) {
		file.push_back(line);
//		istringstream record(line);

	}
}

string cleanup_str(const string &str)
{
	string ret;
	for(auto it = str.begin(); it != str.end(); ++it) {
		if(!ispunct(*it))
			ret += tolower(*it);
	}
	return ret;
}

void search_word(string &word)
{
	string tmp;
	line_no i = 0;
	for( const auto &line : file) {
		istringstream record(line);
		while(record >> tmp) {
			if(cleanup_str(tmp) == word){
				mss[word].insert(i);
//				break;
			}
		}
		++i;
	}
}

ostream &print_result(string &word, ostream &out)
{
	auto loc = mss.find(word);
	if(loc == mss.end()) {
		out << word << " occurs 0 time." << endl;
	} else{
		auto line = loc->second;
		out << word << " occurs " << line.size() << " times." << endl;
		for(auto i : line)
			out << "(line: " << i + 1 << ") " << file[i] << endl;
	}
	return out;
}

int main(int argc, char *argv[])
{
	ifstream infile;
	infile.open(argv[1]);

	input_file(infile);

	string word;

	while(1) {
		cout << "input the word: ";
		cin >> word;
		search_word(word);
		print_result(word, cout) << endl;
	}

	return 0;
}
