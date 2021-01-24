//
// Created by HaigCode.
//
class Leaderboard {
public:
    vector<int> scoreVec;
    map<int, int> idScore;
    Leaderboard() {
        scoreVec.clear();
        idScore.clear();
    }

    void addScore(int playerId, int score) {
        if (idScore.count(playerId) != 0) {
            int oldscore = idScore[playerId];
            idScore[playerId] += score;
            vector<int>::iterator it = find(scoreVec.begin(), scoreVec.end(), oldscore);
            *it += score;
        }
        else {
            idScore[playerId] = score;
            scoreVec.push_back(score);
        }
    }

    int top(int K) {
        sort(scoreVec.begin(), scoreVec.end(),greater<int>());
        int sum = 0;
        for (int i = 0; i < scoreVec.size() && i < K; i++) {
            sum += scoreVec[i];
        }
        return sum;
    }

    void reset(int playerId) {
        int score = idScore[playerId];
        idScore.erase(playerId);
        vector<int>::iterator it = find(scoreVec.begin(), scoreVec.end(), score);
        scoreVec.erase(it);
    }
};
