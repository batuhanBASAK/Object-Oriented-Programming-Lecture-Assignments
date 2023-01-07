#include "SparseMatrix.h"


// Constructors

// Default constructor. Intentionally does nothing.
SparseMatrix::SparseMatrix()
{
}


// Constructor which gets whole SparseMatrixElements 
// from file taken as argument.
SparseMatrix::SparseMatrix(const char* filename)
{
    char ch;
    int rowIndex;
    int colIndex;
    double data;

    std::ifstream infile;
    std::string line;

    infile.open(filename);
    if (infile.fail())
    {
        // An error happend while opening input file
        // display an error message and exit the program.
        std::cout << "Error: Opening file " << filename << std::endl
                  << "Program stoping...\n";
        exit(EXIT_FAILURE);
    }

    // Read entire file line by line. And by analyzing line get rowIndex and SparseVector.
    while (std::getline(infile, line))
    {
        std::stringstream lineStream(line);
        lineStream >> rowIndex;
        SparseVector tmpSparseVector;
        while (lineStream >> colIndex >> ch >> data)
        {
            // Append read index and data to tmp SparseVector
            tmpSparseVector.AppendSparseVectorElement(colIndex, data);
        }
        // Append Sparse vector to SparseMatrix.
        AppendSparseMatrixElement({rowIndex, tmpSparseVector});
    }

    infile.close(); // close input file.
}

// Constructor which builds object
// by taking whole Sparse Matrix Elements as argument.
SparseMatrix::SparseMatrix(std::vector<SparseMatrixElement> elements)
{
    for ( SparseMatrixElement element : elements )
        m_SparseMatrixElements.push_back(element);
}


// Operator overloading functions.


// Computes and returns SparseMatrix (m1 + m2)
const SparseMatrix operator+ (const SparseMatrix& m1, const SparseMatrix& m2)
{
    int lastRowIndexOfm1 = m1.GetLastIndexOfSparseMatrixRow();
    int lastRowIndexOfm2 = m2.GetLastIndexOfSparseMatrixRow();

    int lastRowIndex;

    // tmp sparseMatrixElement type vector to hold entire sum.
    std::vector<SparseMatrixElement> sumOfSparseMatrixElements;

    // find last row.
    if (lastRowIndexOfm1 > lastRowIndexOfm2)
        lastRowIndex = lastRowIndexOfm1;
    else
        lastRowIndex = lastRowIndexOfm2;

    // from 0 to last the last row sum all SparseVectors to get sum of SparseMatrices.
    for (int i = 0; i <= lastRowIndex; i++)
    {
        // tmp SparseMatrixElement to hold current sum.
        SparseMatrixElement sumOfCurrSparseMatrixElements;
        if (!m1.IsRowZero(i) && !m2.IsRowZero(i))
        {
            // If both rows are nonzero.
            sumOfCurrSparseMatrixElements.rowIndex = i;
            sumOfCurrSparseMatrixElements.sparseVector = m1.GetSparseVectorOfSparseMatrixElement(i)
                                                         + m2.GetSparseVectorOfSparseMatrixElement(i);

            if (!sumOfCurrSparseMatrixElements.sparseVector.IsSparseVectorEmpty())
            {
                sumOfSparseMatrixElements.push_back(sumOfCurrSparseMatrixElements);
            }
        }
        else if (!m1.IsRowZero(i))
        {
            // For row i only SparseMatrix m1 has nonzero row.
            sumOfCurrSparseMatrixElements.rowIndex = i;
            sumOfCurrSparseMatrixElements.sparseVector = m1.GetSparseVectorOfSparseMatrixElement(i);
            if (!sumOfCurrSparseMatrixElements.sparseVector.IsSparseVectorEmpty())
            {
                sumOfSparseMatrixElements.push_back(sumOfCurrSparseMatrixElements);
            }
        }
        else if (!m2.IsRowZero(i))
        {
            // For row i only SparseMatrix m2 has nonzero row.
            sumOfCurrSparseMatrixElements.rowIndex = i;
            sumOfCurrSparseMatrixElements.sparseVector = m2.GetSparseVectorOfSparseMatrixElement(i);
            if (!sumOfCurrSparseMatrixElements.sparseVector.IsSparseVectorEmpty())
            {
                sumOfSparseMatrixElements.push_back(sumOfCurrSparseMatrixElements);
            }
        }
    }

    return SparseMatrix(sumOfSparseMatrixElements);
}

// Computes and returns SparseMatrix (m1 - m2).
const SparseMatrix operator- (const SparseMatrix& m1, const SparseMatrix& m2)
{
    int lastRowIndexOfm1 = m1.GetLastIndexOfSparseMatrixRow();
    int lastRowIndexOfm2 = m2.GetLastIndexOfSparseMatrixRow();

    int lastRowIndex;

    // tmp SparseMatrixElement type vector to hold Difference of SparseMatrices.
    std::vector<SparseMatrixElement> diffOfSparseMatrixElements;

    // find last row.
    if (lastRowIndexOfm1 > lastRowIndexOfm2)
        lastRowIndex = lastRowIndexOfm1;
    else
        lastRowIndex = lastRowIndexOfm2;

    // From 0 through last row Substract each SparseVectors. And Append current diff of SparseMatrixElements
    // to diffOfSparseMatrixElements.
    for (int i = 0; i <= lastRowIndex; i++)
    {
        SparseMatrixElement diffOfCurrSparseMatrixElements;
        if (!m1.IsRowZero(i) && !m2.IsRowZero(i))
        {
            // If both m1 and m2 have nonzero row at i'th row.
            diffOfCurrSparseMatrixElements.rowIndex = i;
            diffOfCurrSparseMatrixElements.sparseVector = m1.GetSparseVectorOfSparseMatrixElement(i)
                                                         - m2.GetSparseVectorOfSparseMatrixElement(i);
            if (!diffOfCurrSparseMatrixElements.sparseVector.IsSparseVectorEmpty())
                diffOfSparseMatrixElements.push_back(diffOfCurrSparseMatrixElements);
        }
        else if (!m1.IsRowZero(i))
        {
            // Only m1 has nonzero row in i'th row.
            diffOfCurrSparseMatrixElements.rowIndex = i;
            diffOfCurrSparseMatrixElements.sparseVector = m1.GetSparseVectorOfSparseMatrixElement(i);
            if (!diffOfCurrSparseMatrixElements.sparseVector.IsSparseVectorEmpty())
                diffOfSparseMatrixElements.push_back(diffOfCurrSparseMatrixElements);
        }
        else if (!m2.IsRowZero(i))
        {
            // Only m2 has nonzero row in i'th row.
            diffOfCurrSparseMatrixElements.rowIndex = i;
            diffOfCurrSparseMatrixElements.sparseVector = -m2.GetSparseVectorOfSparseMatrixElement(i);
            if (!diffOfCurrSparseMatrixElements.sparseVector.IsSparseVectorEmpty())
                diffOfSparseMatrixElements.push_back(diffOfCurrSparseMatrixElements);
        }
    }

    // Return (m1 - m2) SparseMatrix.
    return SparseMatrix(diffOfSparseMatrixElements);

}

// Computes and returns the negation of SparseMatrix.
const SparseMatrix SparseMatrix::operator- () const
{
    std::vector<SparseMatrixElement> tmpSparseMatrixElement;
    for ( SparseMatrixElement element : m_SparseMatrixElements)
    {
        // For each element in m_SparseMatrixElements appends negation of SparseVector to tmpSparseMatrixElement.
        tmpSparseMatrixElement.push_back({element.rowIndex, -element.sparseVector});
    }

    // Returns that tmpSparseMatrixElement.
    return SparseMatrix(tmpSparseMatrixElement);
}

// Assingment operator overloading function.
SparseMatrix& SparseMatrix::operator= (const SparseMatrix& m)
{
    if (this != &m)
        m_SparseMatrixElements = m.m_SparseMatrixElements;
    return *this;
}


// Extraction operator overloading function.
std::ostream& operator<< (std::ostream& outstream, const SparseMatrix& m)
{
    for ( SparseMatrixElement element : m.m_SparseMatrixElements )
    {
        outstream << element.rowIndex << " " << element.sparseVector << std::endl;
    }
    return outstream;
}

// Computes and returns (m1 * m2).
const SparseMatrix operator* (const SparseMatrix& m1, const SparseMatrix& m2)
{
    int lastRowIndexOfm1 = m1.GetLastIndexOfSparseMatrixRow();
    int lastRowIndexOfm2 = m2.GetLastIndexOfSparseMatrixRow();

    int lastRowIndex;

    // If at least one of them consist entirely of zeros return 0 SparseMatrix.
    if (lastRowIndexOfm1 < 0 || lastRowIndexOfm2 < 0)
        return SparseMatrix(m1);

    // tmp SparseMatrixElement type vector to hold mult of SparseMatrices.
    std::vector<SparseMatrixElement> multOfSparseMatrixElements;

    // find last row.
    if (lastRowIndexOfm1 > lastRowIndexOfm2)
        lastRowIndex = lastRowIndexOfm1;
    else
        lastRowIndex = lastRowIndexOfm2;

    for (int i = 0; i <= lastRowIndex; i++)
    {

        if (!m1.IsRowZero(i) && !m2.IsRowZero(i))
        {
            // If rows are nonzero multiply that SparseVectors.
            SparseMatrixElement multOfCurrSparseMatrixElements;

            multOfCurrSparseMatrixElements.rowIndex = i;
            multOfCurrSparseMatrixElements.sparseVector = m1.GetSparseVectorOfSparseMatrixElement(i)
                                                         * m2.GetSparseVectorOfSparseMatrixElement(i);
            
            // If current multiplication has nonzero SparseVector append it to multOfSparseMatrixElements.
            if (!multOfCurrSparseMatrixElements.sparseVector.IsSparseVectorEmpty())
                multOfSparseMatrixElements.push_back(multOfCurrSparseMatrixElements);
        }
   }

    return SparseMatrix(multOfSparseMatrixElements);
}


// If row consists entirely of zeros returns true, else false.
bool SparseMatrix::IsRowZero(int rowIndex) const
{
    for (SparseMatrixElement element : m_SparseMatrixElements)
    {
        if (element.rowIndex == rowIndex)
        {
            return false;
        }

    }
    return true;
}


// Returns transpose of SparseMatrix.
const SparseMatrix SparseMatrix::transpose() const
{
    SparseMatrix tmpSparseMatrix; // tmp SparseMatrix to hold transpose SparseMatrix.
    SparseMatrixElement tmpSparseMatrixElement;
    SparseVector tmpSparseVector;
    double data;
    int colIndex;
    int rowIndex;
    int i, j;
    for ( SparseMatrixElement element : m_SparseMatrixElements )
    {
        for (i = 0; i <= element.sparseVector.GetLastIndexOfSparseVectorElements(); i++)
        {
            if (!element.sparseVector.IsSparseVectorElementDataZero(i))
            {
                // i'th SparseVector for current row is nonzero. So append this to transpose SparseMatrix.
                colIndex = element.rowIndex; // get colIndex.
                rowIndex = i; // get rowIndex.
                data = element.sparseVector.GetDataOfSparseVectorElement(i); //get data.

                // Append SparseVectorElement to tmpSparseVector
                tmpSparseVector.AppendSparseVectorElement(colIndex, data);

                // Append tmpSparseVector to tmpSparseMatrix.
                tmpSparseMatrix.AppendSparseMatrixElement(rowIndex, tmpSparseVector);

                tmpSparseVector.ResetSparseVector(); // clear tmpSparseVector for next calls.
            }
        }
    }
    // sort each row in ascending order.
    tmpSparseMatrix.SortSparseMatrixRowsInAscendingOrder();

    return tmpSparseMatrix;
}


// Sorts each row in ascending order.
void SparseMatrix::SortSparseMatrixRowsInAscendingOrder()
{

    // by using Selection Sort Algorithm.
    int i, j;
    int minRowIndex, minIndex;

    for (i = 0; i < m_SparseMatrixElements.size()-1; i++)
    {
        minRowIndex = m_SparseMatrixElements[i].rowIndex;
        minIndex = i;
        for (j = i+1; j < m_SparseMatrixElements.size(); j++)
        {
            if (m_SparseMatrixElements[j].rowIndex < minRowIndex)
            {
                minIndex = j;
                minRowIndex = m_SparseMatrixElements[j].rowIndex;
            }
        }
        std::swap(m_SparseMatrixElements[i], m_SparseMatrixElements[minIndex]);
    }
}


// Returns the largets colIndex value by searching entire SparseVectors in SparseMatrix.
int SparseMatrix::GetLargestColIndexInSparseMatrixElement() const
{
    int largest = 0;
    for (SparseMatrixElement element : m_SparseMatrixElements )
    {
        if (element.sparseVector.GetLastIndexOfSparseVectorElements() > largest)
            largest = element.sparseVector.GetLastIndexOfSparseVectorElements();
    }

    return largest;
}


// Returns index of value where sparseMatrixElements rowIndex is parameter rowIndex 
int SparseMatrix::GetIndexOfSparseMatrixElementRowIndex(int rowIndex) const
{
    for (int i = 0; i <= GetLastIndexOfSparseMatrixRow(); i++)
        if (m_SparseMatrixElements[i].rowIndex == rowIndex)
            return i;
    return -1;
}

// Appends a SparseMatrixElement to m_SparseMatrixElements.
void SparseMatrix::AppendSparseMatrixElement(const SparseMatrixElement& element)
{
    m_SparseMatrixElements.push_back(element);
}

// Appends a SparseMatrixElement to m_SparseMatrixElements.
void SparseMatrix::AppendSparseMatrixElement(int rowIndex, const SparseVector& s)
{
    if (IsRowZero(rowIndex))
        m_SparseMatrixElements.push_back({rowIndex, s});
    else
        m_SparseMatrixElements[GetIndexOfSparseMatrixElementRowIndex(rowIndex)].sparseVector = m_SparseMatrixElements[GetIndexOfSparseMatrixElementRowIndex(rowIndex)].sparseVector + s;
}

int SparseMatrix::GetLastIndexOfSparseMatrixRow() const
{
    return m_SparseMatrixElements[m_SparseMatrixElements.size() - 1].rowIndex;
}

int SparseMatrix::GetRowIndexOfSparseMatrixElements(int index) const
{
    return (m_SparseMatrixElements[index].rowIndex);
}


// Returns SparseVector of SparseMatrixElement in m_SparseMatrixElements which
// has indexRow is parameter indexRow.
const SparseVector SparseMatrix::GetSparseVectorOfSparseMatrixElement(int indexRow) const
{
    for ( SparseMatrixElement element : m_SparseMatrixElements )
    {
        if (element.rowIndex == indexRow)
            return element.sparseVector;
    }
    return SparseVector();
}
