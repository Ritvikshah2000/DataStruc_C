#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int, string> name_map; //(key, value)

    name_map[1] = "Tom";
    name_map[2] = "Max";
    name_map[3] = "John";
    name_map[4] = "Larry";
    name_map[5] = "Austin";

    name_map.insert(pair<int, string>(6, "Jan")); //another way to insert elements

   // name_map.clear(); // clears map;

   //finding an element:
   map<int, string> :: iterator it = name_map.find(5);
    cout << "key found = " << it -> second << endl;
    cout << "Map size : " << name_map.size() << endl;

    for(map<int, string> :: iterator it = name_map.begin(); it != name_map.end(); it++){
        cout << it -> first << " => " << it -> second << endl;
    }

    return 0;
}