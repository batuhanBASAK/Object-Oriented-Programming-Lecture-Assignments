#ifndef SPARSE_VECTOR_H
#define SPARSE_VECTOR_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

struct SparseVectorElement
{
    int index;
    double data;
};

class SparseVector
{
public:

    // Constructor Functions.

    SparseVector(); // Default constructor. Intentionally does nothing.
    
    // Constructor which gets whole SparseVectorElements 
    // from file taken as argument.
    SparseVector(const char* filename);

    // Constructor which builds object
    // by taking whole Sparse Vector Elements as argument.
    SparseVector(const std::vector<SparseVectorElement>& elements);

    // Friend function which computes dot product of two SparseVector.
    friend double dot(const SparseVector& s1, const SparseVector& s2);


    // Operator Overloading Functions.
    friend const SparseVector operator+ (const SparseVector& s1, const SparseVector& s2);
    
    friend const SparseVector operator- (const SparseVector& s1, const SparseVector& s2);

    friend const SparseVector operator* (const SparseVector& s1, const SparseVector& s2);
    
    const SparseVector operator- () const;

    SparseVector& operator= (const SparseVector& s);

    friend std::ostream& operator<< (std::ostream& outstream, const SparseVector& s);

    // Getter Member Functions.
    
    // Returns index of SparseVector which data value is parameter data.
    int GetIndexOfSparseVectorElement(double data) const;

    // Returns data of SparseVector which index is parameter index.
    double GetDataOfSparseVectorElement(int index) const;

    // Setter Member Functions.

    // Appends new SparseVectorElement if there is no SparseVector exists
    // which has same index.
    void AppendSparseVectorElement(const SparseVectorElement& element);

    // Creates a new SparseVectorElement which its data is parameter data and
    // its index is index. And appends that SparseVectorElement into
    // m_VectorElements if a SparseVectorElement which has same index
    // does not exist already.
    void AppendSparseVectorElement(int index, double data);

    // Other Member Functions

    // Checks Whether SparseVectorElement which has index value is index
    // in m_VectorElements has a nonzero data value or not.
    // If that SparseVectorElement's data is 0 returns true, else false.
    bool IsSparseVectorElementDataZero(int index) const;

    // Deletes All SparseVectorElements from SparseVector.
    void ResetSparseVector();

    // Returns true if SparseVector is empty, else false.
    bool IsSparseVectorEmpty() const;

    int GetLastIndexOfSparseVectorElements() const;

private:
    std::vector<SparseVectorElement> m_SparseVectorElements;
};

#endif
