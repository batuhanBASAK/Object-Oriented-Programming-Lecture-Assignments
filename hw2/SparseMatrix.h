#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include "SparseVector.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>

struct SparseMatrixElement
{
    int rowIndex;
    SparseVector sparseVector;
};

class SparseMatrix
{
public:

    // Constructors

    SparseMatrix(); // Default constructor. Intentionally does nothing.

    // Constructor which gets whole SparseMatrixElements 
    // from file taken as argument.
    SparseMatrix(const char* filename);

    // Constructor which builds object
    // by taking whole Sparse Matrix Elements as argument.
    SparseMatrix(std::vector<SparseMatrixElement> elements);


    // Operator overloading functions.

    friend const SparseMatrix operator+ (const SparseMatrix& m1, const SparseMatrix& m2);
    friend const SparseMatrix operator- (const SparseMatrix& m1, const SparseMatrix& m2);
    const SparseMatrix operator- () const;

    SparseMatrix& operator= (const SparseMatrix& m);

    friend std::ostream& operator<< (std::ostream& outstream, const SparseMatrix& m);

    friend const SparseMatrix operator* (const SparseMatrix& m1, const SparseMatrix& m2);


    // If row consists entirely of zeros returns true, else false.
    bool IsRowZero(int rowIndex) const;


    // Returns transpose of SparseMatrix.
    const SparseMatrix transpose() const;

    // Returns index of value where sparseMatrixElements rowIndex is parameter rowIndex 
    int GetIndexOfSparseMatrixElementRowIndex(int rowIndex) const;

    // Returns the largets colIndex value by searching entire SparseVectors in SparseMatrix.
    int GetLargestColIndexInSparseMatrixElement() const;

    // Appends a SparseMatrixElement to m_SparseMatrixElements.
    void AppendSparseMatrixElement(const SparseMatrixElement& element);

    // Appends a SparseMatrixElement to m_SparseMatrixElements.
    void AppendSparseMatrixElement(int rowIndex, const SparseVector& s);

    // Returns last index of SparseMatrix
    int GetLastIndexOfSparseMatrixRow() const;

    // returns rowIndex value of SparseMatrixElement which in m_SparseMatrixElements[index]
    int GetRowIndexOfSparseMatrixElements(int index) const;

    // Returns indexRow'th SparseVector from SparseMatrix.
    const SparseVector GetSparseVectorOfSparseMatrixElement(int indexRow) const;
private:
    std::vector<SparseMatrixElement> m_SparseMatrixElements;

    // Sorts each row in ascending order.
    void SortSparseMatrixRowsInAscendingOrder();
};



#endif
