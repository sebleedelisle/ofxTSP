#pragma once
#include "ofxTSP/Solver.h"
#include "ofUtils.h"

#include <map>
#include <vector>
#include <set>

using namespace std;

namespace ofxTSP {
	/** Solve in a shitty but exact way.
	Presume all routes are symmetric (same cost in both directions)
	**/
	class BruteForce : public Solver {
	public:
		Route solve(const Problem & problem);
		bool hasVisited(int i, const vector<int> & visited);
	
	protected:
		void step(const Problem & problem, Route visited);
	
		map<Route , float> solutions;
		Route bestSolution;
	};
}