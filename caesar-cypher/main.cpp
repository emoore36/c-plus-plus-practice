#include <fstream>
#include <iostream>

using namespace std;

int main() {

  try {
    ifstream fileIn("input.txt", ios::in);
    ofstream fileOut("output.txt", ios::trunc);

    string line;
    while (getline(fileIn, line)) {
      string newLine;
      for (char c : line) {
        if (c == ' ' || c == '!') {
          newLine += c;
          continue;
        }
        newLine += ++c;
      }
      fileOut << newLine;
    }

    fileIn.close();
    fileOut.close();

  } catch (const char *msg) {
    cout << "Error: " << msg << endl;
  }

  return 0;
}