/**
 * Ertsiger
 * 24/09/2016
 * Time: 0.103
 */
#include <iostream>

using namespace std;

int rows, cols;
int heights[101][101];
bool visited[101][101];

/**
 * Example when checking north faces:
 * 2 2      6
 * 3 1 ---> 6
 * 6 2      6
 *          3
 *          3 2
 *          3 1
 * 1st face = {1, 3}
 * 2nd face = {6}
 * 3rd face = {2}
 */
int getNumNorthFaces()
{
    int numFaces = 1;

    for (int i = 1; i < rows; ++i)
    {
        int first = 0; // the one in the northest part
        int second = 0;

        for (int j = 0; j < cols; ++j)
        {
            if (heights[i][j] > heights[i - 1][j])
            {
                if (heights[i][j] <= first || heights[i - 1][j] >= second)
                {
                    ++numFaces;
                }

                first = heights[i - 1][j];
                second = heights[i][j];
            }
            else
            {
                first = 0;
                second = 0;
            }
        }
    }

    return numFaces;
}

int getNumSouthFaces()
{
    int numFaces = 1;

    for (int i = rows - 2; i >= 0; --i)
    {
        int first = 0;
        int second = 0;

        for (int j = 0; j < cols; ++j)
        {
            if (heights[i][j] > heights[i + 1][j])
            {
                if (heights[i][j] <= first || heights[i + 1][j] >= second)
                {
                    ++numFaces;
                }

                first = heights[i + 1][j];
                second = heights[i][j];
            }
            else
            {
                first = 0;
                second = 0;
            }
        }
    }

    return numFaces;
}

int getNumWestFaces()
{
    int numFaces = 1;

    for (int j = 1; j < cols; ++j)
    {
        int first = 0;
        int second = 0;

        for (int i = 0; i < rows; ++i)
        {
            if (heights[i][j] > heights[i][j - 1])
            {
                if (heights[i][j] <= first || heights[i][j - 1] >= second)
                {
                    ++numFaces;
                }

                first = heights[i][j - 1];
                second = heights[i][j];
            }
            else
            {
                first = 0;
                second = 0;
            }
        }
    }

    return numFaces;
}

int getNumEastFaces()
{
    int numFaces = 1;

    for (int j = cols - 2; j >= 0; --j)
    {
        int first = 0;
        int second = 0;

        for (int i = 0; i < rows; ++i)
        {
            if (heights[i][j] > heights[i][j + 1])
            {
                if (heights[i][j] <= first || heights[i][j + 1] >= second)
                {
                    ++numFaces;
                }

                first = heights[i][j + 1];
                second = heights[i][j];
            }
            else
            {
                first = 0;
                second = 0;
            }
        }
    }

    return numFaces;
}

void setUpFaces(int i, int j, const int height)
{
    if (i >= 0 && i < rows && j >= 0 && j < cols)
    {
        if (!visited[i][j] && heights[i][j] == height)
        {
            visited[i][j] = true;
            setUpFaces(i - 1, j, height);
            setUpFaces(i, j - 1, height);
            setUpFaces(i, j + 1, height);
            setUpFaces(i + 1, j, height);
        }
    }
}

int getNumUpFaces()
{
    int numUpFaces = 0;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (!visited[i][j])
            {
                setUpFaces(i, j, heights[i][j]);
                ++numUpFaces;
            }
        }
    }

    return numUpFaces;
}

int main()
{
    while (cin >> rows >> cols)
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cin >> heights[i][j];
                visited[i][j] = false;
            }
        }

        // bottom faces (just 1)
        int numBottomFaces = 1;

        // up faces (analyse heights)
        int numUpFaces = getNumUpFaces();

        // lateral faces
        int numNorthFaces = getNumNorthFaces();
        int numSouthFaces = getNumSouthFaces();
        int numWestFaces = getNumWestFaces();
        int numEastFaces = getNumEastFaces();

        int numTotalFaces = numBottomFaces + numUpFaces + numNorthFaces + numSouthFaces + numWestFaces + numEastFaces;

        cout << numTotalFaces << endl;
    }

    return 0;
}

