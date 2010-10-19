#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp> 
#include <boost/foreach.hpp>

using namespace std;

int main() {
    vector<int> v(10, 10);
    stringstream ostream;
    boost::archive::text_oarchive ar(ostream);
    ar & v;
    cout << "Text archive contents: \"" << ostream.str() << "\"" << endl;

    string data = ostream.str();
    stringstream istream(data);
    boost::archive::text_iarchive ar_i(istream);
    vector<int> v1;

    ar_i & v1;

    cout << "Contents extracted from text archive:" << endl;
    BOOST_FOREACH(int i, v1) {
        cout << "    " << i << endl;
    }

    return 0;
}
