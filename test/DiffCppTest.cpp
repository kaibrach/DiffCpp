#include <gtest/gtest.h>
#include "../include/diff.h"

// Load Expected Results from the specified file
vector<string> loadExpectedResults(string path)
{

    vector<string> lines;
    fstream inputFile;
    string singleLine;

    inputFile.open(path);

    // Check that the specified file can open successfully
    if (inputFile.is_open())
    {

        while (getline(inputFile, singleLine))
        {
            lines.push_back(singleLine);
        }
        inputFile.close();
    }
    // Terminate the program
    else
    {
        cout << "Can not open the specified directory - No such file or folder" << endl;
        exit(EXIT_FAILURE);
    }

    return lines;
}

TEST(TestCase1, CheckingSimpleDiff) {
    char* argvArray[3];
    char** argv = argvArray;
    argvArray[1] = (char*)"/home/runner/work/DiffCpp/DiffCpp/test/TestCases/TestCase1/Input1.txt";
    argvArray[2] = (char*)"/home/runner/work/DiffCpp/DiffCpp/test/TestCases/TestCase1/Input2.txt";
    
    string lineToCheck;

    DiffSession session(3, argv);
    
    vector<string> linesFile1 = session.getLinesFromFile(argv[1]),
                   linesFile2 = session.getLinesFromFile(argv[2]);

    vector<string> expectedOutput = 
        loadExpectedResults("/home/runner/work/DiffCpp/DiffCpp/test/TestCases/TestCase1/ExpectedResults.txt");

    vector<vector<string>> diff = session.getDiff(linesFile1, linesFile2);
    
    if (expectedOutput.size() != diff.size()) {
        EXPECT_TRUE(false);
    }

    else {
        for (int i = 0; i < diff.size(); i++) {
            lineToCheck = "[" + diff[i][0] + "]" + diff[i][1];
            EXPECT_EQ(lineToCheck, expectedOutput[i]);
        }

        EXPECT_TRUE(true);
    }
}

TEST(TestCase2, ComparePythonCode) {
    char* argvArray[3];
    char** argv = argvArray;
    argvArray[1] = (char*)"/home/runner/work/DiffCpp/DiffCpp/test/TestCases/TestCase2/Input1.txt";
    argvArray[2] = (char*)"/home/runner/work/DiffCpp/DiffCpp/test/TestCases/TestCase2/Input2.txt";

    string lineToCheck;

    DiffSession session(3, argv);

    vector<string> linesFile1 = session.getLinesFromFile(argv[1]),
                   linesFile2 = session.getLinesFromFile(argv[2]);

    vector<string> expectedOutput =
        loadExpectedResults("/home/runner/work/DiffCpp/DiffCpp/test/TestCases/TestCase2/ExpectedResults.txt");

    vector<vector<string>> diff = session.getDiff(linesFile1, linesFile2);

    if (expectedOutput.size() != diff.size()) {
        EXPECT_TRUE(false);
    }

    else {
        for (int i = 0; i < diff.size(); i++) {
            lineToCheck = "[" + diff[i][0] + "]" + diff[i][1];
            EXPECT_EQ(lineToCheck, expectedOutput[i]);
        }

        EXPECT_TRUE(true);
    }
}

TEST(TestCase3, CompareCppCode) {
    char* argvArray[4];
    char** argv = argvArray;
    argvArray[1] = (char*)"/home/runner/work/DiffCpp/DiffCpp/test/TestCases/TestCase3/Input1.txt";
    argvArray[2] = (char*)"/home/runner/work/DiffCpp/DiffCpp/test/TestCases/TestCase3/Input2.txt";
    argvArray[3] = (char*)"/W";

    string lineToCheck;

    DiffSession session(4, argv);

    vector<string> linesFile1 = session.getLinesFromFile(argv[1]),
                   linesFile2 = session.getLinesFromFile(argv[2]);

    vector<string> expectedOutput =
        loadExpectedResults("/home/runner/work/DiffCpp/DiffCpp/test/TestCases/TestCase3/ExpectedResults.txt");

    vector<vector<string>> diff = session.getDiff(linesFile1, linesFile2);

    if (expectedOutput.size() != diff.size()) {
        EXPECT_TRUE(false);
    }

    else {
        for (int i = 0; i < diff.size(); i++) {
            lineToCheck = "[" + diff[i][0] + "]" + diff[i][1];
            EXPECT_EQ(lineToCheck, expectedOutput[i]);
        }

        EXPECT_TRUE(true);
    }
}

TEST(TestCase4, CheckingComplexDiff) {
    char* argvArray[3];
    char** argv = argvArray;
    argvArray[1] = (char*)"/home/runner/work/DiffCpp/DiffCpp/test/TestCases/TestCase4/Input1.txt";
    argvArray[2] = (char*)"/home/runner/work/DiffCpp/DiffCpp/test/TestCases/TestCase4/Input2.txt";

    string lineToCheck;

    DiffSession session(3, argv);

    vector<string> linesFile1 = session.getLinesFromFile(argv[1]),
                   linesFile2 = session.getLinesFromFile(argv[2]);

    vector<string> expectedOutput =
        loadExpectedResults("/home/runner/work/DiffCpp/DiffCpp/test/TestCases/TestCase4/ExpectedResults.txt");

    vector<vector<string>> diff = session.getDiff(linesFile1, linesFile2);

    if (expectedOutput.size() != diff.size()) {
        EXPECT_TRUE(false);
    }

    else {
        for (int i = 0; i < diff.size(); i++) {
            lineToCheck = "[" + diff[i][0] + "]" + diff[i][1];
            EXPECT_EQ(lineToCheck, expectedOutput[i]);
        }
        EXPECT_TRUE(true);
    }
}
