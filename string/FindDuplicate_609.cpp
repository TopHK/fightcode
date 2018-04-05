#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

struct file
{
    string directory;
    string fileName;
    string fileContent;
    file(string dir, string name, string content): directory(dir), fileName(name), fileContent(content){}
};

bool myCompare(const file &x, const file &y)
{
    return x.fileContent < y.fileContent;
}

class Solution
{
public:
    vector<vector<string>> findDuplicate(vector<string>& paths)
    {
        vector<file> fileSystem;
        vector<vector<string>> result;

        // step 1: parse each path into file structure
        for(int i = 0; i < paths.size(); ++i)
        {
            string path = paths[i];
            string directory;
            int leftPos = -1;
            int rightPos = 0;

            while(rightPos != -1)
            {
                rightPos = path.find(' ', leftPos+1);
                string tempStr, fileName, fileContent;
                if(rightPos != string::npos) tempStr = path.substr(leftPos+1, rightPos-leftPos-1);
                else tempStr = path.substr(leftPos+1);

                if(directory.empty())
                {
                    directory = tempStr;
                    leftPos = rightPos;
                    continue;
                }

                int leftBracket = tempStr.find('(');
                fileName = tempStr.substr(0, leftBracket);
                int rightBracket = tempStr.find(')');
                fileContent = tempStr.substr(leftBracket+1, rightBracket-leftBracket-1);
                fileSystem.push_back(file(directory, fileName, fileContent));
                leftPos = rightPos;
            }
        }

        // sort by file content
        sort(fileSystem.begin(), fileSystem.end(), myCompare);

        // compare to see if file content between the adjacent file structure
        vector<string> oneGroup;
        for(int i = 0; i < fileSystem.size(); ++i)
        {
            string filePath = fileSystem[i].directory + '/' + fileSystem[i].fileName;
            if(i == 0) oneGroup.push_back(filePath);
            else
            {
                if(fileSystem[i].fileContent == fileSystem[i-1].fileContent)
                {
                    oneGroup.push_back(filePath);
                }
                else
                {
                    if(oneGroup.size() > 1) result.push_back(oneGroup);
                    oneGroup.clear();
                    oneGroup.push_back(filePath);
                }
            }
            if(i == fileSystem.size()-1 && oneGroup.size() > 1) result.push_back(oneGroup);
        }
        return result;
    }
};

void print(const vector<vector<string>> &result)
{
    for(int i = 0; i < result.size(); ++i)
    {
        for(int j = 0; j < result[i].size(); ++j)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    Solution solution;
    vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
    vector<vector<string>> result = solution.findDuplicate(paths);
    print(result);
    return 0;
}


/*
Given a list of directory info including directory path, and all the files with contents in this directory, you need to find out all the groups of duplicate files in the file system in terms of their paths.

A group of duplicate files consists of at least two files that have exactly the same content.

A single directory info string in the input list has the following format:

"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"

It means there are n files (f1.txt, f2.txt ... fn.txt with content f1_content, f2_content ... fn_content, respectively) in directory root/d1/d2/.../dm. Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.

The output is a list of group of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:

"directory_path/file_name.txt"

Example 1:
Input:
["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
Output:
[["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
Note:
No order is required for the final output.
You may assume the directory name, file name and file content only has letters and digits, and the length of file content is in the range of [1,50].
The number of files given is in the range of [1,20000].
You may assume no files or directories share the same name in the same directory.
You may assume each given directory info represents a unique directory. Directory path and file info are separated by a single blank space.
Follow-up beyond contest:
Imagine you are given a real file system, how will you search files? DFS or BFS?
If the file content is very large (GB level), how will you modify your solution?
If you can only read the file by 1kb each time, how will you modify your solution?
What is the time complexity of your modified solution? What is the most time-consuming part and memory consuming part of it? How to optimize?
How to make sure the duplicated files you find are not false positive?
*/
