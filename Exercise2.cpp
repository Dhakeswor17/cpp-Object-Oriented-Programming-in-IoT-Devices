#include <iostream>
#include <fstream>
#include <string>
#include    <vector>
#include <ios>
#include <limits>

using namespace std;

string find_first_element(const string& xml, string tag_name);
vector<string> find_all_elements(const string& xml, string tag_name);


int main() {
	int userInput;
	string page, line, location, temperature, tag_name;
	ifstream inputFile("day-ahead-prices.xml");
	bool keep_running = true;
	vector<string>v1;

	while (getline(inputFile, line)) {
		page.append(line);
		line.erase();
	}
	// Now page is a string that contains the whole xml page

	// Here you need to write a loop that asks user to enter tag name
	// and if tag name is "stop" the program stops
	// otherwise program calls function of 2A or 2B with the tag name
	// and prints the result

	do
	{,m lk
		cout << "Do you want to find the first element[1] or find all elements[2]?: ";
		cin >> userInput;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');		// clear input buffer

		cout << "Enter tag name:";
		getline(cin, tag_name);

		if (tag_name == "stop")
		{
			keep_running = false;
		}
		else if (userInput == 1)
		{
			cout << tag_name + ": " << find_first_element(page, tag_name) << endl;
		}
		else if (userInput == 2)
		{
			v1 = find_all_elements(page, tag_name);

			// printing all the strings stored in the vector
			for (int i = 0; i < v1.size(); i++)
			{
				cout << v1[i] << endl;
			}

			if (v1.size() == 0)
			{
				cout << "Tag not found" << endl;
			}

			cout << "Vector length: " << v1.size() << endl;	// printing vector length
		}

	} while (keep_running);

	return 0;
}

// Exercise 2A
string find_first_element(const string& xml, string tag_name)
{
	// construct start and end tags from from the tag name 
	// add angle brackets to both tags and also slash to end tag
	// then search for tags 
	// if both are found then return the substring between the tags


	string start_tag, end_tag, substr;

	start_tag = "<" + tag_name + ">";
	end_tag = "</" + tag_name + ">";

	size_t p1 = xml.find(start_tag);
	size_t p2 = xml.find(end_tag);

	if (p1 != string::npos && p2 != string::npos)
	{
		p1 += start_tag.length();	// position after start_tag
		p2 -= p1;					// length of the string between tags

		substr = xml.substr(p1, p2);	// substring between the tags
		return substr;
	}
	else
	{
		return "not found"; // return this if tag is not found
	}

}


// Exercise 2B
vector<string> find_all_elements(const string& xml, string tag_name)
{
	vector<string>v1;
	size_t pos_after_start_tag, len_of_substr;
	string start_tag, end_tag, substr;

	start_tag = "<" + tag_name + ">";
	end_tag = "</" + tag_name + ">";

	size_t p1 = xml.find(start_tag);
	size_t p2 = xml.find(end_tag);

	while (p1 != string::npos && p2 != string::npos)
	{
		pos_after_start_tag = p1 + start_tag.length();	// position after start_tag
		len_of_substr = p2 - pos_after_start_tag;		// length of the string between tags

		substr = xml.substr(pos_after_start_tag, len_of_substr);	// substring between the tags

		v1.push_back(substr);			// add string to vector

		p1 = xml.find(start_tag, p1+1);	// searching for the next occurrence of the start tag
		p2 = xml.find(end_tag, p2+1);	// searching for the next occurrence of the end tag

	}

	return v1;

}


