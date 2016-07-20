#ifndef DATE_H
#define DATE_H

#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <string>

class Node
{
    public:
        std::vector<bool> semigroup, generators;

        std::map<int, Node> children;

        int multiplicity, f;
        unsigned long long level;
        
        void buildTree();

        std::string csvLine(), texLine(), dotLine();
        
        static unsigned long long getLevels(), getBranches(), getCount();
        
    private:
        static unsigned long long levels, count, branches;

        void spawnChild(int k);

        void incrementCount();
        void incrementBranches();
        void modifyLevel(unsigned long long level);

        void calcGenerators();
        void createChildren();
        void cleanUp();

        static void step(std::pair<const int, Node> &p);
};

#endif
