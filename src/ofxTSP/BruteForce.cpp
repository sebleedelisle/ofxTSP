#include "ofxTSP/BruteForce.h"
namespace ofxTSP {
	//---------
	vector<int> BruteForce::solve(const Problem & problem) {
		//presume no assymetry

		uint32_t problemSize = problem.distance.size();

		this->solutions.clear();
		vector<int> visited;
		step(problem, visited, 0);

		float best = std::numeric_limits<float>::infinity();
		
		map<vector<int>, float>::const_iterator it;
		map<vector<int>, float>::const_iterator solution;
		for (it = solutions.begin(); it != solutions.end(); it++) {
			if (it->second < best)
				solution = it;
		}
		return solution->first;
	}

	//---------
	bool hasVisited(int i, const vector<int> & visited) {
		vector<int>::const_iterator it;
		for (it = visited.begin(); it != visited.end(); it++) {
			if (*it == i)
				return true;
		}
		return false;
	}

	//---------
	void BruteForce::step(const Problem & problem, vector<int> visited, float distance) {
		if (visited.size() == problem.destinationCount) {
			//we've visited all destinations, add to possible solutions
			solutions.insert(pair<vector<int>, float>(visited, distance));
		}

		for (int i=0; i<problem.destinationCount; i++) {
			if (!hasVisited(i, visited)) {
				vector<int> visitBranch = visited;
				visitBranch.push_back(i);
				step(problem, visited, distance + problem.distance[Journey(visited.back(), i)]);
			}
		}
	}

}