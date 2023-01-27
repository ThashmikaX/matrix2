
#define CMATRIX3_H

#include <iostream>
using namespace std;
// number of raws and colums
#define nR 3
#define nC 3

//define class
class cMatrix
{
    //make data public
public:
    /** Default constructor */
    cMatrix();
    cMatrix(double data[], int rows, int ncols, string name);
    /** Default destructor */
    virtual ~cMatrix();
    /** Copy constructor
     *  \param other Object to copy from
     */
    cMatrix(const cMatrix& other);
    /** Assignment operator
     *  \param other Object to assign from
     *  \return A reference to this
     */
    cMatrix& operator=(const cMatrix& other);

    cMatrix operator+(const cMatrix& other);
    cMatrix operator-(const cMatrix& other);
    cMatrix operator*(const cMatrix& other);
    cMatrix operator^(int x);
    bool operator==(const cMatrix& other);
    bool operator!=(const cMatrix& other);

    void show();

protected:
private:
    double *elm; // matrix data
    int r;       // number of rows
    int c;       // number of columns
    string name;
};
