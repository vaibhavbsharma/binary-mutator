#include "PatchCFG.h"
#include <fstream>
#include <string>

using namespace std;
using namespace Dyninst;
using namespace Dyninst::ParseAPI;

vector<pair<void *, EdgeTypeEnum> > mutatedInsns;

char checkpointPath[500];

void initMutationCheckpoint(char* binaryPath, bool debug) {
  sprintf(checkpointPath, "%s-MutatedInsns.lst", binaryPath);
	ifstream fin(checkpointPath);
	string s1, s2;
	while(fin>>s1>>s2) {
		unsigned long long int addr;
		unsigned int e;
		sscanf(s1.c_str(), "%llx", &addr);
		sscanf(s2.c_str(), "%u", &e);
		//EdgeTypeEnum e = (EdgeTypeEnum) atoi(s2.c_str());
		if(debug) cout<<"prev mutation: "<<s1<<"("<<s2<<")"<<endl;
		pair<void *, EdgeTypeEnum> p ((void *)addr, (EdgeTypeEnum) e);
		mutatedInsns.push_back(p);
	}
	// for(int i=0; i<mutatedInsns.size(); i++) {
	// 	cout<<mutatedInsns[i].first<<" "<<mutatedInsns[i].second<<endl;
	// }
}

void checkpointMutation(void *addr, EdgeTypeEnum e) {
	ofstream fout(checkpointPath, ios_base::app);
	fout<<addr<<" " <<e<<endl;
	fout.close();
}

bool mutatedBranch(void *addr, EdgeTypeEnum e) {
	for(int i=0; i < mutatedInsns.size(); i++) {
		if(mutatedInsns[i].first==addr && mutatedInsns[i].second==e) {
			return true;
		}
	}
	return false;
}
