#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    string text;
    map<string, string> stringVar;
    map<string, string> numberVar;

    ifstream File(argv[1]);
    //ifstream File("test.shny");

    if (!File.is_open())
    {
        cerr << "Cannot open file: " << argv[1] << endl;
        return 1;
    }

    regex var(R"(var\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*=\s*\"?([^"]*)\"?)");

    smatch matches;

    while (getline(File, text))
    {
        try
        {
            if (text.substr(0, 6) == "write(" && text.back() == ')')
            {
                string content = text.substr(6, text.length() - 7);
                if (content.front() == '"' && content.back() == '"')
                {
                    cout << content;
                }
                else
                {
                    bool found = false;
                    for (const auto &[key, value] : stringVar)
                    {
                        if (key == content)
                        {
                            cout << value;
                        }
                    }
                    for (const auto &[key, value] : numberVar)
                    {
                        if (key == content)
                        {
                            found = true;
                            cout << value;
                        }
                    }
                }
            }
            else if (text.substr(0, 5) == "read(" && text.back() == ')')
            {
            }
            else if (text.substr(0, 3) == "var")
            {
                if (regex_search(text, matches, var))
                {
                    if (matches.size() > 1)
                    {
                        string variable = matches[1].str();                        // เก็บชื่อของตัวแปร
                        string value = matches.size() > 2 ? matches[2].str() : ""; // เก็บค่าถ้าหากมี
                        if (value.front() == '"' && value.back() == '"')
                        {
                            if (!value.empty())
                            {
                                stringVar[variable] = value;
                            }
                        }
                        else
                        {
                            if (!value.empty())
                            {
                                numberVar[variable] = value;
                            }
                        }
                    }
                }
            }
            else
            {
                throw runtime_error("Syntax Error!");
            }
        }
        catch (const runtime_error &error)
        {
            cout << "Error: " << error.what() << endl;
        }
    }

    return 0;
}
