#include <string>
#include <vector>
using namespace std;
struct Student {
    string name;
    int score;
};
void addStudent(vector<Student>& database, const string& name, int score);
void updateScore(vector<Student>& database, const string& name, int newScore);
double getAverageScore(const vector<Student>& database);
string findTopStudent(const vector<Student>& database);
