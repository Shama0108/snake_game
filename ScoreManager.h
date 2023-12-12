//keeps tracks of the players score
# pragma

class ScoreManager{
    private:
        int score;

    public:

        ScoreManager();
        void incrementScore(int points);
        void resetScore();
        int getScore() const;

};