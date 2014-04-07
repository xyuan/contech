#ifndef TASK_GRAPH_INFO_HPP
#define TASK_GRAPH_INFO_HPP

#include "TaskId.hpp"
#include "Action.hpp"
#include "ct_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <assert.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <inttypes.h>

using namespace std;
namespace contech {

class BasicBlockInfo
{
public:
    uint lineNumber;
    uint functionNumber;
    uint fileName;
    vector <uint> typeOfMemOps;
};

class FunctionInfo
{
public:
    string functionName;
    vector <uint> typeOfArguments;
    uint returnType;
};

class TypeInfo
{
    string typeName;
    size_t sizeOfType;
};

class TaskGraphInfo
{
public:
    map <uint, BasicBlockInfo> bbInfo;
    map <uint, TypeInfo> tyInfo;
    map <uint, FunctionInfo> funInfo;
    map <uint, string> fileName;
    TaskGraphInfo(ct_file*);
    TaskGraphInfo();
    
    void addRawBasicBlockInfo(uint bbid, uint lineNum, uint numMemOps, string function);
    void writeTaskGraphInfo(ct_file*);
};

}

#endif