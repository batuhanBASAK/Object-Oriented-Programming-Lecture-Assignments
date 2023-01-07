#include "SparseVector.h"
#include <stdlib.h>


// Constructor Functions.

// Default constructor. Intentionally does nothing.
SparseVector::SparseVector()
{
}
    
// Constructor which gets whole SparseVectorElements 
// from file taken as argument.
SparseVector::SparseVector(const char* filename)
{
    double tmpData;
    int tmpIndex;
    char ch;
    std::ifstream infile;

    // Open input file
    infile.open(filename);
    if (infile.fail())
    {
        // An error happend while opening input file!
        // Display an error message and exit the program.

        std::cout << "Error: Opening input file " << filename << std::endl;
        std::cout << "Program is stopping...\n";
        exit(EXIT_FAILURE); 
    }

    // Read each SparseVectorElement from file and append that element
    // to m_SparseVectorElements
    while (infile >> tmpIndex >> ch >> tmpData)
    {
        AppendSparseVectorElement(tmpIndex, tmpData);
    }

    // Close input file.
    infile.close();
}

// Constructor which builds object
// by taking whole Sparse Vector Elements as argument.
SparseVector::SparseVector(const std::vector<SparseVectorElement>& elements)
{
    // Append each element in vector elements to m_SparseVectorElements.
    for (SparseVectorElement element : elements )
    {
        AppendSparseVectorElement(element);
    }
}


// Friend function which computes dot product of two SparseVector.
double dot(const SparseVector& s1, const SparseVector& s2)
{
    double ans = 0.0;
    double s1CurrData;
    double s2CurrData;

    // Index value of last SparseVectorElement in m_SparseVectorElements for s1
    int s1LastIndexOfSparseVectorElements = s1.GetLastIndexOfSparseVectorElements();

    // Index value of last SparseVectorElement in m_SparseVectorElements for s2
    int s2LastIndexOfSparseVectorElements = s2.GetLastIndexOfSparseVectorElements();

    // Last Index value for both s1 and s2.
    int lastIndexOfSparseVectorElements;

    // find lastIndexOfSparseVectorElements
    if (s1LastIndexOfSparseVectorElements > s2LastIndexOfSparseVectorElements)
        lastIndexOfSparseVectorElements = s1LastIndexOfSparseVectorElements;
    else
        lastIndexOfSparseVectorElements = s2LastIndexOfSparseVectorElements;


    for (int i = 0; i <= lastIndexOfSparseVectorElements; i++)
    {
        s1CurrData = s1.GetDataOfSparseVectorElement(i);
        s2CurrData = s2.GetDataOfSparseVectorElement(i);

        if (s1CurrData * s2CurrData != 0.0)
            ans += s1CurrData * s2CurrData;
    }


    return (ans);
}


// Operator Overloading Functions.
const SparseVector operator+ (const SparseVector& s1, const SparseVector& s2)
{
    double s1CurrData;
    double s2CurrData;

    std::vector<SparseVectorElement> sparseVectorElementsOfSums;

    // Index value of last SparseVectorElement in m_SparseVectorElements for s1
    int s1LastIndexOfSparseVectorElements = s1.GetLastIndexOfSparseVectorElements();

    // Index value of last SparseVectorElement in m_SparseVectorElements for s2
    int s2LastIndexOfSparseVectorElements = s2.GetLastIndexOfSparseVectorElements();

    // Last Index value for both s1 and s2.
    int lastIndexOfSparseVectorElements;

    // find lastIndexOfSparseVectorElements
    if (s1LastIndexOfSparseVectorElements > s2LastIndexOfSparseVectorElements)
        lastIndexOfSparseVectorElements = s1LastIndexOfSparseVectorElements;
    else
        lastIndexOfSparseVectorElements = s2LastIndexOfSparseVectorElements;


    for (int i = 0; i <= lastIndexOfSparseVectorElements; i++)
    {
        s1CurrData = s1.GetDataOfSparseVectorElement(i);
        s2CurrData = s2.GetDataOfSparseVectorElement(i);

        if (s1CurrData + s2CurrData != 0.0)
            sparseVectorElementsOfSums.push_back({i, s1CurrData+s2CurrData});
    }

    return SparseVector(sparseVectorElementsOfSums);
}
    
const SparseVector operator- (const SparseVector& s1, const SparseVector& s2)
{
    double s1CurrData;
    double s2CurrData;

    std::vector<SparseVectorElement> sparseVectorElementsOfDiffs;

    // Index value of last SparseVectorElement in m_SparseVectorElements for s1
    int s1LastIndexOfSparseVectorElements = s1.GetLastIndexOfSparseVectorElements();

    // Index value of last SparseVectorElement in m_SparseVectorElements for s2
    int s2LastIndexOfSparseVectorElements = s2.GetLastIndexOfSparseVectorElements();

    // Last Index value for both s1 and s2.
    int lastIndexOfSparseVectorElements;

    // find lastIndexOfSparseVectorElements
    if (s1LastIndexOfSparseVectorElements > s2LastIndexOfSparseVectorElements)
        lastIndexOfSparseVectorElements = s1LastIndexOfSparseVectorElements;
    else
        lastIndexOfSparseVectorElements = s2LastIndexOfSparseVectorElements;


    for (int i = 0; i <= lastIndexOfSparseVectorElements; i++)
    {
        s1CurrData = s1.GetDataOfSparseVectorElement(i);
        s2CurrData = s2.GetDataOfSparseVectorElement(i);

        if (s1CurrData - s2CurrData != 0.0)
            sparseVectorElementsOfDiffs.push_back({i, (s1CurrData - s2CurrData)});
    }

    return SparseVector(sparseVectorElementsOfDiffs);
}

const SparseVector SparseVector::operator- () const
{
    std::vector<SparseVectorElement> sparseVectorElementsOfNegations;

    for ( SparseVectorElement element : m_SparseVectorElements)
    {
        sparseVectorElementsOfNegations.push_back({element.index, -element.data});
    }

    return SparseVector(sparseVectorElementsOfNegations);
}



const SparseVector operator* (const SparseVector& s1, const SparseVector& s2)
{
    double s1CurrData;
    double s2CurrData;

    std::vector<SparseVectorElement> multOfSparseVectorElements;

    int s1LastIndexOfSparseVectorElements = s1.GetLastIndexOfSparseVectorElements();
    int s2LastIndexOfSparseVectorElements = s2.GetLastIndexOfSparseVectorElements();

    // Last Index value for both s1 and s2.
    int lastIndexOfSparseVectorElements;

    // find lastIndexOfSparseVectorElements
    if (s1LastIndexOfSparseVectorElements > s2LastIndexOfSparseVectorElements)
        lastIndexOfSparseVectorElements = s1LastIndexOfSparseVectorElements;
    else
        lastIndexOfSparseVectorElements = s2LastIndexOfSparseVectorElements;


    for (int i = 0; i <= lastIndexOfSparseVectorElements; i++)
    {
        s1CurrData = s1.GetDataOfSparseVectorElement(i);
        s2CurrData = s2.GetDataOfSparseVectorElement(i);

        if (s1CurrData * s2CurrData != 0.0)
            multOfSparseVectorElements.push_back({i, (s1CurrData * s2CurrData)});
    }

    return SparseVector(multOfSparseVectorElements);
}

SparseVector& SparseVector::operator= (const SparseVector& s)
{
    if (this != &s)
        m_SparseVectorElements = s.m_SparseVectorElements;
    return *this;
}

std::ostream& operator<< (std::ostream& outstream, const SparseVector& s)
{
    for (SparseVectorElement element : s.m_SparseVectorElements )
    {
        outstream << element.index  << ":" << element.data << " ";
    }

    return outstream;
}

// Getter Member Functions.
    
// Returns index of SparseVector which data value is parameter data.
// If there is no such SparseVector then returns -1.
int SparseVector::GetIndexOfSparseVectorElement(double data) const
{
    for ( SparseVectorElement element : m_SparseVectorElements )
    {
        if (element.data == data)
            return element.index;
    }

    return -1;
}

// Returns data of SparseVector which index is parameter index.
double SparseVector::GetDataOfSparseVectorElement(int index) const
{
    for ( SparseVectorElement element : m_SparseVectorElements )
    {
        if (element.index == index)
            return element.data;
    }

    return 0.0;
}

// Setter Member Functions.

// Appends new SparseVectorElement if there is no SparseVector exists
// which has same index.
void SparseVector::AppendSparseVectorElement(const SparseVectorElement& element)
{
    // If that element doesn't exist already. Keep proceed for appending.
    if (IsSparseVectorElementDataZero(element.index))
    {
        m_SparseVectorElements.push_back({element.index, element.data});
    }
}

// Creates a new SparseVectorElement which its data is parameter data and
// its index is index. And appends that SparseVectorElement into
// m_SparseVectorElements if a SparseVectorElement which has same index
// does not exist already.
void SparseVector::AppendSparseVectorElement(int index, double data)
{
    if (IsSparseVectorElementDataZero(index))
    {
        m_SparseVectorElements.push_back({index, data});
    }
}

// Other Member Functions

// Checks Whether SparseVectorElement which has index value is index
// in m_SparseVectorElements has a nonzero data value or not.
// If that SparseVectorElement's data is 0 returns true, else false.
bool SparseVector::IsSparseVectorElementDataZero(int index) const
{
    for ( SparseVectorElement element : m_SparseVectorElements )
    {
        if (element.index == index)
        {
            return false;
        }
            
    }

    return true;
}


// Deletes All SparseVectorElements from SparseVector.
void SparseVector::ResetSparseVector()
{
    m_SparseVectorElements.clear();
}

// Returns index value of Last SparseVectorElement in m_SparseVectorElements.
int SparseVector::GetLastIndexOfSparseVectorElements() const
{
    if (m_SparseVectorElements.empty())
    {
       return -1;
    }
    int index = m_SparseVectorElements[m_SparseVectorElements.size() -1 ].index;
    return index;
}

bool SparseVector::IsSparseVectorEmpty() const
{
    if ( m_SparseVectorElements.empty())
        return true;
    return false;
}
