#include <iostream>
// #include <string>
#include <vector>
using namespace std;

class emptyCatalogue {};
class invalidReaction {};

class Result {
   public:
    string reaction;
    float quantity;       // grams
    float effectiveness;  // between 0 and 1
    float getLoss();
};

float Result::getLoss() {
    return quantity * (1 - effectiveness);
}

class ResultCatalogue {
   private:
    vector<Result> results;

   public:
    ResultCatalogue() {
        results.clear();
    }
    ResultCatalogue(vector<Result> newResults) {
        results = newResults;
    }
    vector<Result> getResults();
    void addResult(Result newResult);
    void sortByLoss();
    string toString();
};

vector<Result> ResultCatalogue::getResults() {
    return results;
}

void ResultCatalogue::addResult(Result newResult) {
    if (newResult.effectiveness > 1 || newResult.effectiveness < 0 || newResult.quantity < 0 || newResult.reaction.empty()) {
        throw invalidReaction();
    }
    results.push_back(newResult);
}

int cmp(Result x, Result y) {
    return x.getLoss() > y.getLoss();
}

void ResultCatalogue::sortByLoss() {
    if (results.empty()) {
        throw emptyCatalogue();
    }
    sort(results.begin(), results.end(), cmp);
}

// string ResultCatalogue::toString() {
//     for (auto &result : results) {

//     }
// }

int main() {
}
