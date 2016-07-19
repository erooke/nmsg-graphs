#include "node.h"


unsigned long long Node::count    = 1;
unsigned long long Node::levels   = 0;
unsigned long long Node::branches = 0;

void Node::spawnChild(int k)
{
    // Inherit data from parent
    children[k] = Node();
    children.at(k).semigroup.reserve(f+1);
    for(int k2 = 0; k2 < f+1; k2++){ 
        children.at(k).semigroup[k2]=semigroup[k2];
    }
    children.at(k).f = f;
    
    //Flip the necessary bits (refer to thm 4.1)
    children.at(k).semigroup[k] = false;            
    children.at(k).semigroup[f-k] = true;          
    
    //Increment the necessary counters
    incrementCount();     
    children.at(k).level = level+1;
}
 
void Node::createChildren()
{
    for(int k = (f+1)/2; k < f; k++){        
        if( generators[k]
          & (!semigroup[2*k-f])
          & (3*k != 2*f)
          & (4*k != 3*f)
          & (f-k < multiplicity)){
            spawnChild(k);                    
        }
    }
}
 
void Node::calcGenerators()
{
	multiplicity = 0;
	while(!semigroup[multiplicity]){      
		multiplicity++;
	}
	generators.reserve(f+multiplicity+1);

    // Copy memory from one array to the other
	for(int i = 0; i < f+1; i++){
		generators[i]=semigroup[i];
	}
	for(int i = f+1; i < f+multiplicity+1; i++){
		generators[i]=true;
	}
		
	for(int k = f+multiplicity; k >= multiplicity*2; k--){  
		if(generators[k]){								
			for(int j = k-2; j >= k/2; j--){		
				if(generators[j]&generators[k-j]){		
					generators[k]=false;				
					break;									
				}
			}
		}
	}	
}

void Node::step(std::pair<const int, Node> &p)
{
    p.second.buildTree();
    p.second.cleanUp();
}
 
void Node::buildTree()
{
    calcGenerators();
    createChildren();  
    if(children.empty()){
        incrementBranches();
        modifyLevel(level);
    }else{
        std::for_each(children.begin(), children.end(), step);
    }
}
 
void Node::cleanUp()
{
    children.clear();
}

void Node::incrementCount()
{
    ++count;
}

void Node::incrementBranches()
{
    ++branches;
}

void Node::modifyLevel(unsigned long long level)
{
    if(level > levels)
    {
        levels = level;
    }
}

unsigned long long Node::getBranches()
{
    return Node::branches;
}

unsigned long long Node::getLevels()
{
    return Node::levels;
}

unsigned long long Node::getCount()
{
    return Node::count;
}
