#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/vector.hpp> 
#include <boost/foreach.hpp>

using namespace std;

int main() {
    vector<int> v(10, 10);
    ofstream ostream;
    ostream.open("binary_test.dat");
    boost::archive::binary_oarchive ar(ostream);
    ar & v;
    ostream.close();

    ifstream istream;
    istream.open("binary_test.dat");
    boost::archive::binary_iarchive ar_i(istream);
    vector<int> v1;
    
    cout << "Contents extracted from binary_test.dat archive:" << endl;
    ar_i & v1;
    BOOST_FOREACH(int i, v1) {
        cout << "    " << i << endl;
    }
    istream.close();

    return 0;
}
