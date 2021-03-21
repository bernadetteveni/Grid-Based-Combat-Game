////
////  main.cpp
////
////  A module to test the Vector2 template class.
////
//
//// standard #includes
//#include <iostream>
//#include <iomanip>
//
//// custom #includes
//#include "Vector2.h"
//
//// using declarations
//using namespace std;
//
//// function prototypes
//template <typename ItemType>
//ostream& operator<< (ostream& out, const Vector2<ItemType>& vec);
//
//template <typename ItemType>
//void testType (const ItemType& x1,
//               const ItemType& y1,
//               const ItemType& x2,
//               const ItemType& y2);
//
//
//
//int main ()
//{
//    cout << "Testing int" << endl;
//    cout << "-----------" << endl;
//    testType<int>(1, 2, 4, 6);
//
//    cout << "Testing double" << endl;
//    cout << "--------------" << endl;
//    testType<double>(0.1, 0.2, 0.4, 0.6);
//
//    cout << "Testing float" << endl;
//    cout << "--------------" << endl;
//    testType<float>(0.01f, 0.02f, 0.04f, 0.06f);
//
//    return 0;
//}
//
//
//
////
////  Stream Insertion Operator
////
////  Purpose: To allow formatted Vector2s be be conveniantly
////           inserted into an output stream.  The Vector2 is
////           formatted as a coordinate vector.
////  Parameter(s):
////    <1> out: A reference to the output stream
////    <2> vec: The Vector2 to insert
////  Precondition(s): N/A
////  Returns: out
////  Side Effect: If out.good() is true, the values of vec are
////               inserted into out.  If out.good() is false, the
////               result is undefined.
////
//template <typename ItemType>
//ostream& operator<< (ostream& out, const Vector2<ItemType>& vec)
//{
//    out << "(" << vec.x << ", " << vec.y << ")";
//    return out;
//}
//
//
//
//template <typename ItemType>
//void testType (const ItemType& x1,
//               const ItemType& y1,
//               const ItemType& x2,
//               const ItemType& y2)
//{
//    // 1. Test constructors
//
//    Vector2<ItemType> v1;
//    Vector2<ItemType> v2(x1, y1);
//    Vector2<ItemType> v3(v2);
//
//    cout << "After initialization:" << endl;
//    cout << "  v1: " << v1 << endl;
//    cout << "  v2: " << v2 << endl;
//    cout << "  v3: " << v3 << endl;
//
//    // 2. Test assignment operators
//
//    v3 = v1;
//    v1 = v2;
//    v1.x = ItemType();
//
//    cout << "After assignments:" << endl;
//    cout << "  v1: " << v1 << endl;
//    cout << "  v2: " << v2 << endl;
//    cout << "  v3: " << v3 << endl;
//
//    // 3. Test equality test operator
//
//    cout << "Testing equality test operator:" << endl;
//    cout << boolalpha;
//    cout << "  v1 == v1: " << (v1 == v1) << endl;
//    cout << "  v1 == v2: " << (v1 == v2) << endl;
//    cout << "  v1 == v3: " << (v1 == v3) << endl;
//    cout << "  v2 == v1: " << (v2 == v1) << endl;
//    cout << "  v2 == v2: " << (v2 == v2) << endl;
//    cout << "  v2 == v3: " << (v2 == v3) << endl;
//    cout << "  v3 == v1: " << (v3 == v1) << endl;
//    cout << "  v3 == v2: " << (v3 == v2) << endl;
//    cout << "  v3 == v3: " << (v3 == v3) << endl;
//
//    // 4. Test assigning components
//
//    v1.x = x2;
//    v1.y = y2;
//
//    cout << "After setting v1:" << endl;
//    cout << "  v1: " << v1 << endl;
//    cout << "  v2: " << v2 << endl;
//    cout << "  v3: " << v3 << endl;
//
//    // 5. Test addition operator
//
//    cout << "Testing addition:" << endl;
//    cout << "  v1 + v1: " << (v1 + v1) << endl;
//    cout << "  v1 + v2: " << (v1 + v2) << endl;
//    cout << "  v1 + v3: " << (v1 + v3) << endl;
//    cout << "  v2 + v1: " << (v2 + v1) << endl;
//    cout << "  v2 + v2: " << (v2 + v2) << endl;
//    cout << "  v2 + v3: " << (v2 + v3) << endl;
//    cout << "  v3 + v1: " << (v3 + v1) << endl;
//    cout << "  v3 + v2: " << (v3 + v2) << endl;
//    cout << "  v3 + v3: " << (v3 + v3) << endl;
//
//    // 6. Test subtraction operator
//
//    cout << "Testing subtraction:" << endl;
//    cout << "  v1 - v1: " << (v1 - v1) << endl;
//    cout << "  v1 - v2: " << (v1 - v2) << endl;
//    cout << "  v1 - v3: " << (v1 - v3) << endl;
//    cout << "  v2 - v1: " << (v2 - v1) << endl;
//    cout << "  v2 - v2: " << (v2 - v2) << endl;
//    cout << "  v2 - v3: " << (v2 - v3) << endl;
//    cout << "  v3 - v1: " << (v3 - v1) << endl;
//    cout << "  v3 - v2: " << (v3 - v2) << endl;
//    cout << "  v3 - v3: " << (v3 - v3) << endl;
//
//    // 7. Test getNorm
//
//    cout << "Testing getNorm:" << endl;
//    cout << "  v1.getNorm(): " << v1.getNorm() << endl;
//    cout << "  v2.getNorm(): " << v2.getNorm() << endl;
//    cout << "  v3.getNorm(): " << v3.getNorm() << endl;
//
//    cout << endl;
//}

//
//  MainE.cpp
//
//  A variant on MainC.cpp program from Assignment 5.  This
//    version uses Vector2<float>s instead of Vector2s.
//

// standard includes
#include <string>
#include <iostream>
#include <fstream>

// custom includes
#include "Vector2.h"
#include "PathWalked.h"

// using declarations
using namespace std;

static PathWalked loadPath (const string& filename);
static void printPath (const PathWalked& path, const string& name);



int main ()
{
    cout << "Testing PathWalked class:" << endl;
    cout << "=========================" << endl;
    cout << endl;
    
    // test default constructor
    PathWalked path0;
    
    // test add function and copy constructor
    PathWalked path1 = loadPath("Path1.txt");
    
    // test assignment operator
    PathWalked path2;
    path2 = loadPath("circle.txt");
    
    cout << "Paths after loading:" << endl;
    cout << "--------------------" << endl;
    printPath(path0, "Path 0");
    printPath(path1, "Path 1");
    printPath(path2, "Path 2");
    
    // test assignment operator more and clear function
    path0 = path1;
    path1 = path2;
    path2.clear();
    
    cout << "Paths after assignment and clear:" << endl;
    cout << "---------------------------------" << endl;
    printPath(path0, "Path 0");
    printPath(path1, "Path 1");
    printPath(path2, "Path 2");
    
    // test copy constructor again and destructor
    PathWalked* p_path3 = new PathWalked(path0);
    cout << "Path 3 before clearing path 0:" << endl;
    cout << "------------------------------" << endl;
    printPath(*p_path3, "Path 3");
    path0.clear();
    cout << "Path 3 after clearing path 0:" << endl;
    cout << "-----------------------------" << endl;
    printPath(*p_path3, "Path 3");
    delete p_path3;
    
    cout << "Remaining Paths after delete:" << endl;
    cout << "-----------------------------" << endl;
    printPath(path0, "Path 0");
    printPath(path1, "Path 1");
    printPath(path2, "Path 2");
    
    return 0;
}



PathWalked loadPath (const string& filename)
{
    ifstream in1(filename.c_str());
    
    // check for missing/unreadable file
    if (!in1)
    {
        cerr << "Warning: Error opening path file \"" << filename
        << "\" - substituting empty path" << endl;
        return PathWalked();
    }
    
    // determine the number of positions on the path
    unsigned int count;
    in1 >> count;
    
    // check for bad path count
    if (!in1)
    {
        cerr << "Warning: Error reading position count in path file \""
        << filename << "\" - substituting empty path" << endl;
        return PathWalked();
    }
    
    // read the positions and add them to the path
    PathWalked path;
    for(unsigned int i = 0; i < count; i++)
    {
        float x, y;
        in1 >> x;
        in1 >> y;
        path.add(Vector2<float>(x, y));
    }
    
    // close the file stream when we are done with it
    in1.close();
    
    // check for error reading positions
    if (!in1)
    {
        cerr << "Warning: Error reading positions in path file \""
        << filename << "\" - path may be incorrect" << endl;
        return path;
    }
    
    // return the completed path
    return path;
}

void printPath (const PathWalked& path, const string& name)
{
    cout << name << ":" << endl;
    
    // test empty function
    if(path.empty())
    {
        cout << "(Empty)" << endl;
    }
    else
    {
        // test print function
        path.print();
        
        // test getPathLength function
        cout << "Total Length " << path.getPathLength() << endl;
    }
    
    cout << endl;
}
