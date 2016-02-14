#include "DetectMemoryLeak.h"
#include <string>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>

using std::string;
using std::vector;
using std::list;
using std::map;
using std::stack;
using std::queue;

// DO NOT MODIFY ANY LINE ABOVE OR ADD EXTRA INCLUDES

/*! 
 *  \brief     DM2126 Assignment 2
 *  \details   Submit the whole solution, but only this file will be used to grade
 *  \author    <John Doe>
 *  \date      2015 
 *  \note      <Admin ID>
 */


// Balanced parenthesis
 bool Brackets(const string& input)
{
     stack<char> inputstack;
     
     for (unsigned int x = 0; input[x] != '\0'; ++x)
     {
         
         switch (input[x])
         {
         case '>': if (inputstack.top() != '<' || inputstack.size() == 0 ){ return false; }
                   else  inputstack.pop(); break;                   
         case ')': if (inputstack.top() != '(' || inputstack.size() == 0 ){ return false; }
                   else inputstack.pop(); break;                    
         case '}': if (inputstack.top() != '{' || inputstack.size() == 0 ){ return false; }
                   else inputstack.pop(); break;                    
         case ']': if (inputstack.top() != '[' || inputstack.size() == 0 ){ return false; }
                   else inputstack.pop(); break;
                   
         default: inputstack.push(input[x]); break;

         } 
         if (input[x] == inputstack.top() && x > 0) return false;
     }
     unsigned inputstacksize = inputstack.size();
     if (inputstacksize == 0)
     {
         return true;
     }
     else return false;

}

// Query machine, hits
 void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results)
{
    map<int, unsigned int> mapo;
    for (auto i : queries)
    {
        mapo.insert(std::pair<int, unsigned>(i, 0));
    }
    for (auto d : data)
    {
        if (mapo.count(d) == true)
        {
            map<int, unsigned int>::iterator it;
            it = mapo.find(d);
            it->second += 1;
        }
        

    }
    for (auto q : queries)
    {
        map<int, unsigned int>::iterator it;
        it = mapo.find(q);
        results.push_back(it->second);
    }
}