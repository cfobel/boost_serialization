#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/map.hpp> 
#include <boost/foreach.hpp>

using namespace std;

typedef map<int,int> int_map;
typedef map<short int,int> sint_map;

int main() {
    int_map m;

    for(int i = 0; i < 10; i++) {
        m[i] = 10 - i;
    }

    stringstream ostream;
    boost::archive::text_oarchive ar(ostream);
    ar & m;
    cout << "Text archive contents: \"" << ostream.str() << "\"" << endl;

    string data = ostream.str();
    stringstream istream(data);
    boost::archive::text_iarchive ar_i(istream);
    // Notice we can restore into a different type of map...
    sint_map m1;

    ar_i & m1;

    cout << "Contents extracted from text archive:" << endl;
    BOOST_FOREACH(int_map::value_type data, m1) {
        cout << "    " << data.first << ":" << data.second << endl;
    }

    return 0;
}
