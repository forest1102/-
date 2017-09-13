#pragma once

///////////////////////////////////////////////////////////////////////
//
//  ハイスコア一覧
//
class Score : public MyApp::Scene
{
private:

	std::array<ScoreData, GameInfo::MAX_SCORE_SIZE> m_highScores;

public:

	void init() override;

	void update() override;

	void draw() const override;
};