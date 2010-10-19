#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/map.hpp> 
//#include <boost/serialization/nvp.hpp> 
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
    boost::archive::xml_oarchive ar(ostream);
    ar & BOOST_SERIALIZATION_NVP(m);
    //ar & boost::serialization::make_nvp("my_map_name", m);
    cout << "Text archive contents: \"" << ostream.str() << "\"" << endl;

    string data = ostream.str();
    stringstream istream(data);
    boost::archive::xml_iarchive ar_i(istream);
    sint_map m1;

    ar_i & BOOST_SERIALIZATION_NVP(m1);
    //ar_i & boost::serialization::make_nvp("my_map_name", m1);

    cout << "Contents extracted from xml archive:" << endl;
    BOOST_FOREACH(int_map::value_type data, m1) {
        cout << "    " << data.first << ":" << data.second << endl;
    }

    return 0;
}
