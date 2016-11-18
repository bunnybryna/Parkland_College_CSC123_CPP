#include <iostream>
// for vector
#include <vector>
// for sort()
#include <algorithm>

using namespace std;

int main()
{
    vector<string> myNameList;
    myNameList.push_back("Bryna");
    myNameList.push_back("Zhao");
    myNameList.push_back("Yongtao");
    myNameList.push_back("Li");

    sort(myNameList.begin(), myNameList.end());

    for (int i=0;i<myNameList.size();i++)
    {

        cout<< myNameList[i] << endl;
    }

    // space allocation
    cout << myNameList.capacity() << " spaces used" << endl;
    cout << myNameList.max_size() << " maximum size" << endl;
    return 0;
}
